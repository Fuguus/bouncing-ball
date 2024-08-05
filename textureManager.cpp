#include "textureManager.hpp"

SDL_Texture* textureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* ballTex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return ballTex;
}