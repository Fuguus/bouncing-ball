#include "ball.hpp"
#include "textureManager.hpp"
#include "windowProperties.hpp"

Ball::Ball(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = textureManager::LoadTexture(textureSheet, renderer);
    
    xpos = x;
    ypos = y;

    xposf = x;
    yposf = y;

    xvel = INITIAL_VX;
    yvel = INITIAL_VY;

    xacc = INITIAL_AX;
    yacc = INITIAL_AY;

    srcRect.h = 20;
    srcRect.w = 20;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void Ball::handle_collision()
{   
    if ((yposf + srcRect.w) > SCREEN_HEIGHT)
    {
        yposf = SCREEN_HEIGHT - srcRect.w;
        yvel = -yvel;
    } 
    else if (yposf < 0) 
    {
        yposf = 0;
        yvel = -yvel;
    }

    if ((xposf + srcRect.w) > SCREEN_WIDTH)
    {
        xposf = SCREEN_WIDTH - srcRect.w;
        xvel = -xvel;
    }
    else if (xposf < 0)
    {
        xposf = 0;
        xvel = -xvel;
    }
}

void Ball::Update()
{   
    xvel += xacc;
    yvel += yacc;

    xposf += xvel;
    yposf += yvel;

    handle_collision();
    
    xpos = xposf;
    ypos = yposf;

    destRect.x = xpos;
    destRect.y = ypos;

}

void Ball::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect); 
}