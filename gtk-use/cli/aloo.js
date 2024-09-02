#!/home/linuxbrew/.linuxbrew/node
"use strict";
/// <reference types="node" />
Object.defineProperty(exports, "__esModule", { value: true });
var child_process_1 = require("child_process");
var fs_1 = require("fs");
var writeFileSync = require("fs").writeFileSync;
var argv = require("process").argv;
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
    (0, fs_1.mkdirSync)("".concat(project, "/src"));
    (0, fs_1.mkdirSync)("".concat(project, "/test"));
    var content = (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/main.c")
        .toString()
        .replace("$appName", appName);
    writeFileSync(project + "/src/main.c", content);
    var cmake = (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/CMakeLists.txt").toString();
    cmake = cmake.replace("${project}", project);
    cmake = cmake.replace("${libaloo}", argv[1].split("/cli/aloo")[0] + "/lib/libaloo.a");
    cmake = cmake.replace("${include_dir}", argv[1].split("/cli/aloo")[0] + "/include");
    writeFileSync(project + "/CMakeLists.txt", cmake);
    while (cmake.includes("(run.exe")) {
        cmake = cmake.replace("(run.exe", "(test-run.exe");
    }
    cmake = cmake.replace("src/main.c", "main.c");
    cmake = cmake.replace("/bin", "/../bin");
    writeFileSync(project + "/test/CMakeLists.txt", cmake);
    writeFileSync(project + "/test/main.c", (0, fs_1.readFileSync)(argv[1].split("/aloo")[0] + "/sample/test.c")
        .toString()
        .replace("$appName", appName));
    writeFileSync(project + "/aloo.json", JSON.stringify({
        project: project,
        app: appName,
        description: desc,
        $schema: argv[1].split("/aloo")[0] + "/aloo.schema.json",
    }));
}
function help() {
    console.log("\t\t\t\t\t\t\t\t\t\x1b[1mALOO CLI\x1b[0m");
    console.log("\x1b[32mCommands\x1b[0m");
    console.log("\t\t\t\x1b[1maloo create-app <name>\x1b[0m\t\t\t\t\tCreates C Aloo app template\n");
    console.log("\t\t\t\x1b[1maloo run\x1b[0m\t\t\t\t\t\t\t\tRuns Aloo app\n");
    console.log("\t\t\t\x1b[1maloo test\x1b[0m\t\t\t\t\t\t\t\tRuns Aloo app tests\n");
}
if (argv.length > 2) {
    var command = argv[2];
    switch (command) {
        case "create-app":
            createGtkApp(argv[3]);
            break;
        case "run":
            (0, child_process_1.exec)("".concat(argv[1].split("/aloo")[0], "/run.sh ").concat(process.cwd()), function (error, stdout, stderr) {
                if (error) {
                    console.log("error: ".concat(error.message));
                    return;
                }
                if (stderr) {
                    console.log("stderr: ".concat(stderr));
                    return;
                }
                console.log("success: ".concat(stdout));
            });
            break;
        case "test":
            (0, child_process_1.exec)("".concat(argv[1].split("/aloo")[0], "/run-test.sh ").concat(process.cwd()), function (error, stdout, stderr) {
                if (error) {
                    console.log("error: ".concat(error.message));
                    return;
                }
                if (stderr) {
                    console.log("stderr: ".concat(stderr));
                    return;
                }
                console.log("success: ".concat(stdout));
            });
            break;
        default:
            help();
            break;
    }
}
else {
    help();
}
