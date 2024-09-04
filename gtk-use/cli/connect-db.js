"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.connectDbWithModel = connectDbWithModel;
var fs_1 = require("fs");
function connectDbWithModel(argv) {
    var _a;
    var args = argv.slice(3);
    var dbName;
    if (args.length == 0) {
        dbName = prompt("Select a database [sqlite3/mongo]: ", "sqlite3");
    }
    else {
        dbName = args[0];
    }
    if (dbName == null)
        return;
    var dbCreate = prompt("Create new sqlite3 db file [yes/no]: ", "yes");
    var dbPath;
    if (dbCreate == "yes") {
        dbPath = prompt("Enter path to create db: ", "db.sqlite");
        if (dbPath == null)
            return;
        (0, fs_1.writeFileSync)(dbPath, "");
    }
    else {
        dbPath = prompt("Enter path to db: ", "db.sqlite");
        if (dbPath == null)
            return;
    }
    var alooCli = argv[1];
    var modelName = "";
    var matchModel = null;
    if (args.length == 1 && args[0].match(/--model=\w+/)) {
        matchModel = args[0].match(/--model=\w+/);
        if (matchModel != null && typeof matchModel[0] == "string") {
            modelName = matchModel[0].split("--match=")[1];
        }
    }
    else {
        if (args.length >= 2)
            matchModel = args[1].match(/--model=\w+/);
        if (matchModel != null)
            modelName = matchModel[0].split("--match=")[1];
        else {
            var model = prompt("Enter model name: ");
            if (model == null)
                throw "Model name is requied";
            modelName = model;
        }
    }
    var alooJson = JSON.parse((0, fs_1.readFileSync)(process.cwd() + "/aloo.json").toString());
    if (!alooJson["models"] || alooJson["models"].length == 0) {
        throw "No models are present create new model with `aloo model`";
    }
    else if (!alooJson["models"].find(function (model) { return model["modelName"] == modelName; })) {
        throw "No model found with name " + modelName;
    }
    else {
        if (!(0, fs_1.existsSync)(process.cwd() + "/server")) {
            (0, fs_1.mkdirSync)(process.cwd() + "/server");
        }
        var serverSampleHeader = (0, fs_1.readFileSync)("".concat(alooCli.split("/bin/aloo")[0], "/cli/sample/main.server.h")).toString();
        while (serverSampleHeader.includes("$modelName"))
            serverSampleHeader = serverSampleHeader.replace("$modelName", modelName);
        (0, fs_1.writeFileSync)("".concat(process.cwd(), "/server/").concat(modelName, ".h"), serverSampleHeader);
        var serverSample = (0, fs_1.readFileSync)("".concat(alooCli.split("/bin/aloo")[0], "/cli/sample/main.server.c")).toString();
        while (serverSample.includes("$modelName"))
            serverSample = serverSample.replace("$modelName", modelName);
        var model = alooJson["models"].find(function (model) { return model["modelName"] == modelName; });
        if (model == undefined || model == null)
            return;
        serverSample = serverSample.replace("$cols", (_a = model.members) === null || _a === void 0 ? void 0 : _a.map(function (el) { return el.member; }).join(", "));
        serverSample = serverSample.replace("$body", sqlBody(model.members));
        var typeConvert_1 = {
            string: ["", ""],
            int: ["str_to_int(", ")"],
            float: ["strtod(", ")"],
            bool: ["str_to_int(", ")"],
        };
        (serverSample = serverSample.replace("val.$member = values[i++];", model.members
            .map(function (member) {
            return "val." +
                member.member +
                " = " +
                typeConvert_1[member.type][0] +
                "values[i++]" +
                typeConvert_1[member.type][1] +
                ";\n";
        })
            .join("\t"))),
            // console.log(serverSample);
            (0, fs_1.writeFileSync)("".concat(process.cwd(), "/server/").concat(modelName, ".c"), serverSample);
    }
}
function sqlBody(members) {
    var body = "ID INTEGER PRIMARY KEY AUTOINCREMENT";
    var types = {
        int: "INTEGER",
        string: "TEXT",
        float: "FLOAT",
        bool: "INTEGER",
    };
    members.forEach(function (member) {
        body += ", ".concat(member.member, " ").concat(types[member.type]);
    });
    return body;
}
