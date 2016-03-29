#include "DummyGame.h"
#include "../Graphics/WindowDescription.h"

namespace Games
{
	DummyGame::DummyGame()
	{
		Graphics::WindowDescription main;
		main.name = "main";
		main.tag = "main";
		main.width = 800;
		main.height = 600;
		main.x = 0;
		main.y = 0;
		this->AddWindow(main);

		Graphics::WindowDescription top;
		top.name = "top";
		top.tag = "top";
		top.width = 800;
		top.height = 600;
		top.x = 800 + 20;
		top.y = 0;
		this->AddWindow(top);

		m_topRoot = std::make_shared<TopScreen>();
		m_mainRoot = std::make_shared<Graphics::Actor>();
	}

	void DummyGame::Load()
	{
		m_topRoot->Load();
		m_mainRoot->Load();
	}

	void DummyGame::LoadComplete()
	{
		m_topRoot->LoadComplete();
		m_mainRoot->LoadComplete();
	}

	void DummyGame::Update(float delta, std::string tag)
	{
		if (tag == "top")
			m_topRoot->Update(delta);
		else if (tag == "main")
			m_mainRoot->Update(delta);
	}

	void DummyGame::Draw(std::string tag, sf::RenderWindow* window)
	{
		sf::RenderStates states;
		if (tag == "top")
		{			
			m_topRoot->draw(*window, states);
		}
		else if (tag == "main")
			m_mainRoot->draw(*window, states);
	}

	DummyGame::~DummyGame()
	{
	}

}