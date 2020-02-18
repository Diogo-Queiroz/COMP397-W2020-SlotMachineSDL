#include "SlotPlayButton.h"
#include "SlotMachine.h"
#include "SlotMachineImage.h"
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
			TheSlotMachine::Instance()->m_spinResult = TheSlotMachine::Instance()->reels();
			TheSlotMachine::Instance()->m_fruits =
				TheSlotMachine::Instance()->m_spinResult[0] + " - " +
				TheSlotMachine::Instance()->m_spinResult[1] + " - " +
				TheSlotMachine::Instance()->m_spinResult[2];
			std::cout << "Result: " + TheSlotMachine::Instance()->m_fruits << std::endl;
			TheSlotMachine::Instance()->determineWinnings();
			TheSlotMachine::Instance()->m_turn++;
			TheSlotMachine::Instance()->showPlayerStats();
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
