#pragma once
#include "ballSim.hpp"

class Ball {
    public:
        Ball(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
        ~Ball();

        void Update();
        void Render();

    private:
        float xposf;
        float yposf;

        float xvel;
        float yvel;

        float xacc;
        float yacc;

        int xpos;
        int ypos;

        void handle_collision();

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
};