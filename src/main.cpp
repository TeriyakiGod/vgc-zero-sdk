#include "Game.h"
#include "ExampleScene.h"
#include <memory>

int main()
{
    Game game;
    game.Init();

    auto exampleScene = std::make_shared<ExampleScene>();

    game.addScene(exampleScene);

    game.setActiveScene(0);

    game.Run();
    game.Cleanup();
    return 0;
}