#include "raylib.h"
#include "Engine.hpp"


// utility header for SearchAndSetResourceDir

int main (void)
{
	kai::Engine engines;
	engines.Init();
	engines.Run();
	engines.Shutdown();
}
