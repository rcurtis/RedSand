#include "Actor.h"
#include "../Utils/Log.h"

namespace Graphics
{
	void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		m_lastTransform = states.transform * getTransform();
		OnDraw(target, m_lastTransform);

		for (auto& child : m_children)
		{
			child->draw(target, m_lastTransform);
		}
	}

	Actor::Actor()
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::Update(float delta)
	{
		OnUpdate(delta);
		for (auto& child : m_children)
		{
			child->Update(delta);
		}
	}

	void Actor::AddChild(Actor* child)
	{
		if (std::find(m_children.begin(), m_children.end(), child) == m_children.end())
		{
			m_children.push_back(child);
		}
	}

	void Actor::RemoveChild(Actor* child)
	{
		auto found = std::find(m_children.begin(), m_children.end(), child);
		if (found != m_children.end())
		{
			m_children.erase(found);
		}
	}

	void Actor::RemoveAllChildren()
	{
		m_children.clear();
	}

	void Actor::LoadComplete()
	{
		OnLoadComplete();
		for (auto& child : m_children)
		{
			child->LoadComplete();
		}
	}

	void Actor::MousePressed(int buttonCode, int x, int y)
	{
		auto global = m_lastTransform.transformPoint(0, 0);
		sf::Rect<int> rect{ int(global.x), int(global.y), int(global.x) + width, int(global.y) + height };
		if(rect.contains(x, y))
		{
			OnMousePressed(buttonCode, x, y);
		}

		for(auto& child : m_children)
		{
			child->MousePressed(buttonCode, x, y);
		}
	}

	void Actor::MouseReleased(int buttonCode, int x, int y)
	{
		auto global = m_lastTransform.transformPoint(0, 0);
		sf::Rect<int> rect{ int(global.x), int(global.y), int(global.x) + width, int(global.y) + height };
		if (rect.contains(x, y))
		{
			OnMouseReleased(buttonCode, x, y);
		}

		for (auto& child : m_children)
		{
			child->MouseReleased(buttonCode, x, y);
		}
	}

	void Actor::Load()
	{
		OnLoad();
		for (auto& child : m_children)
		{
			child->Load();
		}
	}
}
