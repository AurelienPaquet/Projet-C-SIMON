#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

void Vert_5()
{
    VERT_5 = SDL_LoadBMP("CouleurVERT_5.bmp");
    tVERT_5 = SDL_CreateTextureFromSurface(renderer, VERT_5);
    SDL_FreeSurface(VERT_5);

    SDL_RenderCopy(renderer, tVERT_5, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Jaune_5()
{
    JAUNE_5 = SDL_LoadBMP("CouleurJAUNE_5.bmp");
    tJAUNE_5 = SDL_CreateTextureFromSurface(renderer, JAUNE_5);
    SDL_FreeSurface(JAUNE_5);

    SDL_RenderCopy(renderer, tJAUNE_5, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Rouge_5()
{
    ROUGE_5 = SDL_LoadBMP("CouleurROUGE_5.bmp");
    tROUGE_5 = SDL_CreateTextureFromSurface(renderer, ROUGE_5);
    SDL_FreeSurface(ROUGE_5);

    SDL_RenderCopy(renderer, tROUGE_5, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Bleu_5()
{
    BLEU_5 = SDL_LoadBMP("CouleurBLEU_5.bmp");
    tBLEU_5 = SDL_CreateTextureFromSurface(renderer, BLEU_5);
    SDL_FreeSurface(BLEU_5);

    SDL_RenderCopy(renderer, tBLEU_5, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Orange_5()
{
    ORANGE_5 = SDL_LoadBMP("CouleurORANGE_5.bmp");
    tORANGE_5 = SDL_CreateTextureFromSurface(renderer, ORANGE_5);
    SDL_FreeSurface(ORANGE_5);

    SDL_RenderCopy(renderer, tORANGE_5, NULL, NULL);
    SDL_RenderPresent(renderer);
}
int choixcouleur_5(resultat)
{
    bool Choos = false;

    SDL_Rect CouleurVert_5={1120, 110, 360, 390};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurVert_5);

    SDL_Rect CouleurRouge_5={1500, 110, 380, 300};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurRouge_5);

    SDL_Rect CouleurJaune_5={1070, 410, 210, 400};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurJaune_5);

    SDL_Rect CouleurBleu_5={1700, 430, 210, 400};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurBleu_5);

    SDL_Rect CouleurOrange_5={1230,750,520,210};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurOrange_5);



    SDL_Log("Faite le choix de votre couleur");
    do
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN :
                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&CouleurBleu_5))
                {
                    resultat = 4;
                    Choos = true;
                    SDL_Log("Bleu, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurRouge_5))
                {
                    resultat = 2;
                    Choos = true;
                    SDL_Log("Rouge, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurVert_5))
                {
                    resultat = 1;
                    Choos = true;
                    SDL_Log("Vert, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurJaune_5))
                {
                    resultat = 3;
                    Choos = true;
                    SDL_Log("Jaune, Resultat = %d",resultat);
                };
                if(SDL_HasIntersection(&Cursor,&CouleurOrange_5))
                {
                    resultat = 5;
                    Choos = true;
                    SDL_Log("Orange, Resultat = %d",resultat);
                }
                break;
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE :
                    stop();
                    break;
                }
        }
    }
    while(Choos == false);
    return resultat;
}
void couleur_5()
{
    if(tab[i]==0)
    {
    Vert_5();
    SDL_Log("Vert");

    }
    if(tab[i]==1)
    {

    Rouge_5();
    SDL_Log("Rouge");

    }
    if(tab[i]==2)
    {

    Jaune_5();
    SDL_Log("Jaune");

    }
    if(tab[i]==3)
    {
    Bleu_5();
    SDL_Log("Bleu");
    }
    if(tab[i]==4)
    {
    Orange_5();
    SDL_Log("Orange");
    }
}
void affichagecouleur_5()
{
    Initial_5 = SDL_LoadBMP("JeuInitial_5.bmp");
    tInitial_5 = SDL_CreateTextureFromSurface(renderer, Initial_5);
    SDL_FreeSurface(Initial_5);

    SDL_RenderCopy(renderer, tInitial_5, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Perdu_5()
{
    PERDU_5 = SDL_LoadBMP("JeuPerdu_5.bmp");
    tPerdu_5 = SDL_CreateTextureFromSurface(renderer, PERDU_5);
    SDL_FreeSurface(PERDU_5);

    SDL_RenderCopy(renderer, tPerdu_5, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void jouer_5()
{
    int continuer = 0;
    int compteur = 1,resultat;
    srand(time(NULL));

    SDL_Event event;

    for(i=0;i<100;i++)
    {
        tab[i]=rand()%5;
    }
    affichagecouleur_5();

    SDL_Log("bienvenu");
    SDL_Log("Tour n 1");
    printf("\n");
    while(continuer!=1)
    {
        affichagecouleur_5();
        SDL_Delay(500);
        for(i=0;i<compteur;i++)
        {
            couleur_5(tab[i]);
            SDL_Delay(500);
            affichagecouleur_5();
            SDL_Delay(500);
        }

        for(i=0;i<compteur;i++)
        {
            resultat = choixcouleur_5(resultat);
            couleur_5(resultat-1);
            SDL_Delay(500);
            affichagecouleur_5();
            SDL_Delay(500);
            if(tab[i]+1==resultat)
            {
                continuer=0;
            }
            else
            {
                continuer=1;
                SDL_Log("Vous avez Perdu !");
                Perdu_5();
                SDL_Delay(2000);
                MenuScore(compteur);
                break;
            }
        }

        compteur++;
        affichagecouleur_5();
        printf("\n");
        SDL_Log("Tour n %d",compteur);
        printf("\n");

        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                    stop();
                break;
            }
            break;
        }
    }
}
