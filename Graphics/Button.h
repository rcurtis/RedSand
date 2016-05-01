#pragma once
#include "Actor.h"
#include <functional>


namespace Graphics {
	class Image;
}

namespace S2D
{

	enum class ButtonState
	{
		Default,
		Pressed,
		Inactive
	};
	
	class Button : public Graphics::Actor
	{
	public:
		Button(const std::string& defaultImage, const std::string& pressedImage, const std::string& inactiveImage);
		~Button() override;

		ButtonState GetButtonState() const { return state; }
		void SetButtonState(ButtonState state) { this->state = state; }
		void SetClickListener(std::function<void(const std::string& tag)> listener) { buttonClickListener = listener; }

	protected:
		void OnUpdate(float delta) override;
		void OnLoad() override;
		void OnLoadComplete() override;
		bool OnMousePressed(int buttonCode, int x, int y) override;
		bool OnMouseReleased(int buttonCode, int x, int y) override;	

	private:
		ButtonState state = ButtonState::Default;
		const std::string defaultImage, pressedImage, inactiveImage;
		std::shared_ptr<Graphics::Image> defaultt;
		std::shared_ptr<Graphics::Image> pressed;
		std::shared_ptr<Graphics::Image> inactive;
		bool depressed = false;
		float timeDepressed = 0.f;
		float maxTimeDepressed = 0.1f;
		std::function<void(const std::string& tag)> buttonClickListener;
	};

}
