#include "App.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv)
{
	srand(time(NULL));
	App::Strings arg;
	for (int i=1; i<argc; i++) arg.push_back(argv[i]);
	App app(arg);
	return app.Run();
}
