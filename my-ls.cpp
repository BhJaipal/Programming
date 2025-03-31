#include <boost/filesystem.hpp>
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
	{"c", "\033[1;35m\033[0m"},
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
	{"package-lock.json", "\033[1;31m\033[0m "},
	{".nuxt", "\033[1;32m\033[0m"},
	{"Dockerfile", "\033[1;36m\033[0m"},
	{"Doxyfile", "\033[1;34m\033[0m"},
};
std::map<std::string, std::string> defaultFile{
	{"folder", "\033[1;36m🖿\033[0m"},
	{"file", "\033[1;37m🗅\033[0m"},
};

std::map<int, std::string> permsMap{
	{0, "---"}, {1, "--x"}, {2, "-w-"}, {3, "-wx"},
	{4, "r--"}, {5, "r-x"}, {6, "rw-"}, {7, "rwx"},
};
namespace fs = std::filesystem;

class FileSize {
	uintmax_t size;
	std::string unit;

public:
	FileSize(uintmax_t s) : size(s) {
		if (size < 1024) {
			unit = "B";
		} else if (size < 1024 * 1024) {
			unit = "KB";
			size /= 1024;
		} else if (size < 1024 * 1024 * 1024) {
			unit = "MB";
			size /= 1024 * 1024;
		} else {
			unit = "GB";
			size /= 1024 * 1024 * 1024;
		}
	}
	std::string toString() const { return std::to_string(size) + " " + unit; }
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
	fs::path cwd = fs::current_path();
	int is_all = 0;
	int is_full = 0;
	for (int i = 0; i < argc; i++) {
		std::string all = argv[i];
		if (all == "-a" || all == "--all") { is_all = 1; }
		if (all == "-l") { is_full = 1; }
	}

	if (is_full) {
		std::cout << "\033[1;34mRoot\t  Group\tUser\t  Dir \tSize  \t";
	} else std::cout << "   ";
	std::cout << "\033[1;34mName\033[0m\n";
	for (auto &p : fs::directory_iterator(cwd)) {
		std::vector<std::string> fileName = split(p.path().string(), "/");
		if (!is_all && fileName[fileName.size() - 1][0] == '.') continue;
		std::string icon =
			noExt[fileName[fileName.size() - 1]].size() > 0
				? noExt[fileName[fileName.size() - 1]]
				: (p.path().extension().string().size() > 0
					   ? (fileIcons[p.path().extension().string().substr(1)]
									  .size() > 0
							  ? fileIcons[p.path().extension().string().substr(
									1)]
							  : defaultFile["file"]) +
							 " "
					   : (p.is_directory() ? defaultFile["folder"]
										   : defaultFile["file"] + " "));
		fs::perms permissions = fs::status(p.path()).permissions();
		int permInt = int(permissions);
		int perm;
		int permArr[3];
		// for (int i = 0; i < 3; i++) {
		// 	perm = permInt % 8;
		// 	permArr[i] = perm;
		// 	permInt /= 8;
		// }
		// int root = permArr[2];
		// int group = permArr[1];
		// int others = permArr[0];

		int others = (permInt % 8);
		int group = (permInt % 0100) / 8;
		int root = (permInt / 0100) % 8;
		if (is_full) {
			std::cout << permsMap[root] << "\t   " << permsMap[group] << " \t"
					  << permsMap[others] << " \t  "
					  << (p.is_directory() ? "\033[1;32m ✔ " : "\033[1;31m ✘ ")
					  << " \033[0m\t";
			fs::path path = p.path();
			uintmax_t size;
			if (p.is_directory()) {
				namespace bf = boost::filesystem;
				size = 0;
				for (fs::directory_entry const &entry :
					 fs::directory_iterator(path))
					if (entry.is_regular_file()) size += entry.file_size();
			} else size = fs::file_size(path);
			std::cout << FileSize(size).toString() << " \t";
		}
		int isExecuable =
			others == 1 || others == 3 || others == 5 || others == 7;
		if (!p.is_directory() && isExecuable) std::cout << "\033[1;32m";
		if ((icon == defaultFile["file"] + " ") && isExecuable) {
			std::cout << "\033[1;32m\033[0m ";
		} else std::cout << icon << " ";
		if (p.is_directory()) std::cout << "\033[1;36m ";
		else if (isExecuable) std::cout << "\033[1;32m";
		std::cout << fileName[fileName.size() - 1] << "\033[0m\n";
	}
	return 0;
}
