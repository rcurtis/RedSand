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
		void MousePressed(int buttonCode, int x, int y);
		void MouseReleased(int buttonCode, int x, int y);
		int GetWidth() const { return width; }
		int GetHeight() const { return height; }
		 
	protected:
		virtual void OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const {}
		virtual void OnUpdate(float delta){}
		virtual void OnLoad(){}
		virtual bool OnMousePressed(int buttonCode, int x, int y) { return false; }
		virtual bool OnMouseReleased(int buttonCode, int x, int y) { return false; }

		int width = 0, height = 0;

	private:
		std::vector<std::shared_ptr<Actor>> m_children;
		mutable sf::Transform m_lastTransform;
	};

}