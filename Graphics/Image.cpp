#include "Image.h"

namespace Graphics
{	

	void Image::OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const
	{
		target.draw(m_sprite, states);
	}

	Image::Image(): m_texture(nullptr)
	{
	}

	Image::Image(sf::Texture* texture)
	{
		m_texture = texture;
		m_sprite = sf::Sprite(*m_texture);
	}

	Image::~Image()
	{
	}

}