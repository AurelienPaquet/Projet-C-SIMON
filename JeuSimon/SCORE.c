#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"



void score(compteur)
{
    char TextScore[3];
    SDL_Color NOIR = {255,155,0}; // cest la couleur de l'écriture

    ImageScore = SDL_LoadBMP("Score.bmp");//On charge la derniere image avec le score
    ImageTScore = SDL_CreateTextureFromSurface(renderer, ImageScore);
    SDL_FreeSurface(ImageScore);

    sprintf(TextScore, "%d", compteur-1); // on utilise sprintf pour associer a un char a un numero

    SDL_Rect TextPosition={575,625,75,75}; // c'est la position ou le score s'écrit
    police = TTF_OpenFont("Miglia.TTF", 50); // c'est le chargement de la police d'écriture
    SurfaceScore = TTF_RenderText_Blended(police, TextScore, NOIR);// on applique la couleur, la police au text voulu
    textureScore = SDL_CreateTextureFromSurface(renderer, SurfaceScore);
    SDL_FreeSurface(SurfaceScore);
    TTF_CloseFont(police);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, ImageTScore, NULL, NULL);
    SDL_RenderCopy(renderer, textureScore, NULL, &TextPosition);
    SDL_RenderPresent(renderer);
}

void MenuScore(compteur)
{
    bool Continuer = true;
    int Choix = 0;

    SDL_Event event;

    SDL_Rect ButtonEscap={30,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &ButtonEscap);


    SDL_Rect ButtonNon={1060,780,540,200};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &ButtonNon);

    SDL_Rect ButtonOui={1060,500,540,200};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &ButtonOui);

    SDL_RenderClear(renderer);
    score(compteur);
    do
    {

        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT :
            stop();
            break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
                stop();
                break;
            }
        case SDL_MOUSEBUTTONDOWN :

                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;

                if(SDL_HasIntersection(&Cursor,&ButtonEscap))
                {
                    Choix = 2;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonNon))
                {
                    Choix = 4;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonOui))
                {
                    Choix = 3;
                }
            break;
        }

        switch(Choix)
        {
        case 1 :
            Continuer = false;
            break;
        case 2 :
            stop();
            break;
        case 3 :
            Continuer = false; // En théorie c'était ici qu'on demandait a l'utilisateur si il voulait enregistrer son score ou pas
            break;
        case 4 :
            Continuer = false; // on retourne directement au menu principale
            break;
        }
        Choix = 0;
    }
    while(Continuer != false);
    MenuJoueur();
}
