#include "dynamic-typed/dynamic-typed.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dict *variables;

unsigned var_exists(char *str) {
	if (variables->len == 0) return -1;
	for (unsigned i = 0;i < variables->len; i++) {
		if (!strcmp(variables->arr[i].key.data, str))
			return i;
	}
	return -1;
}

char contains(char *line, char l);
char start_with(char *str, char *search);

int main() {
	variables= dict_new();
	size_t len = 30;

	char *input = malloc(sizeof(char[30]));
	char off_guard = 0;
	while (1) {
		printf("\e[38;5;85m> \e[0m");
		getline(&input, &len, stdin);
		if (start_with(input, "exit(")) {
			if (input[5] == ')') {
				return 0;
			}
			int i= 0;
			char num = 0;
			while (input[i + 5] >= '0' && input[i + 5] <= '9') {
				num *= 10;
				num += input[i+5] - 0x30;
				i++;
			}
			return num;
		} else if (contains(input, '=')) {
			char varname[10], exit_err = 0;
			int len = 0;
			for (int i=0; i< 10; i++) {
				if (
					(input[i] >= 'a' && input[i] <= 'z') ||
					(input[i] >= 'A' && input[i] <= 'Z') ||
					(input[i] >= '0' && input[i] <= '9') ||
					input[i] == '_') {
					varname[i] = input[i];
					len++;
				} else if (i == 0 && input[i] <= '9' && input[i] >= '0') {
					printf("   ^ \n\e[91mSyntaxError:\e[0m Variable name cannot start with a digit\n");
					exit_err = 1;
					break;
				}
				else if (input[i] == ' ' || input[i] == '=') break;
				else {
					printf("   ^ \n\e[91mSyntaxError:\e[0m Variable name cannot contain a special symbol like: %c(%d)\n", input[i], input[i]);
					exit_err = 1;
				}
			}
			if (exit_err) continue;
			varname[len] = 0;
			for (int i = 0; i < 10; i++) {
				if (!(input[len + i] == ' ' || input[len + i] == '=')) {
					len += i;
					break;
				}
			}
			input += len;
			char type, hex = 0;
			if (start_with(input, "0x")) {
				input += 2;
				type = 1;
				hex = 1;
			} else if (input [0]== '"') {
				type = 0;
				input++;
			} else {
				type = 1;
			}
			if (input[strlen(input) -1] == '\n')
				input[strlen(input) - 1] = 0;
			union {int i; char str[20];} val;
			if (!type) {
				for (int i=0; i < 20; i++) {
					if (input[i] == '"') break;
					if (input[i] == 0) break;
					val.str[i] = input[i];
				}
			} else {
				val.i = 0;
				if (hex) {
					for (int i = 0; i < 20; i++) {
						if (!input[i]) break;
						val.i *= 16;
						if (input[i] >= '0' && input[i] <= '9') {
							val.i += input[i] - 0x30;
						}
						else if (input[i] <= 'f' && input[i] >= 'a') {
							val.i += input[i] - 0x61 + 10;
						}
						else if (input[i] <= 'F' && input[i] >= 'A') {
							val.i += input[i] - 0x41 + 10;
						}
						else break;
					}
				} else {
					for (int i = 0; i < 20; i++) {
						if (!input[i]) break;
						val.i *= 10;
						if (input[i] <= '9' && input[i] >= '0') {
							val.i += input[i] - 0x30;
						} else break;
					}
				}
			}
			if (var_exists(varname) != -1) {
				printf("   ^ \n\e[91mSyntaxError:\e[0m Variable named '%s' already exists\n", varname);
				continue;
			}
			if (type) {
				dict_add_element(variables, String.to_object(varname), Int.to_object(val.i));
				printf("%s:\n\t.byte %d\n", varname, val.i);
			} else {
				dict_add_element(variables, String.to_object(varname), String.to_object(val.str));
				printf("%s:\n\t.ascii %s\n", varname, val.str);
			}
		} else if (start_with(input, "show ")) {
			char varname[10], len = 0;
			input += 5;
			for (char i = 0;i< 10;i++) {
				if (input[i] == '\n') break;
				else if (input[i] == ' ') break;
				else if (input[i] == 0) break;
				varname[i] = input[i];
				len++;
			}
			varname[len] = 0;
			unsigned exist = var_exists(varname);
			if (exist == -1) {
				printf("        ^ \n\e[91mError:\e[0m Variable '%s' does not exists\n", varname);
				printf("\e[92m[TIP]: \e[0mDeclare variables by `%s = value`\n", varname);
			} else {
				ObjectType type = variables->arr[exist].value.type;
				printf("%s { type: %s, value: ", varname, type == INT ? "byte" : "ascii");
				if (type == INT)
					Int.print(variables->arr[exist].value);
				else
					String.print(variables->arr[exist].value);
				printf(" }\n");
			}
		}
		else {
			char cmd[10];
			for (int i = 0; i < 10; i++) {
				if (input[i] == '\n') break;
				else if (input[i] == ' ') break;
				else if (input[i] == 0) break;
				cmd[i] = input[i];
			}
			printf("    ^\n\e[91mError: \e[0mUnknown instruction '%s'\n", cmd);
		}
	}
}

char contains(char *line, char l) {
	unsigned i=0;
	while (line[i] != l) {
		if (!line[i]) return 0;
		i++;
	}
	return 1;
}
char start_with(char *str, char *search) {
	unsigned i =0;
	while (str[i] == search[i]) {
		if (!str[i])
			return 1;
		i++;
	}
	if (search[i] == 0) return 1;
	return 0;
}
