#!/home/jaipal001/.bun/bin/bun
"use strict";
/// <reference types="node" />
Object.defineProperty(exports, "__esModule", { value: true });
var model_1 = require("./model");
var fs_1 = require("fs");
var connect_db_1 = require("./connect-db");
var writeFileSync = require("fs").writeFileSync;
var argv = require("process").argv;
console.log(argv);
function createGtkApp(project) {
    if (!project) {
        project = prompt("Enter Project Name: ", "aloo-project");
    }
    if (!project)
        return;
    if ((0, fs_1.existsSync)(project)) {
        throw "Project Already Exists";
    }
    var appName = prompt("Enter App Name: ", "Example App");
    var appDesc = prompt("Do you want to add a description? ", "n");
    var desc = "An default template for aloo App";
    if (appDesc == "y") {
        desc = prompt("Enter App Description: ", "An default template for aloo App");
    }
    (0, fs_1.mkdirSync)(project);
    (0, fs_1.mkdirSync)("".concat(project, "/app"));
    (0, fs_1.mkdirSync)("".concat(project, "/test"));
    if (typeof argv[1] != "string")
        return;
    if (appName == null)
        throw "Name must be provided";
    var content = (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/main.c")
        .toString()
        .replace("$appName", appName)
        .replace("$project", project);
    writeFileSync(project + "/app/main.c", content);
    var cmake = (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/CMakeLists.txt").toString();
    cmake = cmake.replace("${appName}", appName);
    cmake = cmake.replace("${libaloo}", argv[1].split("/cli/aloo")[0] + "/lib/libaloo.a");
    cmake = cmake.replace("${include_dir}", argv[1].split("/cli/aloo")[0] + "/include");
    writeFileSync(project + "/CMakeLists.txt", cmake);
    while (cmake.includes("(run.exe")) {
        cmake = cmake.replace("(run.exe", "(test-run.exe");
    }
    cmake = cmake.replace("app/main.c", "main.c");
    cmake = cmake.replace("/bin", "/../bin");
    writeFileSync(project + "/test/CMakeLists.txt", cmake);
    writeFileSync(project + "/test/main.c", (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/test.c")
        .toString()
        .replace("$appName", appName)
        .replace("$project", project));
    writeFileSync(project + "/aloo.json", JSON.stringify({
        project: project,
        app: appName,
        description: desc,
        $schema: argv[1].split("/aloo")[0] + "/aloo.schema.json",
    }));
}
function findAlooJson(path) {
    if (path == "/" || path == "/home") {
        return null;
    }
    if (!(0, fs_1.existsSync)(path + "/aloo.json")) {
        if (path.match(/\/home\/(\.|\w|\d|_|\s)+/g)) {
            return null;
        }
        return findAlooJson(path.split("/").slice(0, -1).join("/"));
    }
    return path;
}
var project = findAlooJson(process.cwd());
if (argv[2] != "create-app" &&
    argv[2] != "help" &&
    argv.length >= 3 &&
    project == null) {
    throw "aloo.json not found";
}
var command = argv[2];
switch (command) {
    case "create-app":
        createGtkApp(argv[3]);
        break;
    case "model":
        (0, model_1.createModel)(argv.slice(3));
        break;
    case "connect-db":
        (0, connect_db_1.connectDbWithModel)(argv);
        break;
}
