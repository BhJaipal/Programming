#!/home/jaipal001/.bun/bin/bun

/// <reference types="node" />

import { exec } from "child_process";
import { existsSync, mkdirSync, readFileSync } from "fs";

let { writeFileSync } = require("fs");
let { argv } = require("process");

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
	mkdirSync(`${project}/src`);
	mkdirSync(`${project}/test`);
	let content = readFileSync(
		(argv[1] as string).split("/aloo")[0] + "/sample/main.c"
	)
		.toString()
		.replace("$appName", appName!);

	writeFileSync(project + "/src/main.c", content);

	let cmake = readFileSync(
		(argv[1] as string).split("/aloo")[0] + "/sample/CMakeLists.txt"
	).toString();
	cmake = cmake.replace("${project}", project);
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
	cmake = cmake.replace("src/main.c", "main.c");
	cmake = cmake.replace("/bin", "/../bin");
	writeFileSync(project + "/test/CMakeLists.txt", cmake);
	writeFileSync(
		project + "/test/main.c",
		readFileSync((argv[1] as string).split("/aloo")[0] + "/sample/test.c")
			.toString()
			.replace("$appName", appName!)
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

function help() {
	console.log("\t\t\t\t\t\t\t\t\t\x1b[1mALOO CLI\x1b[0m");
	console.log("\x1b[32mCommands\x1b[0m");
	console.log(
		"\t\t\t\x1b[1maloo create-app <name>\x1b[0m\t\t\t\t\tCreates C Aloo app template\n"
	);
	console.log("\t\t\t\x1b[1maloo run\x1b[0m\t\t\t\t\t\t\t\tRuns Aloo app\n");
	console.log(
		"\t\t\t\x1b[1maloo test\x1b[0m\t\t\t\t\t\t\t\tRuns Aloo app tests\n"
	);
}

if (argv.length > 2) {
	let command = argv[2];

	switch (command) {
		case "create-app":
			createGtkApp(argv[3]);
			break;
		case "run":
			exec(
				`${argv[1].split("/aloo")[0]}/run.sh ${process.cwd()}`,
				(error, stdout, stderr) => {
					if (error) {
						console.log(`error: ${error.message}`);
						return;
					}
					if (stderr) {
						console.log(`stderr: ${stderr}`);
						return;
					}
					console.log(`success: ${stdout}`);
				}
			);
			break;
		case "test":
			exec(
				`${argv[1].split("/aloo")[0]}/run-test.sh ${process.cwd()}`,
				(error, stdout, stderr) => {
					if (error) {
						console.log(`error: ${error.message}`);
						return;
					}
					if (stderr) {
						console.log(`stderr: ${stderr}`);
						return;
					}
					console.log(`success: ${stdout}`);
				}
			);
			break;
		default:
			help();
			break;
	}
} else {
	help();
}
