#include "ResetButton.h"
#include "Config.h"
#include "Game.h"

ResetButton::ResetButton()
	: Button("../Assets/textures/reset-button.png", "resetButton",
		RESET_BUTTON, glm::vec2(Config::SCREEN_HEIGHT * 0.6f, Config::SCREEN_HEIGHT * 0.7f)),
		m_isClicked(false)
{
}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("button", 0);
			TheSlotMachine::Instance()->resetAll();
			m_isClicked = false;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
	return false;
}
