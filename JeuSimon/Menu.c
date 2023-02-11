#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

void depart()
{
    Depart = SDL_LoadBMP("MenuDepart.bmp"); // chargement de l'image en .bmp qui est dans le dossier du projet
    tDepart = SDL_CreateTextureFromSurface(renderer, Depart); // création d'une texture de la part d'une surface
    SDL_FreeSurface(Depart);// libération de la mémoire ou il y avait la surface

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer); // on efface le rendu précédent pour réafficher la nouvelle image
    SDL_RenderCopy(renderer, tDepart, NULL, NULL); // On copie l'image sur le rendu, les deux 'NULL' dans les parenthèses permettent si on le veut de redimensionner l'image
    SDL_RenderPresent(renderer); // on actualise l'affichage
    SDL_Log("Premiere image bien affichee!");
}
void multi()
{
    Multi = SDL_LoadBMP("MenuMultijoueur.bmp");
    tMulti = SDL_CreateTextureFromSurface(renderer, Multi);
    SDL_FreeSurface(Multi);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tMulti, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Log("Menu Multi bien initialise...");
}
void difficulte()
{
    Difficulte = SDL_LoadBMP("MenuDifficulte.bmp");
    tDifficulte = SDL_CreateTextureFromSurface(renderer, Difficulte);
    SDL_FreeSurface(Difficulte);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tDifficulte, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Log("Menu Difficulte bien initialise...");
}

void OPTION()
{
    MenuOption = SDL_LoadBMP("MenuOption.bmp");
    tOption = SDL_CreateTextureFromSurface(renderer, MenuOption);
    SDL_FreeSurface(MenuOption);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tOption, NULL, NULL);
    SDL_RenderPresent(renderer);
}

// même menu que dans le main donc même explication

void MenuJoueur()
{
    int Choix=0;

    SDL_Rect ButtonSolo={250,520,510,110};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonSolo);

    SDL_Rect ButtonDuo={250,660,510,110};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonDuo);

    SDL_Rect ButtonEscap={30,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonEscap);

    SDL_Rect ButtonReturn={680,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonReturn);

    SDL_Event event;

    bool Continuer = true;

    multi();

    do
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT :
            stop();
            break;
        case SDL_MOUSEBUTTONDOWN :

                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;

                if(SDL_HasIntersection(&Cursor,&ButtonSolo))
                {
                    Choix = 1;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonDuo))
                {
                    Choix = 2;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonReturn))
                {
                    Choix = 3;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonEscap))
                {
                    Choix = 4;
                }
            break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
                stop();
                break;
            }
            break;
        }

        switch(Choix)
        {
        case 1 :
            MenuDifficulte();
            break;
        case 2 :
            jouer_Duo();
            break;
        case 3 :
            Continuer = false;
            break;
        case 4 :
            stop();
            break;
        }
        Choix = 0;
    }
    while(Continuer != false);
    depart();
}

void MenuDifficulte()
{
    bool Continuer = true;
    int Choix = 0;

    SDL_Event event;

    SDL_Rect ButtonSimple={290,510,420,80};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonSimple);

    SDL_Rect ButtonMoyen={290,610,420,80};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonMoyen);

    SDL_Rect ButtonDifficile={290,700,420,80};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonDifficile);

    SDL_Rect ButtonEscap={30,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonEscap);

    SDL_Rect ButtonReturn={680,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonReturn);

    difficulte();
        do
        {
            SDL_WaitEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT :
                Continuer = false;
                break;
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE :
                    stop();
                    break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN :
                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&ButtonSimple))
                {
                    Choix = 1;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonMoyen))
                    {
                        Choix = 2;
                    }
                if(SDL_HasIntersection(&Cursor,&ButtonDifficile))
                    {
                        Choix = 3;
                    }
                if(SDL_HasIntersection(&Cursor,&ButtonEscap))
                    {
                        Choix = 4;
                    }
                if(SDL_HasIntersection(&Cursor,&ButtonReturn))
                {
                    Choix = 5;
                }
                break;
            }

        switch(Choix)
        {
        case 1 :
            affichagecouleur_4();
            jouer_4();
            break;
        case 2 :
            affichagecouleur_5();
            jouer_5();
            break;
        case 3 :
            affichagecouleur_6();
            jouer_6();
            break;
        case 5 :
            Continuer=false;
            break;
        case 4 :
            stop();
            break;
        }
        Choix = 0;
    }
    while(Continuer!=false);
    MenuJoueur();
}

// Regle du jeu
void MenuOPTION()
{
    bool Continuer = true;
    int Choix = 0;

    SDL_Event event;

    SDL_Rect ButtonEscap={30,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonEscap);

    SDL_Rect ButtonReturn={680,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &ButtonReturn);

    OPTION();
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

                if(SDL_HasIntersection(&Cursor,&ButtonReturn))
                {
                    Choix = 1;
                }
                if(SDL_HasIntersection(&Cursor,&ButtonEscap))
                {
                    Choix = 2;
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
        }
        Choix = 0;
    }
    while(Continuer != false);
    depart();
}

