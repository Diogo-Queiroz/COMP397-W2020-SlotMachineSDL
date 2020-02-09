#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "SlotMachine.h"
#include "StartButton.h"
#include "SlotPlayButton.h"

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
	StartButton* m_pStartButton;
	SlotPlayButton* m_pSlotPlayButton;
};

#endif /* defined (__LEVEL_1_SCENE__) */
