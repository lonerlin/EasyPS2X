#include "EasyPS2X.h"
#include<Vector.h>


void EasyPS2X::setPressedEvent(unsigned int button,void (*pressedEvent)())
{
    setEvent(button,pressedEvent,PRESSED);
}
void EasyPS2X::setReleasedEvent(unsigned int button,void (*releasedEvent)())
{
    setEvent(button,releasedEvent,RELEASED);
}
void EasyPS2X::setHeldEvent(unsigned int button,void (*heldEvent)())
{
    setEvent(button,heldEvent,HELD);
}
void EasyPS2X::update()
{
    read_gamepad(false, 0);
    for(int i=0;i<vPressedEvent.size();++i)
    {
        if(ButtonPressed(vPressedEvent[i].button))
        {
            vPressedEvent[i].evenFun();
        }
    }
    for(int i=0;i<vReleasedEvent.size();++i)
    {
        if(ButtonReleased(vReleasedEvent[i].button))
        {
            vReleasedEvent[i].evenFun();
        }
    }
    for(int i=0;i<vHeldEvent.size();++i)
    {
        if(Button(vHeldEvent[i].button))
        {
            vHeldEvent[i].evenFun();
        }
    }
}
int EasyPS2X::getStickLX()
{
    return map(Analog(PSS_LX),0,255,-255,255);
}
int EasyPS2X::getStickLY()
{
     return map(Analog(PSS_LY),0,255,255,-255);
}
int EasyPS2X::getStickRX()
{
     return map(Analog(PSS_RX),0,255,-255,255);
}
int EasyPS2X::getStickRY()
{
    return map(Analog(PSS_RY),0,255,255,-255);
}
void EasyPS2X::setEvent(unsigned int button,void (*pEvent)(),int type)
{
    event et;
    et.button=button;
    et.evenFun=pEvent;
    switch(type)
    {
        case PRESSED:
            vPressedEvent.push_back(et);
            break;
        case RELEASED:
            vReleasedEvent.push_back(et);
            break;
        case HELD:
            vHeldEvent.push_back(et);
            break;
        default:
            break;
    }
}

