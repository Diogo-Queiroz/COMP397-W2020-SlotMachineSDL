#pragma once
#ifndef __QuitButton__
#define __QuitButton__

#include "Button.h"

class QuitButton : public Button
{
public:
	QuitButton();
	~QuitButton();
	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* define (__BetButton__) */