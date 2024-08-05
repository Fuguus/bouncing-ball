#include "ballSim.hpp"
#include "textureManager.hpp"
#include "ball.hpp"
#include "windowProperties.hpp"

Ball* ball1;

ballSim::ballSim() 
{

}
ballSim::~ballSim()
{

}

void ballSim::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{   
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    ball1 = new Ball("assets/ball.bmp", renderer, INITIAL_X, INITIAL_Y);

}

void ballSim::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void ballSim::update()
{  
    ball1->Update();    
}

void ballSim::render()
{
    SDL_RenderClear(renderer);

    ball1->Render();   

    SDL_RenderPresent(renderer);
}

void ballSim::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "ballSim cleaned" << std::endl;
}

