#include "Input.h"
#include "raymath.h"

const Vector2 Input::JoystickVector()
{
    return Vector2Normalize(Vector2{
        static_cast<float>(IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)),
        static_cast<float>(IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP))});
}

const bool Input::AButton() { return IsKeyDown(KEY_ONE); }
const bool Input::BButton() { return IsKeyDown(KEY_TWO); }
const bool Input::CButton() { return IsKeyDown(KEY_THREE); }
const bool Input::DButton() { return IsKeyDown(KEY_SPACE); }