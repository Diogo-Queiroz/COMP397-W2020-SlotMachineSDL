#include "Level1Scene.h"
#include "SlotMachine.h"
#include "Game.h"
#include <iostream>

float winRatio;

Level1Scene::Level1Scene()
{
	TheSoundManager::Instance()->load("../Assets/audio/casino-lounge.mp3",
		"lounge", sound_type::SOUND_SFX);
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	TheSoundManager::Instance()->playSound("lounge", 1);
	m_pSlotMachine->draw();
	m_pSlotPlayButton->draw();
	m_pResetButton->draw();
	m_pQuitButton->draw();

	//Labels
	m_pJackpotLabel->draw();
	m_pMoneyLabel->draw();
	m_pTurnLabel->draw();
	m_pWinLabel->draw();
	m_pLossLabel->draw();
	m_pWinRatioLabel->draw();
	m_pBetLabel->draw();

	// Buttons
	m_pPlus_01_Button->draw();
	m_pPlus_05_Button->draw();
	m_pPlus_10_Button->draw();
	m_pPlus_25_Button->draw();
	m_pPlus_50_Button->draw();
	m_pPlus_100_Button->draw();

	m_pMinus_01_Button->draw();
	m_pMinus_05_Button->draw();
	m_pMinus_10_Button->draw();
	m_pMinus_25_Button->draw();
	m_pMinus_50_Button->draw();
	m_pMinus_100_Button->draw();

	// Spin images
	m_pSpinImage1->draw();
	m_pSpinImage2->draw();
	m_pSpinImage3->draw();
}

void Level1Scene::updateLabels() const
{
	m_pMoneyLabel->setText("Player Money: " + std::to_string(TheSlotMachine::Instance()->getPlayerMoney()));
	m_pJackpotLabel->setText("JackPot: " + std::to_string(TheSlotMachine::Instance()->m_jackpot));
	m_pTurnLabel->setText("Turn: " + std::to_string(TheSlotMachine::Instance()->m_turn));
	m_pWinLabel->setText("Winnings: " + std::to_string(TheSlotMachine::Instance()->m_winNumber));
	m_pLossLabel->setText("Losses" + std::to_string(TheSlotMachine::Instance()->m_lossNumber));
	winRatio = TheSlotMachine::Instance()->m_winRatio;
	m_pWinRatioLabel->setText("WinRatio: " + std::to_string(winRatio) + "%");
	m_pBetLabel->setText("Bet: " +  std::to_string(TheSlotMachine::Instance()->m_playerBet));
	/*std::cout << "spin result ";
	for (int i = 0; i < TheSlotMachine::Instance()->m_spinResult.size(); i++)
	{
		std::cout << TheSlotMachine::Instance()->m_spinResult[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "m_pFruits = " << TheSlotMachine::Instance()->m_fruits << std::endl;
	std::vector<std::string> spinResults = TheSlotMachine::Instance()->m_spinResult;
	if (spinResults.empty())
	{
		std::cout << "Is Empty" << std::endl;
	}
	else
	{
		std::cout << "Not Empty" << std::endl;
		m_pSpinImage1->setImage(spinResults[0]);
		m_pSpinImage1->draw();
	}*/
	//m_pSpinImage2->setImage(TheSlotMachine::Instance()->m_spinResult[1]);
	//m_pSpinImage3->setImage(TheSlotMachine::Instance()->m_spinResult[2]);
}

