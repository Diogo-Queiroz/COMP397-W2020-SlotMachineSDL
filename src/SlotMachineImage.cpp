#include "SlotMachineImage.h"

#include <utility>
#include "Game.h"

SlotMachineImage* SlotMachineImage::s_pInstance;

SlotMachineImage::SlotMachineImage(std::string imageStr, glm::vec2 position, int id)
{
	
	m_id = id;
	m_fruits = std::move(imageStr);
	m_position = position;
	TheTextureManager::Instance()->load("../Assets/textures/MachineItems.png",
		"spinImage-" + std::to_string(m_id), TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("spinImage-" + std::to_string(id));
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
}

SlotMachineImage::~SlotMachineImage()
= default;

void SlotMachineImage::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	
	/**
	 * This code to select images from a set of images were shared with me from Lucas
	 * and also the images that were used in this part. Every item in the slot machine
	 * is filled with images that were edited by Lucas, he has a better understanding
	 * and were essential to this part to work properly.
	 */
	TheTextureManager::Instance()->drawFrame(
		"spinImage-" + std::to_string(m_id), m_position.x - 30, m_position.y - 45,
		67, 91, 0, item,
		TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);
}

void SlotMachineImage::update()
{
}

void SlotMachineImage::clean()
{
}

void SlotMachineImage::setImage(std::string imageStr)
{
	TheTextureManager::Instance()->load("../Assets/textures/" + imageStr + ".png",
		"spinImage-" + std::to_string(m_id), TheGame::Instance()->getRenderer());
}

int SlotMachineImage::getItem()
{
	return item;
}

void SlotMachineImage::setItem(int itemIndex)
{
	item = itemIndex;
}
