#include <SDL3/SDL.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* win = SDL_CreateWindow("GAME", 1000, 1000, 0);

    while (1)
        ;

    return 0;
}