#!/home/jaipal001/.bun/bin/bun
/// <reference types="node" />

import { createModel } from "./model";
import { existsSync, mkdirSync, readFileSync } from "fs";
import { connectDbWithModel } from "./connect-db";

let { writeFileSync } = require("fs");
let { argv }: { argv: string[] } = require("process");

console.log(argv);

function createGtkApp(project?: string | null) {
	if (!project) {
		project = prompt("Enter Project Name: ", "aloo-project");
	}
	if (!project) return;
	if (existsSync(project)) {
		throw "Project Already Exists";
	}
	let appName = prompt("Enter App Name: ", "Example App");
	let appDesc = prompt("Do you want to add a description? ", "n");
	let desc: string | null = "An default template for aloo App";
	if (appDesc == "y") {
		desc = prompt(
			"Enter App Description: ",
			"An default template for aloo App"
		);
	}

	mkdirSync(project);
	mkdirSync(`${project}/app`);
	mkdirSync(`${project}/test`);
	if (typeof argv[1] != "string") return;
	if (appName == null) throw "Name must be provided";
	let content = readFileSync(argv[1].split("/aloo")[0] + "/sample/main.c")
		.toString()
		.replace("$appName", appName)
		.replace("$project", project);

	writeFileSync(project + "/app/main.c", content);

	let cmake = readFileSync(
		argv[1].split("/aloo")[0] + "/sample/CMakeLists.txt"
	).toString();
	cmake = cmake.replace("${appName}", appName);
	cmake = cmake.replace(
		"${libaloo}",
		argv[1].split("/cli/aloo")[0] + "/lib/libaloo.a"
	);
	cmake = cmake.replace(
		"${include_dir}",
		argv[1].split("/cli/aloo")[0] + "/include"
	);
	writeFileSync(project + "/CMakeLists.txt", cmake);
	while (cmake.includes("(run.exe")) {
		cmake = cmake.replace("(run.exe", "(test-run.exe");
	}
	cmake = cmake.replace("app/main.c", "main.c");
	cmake = cmake.replace("/bin", "/../bin");
	writeFileSync(project + "/test/CMakeLists.txt", cmake);
	writeFileSync(
		project + "/test/main.c",
		readFileSync(argv[1].split("/aloo")[0] + "/sample/test.c")
			.toString()
			.replace("$appName", appName)
			.replace("$project", project)
	);
	writeFileSync(
		project + "/aloo.json",
		JSON.stringify({
			project,
			app: appName,
			description: desc,
			$schema: argv[1].split("/aloo")[0] + "/aloo.schema.json",
		})
	);
}

function findAlooJson(path: string) {
	if (path == "/" || path == "/home") {
		return null;
	}
	if (!existsSync(path + "/aloo.json")) {
		if (path.match(/\/home\/(\.|\w|\d|_|\s)+/g)) {
			return null;
		}
		return findAlooJson(path.split("/").slice(0, -1).join("/"));
	}
	return path;
}

let project = findAlooJson(process.cwd());
if (
	argv[2] != "create-app" &&
	argv[2] != "help" &&
	argv.length >= 3 &&
	project == null
) {
	throw "aloo.json not found";
}

let command = argv[2];
switch (command) {
	case "create-app":
		createGtkApp(argv[3]);
		break;
	case "model":
		createModel(argv.slice(3));
		break;
	case "connect-db":
		connectDbWithModel(argv);
		break;
}
