#pragma once
#ifndef __BetButton__
#define __BetButton__

#include "Button.h"
#include "GameItemType.h"

class BetButton : public Button
{
public:
	BetButton(int value, GameItemType type, const std::string& stringType);
	~BetButton();
	bool ButtonClick() override;

private:
	GameItemType m_type;
	int m_betValue;
	bool m_isClicked;
};

#endif /* define (__BetButton__) */