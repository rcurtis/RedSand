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
		void Update(float delta);
		void Load();
		void AddChild(Actor* child);
		void RemoveChild(Actor* child);
		void RemoveAllChildren();
		void LoadComplete();
		void MousePressed(int buttonCode, int x, int y);
		void MouseReleased(int buttonCode, int x, int y);
		int GetWidth() const { return width; }
		int GetHeight() const { return height; }
		std::string tag;
		 
	protected:
		virtual void OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const {}
		virtual void OnUpdate(float delta){}
		virtual void OnLoad(){}
		virtual void OnLoadComplete(){}
		virtual bool OnMousePressed(int buttonCode, int x, int y) { return false; }
		virtual bool OnMouseReleased(int buttonCode, int x, int y) { return false; }

		int width = 0, height = 0;

	private:
		std::vector<Actor*> m_children;
		mutable sf::Transform m_lastTransform;
	};

}