#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

void Vert_6()
{
    VERT_6 = SDL_LoadBMP("CouleurVERT_6.bmp");
    tVERT_6 = SDL_CreateTextureFromSurface(renderer, VERT_6);
    SDL_FreeSurface(VERT_6);

    SDL_RenderCopy(renderer, tVERT_6, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Jaune_6()
{
    JAUNE_6 = SDL_LoadBMP("CouleurJAUNE_6.bmp");
    tJAUNE_6 = SDL_CreateTextureFromSurface(renderer, JAUNE_6);
    SDL_FreeSurface(JAUNE_6);

    SDL_RenderCopy(renderer, tJAUNE_6, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Rouge_6()
{
    ROUGE_6 = SDL_LoadBMP("CouleurROUGE_6.bmp");
    tROUGE_6 = SDL_CreateTextureFromSurface(renderer, ROUGE_6);
    SDL_FreeSurface(ROUGE_6);

    SDL_RenderCopy(renderer, tROUGE_6, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Bleu_6()
{
    BLEU_6 = SDL_LoadBMP("CouleurBLEU_6.bmp");
    tBLEU_6 = SDL_CreateTextureFromSurface(renderer, BLEU_6);
    SDL_FreeSurface(BLEU_6);

    SDL_RenderCopy(renderer, tBLEU_6, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Orange_6()
{
    ORANGE_6 = SDL_LoadBMP("CouleurORANGE_6.bmp");
    tORANGE_6 = SDL_CreateTextureFromSurface(renderer, ORANGE_6);
    SDL_FreeSurface(ORANGE_6);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tORANGE_6, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Violet_6()
{
    VIOLET_6 = SDL_LoadBMP("CouleurVIOLET_6.bmp");
    tVIOLET_6 = SDL_CreateTextureFromSurface(renderer, VIOLET_6);
    SDL_FreeSurface(VIOLET_6);

    SDL_RenderCopy(renderer, tVIOLET_6, NULL, NULL);
    SDL_RenderPresent(renderer);
}
int choixcouleur_6(resultat)
{
    bool Choos = false;

    SDL_Rect CouleurVert_6={1200, 110, 280, 220};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurVert_6);

    SDL_Rect CouleurRouge_6={1500, 110, 320, 220};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurRouge_6);

    SDL_Rect CouleurJaune_6={1100, 290, 160, 430};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurJaune_6);

    SDL_Rect CouleurBleu_6={1750, 310, 180, 490};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurBleu_6);

    SDL_Rect CouleurViolet_6={1170,710,300,250};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurViolet_6);

    SDL_Rect CouleurOrange_6={1500,750,310,210};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurOrange_6);

    SDL_Log("Faite le choix de votre couleur");
    do
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN :
                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&CouleurBleu_6))
                {
                    resultat = 4;
                    Choos = true;
                    SDL_Log("Bleu, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurRouge_6))
                {
                    resultat = 2;
                    Choos = true;
                    SDL_Log("Rouge, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurVert_6))
                {
                    resultat = 1;
                    Choos = true;
                    SDL_Log("Vert, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurJaune_6))
                {
                    resultat = 3;
                    Choos = true;
                    SDL_Log("Jaune, Resultat = %d",resultat);
                };
                if(SDL_HasIntersection(&Cursor,&CouleurOrange_6))
                {
                    resultat = 5;
                    Choos = true;
                    SDL_Log("Orange, Resultat = %d",resultat);
                }
                if(SDL_HasIntersection(&Cursor,&CouleurViolet_6))
                {
                    resultat = 6;
                    Choos = true;
                    SDL_Log("Violet, Resultat = %d",resultat);
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
void couleur_6()
{
    if(tab[i]==0)
    {
    Vert_6();
    SDL_Log("Vert");

    }
    if(tab[i]==1)
    {

    Rouge_6();
    SDL_Log("Rouge");

    }
    if(tab[i]==2)
    {

    Jaune_6();
    SDL_Log("Jaune");

    }
    if(tab[i]==3)
    {
    Bleu_6();
    SDL_Log("Bleu");
    }
    if(tab[i]==4)
    {
    Orange_6();
    SDL_Log("Orange");
    }
    if(tab[i]==5)
    {
    Violet_6();
    SDL_Log("Violet");
    }
}
void affichagecouleur_6()
{
    Initial_6 = SDL_LoadBMP("JeuInitial_6.bmp");
    tInitial_6 = SDL_CreateTextureFromSurface(renderer, Initial_6);
    SDL_FreeSurface(Initial_6);

    SDL_RenderCopy(renderer, tInitial_6, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Perdu_6()
{
    PERDU_6 = SDL_LoadBMP("JeuPerdu_6.bmp");
    tPerdu_6 = SDL_CreateTextureFromSurface(renderer, PERDU_6);
    SDL_FreeSurface(PERDU_6);

    SDL_RenderCopy(renderer, tPerdu_6, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void jouer_6()
{
    int continuer = 0;
    int compteur = 1,resultat;
    srand(time(NULL));

    SDL_Event event;

    for(i=0;i<100;i++)
    {
        tab[i]=rand()%6;
    }
    affichagecouleur_6();

    SDL_Log("bienvenu");
    SDL_Log("Tour n 1");
    printf("\n");
    while(continuer!=1)
    {
                        affichagecouleur_6();
                        SDL_Delay(500);
                            for(i=0;i<compteur;i++)
                            {
                            couleur_6(tab[i]);
                            SDL_Delay(500);
                            affichagecouleur_6();
                            SDL_Delay(500);
                            }

                            for(i=0;i<compteur;i++)
                            {
                                resultat = choixcouleur_6(resultat);
                                couleur_6(resultat-1);
                                SDL_Delay(500);
                                affichagecouleur_6();
                                SDL_Delay(500);
                                if(tab[i]+1==resultat)
                                {
                                    continuer=0;
                                }
                                else
                                {
                                    continuer=1;
                                    SDL_Log("Vous avez Perdu !");
                                    Perdu_6();
                                    SDL_Delay(2000);
                                    MenuScore(compteur);
                                    break;
                                }
                            }
                            compteur++;
                            affichagecouleur_6();
                            printf("\n");
                            SDL_Log("Tour n %d",compteur);
                            printf("\n");

            SDL_WaitEvent(&event);
            switch(event.type)
            {
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                        {
                         case SDLK_i :
                            stop();
                            break;
                        }
            break;
            }
    }
}
