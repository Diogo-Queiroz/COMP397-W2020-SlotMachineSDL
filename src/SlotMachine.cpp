#include "SlotMachine.h"
#include "TextureManager.h"
#include "Game.h"
#include <vector>
#include <stdio.h>
#include <fenv.h>
#include <math.h>

SlotMachine* SlotMachine::s_pInstance;

SlotMachine::SlotMachine()
{
    TheTextureManager::Instance()->load("../Assets/textures/slot-machine.png",
        "slotMachine", TheGame::Instance()->getRenderer());

    glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slotMachine");
    setWidth(size.x);
    setHeight(size.y);

    setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
    setIsColliding(false);
    setType(GameObjectType::SLOT_MACHINE);
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
    int xComponent = getPosition().x;
    int yComponent = getPosition().y;

    TheTextureManager::Instance()->draw("slotMachine", xComponent, yComponent,
        TheGame::Instance()->getRenderer(), 0, 255, true);
}

void SlotMachine::update()
{
}

void SlotMachine::clean()
{
}

void SlotMachine::showPlayerStats()
{
	m_winRatio = m_winNumber / m_turn;
    std::cout << "Jackpot: " << m_jackpot << std::endl;
    std::cout << "Player Money: " << m_playerMoney << std::endl;
    std::cout << "Turn: " << m_turn << std::endl;
    std::cout << "Wins: " << m_winNumber << std::endl;
    std::cout << "Loses: " << m_lossNumber << std::endl;
    std::cout << "Win Ratio: " << m_winRatio * 100 << "%" << std::endl;
}

void SlotMachine::resetFruitTally()
{
    m_bars = 0;
    m_bells = 0;
	m_grapes = 0;
    m_sevens = 0;
    m_blanks = 0;
    m_bananas = 0;
    m_oranges = 0;
    m_cherries = 0;
}

void SlotMachine::resetAll()
{
    m_playerMoney = 1000;
    m_winnings = 0;
    m_jackpot = 5000;
    m_turn = 0;
    m_playerBet = 0;
    m_winNumber = 0;
    m_lossNumber = 0;
    m_winRatio = 0;
}

void SlotMachine::showWinMessage()
{
    m_playerMoney += m_winnings;
    std::cout << "You won: $" << m_winnings << std::endl;
    resetFruitTally();
    checkJackpot();
}

void SlotMachine::showLossMessage()
{
    m_playerMoney -= m_playerBet;
    std::cout << "You lost!!!" << std::endl;
	if (m_playerMoney <= 0)
	{
        TheGame::Instance()->changeSceneState(END_SCENE);
	}
    resetFruitTally();
}

bool SlotMachine::checkRange(int value, int lowerBounds, int upperBounds)
{
	if (value >= lowerBounds && value <= upperBounds)
	{
		return true;
	}
	return false;
}

