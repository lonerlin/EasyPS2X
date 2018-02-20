#ifndef EasyPS2X_h
    #define EasyPS2X_h

#include "PS2X_lib.h"
#include<Vector.h>

#define PRESSED 0
#define RELEASED 1
#define HELD 2

struct event{
    unsigned int button;
    void (*evenFun)();
};
class EasyPS2X:public PS2X
{
    public:

      void update();
      void setPressedEvent(unsigned int button,void (*pressedEvent)());
      void setReleasedEvent(unsigned int button,void (*pressedEvent)());
      void setHeldEvent(unsigned int button,void (*heldEvent)());
      int getStickLX();
      int getStickLY();
      int getStickRX();
      int getStickRY();
    private:
      Vector<event> vPressedEvent;
      Vector<event> vReleasedEvent;
      Vector<event> vHeldEvent;
      void setEvent(unsigned int button,void (*pressedEvent)(),int type);

};

#endif
