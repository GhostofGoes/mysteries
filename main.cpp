#include <SDL.h>

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    auto window = SDL_CreateWindow("Mysteries", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, 0);

    if (window == nullptr) {
        SDL_Log("SDL_CreateWindow failed: %s\n", SDL_GetError());
        return 1;
    }

    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        return 1;
    }

    /* TODO, as they say. */

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
