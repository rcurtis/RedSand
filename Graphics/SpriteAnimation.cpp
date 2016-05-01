#include "SpriteAnimation.h"

namespace S2D
{

	SpriteAnimation::SpriteAnimation()
	{

	}

	SpriteAnimation::~SpriteAnimation()
	{
	}

	void SpriteAnimation::Play()
	{
		if (isPlaying)
			return;
		isPlaying = true;
	}

	void SpriteAnimation::Stop()
	{
		if (!isPlaying)
			return;
		isPlaying = false;
	}

	void SpriteAnimation::Reset()
	{
	}

	void SpriteAnimation::OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const
	{
		auto src = atlas->atlas()->frames[currentFrameIndex]->spriteSourceSize;
		auto trans = states.transform;
		trans.translate(float(src.x), float(src.y));
		target.draw(sprite, trans);
	}

	void SpriteAnimation::FlipFrame()
	{
		currentFrameIndex++;
		if (currentFrameIndex >= (int)atlas->atlas()->frames.size())
			currentFrameIndex = 0;

		auto frame = atlas->atlas()->frames[currentFrameIndex]->frame;
		auto src = atlas->atlas()->frames[currentFrameIndex]->spriteSourceSize;
		sprite.setTextureRect({ frame.x, frame.y, frame.w, frame.h });
	}

	void SpriteAnimation::OnUpdate(float delta)
	{
		if (!isPlaying)
			return;

		timeOnFrame += delta;
		if (timeOnFrame > timePerFrame)
		{
			FlipFrame();
			timeOnFrame = 0.f;
		}			
	}

	void SpriteAnimation::OnLoad()
	{
	}

	void SpriteAnimation::OnLoadComplete()
	{
		sprite.setTexture(*texture);
		auto frame = atlas->atlas()->frames[0]->frame;
		sf::IntRect rect{ frame.x, frame.y, frame.w, frame.h };
		sprite.setTextureRect(rect);
	}

	bool SpriteAnimation::OnMousePressed(int buttonCode, int x, int y)
	{
		return false;
	}

	bool SpriteAnimation::OnMouseReleased(int buttonCode, int x, int y)
	{
		return false;
	}
}
