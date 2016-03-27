
#include "../Graphics/Stage.h"
#include "../Graphics/WindowDescription.h"
#include <Windows.h>


void main()
{
	Graphics::Stage stage;
	Graphics::WindowDescription main;
	main.name = "main";
	main.width = 800;
	main.height = 600;
	main.x = 0;
	main.y = 0;
	stage.AddWindow(main);

	Graphics::WindowDescription top;
	top.name = "top";
	top.width = 800;
	top.height = 600;
	top.x = 800 + 20;
	top.y = 0;
	stage.AddWindow(top);

	stage.Run();

	while (true)
		Sleep(1);

}
