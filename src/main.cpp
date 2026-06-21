// Including libraries

#include <SDL3/SDL.h>
#include <cstdio>
#include "classes.h"

// Defining const vars

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 500

Transform cube; // Thats my cube, worlds best cube

int main(int argc, char *argv[])    //Starting program
{
    // Initializing SDL video thing
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Creating a window
    SDL_Window* win = SDL_CreateWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (win == nullptr) {
        printf("\nError window: %s", SDL_GetError());
    }

    // Creating a renderer
    SDL_Renderer* render = SDL_CreateRenderer(win, nullptr);
    if (render == nullptr) {
        printf("\nError render: %s", SDL_GetError());
    }

    // Defining vars for worlds best cube
    cube.scale.x = 10;
    cube.scale.y = 10;
    cube.position.x = 0;
    cube.position.y = 0;

    // Creating SDL cube with my cube
    SDL_FRect rect;
    rect.h = cube.scale.y;
    rect.w = cube.scale.x;
    rect.x = (SCREEN_HEIGHT - rect.h) / 2.0f;
    rect.y = (SCREEN_WIDTH - rect.w) / 2.0f;

    // Drawing an ugly background
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    // Drawing worlds best cube
    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    SDL_RenderFillRect(render, &rect);

    SDL_RenderPresent(render);  // Rendering screen (owwww look at that sweet cube baby)

    SDL_Delay(3000);    // Waiting 3 seconds
    SDL_DestroyRenderer(render);    // Killing scree- wait! WHERE IS MY CUBEEEE!?!?!?
    SDL_Quit(); // Stopping SDL thing
    return 0;
}