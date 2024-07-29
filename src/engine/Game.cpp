#include "Game.h"
#include "raylib.h"

Game::Game() {}

void Game::Init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
}

void Game::Run()
{
    while (!WindowShouldClose())
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
    CloseWindow();
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