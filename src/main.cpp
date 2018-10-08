#include "App.h"

int main(int argc, char ** argv)
{
	App::Strings arg;
	for (int i=1; i<argc; i++) arg.push_back(argv[i]);
	App app(arg);
	return app.Run();
}
