#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

void init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        SDL_Log("Initialisation...");

        window = SDL_CreateWindow(title, xpos, ypos , width, height, flags);
        if(window)
        {
            SDL_Log("Window Créer !");
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer)
        {
            SDL_Log("Renderer Créer !");
        }

        Marche = true;
    }else{
    Marche = false;
    }
}

void init_ttf() // initialise si il y a pas une erreur
{
    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return 0;
    }
    if (police == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }
    if (textureScore == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }
    if (SurfaceScore == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }
}

void stop()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Icone() // chargment de l'image et application sur l'icone de la fenetre
{
    icone = SDL_LoadBMP("icone.bmp");
    SDL_SetWindowIcon(window, icone);
}
