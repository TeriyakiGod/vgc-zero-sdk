#include "ExampleScene.h"
#include "Text.h"
#include "Input.h"

class Ball : public GameObject
{
public:
    Ball(float x, float y, float radius, float speedX, float speedY, int layerIndex = 0)
        : GameObject(layerIndex), x(x), y(y), radius(radius), speedX(speedX), speedY(speedY) {}

    void update() override
    {
        x += speedX;
        y += speedY;

        if (x - radius <= 0 || x + radius >= GetScreenWidth())
        {
            speedX *= -1;
        }
        if (y - radius <= 0 || y + radius >= GetScreenHeight())
        {
            speedY *= -1;
        }
    }

    void draw() override
    {
        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, RED);
    }

private:
    float x, y;
    float radius;
    float speedX, speedY;
};

class InputTest : public GameObject
{
public:
    InputTest(int layerIndex = 0) : GameObject(layerIndex) {}

    void update() override
    {
        joystick = Input::JoystickVector();
        buttonA = Input::AButton();
        buttonB = Input::BButton();
        buttonC = Input::CButton();
    }

    void draw() override
    {
        // Draw squares for buttons
        DrawRectangle(100, 25, 20, 20, buttonA ? RED : LIGHTGRAY);
        DrawRectangle(100, 50, 20, 20, buttonB ? GREEN : LIGHTGRAY);
        DrawRectangle(100, 75, 20, 20, buttonC ? BLUE : LIGHTGRAY);

        // Draw joystick vector
        DrawLine(30, 64, 30 + static_cast<int>(joystick.x * 20), 64 + static_cast<int>(joystick.y * 20), RED);
        DrawCircle(30 + static_cast<int>(joystick.x * 20), 64 + static_cast<int>(joystick.y * 20), 5, BLACK);
    }

private:
    Vector2 joystick;
    bool buttonA = false;
    bool buttonB = false;
    bool buttonC = false;
};

ExampleScene::ExampleScene()
{
    auto ball = std::make_shared<Ball>(GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f, 10.0f, 2.0f, 2.0f, 1);
    addObject(ball);

    auto text = std::make_shared<Text>("Example scene", GetScreenWidth() / 2.0f, 110, 17, BLACK,
                                       HorizontalAlignment::CENTER, VerticalAlignment::MIDDLE, 0);
    addObject(text);

    auto inputTest = std::make_shared<InputTest>(0);
    addObject(inputTest);
}