void Level1Scene::update()
{
	m_pSpinImage1->setItem(TheSlotMachine::Instance()->m_spinResultIndex[0]);
	m_pSpinImage2->setItem(TheSlotMachine::Instance()->m_spinResultIndex[1]);
	m_pSpinImage3->setItem(TheSlotMachine::Instance()->m_spinResultIndex[2]);
	
	m_pSlotPlayButton->setMousePosition(m_mousePosition);
	m_pSlotPlayButton->ButtonClick();

	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();

	m_pPlus_01_Button->setMousePosition(m_mousePosition);
	m_pPlus_05_Button->setMousePosition(m_mousePosition);
	m_pPlus_10_Button->setMousePosition(m_mousePosition);
	m_pPlus_25_Button->setMousePosition(m_mousePosition);
	m_pPlus_50_Button->setMousePosition(m_mousePosition);
	m_pPlus_100_Button->setMousePosition(m_mousePosition);

	m_pMinus_01_Button->setMousePosition(m_mousePosition);
	m_pMinus_05_Button->setMousePosition(m_mousePosition);
	m_pMinus_10_Button->setMousePosition(m_mousePosition);
	m_pMinus_25_Button->setMousePosition(m_mousePosition);
	m_pMinus_50_Button->setMousePosition(m_mousePosition);
	m_pMinus_100_Button->setMousePosition(m_mousePosition);

	m_pPlus_01_Button->ButtonClick();
	m_pPlus_05_Button->ButtonClick();
	m_pPlus_10_Button->ButtonClick();
	m_pPlus_25_Button->ButtonClick();
	m_pPlus_50_Button->ButtonClick();
	m_pPlus_100_Button->ButtonClick();

	m_pMinus_01_Button->ButtonClick();
	m_pMinus_05_Button->ButtonClick();
	m_pMinus_10_Button->ButtonClick();
	m_pMinus_25_Button->ButtonClick();
	m_pMinus_50_Button->ButtonClick();
	m_pMinus_100_Button->ButtonClick();
	
	//std::cout << "Player Bet = " << TheSlotMachine::Instance()->m_playerBet << std::endl;
	//std::cout << "PLayer Money = " << TheSlotMachine::Instance()->m_playerMoney << std::endl;
	//std::cout << "Turn = " << TheSlotMachine::Instance()->m_turn << std::endl;
	//std::cout << "Winnings = " << TheSlotMachine::Instance()->m_winnings << std::endl;
	//std::cout << "WinNumber = " << TheSlotMachine::Instance()->m_winNumber << std::endl;
	//std::cout << "LossNumber = " << TheSlotMachine::Instance()->m_lossNumber << std::endl;
	//std::cout << "winRatio = " << TheSlotMachine::Instance()->m_winRatio << std::endl;
	
}

