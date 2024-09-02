import { existsSync, mkdirSync, writeFileSync } from "fs";

export function createModel(argv: string[]) {
	if (!argv.length) throw "No name is provided";
	let match = argv[0].match(/([a-z]|[A-Z])+/);

	if (match == null) throw "Name must be only alphabets";
	if (match[0] != argv[0]) throw "Invalid name " + argv[0];
	if (argv.length == 1) throw "No properties are provided";

	let modelTypes = ["string", "int", "float", "bool"];
	let modelName = argv[0];

	const modelProps = argv
		.slice(1)
		.reduce((acc: { key: string; type: string }[], arg) => {
			if (!arg.includes(":")) throw "Invalid property " + arg;
			const [key, type] = arg.split(":");
			for (const element of key) {
				if (
					!(
						(element.charCodeAt(0) >= 65 &&
							element.charCodeAt(0) <= 90) ||
						(element.charCodeAt(0) >= 97 &&
							element.charCodeAt(0) <= 122)
					)
				) {
					throw "Invalid token " + element + " in " + key;
				}
			}
			for (const element of type) {
				if (
					!(
						(element.charCodeAt(0) >= 65 &&
							element.charCodeAt(0) <= 90) ||
						(element.charCodeAt(0) >= 97 &&
							element.charCodeAt(0) <= 122)
					)
				) {
					throw `Invalid token '${element}' in ${type}`;
				}
			}
			if (!modelTypes.includes(type)) throw `Invalid type '${type}'`;

			// ... validation code ...
			return [...acc, { key, type }];
		}, []);

	let typeSwitch = {
		string: "char *",
		bool: "boolean",
		int: "int",
		float: "float",
	};
	let content = `#include "aloo.h"

typedef struct _${modelName} {
	${modelProps
		.map((props) => `${typeSwitch[props.type]} ${props.key};`)
		.join("\n\t")}
};
`;

	if (!existsSync(process.cwd() + "/models"))
		mkdirSync(process.cwd() + "/models");

	if (!existsSync(process.cwd() + "/models/" + argv[0] + ".c")) {
		writeFileSync(process.cwd() + "/models/" + argv[0] + ".c", content);
	} else {
		throw "Model '" + modelName + "' already exists";
	}
}
