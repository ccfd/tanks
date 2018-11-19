#include "App.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(int argc, char ** argv)
{
	srand(time(NULL));
	App::Strings arg;
	for (int i=1; i<argc; i++) arg.push_back(argv[i]);
	if (arg.size() > 0) {
		if (arg[0] == "players") {
			std::vector<std::string> list = PlayerFactory::List();
			for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++) {
				std::cout << *it << "\n";
			}
			return 0;
		}
	} 
	App app(arg);
	return app.Run();
}
