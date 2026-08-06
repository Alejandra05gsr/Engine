#include "raylib.h"
#include "Engine.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


// utility header for SearchAndSetResourceDir

int main ()
{
	kai::Engine engines;
	engines.Init();
	engines.Run();
	engines.Shutdown();
	return 0;
}
