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

		auto size = texture->getSize();
		this->width = size.x;
		this->height = size.y;
	}

	Image::~Image()
	{
		if(m_texture)
		{
			delete m_texture;
			m_texture = nullptr;
		}
	}

}