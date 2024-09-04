"use strict";
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.createModel = createModel;
var fs_1 = require("fs");
function createModel(argv) {
    if (!argv.length)
        throw "No name is provided";
    var match = argv[0].match(/([a-z]|[A-Z])+/);
    if (match == null)
        throw "Name must be only alphabets";
    if (match[0] != argv[0])
        throw "Invalid name " + argv[0];
    if (argv.length == 1)
        throw "No properties are provided";
    var modelTypes = ["string", "int", "float", "bool"];
    var modelName = argv[0];
    var modelProps = argv
        .slice(1)
        .reduce(function (acc, arg) {
        if (!arg.includes(":"))
            throw "Invalid property " + arg;
        var _a = arg.split(":"), key = _a[0], type = _a[1];
        for (var _i = 0, key_1 = key; _i < key_1.length; _i++) {
            var element = key_1[_i];
            if (!((element.charCodeAt(0) >= 65 &&
                element.charCodeAt(0) <= 90) ||
                (element.charCodeAt(0) >= 97 &&
                    element.charCodeAt(0) <= 122))) {
                throw "Invalid token " + element + " in " + key;
            }
        }
        for (var _b = 0, type_1 = type; _b < type_1.length; _b++) {
            var element = type_1[_b];
            if (!((element.charCodeAt(0) >= 65 &&
                element.charCodeAt(0) <= 90) ||
                (element.charCodeAt(0) >= 97 &&
                    element.charCodeAt(0) <= 122))) {
                throw "Invalid token '".concat(element, "' in ").concat(type);
            }
        }
        if (!modelTypes.includes(type))
            throw "Invalid type '".concat(type, "'");
        // ... validation code ...
        return __spreadArray(__spreadArray([], acc, true), [{ key: key, type: type }], false);
    }, []);
    var typeSwitch = {
        string: "char *",
        bool: "_Bool",
        int: "int",
        float: "float",
    };
    var content = "#include \"aloo.h\"\n#include <stdbool.h>\n\ntypedef struct _".concat(modelName, " {\n\tint id;\n\t").concat(modelProps
        .map(function (props) { return "".concat(typeSwitch[props.type], " ").concat(props.key, ";"); })
        .join("\n\t"), "\n} ").concat(modelName, ";\n");
    if (!(0, fs_1.existsSync)(process.cwd() + "/models"))
        (0, fs_1.mkdirSync)(process.cwd() + "/models");
    if (!(0, fs_1.existsSync)(process.cwd() + "/models/" + argv[0] + ".h")) {
        (0, fs_1.writeFileSync)(process.cwd() + "/models/" + argv[0] + ".h", content);
        var alooJson = (0, fs_1.readFileSync)("".concat(process.cwd(), "/aloo.json")).toString();
        var aloo = JSON.parse(alooJson);
        if (aloo["models"])
            aloo["models"] = __spreadArray(__spreadArray([], aloo["models"], true), [
                {
                    modelName: modelName,
                    members: modelProps.map(function (_a) {
                        var key = _a.key, type = _a.type;
                        return {
                            member: key,
                            type: type,
                        };
                    }),
                },
            ], false);
        else
            aloo["models"] = [
                {
                    modelName: modelName,
                    members: modelProps.map(function (_a) {
                        var key = _a.key, type = _a.type;
                        return {
                            member: key,
                            type: type,
                        };
                    }),
                },
            ];
        alooJson = JSON.stringify(aloo);
        (0, fs_1.writeFileSync)("".concat(process.cwd(), "/aloo.json"), alooJson);
    }
    else {
        throw "Model '" + modelName + "' already exists";
    }
}
