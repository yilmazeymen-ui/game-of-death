#include <SDL3/SDL.h>
#include <cstdio>

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("GAME", 500, 500, 0);
    if (win == nullptr) {
        printf("\nError window: %s", SDL_GetError());
    }

    SDL_Renderer* render = SDL_CreateRenderer(win, nullptr);
    if (render == nullptr) {
        printf("\nError render: %s", SDL_GetError());
    }

    SDL_SetRenderDrawColor(render, 0, 0, 120, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    SDL_Delay(3000);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    return 0;
}