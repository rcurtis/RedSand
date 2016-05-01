#pragma once
#include "TexturePackerAtlas.h"
#include <SFML/Graphics/Texture.hpp>
#include "Actor.h"

namespace S2D
{

	class SpriteAnimation : public Graphics::Actor
	{
	public:
		SpriteAnimation();
		~SpriteAnimation();
		void SetAtlas(Graphics::TexturePackerAtlas* atlas) { this->atlas = atlas; }
		void SetTexture(sf::Texture* texture) { this->texture = texture; }

		void Play();
		void Stop();
		void Reset();

		void SetFramesPerSecond(int fps) { timePerFrame = 1.f / fps; }

	protected:
		void OnDraw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
		void FlipFrame();
		void OnUpdate(float delta) override;
		void OnLoad() override;
		void OnLoadComplete() override;
		bool OnMousePressed(int buttonCode, int x, int y) override;
		bool OnMouseReleased(int buttonCode, int x, int y) override;

	private:
		Graphics::TexturePackerAtlas* atlas = nullptr;
		sf::Texture* texture = nullptr;
		bool isPlaying = false;
		float timeOnFrame = 0.f;
		sf::Sprite sprite;
		float timePerFrame = 1.f / 60.f;
		int currentFrameIndex = 0;
	};

}
