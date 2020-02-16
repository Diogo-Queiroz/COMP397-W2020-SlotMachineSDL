#include "QuitButton.h"
#include "Config.h"
#include "Game.h"

QuitButton::QuitButton()
	: Button("../Assets/textures/quit-button.png", "quitButton",
		QUIT_BUTTON, glm::vec2(Config::SCREEN_HEIGHT * 0.6f, Config::SCREEN_HEIGHT * 0.7f)),
	m_isClicked(false)
{
}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->quit();
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
