#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif // _GNU_SOURCE

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	struct passwd *passwdEnt = getpwuid(getuid());
	std::string home = passwdEnt->pw_dir;

	std::vector<std::string> args;
	args.push_back("/usr/bin/docker");
	args.push_back("run");
	args.push_back("--rm");
	args.push_back("-it");
	args.push_back("--network=host");
	args.push_back("--user");
	args.push_back(std::to_string(getuid()) + ":" + std::to_string(getgid()));
	args.push_back("-v");
	args.push_back("/opt/Synopsys:/opt/Synopsys");
	args.push_back("-v");
	args.push_back(home + ":" + home);
	args.push_back("-w");
	args.push_back(get_current_dir_name());
	args.push_back("synopsys");

	std::vector<std::string> allowedCommands = {"vcs", "verdi"};
	if (std::find(allowedCommands.begin(), allowedCommands.end(), argv[1]) == allowedCommands.end()) return 1;

	for (int i = 1; i < argc; i++) args.push_back(argv[i]);

	std::vector<const char *> argsExec;
	for (const std::string &arg : args) argsExec.push_back(arg.c_str());
	argsExec.push_back(NULL);

	setuid(0);
	setgid(0);
	execv(argsExec[0], (char *const *)argsExec.data());
}
