#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pSlotMachine->draw();
	m_pSlotPlayButton->draw();

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
}

void Level1Scene::update()
{
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
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSlotPlayButton->setMouseButtonClicked(false);
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
	//m_pPlane = new Plane(); // instantiates Plane
	//addChild(m_pPlane);

	//m_pIsland = new Island(); // instantiates Island
	//addChild(m_pIsland);

	// The Slot Machine
	m_pSlotMachine =		new SlotMachine();
	addChild(m_pSlotMachine);

	// SDL Colors
	const SDL_Color blue = { 0,0,255,255 };
	const int size = 15;
	
	//Labels
	m_pJackpotLabel =		new Label("Jackpot Label", "Dock51", size, blue,
								glm::vec2(120, 100.f));
	m_pMoneyLabel =			new Label("Money Player", "Dock51", size, blue,
								glm::vec2(400, 150.f));
	m_pTurnLabel =			new Label("Turn Label", "Dock51", size, blue,
								glm::vec2(600, 200.f));
	m_pWinLabel =			new Label("Win Label", "Dock51", size, blue,
								glm::vec2(150, 250.f));
	m_pLossLabel =			new Label("Loss Label", "Dock51", size, blue,
								glm::vec2(30, 300.f));
	m_pWinRatioLabel =		new Label("WIn Ratio Label", "Dock51", size, blue,
								glm::vec2(280, 350.f));
	m_pBetLabel =			new Label("Bet Label""Dock51", "Dock51", size, blue,
								glm::vec2(360, 400.f));

	// Buttons
	m_pSlotPlayButton =		new SlotPlayButton();
	m_pQuitButton = new QuitButton();
	m_pResetButton = new ResetButton();
	addChild(m_pSlotPlayButton);
	addChild(m_pQuitButton);
	addChild(m_pResetButton);

	m_pPlus_01_Button =		new BetButton(1, plus, "plus");
	m_pPlus_05_Button =		new BetButton(5, plus, "plus");
	m_pPlus_10_Button =		new BetButton(10, plus, "plus");
	m_pPlus_25_Button =		new BetButton(25, plus, "plus");
	m_pPlus_50_Button =		new BetButton(50, plus, "plus");
	m_pPlus_100_Button =	new BetButton(100, plus, "plus");

	m_pMinus_01_Button =	new BetButton(1, minus, "minus");
	m_pMinus_05_Button =	new BetButton(5, minus, "minus");
	m_pMinus_10_Button =	new BetButton(10, minus, "minus");
	m_pMinus_25_Button =	new BetButton(25, minus, "minus");
	m_pMinus_50_Button =	new BetButton(50, minus, "minus");
	m_pMinus_100_Button =	new BetButton(100, minus, "minus");	

	// Buttons Positions
	m_pPlus_01_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH,50));
	m_pPlus_05_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH + 50, 100));
	m_pPlus_10_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH + 100, 150));
	m_pPlus_25_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH + 150, 200));
	m_pPlus_50_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH + 250, 250));
	m_pPlus_100_Button->setPosition(glm::vec2(Config::SCREEN_WIDTH + 300, 300));
					   
	m_pMinus_01_Button->setPosition(glm::vec2(100, 50));
	m_pMinus_05_Button->setPosition(glm::vec2(100, 100));
	m_pMinus_10_Button->setPosition(glm::vec2(100, 150));
	m_pMinus_25_Button->setPosition(glm::vec2(100, 200));
	m_pMinus_50_Button->setPosition(glm::vec2(100, 250));
	m_pMinus_100_Button->setPosition(glm::vec2(100, 300));

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

