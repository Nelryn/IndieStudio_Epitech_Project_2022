#include "blb.hpp"
#include "Player.hpp"
#include "MenuState.hpp"
#include "Map.hpp"
#include "Wall.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include "MenuState.hpp"
#include <stdlib.h>
#include "IntroState.hpp"

#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

int main(void)
{
    blb::Core *core = blb::Core::getInstance();

    std::shared_ptr<blb::AGamestate> state(new IntroState);

    core->setWindow(new blb::Window(1024, 720, "Indie STUDIO"));
    core->win->setState(FLAG_MSAA_4X_HINT);
    core->pushGameState(state);
    blb::Core::createModel("maison",
        "./resources/simplified_roof_bricks_nofloor.glb");
    blb::Core::createModel("walk", "./resources/walk.glb");
    blb::Core::createModel("bomb", "./resources/bomb.glb");
    blb::Core::createModel("lightning", "./resources/lightning.obj");
    blb::Core::createModel("red_bomb", "./resources/red_bomb.glb");

    core->run();

    return (0);
}
