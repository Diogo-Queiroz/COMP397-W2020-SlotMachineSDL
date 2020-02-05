#include "Plane.h"
#include "Game.h"

Plane::Plane():m_maxSpeed(10.0f)
{
	TheTextureManager::Instance()->load("../Assets/textures/plane.png",
		"plane", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("plane");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::PLANE);
	setVelocity(glm::vec2(0.0f, 0.0f));
	
}

Plane::~Plane()
{
}

void Plane::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("plane", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Plane::update()
{
	auto currentPosition = getPosition();

	setPosition(glm::vec2(currentPosition.x + getVelocity().x, currentPosition.y + getVelocity().y));
}

void Plane::clean()
{
}

void Plane::move(Move newMove)
{
	auto currentVelocity = getVelocity();
	
	switch(newMove)
	{
	case RIGHT:
		//setPosition(glm::vec2(currentPosition.x + 10.0f, currentPosition.y));
		setVelocity(glm::vec2(1.0f * m_maxSpeed, 0.0f));
		break;
	case LEFT:
		//setPosition(glm::vec2(currentPosition.x - 10.0f, currentPosition.y));
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, 0.0f));
		break;
	}
}
