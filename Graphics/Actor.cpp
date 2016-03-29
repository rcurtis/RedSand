#include "Actor.h"

namespace Graphics
{
	void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		auto combined = states.transform * getTransform();
		OnDraw(target, combined);

		for (auto& child : m_children)
		{
			child->draw(target, combined);
		}
	}

	Actor::Actor()
		: m_children(std::vector<std::shared_ptr<Actor>>())
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

	void Actor::AddChild(std::shared_ptr<Actor> child)
	{
		if (std::find(m_children.begin(), m_children.end(), child) == m_children.end())
		{
			m_children.push_back(child);
		}
	}

	void Actor::RemoveChild(std::shared_ptr<Actor> child)
	{
		auto found = std::find(m_children.begin(), m_children.end(), child);
		if (found != m_children.end())
		{
			m_children.erase(found);
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
