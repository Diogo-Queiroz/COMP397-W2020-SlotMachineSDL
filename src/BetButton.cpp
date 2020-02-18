#include "BetButton.h"
#include "SoundManager.h"
#include "SlotMachine.h"

BetButton::BetButton(int value, GameItemType type, const std::string& stringType)
	:Button("../Assets/textures/slot-" + stringType + "-" + std::to_string(value) + ".png",
		"btnBetValue" + stringType + std::to_string(value),
		BET_BUTTON, glm::vec2(400.0f, 500.0f)), m_isClicked(false)
{
	m_betValue = value;
	m_type = type;
	std::cout << "../Assets/texture/slot-" + stringType + "-" + std::to_string(value) + ".png" << std::endl;
	// slot-minus-1
}

BetButton::~BetButton()
= default;

bool BetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("buttonPressed", 0);
			TheSlotMachine::Instance()->setPlayerBet(m_betValue, m_type);
			if (TheSlotMachine::Instance()->getPlayerBet() <= 0)
			{
				TheSlotMachine::Instance()->setPlayerBet(0, negative);
			}
			else if (TheSlotMachine::Instance()->getPlayerBet() > TheSlotMachine::Instance()->m_playerMoney)
			{
				TheSlotMachine::Instance()->setPlayerBet(0, negative);
			}
			/*
			 * GameManager::Instance()->playerBet += m_betValue;
			 * if (GameManager::Instance()->playerBet < 0) {
			 *	GameManager::Instance()->playerBet = 0;
			 * }
			 */
			
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
