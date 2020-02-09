#include "SlotPlayButton.h"
#include "Game.h"

SlotPlayButton::SlotPlayButton() : Button(
	"../Assets/textures/StartButton.png",
	"slotPlayButton",
	SLOT_MACHINE_PLAY, glm::vec2(400.0f, 300.0f)), m_isClicked(false) 
{
}

SlotPlayButton::~SlotPlayButton()
{
}

bool SlotPlayButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{;
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
	return false;
}
