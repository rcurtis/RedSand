
#include <Windows.h>
#include <memory>

#include "../Graphics/Stage.h"
#include "../Graphics/WindowDescription.h"
#include "../Games/DummyGame.h"
#include "../Utils/Log.h"

void main()
{
	Utils::Log::Init("C:/Logs/graphicsTest");
	auto stage = std::make_shared<Games::DummyGame>();
	Graphics::WindowDescription main;
	main.name = "main";
	main.tag = "main";
	main.width = 800;
	main.height = 600;
	main.x = 0;
	main.y = 0;
	stage->AddWindow(main);

	Graphics::WindowDescription top;
	top.name = "top";
	top.tag = "top";
	top.width = 800;
	top.height = 600;
	top.x = 800 + 20;
	top.y = 0;
	stage->AddWindow(top);

	stage->Run();

	while (true)
		Sleep(1);

}
