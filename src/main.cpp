#include "Game.hpp"
#include "ExampleScene.hpp"
#include <memory>

int main()
{
    Game game;

    auto exampleScene = std::make_shared<ExampleScene>();

    game.addScene(exampleScene);

    game.setActiveScene(0);

    game.Init();
    game.Run();
    game.Cleanup();
    return 0;
}