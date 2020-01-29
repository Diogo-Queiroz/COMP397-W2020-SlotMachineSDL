#include "StartButton.h"
#include "Game.h"

StartButton::StartButton()
	// call super constructor
	:Button(
		"../Assets/textures/StartButton.png",
		"startButton",
		START_BUTTON, glm::vec2(400.0f, 300.0f))
{
	
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		std::cout << "Mouse Button Clicked!" << std::endl;
		return true;
	}

	return false;
}


