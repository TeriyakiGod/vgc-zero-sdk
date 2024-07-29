#include "Game.hpp"
#include "raylib-cpp.hpp"

Game::Game()
    : window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE)
{
    // Constructor
}

void Game::Init()
{
    SetTargetFPS(TARGET_FPS);
    for (auto &scene : scenes)
    {
        scene->init();
    }
}

void Game::Run()
{
    while (!window.ShouldClose())
    {
        Update();
        Draw();
    }
}

void Game::Update()
{
    if (activeScene)
    {
        activeScene->update();
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (activeScene)
    {
        activeScene->draw();
    }
    if (DRAW_FPS)
        DrawFPS(10, 10);
    EndDrawing();
}

void Game::Cleanup()
{
    window.Close(); // This will automatically call CloseWindow
}

void Game::addScene(std::shared_ptr<Scene> scene)
{
    scenes.push_back(scene);
}

void Game::setActiveScene(size_t index)
{
    if (index < scenes.size())
    {
        activeScene = scenes[index];
    }
}
