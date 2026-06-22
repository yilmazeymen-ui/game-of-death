/*** Including libraries ***/

#include "../include/glad/glad.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <cstdio>
#include "classes.h"

/*** Defining const vars ***/

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 500

Transform cube; // Thats my cube, worlds best cube

int main(int argc, char *argv[]) //Starting program
{
    // Initializing SDL video thing
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Defining OpenGL preferences
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Creating a window
    SDL_Window* win = SDL_CreateWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    if (win == nullptr) {
        printf("\nError window: %s", SDL_GetError());
        return 1;
    }

    // Creating an OpenGL Context
    SDL_GLContext glContext = SDL_GL_CreateContext(win);
    if (glContext == nullptr) {
        printf("\nError OpenGL: %s", SDL_GetError());
        return 1;
    }

    // Starting OpenGL
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("OpenGL loader error!\n");
        return 1;
    }

    // VSync ON
    SDL_GL_SetSwapInterval(1);

    bool running = true;
    SDL_Event event;

    // Program loop
    while (running) {
        // Breaking loop when user gives quit command
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }
        
        glClearColor(0.0f, 0.5f, 0.5f, 1.0f);                   // Cyan colored background

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // I don't now what the frick is this

        SDL_GL_SwapWindow(win);                                 // Drawing window
    }

    SDL_GL_DestroyContext(glContext);   // Destroying OpenGL context
    SDL_DestroyWindow(win);             // Killing window
    SDL_Quit();                         // Stopping SDL thing
    return 0;                           // Closing program
}