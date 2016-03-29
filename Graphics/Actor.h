#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

namespace Graphics
{

	class Actor : public sf::Transformable, public sf::Drawable
	{
	public:
		Actor();
		virtual ~Actor();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual void Update(float delta);
		void Load();
		void AddChild(std::shared_ptr<Actor> child);
		void RemoveChild(std::shared_ptr<Actor> child);
		virtual void LoadComplete(){}

		 
	protected:
		virtual void OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const {}
		virtual void OnUpdate(float delta){}
		virtual void OnLoad(){}

	private:
		std::vector<std::shared_ptr<Actor>> m_children;
	};

}