#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

class Input
{
public:
    static const Vector2 JoystickVector();
    static const bool AButton();
    static const bool BButton();
    static const bool CButton();
    static const bool DButton();
};

#endif // INPUT_H