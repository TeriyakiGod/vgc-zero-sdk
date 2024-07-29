#ifndef GAME_H
#define GAME_H

#include "Scene.hpp"
#include "Input.hpp"
#include <memory>
#include <vector>
#include <raylib-cpp.hpp>

class Game
{
public:
    Game();

    void Init();
    void Run();
    void Update();
    void Draw();
    void Cleanup();
    void addScene(std::shared_ptr<Scene> scene);
    void setActiveScene(size_t index);

private:
    const int SCREEN_WIDTH = 128;
    const int SCREEN_HEIGHT = 128;
    const char *WINDOW_TITLE = "Game";
    const int TARGET_FPS = 30;
    const bool DRAW_FPS = true;

    raylib::Window window;
    std::vector<std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> activeScene;
};

#endif // GAME_H
