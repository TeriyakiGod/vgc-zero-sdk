#include "Input.hpp"

raylib::Vector2 Input::JoystickVector()
{
    return raylib::Vector2{
        static_cast<float>(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)),
        static_cast<float>(IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP))}
        .Normalize();
}

bool Input::AButton() { return IsKeyDown(KEY_ONE); }
bool Input::BButton() { return IsKeyDown(KEY_TWO); }
bool Input::CButton() { return IsKeyDown(KEY_THREE); }
bool Input::DButton() { return IsKeyDown(KEY_SPACE); }
