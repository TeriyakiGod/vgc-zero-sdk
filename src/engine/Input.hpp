#ifndef INPUT_H
#define INPUT_H

#include "raylib-cpp.hpp"

class Input
{
public:
    static raylib::Vector2 JoystickVector();
    static bool AButton();
    static bool BButton();
    static bool CButton();
    static bool DButton();
};

#endif // INPUT_H
