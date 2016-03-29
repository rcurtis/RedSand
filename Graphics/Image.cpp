#include "Image.h"

namespace Graphics
{	

	void Image::OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const
	{
		auto localState = states;
		localState = m_transform * states.transform;
		target.draw(m_sprite, localState);
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