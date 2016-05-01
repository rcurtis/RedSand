#include "Button.h"
#include "AssetManager.h"
#include "Image.h"

namespace S2D
{
	Button::Button(const std::string& defaultt, const std::string& pressed, const std::string& inactive)
		: defaultImage(defaultt), pressedImage(pressed), inactiveImage(inactive)
	{
	}

	Button::~Button()
	{
	}

	void Button::OnUpdate(float delta)
	{
		if(state == ButtonState::Pressed)
		{
			timeDepressed += delta;
			if(timeDepressed > maxTimeDepressed)
			{
				state = ButtonState::Default;
				depressed = false;
				RemoveAllChildren();
				AddChild(defaultt);
			}
		}
	}

	void Button::OnLoad()
	{
		auto& manager = Graphics::AssetManager::instance();
		manager.Load(defaultImage, "default");
		manager.Load(pressedImage, "pressed");
		manager.Load(inactiveImage, "inactive");
	}

	void Button::OnLoadComplete()
	{
		auto& manager = Graphics::AssetManager::instance();
		defaultt = std::make_shared<Graphics::Image>(manager.GetAsset<sf::Texture>("default"));
		pressed = std::make_shared<Graphics::Image>(manager.GetAsset<sf::Texture>("pressed"));
		inactive = std::make_shared<Graphics::Image>(manager.GetAsset<sf::Texture>("inactive"));

		width = defaultt->GetWidth();
		height = defaultt->GetHeight();

		AddChild(defaultt);
	}

	bool Button::OnMousePressed(int buttonCode, int x, int y)
	{
		if(state != ButtonState::Default)
			return false;

		timeDepressed = 0;
		state = ButtonState::Pressed;
		RemoveAllChildren();
		AddChild(pressed);
		buttonClickListener(tag);
		return true;
	}

	bool Button::OnMouseReleased(int buttonCode, int x, int y)
	{
		return false;
	}
}