void Level1Scene::clean()
{
	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSlotPlayButton->setMouseButtonClicked(true);
				
				m_pPlus_01_Button->setMouseButtonClicked(true);
				m_pPlus_05_Button->setMouseButtonClicked(true);
				m_pPlus_10_Button->setMouseButtonClicked(true);
				m_pPlus_25_Button->setMouseButtonClicked(true);
				m_pPlus_50_Button->setMouseButtonClicked(true);
				m_pPlus_100_Button->setMouseButtonClicked(true);

				m_pMinus_01_Button->setMouseButtonClicked(true);
				m_pMinus_05_Button->setMouseButtonClicked(true);
				m_pMinus_10_Button->setMouseButtonClicked(true);
				m_pMinus_25_Button->setMouseButtonClicked(true);
				m_pMinus_50_Button->setMouseButtonClicked(true);
				m_pMinus_100_Button->setMouseButtonClicked(true);

				m_pResetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSlotPlayButton->setMouseButtonClicked(false);

				m_pPlus_01_Button->setMouseButtonClicked(false);
				m_pPlus_05_Button->setMouseButtonClicked(false);
				m_pPlus_10_Button->setMouseButtonClicked(false);
				m_pPlus_25_Button->setMouseButtonClicked(false);
				m_pPlus_50_Button->setMouseButtonClicked(false);
				m_pPlus_100_Button->setMouseButtonClicked(false);

				m_pMinus_01_Button->setMouseButtonClicked(false);
				m_pMinus_05_Button->setMouseButtonClicked(false);
				m_pMinus_10_Button->setMouseButtonClicked(false);
				m_pMinus_25_Button->setMouseButtonClicked(false);
				m_pMinus_50_Button->setMouseButtonClicked(false);
				m_pMinus_100_Button->setMouseButtonClicked(false);

				m_pResetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				
				Level1Scene::updateLabels(); // Method to update labels after release the mouse button to reduce memory leak
				
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				m_pPlane->move(LEFT);
				break;
			case SDLK_d:
				m_pPlane->move(RIGHT);
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				m_pPlane->setIsMoving(false);
				break;
			case SDLK_d:
				m_pPlane->setIsMoving(false);
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	TheSlotMachine::Instance()->resetAll();
	TheSlotMachine::Instance()->resetFruitTally();
	// The Slot Machine
	m_pSlotMachine =		new SlotMachine();
	addChild(m_pSlotMachine);

	// Slot Images
	m_pSpinImage1 = new SlotMachineImage("Blank", glm::vec2(416, 227), 1);
	m_pSpinImage2 = new SlotMachineImage("Blank", glm::vec2(493, 227), 2);
	m_pSpinImage3 = new SlotMachineImage("Blank", glm::vec2(570, 227), 3);
	m_pSpinImage1->setItem(0);
	m_pSpinImage2->setItem(0);
	m_pSpinImage3->setItem(0);
	//addChild(m_pSpinImage1);
	//addChild(m_pSpinImage2);
	//addChild(m_pSpinImage3);
	
	// SDL Colors
	const SDL_Color white = { 255,255,255,255 };
	const std::string fontType = "Kingthings Trypewriter 2";
	const int size = 18;
	
	//Labels
	m_pJackpotLabel =		new Label("Jackpot Label", fontType, size, white,
								glm::vec2(225, 10.0f));
	m_pMoneyLabel =			new Label("Money Player", fontType, size, white,
								glm::vec2(225, 150.0f));
	m_pTurnLabel =			new Label("Turn Label", fontType, size, white,
								glm::vec2(225, 200.0f));
	m_pWinLabel =			new Label("Win Label", fontType, size, white,
								glm::vec2(225, 250.0f));
	m_pLossLabel =			new Label("Loss Label", fontType, size, white,
								glm::vec2(225, 300.0f));
	m_pWinRatioLabel =		new Label("WIn Ratio Label", fontType, size, white,
								glm::vec2(225, 350.0f));
	m_pBetLabel =			new Label("Bet Label", fontType, size, white,
								glm::vec2(225, 400.0f));

	// Buttons
	m_pSlotPlayButton =		new SlotPlayButton();
	m_pQuitButton = new QuitButton();
	m_pResetButton = new ResetButton();
	addChild(m_pSlotPlayButton);
	addChild(m_pQuitButton);
	addChild(m_pResetButton);

	m_pMinus_01_Button =	new BetButton(1, minus, "minus");
	m_pMinus_05_Button =	new BetButton(5, minus, "minus");
	m_pMinus_10_Button =	new BetButton(10, minus, "minus");
	m_pMinus_25_Button =	new BetButton(25, minus, "minus");
	m_pMinus_50_Button =	new BetButton(50, minus, "minus");
	m_pMinus_100_Button =	new BetButton(100, minus, "minus");	

	m_pPlus_01_Button =		new BetButton(1, plus, "plus");
	m_pPlus_05_Button =		new BetButton(5, plus, "plus");
	m_pPlus_10_Button =		new BetButton(10, plus, "plus");
	m_pPlus_25_Button =		new BetButton(25, plus, "plus");
	m_pPlus_50_Button =		new BetButton(50, plus, "plus");
	m_pPlus_100_Button =	new BetButton(100, plus, "plus");


	// Buttons Positions
	m_pSlotPlayButton->setPosition(glm::vec2(Config::SCREEN_WIDTH - 40, Config::SCREEN_HEIGHT - 20));
	m_pResetButton->setPosition(glm::vec2(Config::SCREEN_WIDTH - 100, Config::SCREEN_HEIGHT - 20));
	m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH - 20, 20));
	
	m_pPlus_01_Button->setPosition(glm::vec2(25,25));
	m_pPlus_05_Button->setPosition(glm::vec2(25, 65));
	m_pPlus_10_Button->setPosition(glm::vec2(25, 105));
	m_pPlus_25_Button->setPosition(glm::vec2(25, 145));
	m_pPlus_50_Button->setPosition(glm::vec2(25, 185));
	m_pPlus_100_Button->setPosition(glm::vec2(25, 225));
					   
	m_pMinus_01_Button->setPosition(glm::vec2(65, 25));
	m_pMinus_05_Button->setPosition(glm::vec2(65, 65));
	m_pMinus_10_Button->setPosition(glm::vec2(65, 105));
	m_pMinus_25_Button->setPosition(glm::vec2(65, 145));
	m_pMinus_50_Button->setPosition(glm::vec2(65, 185));
	m_pMinus_100_Button->setPosition(glm::vec2(65, 225));

	// Adding Childs
	addChild(m_pPlus_01_Button);
	addChild(m_pPlus_05_Button);
	addChild(m_pPlus_10_Button);
	addChild(m_pPlus_25_Button);
	addChild(m_pPlus_50_Button);
	addChild(m_pPlus_100_Button);

	addChild(m_pMinus_01_Button);
	addChild(m_pMinus_05_Button);
	addChild(m_pMinus_10_Button);
	addChild(m_pMinus_25_Button);
	addChild(m_pMinus_50_Button);
	addChild(m_pMinus_100_Button);

	// Position labels and texts
	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