std::vector<std::string> SlotMachine::reels()
{
	std::vector<std::string> betLine = { "", "", "" };
    std::vector<int> outCome = { 0, 0, 0 };

    for (auto spin = 0; spin < 3; spin++)
    {
    	outCome[spin] = floor( (static_cast<double>(rand()) / (RAND_MAX) * 65) + 1);
        /*switch (outCome[spin])
        {
            case checkRange(outCome[spin], 1, 27):
                betLine[spin] = "Blank";
                m_blanks++;
                break;
            case checkRange(outCome[spin], 28, 37): // 15.4% probability
                betLine[spin] = "Grapes";
                m_grapes++;
                break;
            case checkRange(outCome[spin], 38, 46): // 13.8% probability
                betLine[spin] = "Banana";
                m_bananas++;
                break;
            case checkRange(outCome[spin], 47, 54): // 12.3% probability
                betLine[spin] = "Orange";
                m_oranges++;
                break;
            case checkRange(outCome[spin], 55, 59): //  7.7% probability
                betLine[spin] = "Cherry";
                m_cherries++;
                break;
            case checkRange(outCome[spin], 60, 62): //  4.6% probability
                betLine[spin] = "Bar";
                m_bars++;
                break;
            case checkRange(outCome[spin], 63, 64): //  3.1% probability
                betLine[spin] = "Bell";
                m_bells++;
                break;
            case checkRange(outCome[spin], 65, 65): //  1.5% probability
                betLine[spin] = "Seven";
                m_sevens++;
                break;
        }*/
        std::cout << outCome[spin] << std::endl;
        if (checkRange(outCome[spin], 1, 27))
        {
            betLine[spin] = "Blank";
            m_blanks++;
        }
        else if (checkRange(outCome[spin], 28, 37)) // 15.4% probability 
        {
            betLine[spin] = "Grapes";
            m_grapes++;
        }
        else if (checkRange(outCome[spin], 38, 46)) // 13.8% probability
        {
            betLine[spin] = "Banana";
            m_bananas++;
        }
        else if (checkRange(outCome[spin], 47, 54)) // 12.3% probability
        {
            betLine[spin] = "Orange";
            m_oranges++;
        }
        else if (checkRange(outCome[spin], 55, 59)) //  7.7% probability
        {
            betLine[spin] = "Cherry";
            m_cherries++;

        }
        else if (checkRange(outCome[spin], 60, 62)) //  4.6% probability
        {
            betLine[spin] = "Bar";
            m_bars++;
        }
        else if (checkRange(outCome[spin], 63, 64)) //  3.1% probability
        {
            betLine[spin] = "Bell";
            m_bells++;
        }
        else if (checkRange(outCome[spin], 65, 65)) //  1.5% probability
        {
            betLine[spin] = "Seven";
            m_sevens++;
        }
        
    }

	for (int i = 0; i < betLine.size(); ++i)
	{
        std::cout << "Bet[" << i << "] : " << betLine[i] << " from outCome[" << i << "] : " << outCome[i] << std::endl;
	}
	
	return betLine;
}

void SlotMachine::determineWinnings()
{
	if (m_blanks == 0)
	{
		if (m_grapes == 3)
			m_winnings = m_playerBet * 10;
		else if (m_bananas == 3)
			m_winnings = m_playerBet * 20;
		else if (m_oranges == 3)
			m_winnings = m_playerBet * 30;
		else if (m_cherries == 3)
			m_winnings = m_playerBet * 40;
		else if (m_bars == 3)
			m_winnings = m_playerBet * 50;
		else if (m_bells == 3)
			m_winnings = m_playerBet * 75;
		else if (m_sevens == 3)
			m_winnings = m_playerBet * 100;
		else if (m_grapes == 2)
			m_winnings = m_playerBet * 2;
		else if (m_bananas == 2)
			m_winnings = m_playerBet * 2;
		else if (m_oranges == 2)
			m_winnings = m_playerBet * 3;
		else if (m_cherries == 2)
			m_winnings = m_playerBet * 4;
		else if (m_bars == 2)
			m_winnings = m_playerBet * 5;
		else if (m_bells == 2)
			m_winnings = m_playerBet * 10;
		else if (m_sevens == 2)
			m_winnings = m_playerBet * 20;
		else if (m_sevens == 1)
			m_winnings = m_playerBet * 5;
		else
			m_winnings = m_playerBet * 1;

		m_winNumber++;
		showWinMessage();
	}
    else
    {
	    m_lossNumber++;
	    showLossMessage();
    }
}

void SlotMachine::setPlayerBet(int m_bet_value, GameItemType m_type)
{
	switch (m_type)
	{
    case plus:
        m_playerBet += m_bet_value;
        break;
    case minus:
        m_playerBet -= m_bet_value;
		break;
    case negative:
        m_playerBet = 0;
        break;
	}
}

int SlotMachine::getPlayerBet()
{
    return m_playerBet;
}

void SlotMachine::checkJackpot()
{
    auto jackPotTry = floor((rand() * 51) + 1);
    auto jackPotWin = floor((rand() * 51) + 1);
	if (jackPotTry == jackPotWin)
	{
        std::cout << "You won the $" << m_jackpot << " Jackpot!!" << std::endl;
        m_playerMoney += m_jackpot;
        m_jackpot = 1000;
	}
}
