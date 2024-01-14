#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef char *string;
typedef string *strArr;
typedef int *intArr;
typedef struct {
  string key;
  int value;
} pair;
typedef pair *Map;
typedef struct {
  Map map;
  int len;
} Dict;

#define PAIR_SIZE (sizeof(char[20]) + sizeof(int))

int compare(const string, const string);
void createMap(pair *dict, int len, Dict *ret);
void printMap(Dict *);
string format(const char *str, int len);
intArr allValues(Dict *);
strArr allKeys(Dict *);
int getValue(Dict *, string);

int compare(const string str1, const string str2) {
  int cmp = 0;
  if (strlen(str2) == strlen(str1)) {
    cmp = 1;
    for (int i = 0; i < strlen(str1); i++) {
      if (str1[i] != str2[i]) {
        cmp = 0;
      }
    }
  }
  return cmp;
}
/**
 * @param *str string to be centered
 * @param len output size of string
 * @return centered string in spaces
 */
string format(const char *str, int len) {
  string out = malloc(sizeof(char) * len);
  int front = (len - strlen(str)) / 2;
  int rear = len - (front + strlen(str));
  for (int i = 0; i < front; i++) {
    out[i] = ' ';
  }
  for (int i = front; i < front + strlen(str); i++) {
    out[i] = str[i - front];
  }
  for (int i = 0; i < rear; i++) {
    out[i + front + strlen(str)] = ' ';
  }
  return out;
}

/**
 * @param *dict Dictionary for creation
 * @param length length of dictionary
 * @param *ret Dictionary for output
 */
void createMap(pair *dict, int len, Dict *ret) {
  ret->map = malloc(PAIR_SIZE * len);
  for (int i = 0; i < len; i++) {
    (*ret).map[i].key = malloc(sizeof(char) * 20);
    strcpy((*ret).map[i].key, (dict)[i].key);
    (*ret).map[i].value = (dict)[i].value;
  }
  ret->len = len;
}

/**
 * @param *dict Dictionary struct
 * @return list of keys of all pairs
 */
strArr allKeys(Dict *dict) {
  strArr kys = malloc(sizeof(char[20]) * (*dict).len);
  for (int i = 0; i < (*dict).len; i++) {
    kys[i] = (*dict).map[i].key;
  }
  return kys;
}

/**
 * @param *dict Dictionary struct
 * @return list of values of all pairs
 */
intArr allValues(Dict *dict) {
  intArr vals = malloc(sizeof(int) * dict->len);
  for (int i = 0; i < (*dict).len; i++) {
    vals[i] = (*dict).map[i].value;
  }
  return vals;
}

/**
 * @param *dict Dictionary struct
 * @param key key to be found
 * @return value of key in Dictionary
 */
int getValue(Dict *dict, const string key) {
  int val, exist = 0;
  for (int i = 0; i < (*dict).len; i++) {
    if (compare(dict->map[i].key, key)) {
      val = (*dict).map[i].value;
      exist = 1;
    }
  }
  if (exist) {
    return val;
  } else {
    fprintf(stderr, "KeyError: %s does not exist\n", key);
    exit(EXIT_FAILURE);
  }
}
void append(Dict *dict, pair bond) {
  dict->map = realloc(dict->map, PAIR_SIZE * (dict->len + 1));
  dict->map[dict->len].key = malloc(sizeof(char) * 20);
  strcpy(dict->map[dict->len].key, bond.key);
  dict->map[dict->len].value = bond.value;
  dict->len++;
}
void printMap(Dict *dict) {
  printf("Map elems: %d\n", dict->len);
  printf("%s\tvalue\n", format("key", 20));
  for (int i = 0; i < dict->len; i++) {
    printf("%s\t%d\n", format(dict->map[i].key, 20), dict->map[i].value);
  }
}

void delete(Dict *dict, const string key) {
  int found = 0, index = -1;
  strArr allKey = allKeys(dict);
  for (int i = 0; i < dict->len; i++) {
    if (compare(key, allKey[i])) {
      found = 1;
      index = i;
    }
  }
  if (found && index != -1) {
    for (int i = index; i < dict->len - 1; i++) {
      dict->map[i].value = dict->map[i + 1].value;
      strcpy(dict->map[i].key, dict->map[i + 1].key);
    }
    dict->map = realloc(dict->map, (dict->len * PAIR_SIZE) - 1);
    dict->len--;
  }
}

int main(int argc, char *argv[]) {
  pair dicton[3] = {{"Jaipal", 7}, {"hema", 4}, {"Saurabh", 9}};
  Dict dict;
  createMap(dicton, 3, &dict);
  pair bond = {"Abhishek", 1};
  append(&dict, bond);
  printMap(&dict);
  delete (&dict, "Jaipal");
  printf("After deleting Jaipal\n");
  printMap(&dict);
  return EXIT_SUCCESS;
}
