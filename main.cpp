#include "ballSim.hpp"
#include "windowProperties.hpp"

int main(int argv, char** args)
{   

    const int FPS = 75;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    ballSim sim;

    sim.init("bouncing-ball", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while (sim.running())
    {

        frameStart = SDL_GetTicks();

        sim.handleEvents();
        sim.update();
        sim.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    sim.clean();

    return 0;
}