#include "ExampleScene.hpp"
#include "Input.hpp"

class InputTest : public GameObject
{
public:
    InputTest(int layerIndex = 0) : GameObject(layerIndex) {}

    void init() override
    {
        // init
    }

    void update() override
    {
        joystick = Input::JoystickVector();
        buttonA = Input::AButton();
        buttonB = Input::BButton();
        buttonC = Input::CButton();
        buttonD = Input::DButton();
    }

    void draw() override
    {
        // Draw squares for buttons
        DrawRectangle(100, 25, 20, 20, buttonA ? RED : LIGHTGRAY);
        DrawRectangle(100, 50, 20, 20, buttonB ? GREEN : LIGHTGRAY);
        DrawRectangle(100, 75, 20, 20, buttonC ? BLUE : LIGHTGRAY);

        // Draw joystick vector
        DrawLine(30, 64, 30 + static_cast<int>(joystick.x * 20), 64 + static_cast<int>(joystick.y * 20), RED);
        DrawCircle(30 + static_cast<int>(joystick.x * 20), 64 + static_cast<int>(joystick.y * 20), 5, buttonD ? RED : LIGHTGRAY);
    }

private:
    Vector2 joystick;
    bool buttonA = false;
    bool buttonB = false;
    bool buttonC = false;
    bool buttonD = false;
};

ExampleScene::ExampleScene()
{
    addObject(std::make_shared<InputTest>());
}