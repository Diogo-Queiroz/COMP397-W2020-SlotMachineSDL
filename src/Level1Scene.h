#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "SlotMachine.h"
#include "StartButton.h"
#include "SlotPlayButton.h"
#include "Label.h"
#include "BetButton.h"
#include "QuitButton.h"
#include "ResetButton.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Plane* m_pPlane;
	Island* m_pIsland;
	SlotMachine* m_pSlotMachine;

	// private data member
	glm::vec2 m_mousePosition;

	// Label Members
	Label* m_pJackpotLabel;
	Label* m_pMoneyLabel;
	Label* m_pTurnLabel;
	Label* m_pWinLabel;
	Label* m_pLossLabel;
	Label* m_pWinRatioLabel;
	Label* m_pBetLabel;

	// Buttons
	SlotPlayButton* m_pSlotPlayButton;
	
	BetButton* m_pPlus_01_Button;
	BetButton* m_pPlus_05_Button;
	BetButton* m_pPlus_10_Button;
	BetButton* m_pPlus_25_Button;
	BetButton* m_pPlus_50_Button;
	BetButton* m_pPlus_100_Button;
	
	BetButton* m_pMinus_01_Button;
	BetButton* m_pMinus_05_Button;
	BetButton* m_pMinus_10_Button;
	BetButton* m_pMinus_25_Button;
	BetButton* m_pMinus_50_Button;
	BetButton* m_pMinus_100_Button;

	QuitButton* m_pQuitButton;
	ResetButton* m_pResetButton;
	//DialogButton* m_pDialogButton;

};

#endif /* defined (__LEVEL_1_SCENE__) */
