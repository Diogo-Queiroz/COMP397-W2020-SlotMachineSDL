#pragma once
#ifndef __SLOT_MACHINE_IMAGE__
#define __SLOT_MACHINE_IMAGE__
#include "DisplayObject.h"
#include "GameItemType.h"
#include <sstream>

class SlotMachineImage : public DisplayObject
{
public:
    static SlotMachineImage* Instance()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new SlotMachineImage("Blank", glm::vec2(0,0), 0);
            return s_pInstance;
        }
        return s_pInstance;
    }
	
    SlotMachineImage(std::string imageStr, glm::vec2 position, int id);
    ~SlotMachineImage();


    void draw() override;
    void update() override;
    void clean() override;

    std::string m_fruits = "";
    glm::vec2 m_position;
    int m_id = 1;

    void setImage(std::string imageStr);
    int getItem();
    void setItem(int itemIndex);

    int item;
    GameItemType itemType;

protected:

    static SlotMachineImage* s_pInstance;
};

typedef SlotMachineImage TheSlotMachineImage;

#endif /* defined (__SLOT_MACHINE_IMAGE__) */