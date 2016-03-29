
#include <Windows.h>
#include <memory>

#include "../Graphics/Stage.h"
#include "../Games/DummyGame.h"
#include "../Utils/Log.h"

void main()
{
	Utils::Log::Init("C:/Logs/graphicsTest");
	auto game = std::make_shared<Games::DummyGame>();

	game->Run();

	while (true)
		Sleep(1);

}
