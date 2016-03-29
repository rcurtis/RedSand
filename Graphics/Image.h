#pragma once
#include "Actor.h"
#include "SFML/Graphics.hpp"

namespace Graphics
{

	class Image : public Actor
	{
	protected:
		void OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
	public:
		Image();
		explicit Image(sf::Texture* texture);
		~Image();

	private:
		sf::Texture* m_texture;
		sf::Sprite m_sprite;
	};

}
