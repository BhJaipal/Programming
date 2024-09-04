import { existsSync, mkdirSync, readFileSync, writeFileSync } from "fs";

export function connectDbWithModel(argv: string[]) {
	let args = argv.slice(3);
	let dbName: string | null;
	if (args.length == 0) {
		dbName = prompt("Select a database [sqlite3/mongo]: ", "sqlite3");
	} else {
		dbName = args[0];
	}
	if (dbName == null) return;

	let dbCreate = prompt("Create new sqlite3 db file [yes/no]: ", "yes");
	let dbPath: string | null;

	if (dbCreate == "yes") {
		dbPath = prompt("Enter path to create db: ", "db.sqlite");
		if (dbPath == null) return;
		writeFileSync(dbPath, "");
	} else {
		dbPath = prompt("Enter path to db: ", "db.sqlite");
		if (dbPath == null) return;
	}
	let alooCli = argv[1];

	let modelName: string = "";
	let matchModel: string[] | null = null;
	if (args.length == 1 && args[0].match(/--model=\w+/)) {
		matchModel = args[0].match(/--model=\w+/);
		if (matchModel != null && typeof matchModel[0] == "string") {
			modelName = matchModel[0].split("--match=")[1];
		}
	} else {
		if (args.length >= 2) matchModel = args[1].match(/--model=\w+/);
		if (matchModel != null) modelName = matchModel[0].split("--match=")[1];
		else {
			let model = prompt("Enter model name: ");
			if (model == null) throw "Model name is requied";
			modelName = model;
		}
	}
	let alooJson: {
		models: {
			modelName: string;
			members: { member: string; type: string }[];
		}[];
	} = JSON.parse(readFileSync(process.cwd() + "/aloo.json").toString());
	if (!alooJson["models"] || alooJson["models"].length == 0) {
		throw "No models are present create new model with `aloo model`";
	} else if (
		!alooJson["models"].find((model) => model["modelName"] == modelName)
	) {
		throw "No model found with name " + modelName;
	} else {
		if (!existsSync(process.cwd() + "/server")) {
			mkdirSync(process.cwd() + "/server");
		}
		let serverSampleHeader = readFileSync(
			`${alooCli.split("/aloo")[0]}/sample/main.server.h`
		).toString();
		while (serverSampleHeader.includes("$modelName"))
			serverSampleHeader = serverSampleHeader.replace(
				"$modelName",
				modelName
			);
		writeFileSync(
			`${process.cwd()}/server/${modelName}.h`,
			serverSampleHeader
		);

		let serverSample = readFileSync(
			`${alooCli.split("/aloo")[0]}/sample/main.server.c`
		).toString();
		while (serverSample.includes("$modelName"))
			serverSample = serverSample.replace("$modelName", modelName);

		let model = alooJson["models"].find(
			(model) => model["modelName"] == modelName
		);
		if (model == undefined || model == null) return;
		serverSample = serverSample.replace("$body", sqlBody(model.members));

		let typeConvert = {
			string: ["", ""],
			int: ["str_to_int(", ")"],
			float: ["strtod(", ")"],
			bool: ["str_to_int(", ")"],
		};
		serverSample = serverSample.replace(
			"val.$member = values[i++];",
			model.members
				.map(
					(member) =>
						"val." +
						member.member +
						" = " +
						typeConvert[member.type][0] +
						"values[i++]" +
						typeConvert[member.type][1] +
						";\n"
				)
				.join("\t")
		);
		serverSample = serverSample.replace(
			"$col_count",
			model.members.length.toString()
		);
		serverSample = serverSample.replace(
			"$cols$",
			model.members.map((el) => `"${el.member}"`).join(", ")
		);
		serverSample = serverSample.replace(
			"$cols",
			model.members?.map((el) => el.member).join(", ")
		);
		// console.log(serverSample);
		writeFileSync(`${process.cwd()}/server/${modelName}.c`, serverSample);
	}
}

function sqlBody(members: { member: string; type: string }[]) {
	let body = "ID INTEGER PRIMARY KEY AUTOINCREMENT";
	let types = {
		int: "INTEGER",
		string: "TEXT",
		float: "FLOAT",
		bool: "INTEGER",
	};
	members.forEach((member) => {
		body += `, ${member.member} ${types[member.type]}`;
	});
	return body;
}
