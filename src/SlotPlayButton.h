#pragma once
#ifndef __SLOT_PLAY_BUTTON__
#define __SLOT_PPLAY_BUTTON__

#include "Button.h"

class SlotPlayButton : public Button
{
public:
	SlotPlayButton();
	~SlotPlayButton();

	bool ButtonClick() override;

private:
	bool m_isClicked;
};

#endif /* define (__SLOT_PPLAY_BUTTON__) */