#include <filesystem>
#include <iostream>
#include <map>
#include <vector>

std::map<std::string, std::string> fileIcons{
	{"xml", "\033[1;31m\033[0m"},
	{"html", "\033[1;31m\033[0m"},
	{"wasm", "\033[1;34m\033[0m"},
	{"js", "\033[33m\033[0m"},
	{"py", "\033[33m\033[0m"},
	{"ipynb", ""},
	{"cpp", "\033[1;36m\033[0m"},
	{"c", "\033[1;34m\033[0m"},
	{"h", "\033[1;34m\033[0m"},
	{"d", "\033[1;34m\033[0m"},
	{"cs", ""},
	{"html", ""},
	{"css", ""},
	{"md", ""},
	{"txt", ""},
	{"java", "\033[1;31m\033[0m"},
	{"jar", "\033[1;36m\033[0m"},
	{"class", "\033[1;31m\033[0m"},
	{"go", "\033[1;36m\033[0m"},
	{"sh", ""},
	{"ps1", ""},
	{"png", ""},
	{"jpg", ""},
	{"jpeg", ""},
	{"gif", ""},
	{"rb", "\033[1;31m\033[0m"},
	{"svg", ""},
	{"zip", ""},
	{"gz", ""},
	{"tar", ""},
	{"xz", ""},
	{"iso", ""},
	{"pdf", ""},
	{"doc", ""},
	{"docx", ""},
	{"ppt", ""},
	{"pptx", ""},
	{"odt", ""},
	{"ods", ""},
	{"odp", ""},
	{"7z", ""},
	{"exe", ""},
	{"deb", "\033[1;31m\033[0m"},
	{"msi", "\033[1;36m\033[0m"},
	{"apk", "\033[1;32m\033[0m"},
	{"rpm", "\033[1;31m\033[0m"},
	{"fs", ""},
	{"wav", ""},
	{"mp3", ""},
	{"mp4", ""},
	{"avi", ""},
	{"mov", ""},
	{"mkv", ""},
	{"swift", ""},
	{"vue", "\033[32m\033[0m"},
	{"gql", ""},
	{"graphql", ""},
	{"svelte", "\033[31m\033[0m"},
	{"ts", "\033[34m\033[0m"},
	{"ts", "\033[36m\033[0m"},
	{"tsx", ""},
	{"json", ""},
	{"db", "\ue706"},
	{"sqlite", ""},
	{"lock", ""},
	{"rs", ""},
	{"zig", ""},
	{"s", ""},
	{"scala", "\ue68e"},
	{"less", "\ue758"},
	{"css", ""},
	{"hs", "\033[1;34m\033[0m"},
	{"nim", ""},
	{"php", ""},
	{"jl", ""},
	{"cbl", ""},
	{"ttf", ""},
	{"ex", ""},
	{"v", ""},
	{"spec.ts", "\033[1;31m󰏪\033[0m"},
	{"spec.js", "\033[1;31m󰏪\033[0m"},
	{"spec.rb", "\033[1;31m󰏪\033[0m"},
	{"spec.c", "\033[1;31m󰏪\033[0m"},
	{"spec.cpp", "\033[1;31m󰏪\033[0m"},
	{"elm", ""},
	{"kt", ""},
	{"vim", "\033[1;32m\033[0m"},
	{"r", "\033[1;36m\033[0m"},
	{"dart", "\033[1;36m\033[0m"},
};
std::map<std::string, std::string> noExt{
	{"gradle", "\033[1;36m[0m"},
	{"gradle.bat", "\033[1;36m[0m"},
	{"angular.json", "\033[31m\033[0m"},
	{"firebase.json", "\033[33m\033[0m"},
	{"tsconfig.json", "\033[34m\033[0m"},
	{"webpack.config.js", "\033[34m\033[0m"},
	{"webpack.config.ts", "\033[34m\033[0m"},
	{"babel.config.js", "\033[34m\033[0m"},
	{"babel.config.ts", "\033[34m\033[0m"},
	{"electron", "\033[34m\033[0m"},
	{".git", "\033[1;31m\033[0m"},
	{".gitignore", "\033[1;31m\033[0m"},
	{".github", ""},
	{".gitlab", "\033[1;31m\033[0m"},
	{"test", "\033[1;31m󰏪\033[0m"},
	{".vscode", "\033[1;36m\033[0m"},
	{"jquery.js", "\033[1;36m\033[0m"},
	{"jquery-ui.js", "\033[1;33m\033[0m"},
	{"jquery.ts", "\033[1;36m\033[0m"},
	{"jquery-ui.ts", "\033[1;33m\033[0m"},
	{"jquery.d.ts", "\033[1;36m\033[0m"},
	{"jquery-ui.d.ts", "\033[1;33m\033[0m"},
	{"package.json", "\033[1;32m\033[0m"},
	{"package-lock.json", "\033[1;31m\033[0m"},
	{".nuxt", "\033[1;32m\033[0m"},
	{"Dockerfile", "\033[1;36m\033[0m"},
	{"Doxyfile", "\033[1;34m\033[0m"},
};
std::map<std::string, std::string> defaultFile{
	{"folder", "\033[1;36m🖿\033[0m"},
	{"file", "\033[1;30;47m 🗅 \033[0m"},
};

bool ends_with(std::string const &fullString, std::string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(),
										ending.length(), ending));
	} else {
		return false;
	}
}

std::vector<std::string> split(const std::string &str,
							   const std::string &delimiter) {
	std::vector<std::string> tokens;
	std::size_t pos = 0;
	std::size_t found = str.find(delimiter);

	while (found != std::string::npos) {
		tokens.push_back(str.substr(pos, found - pos));
		pos = found + delimiter.length();
		found = str.find(delimiter, pos);
	}

	tokens.push_back(str.substr(pos));
	return tokens;
}

int main(int argc, char const *argv[]) {
	std::filesystem::path cwd = std::filesystem::current_path();
	int is_all = 0;
	for (int i = 0; i < argc; i++) {
		std::string all = argv[i];
		if (all == "-a" || all == "--all") {
			is_all = 1;
			break;
		}
	}

	for (auto &p : std::filesystem::directory_iterator(cwd)) {
		std::vector<std::string> fileName = split(p.path().string(), "/");
		if (!is_all && fileName[fileName.size() - 1][0] == '.') continue;
		std::string icon =
			noExt[fileName[fileName.size() - 1]].size() > 0
				? noExt[fileName[fileName.size() - 1]]
				: (p.path().extension().string().size() > 0
					   ? fileIcons[p.path().extension().string().substr(1)]
					   : (p.is_directory() ? defaultFile["folder"]
										   : defaultFile["file"]));
		std::cout << icon << "  " << fileName[fileName.size() - 1] << "\n";
	}
	return 0;
}
