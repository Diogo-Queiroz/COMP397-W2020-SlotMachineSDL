#include "SlotPlayButton.h"
#include "SlotMachine.h"
#include "Game.h"

SlotPlayButton::SlotPlayButton() : Button(
	"../Assets/textures/slot-spin-btn.png",
	"slotPlayButton",
	SLOT_MACHINE_PLAY, glm::vec2(100.0f, 100.0f)), m_isClicked(false) 
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
		{
			SlotMachine().reels();
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
