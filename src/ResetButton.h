#pragma once
#ifndef __ResetButton__
#define __ResetButton__

#include "Button.h"

class ResetButton : public Button
{
public:
	ResetButton();
	~ResetButton();
	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* define (__BetButton__) */