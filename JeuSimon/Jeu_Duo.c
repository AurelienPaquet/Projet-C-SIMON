#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

// voici le dernier code qu'on a pu faire
// Il y a beaucoup de problème car on se perd facilement
// si on voudrait y arriver il faudrait recommencer proprement pour tout bien refaire de A - Z


void jouer_Duo()
{
    int compteur=1,resultat;
    int Boucle=0,Quitter,cas = 0;
    int Joueur;

    player1();
    SDL_Delay(600);
    SDL_Log("Joueur 1, Entrez la premiere couleur de la combinaison : ");
    tab[0]=choixcouleurDuo(resultat);
    SDL_Delay(150);
    SDL_Log("Joueur 2, La première couleur a memoriser est donc : %d",tab[0]);
    affichagecouleur_4(tab[0]);
    SDL_Delay(500);

    do
    {
        Joueur=Boucle%2;
        if(Joueur == 0)
        {
            player2();
            SDL_Delay(600);
        }
        else
        {
            player1();
            SDL_Delay(600);
        }
        if(Boucle != 0)
        {
            SDL_Log("La derniere couleur est :");
            affichagecouleur_4(tab[compteur]);
            SDL_Log(tab[compteur]);
        }

            SDL_Log("Que vaut la combinaison ?");
            for(i=0;i<compteur;i++)
            {
                resultat=reponseDuo(resultat);
                affichagecouleur_4(resultat);
                SDL_Delay(300);
                couleur_4();
                SDL_Delay(300);
                if(resultat == tab[i])
                {
                    Quitter = 0;
                    cas = 1;
                }
                else
                    cas = 2;
            }
                switch(cas)
                {
                case 1 :
                    SDL_Log("Bravo vous avez Juste, a vous de rajouer une couleur :");
                    tab[compteur]=choixcouleurDuo(resultat);
                    break;
                case 2 :
                    Quitter = 0;
                    break;
                default :
                    SDL_Log("Vous avez perdu !");
                    Quitter = 1;

                }
                Boucle++;
                compteur++;
                cas = 0;
    }
    while( Quitter != 1);
}

void player1()
{
SDL_Surface* image = SDL_LoadBMP("Player1.bmp");
SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(renderer, image);
SDL_FreeSurface(image);
SDL_Rect src={0, 0, 600, 200};
SDL_Rect dst={ 160, 550, 600, 200 };

SDL_RenderCopy(renderer, pTextureImage, &src, &dst);
SDL_RenderPresent(renderer);
}

void player2()
{
SDL_Surface* image = SDL_LoadBMP("Player2.bmp");
SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(renderer, image);
SDL_FreeSurface(image);
SDL_Rect src={0, 0, 600, 200};
SDL_Rect dst={ 160, 550, 600, 200 };

SDL_RenderCopy(renderer, pTextureImage, &src, &dst);
SDL_RenderPresent(renderer);
}

void Player(modulo)
{

    if(Compt == 1)
        switchJoueur = 1;
    else
        switchJoueur = 2;

    switch(switchJoueur)
    {
    case 1 :
        SDL_Log("Player 1 :");
        player1();
        break;
    case 2 :
        SDL_Log("Player 2 :");
        player2();
        break;
    }
}

int reponseDuo(resultat)
{

    SDL_Rect CouleurVert_4={1100, 140, 375, 380};
    SDL_Rect CouleurRouge_4={1510, 140, 390, 380};
    SDL_Rect CouleurJaune_4={1100, 560, 375, 380};
    SDL_Rect CouleurBleu_4={1510, 560, 375, 380};


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Choisir la couleur noir
    SDL_RenderClear(renderer); // Colorier en noir toutes la fenêtre

    SDL_SetRenderDrawColor(renderer, 0, 255 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurVert_4);

    SDL_SetRenderDrawColor(renderer, 255, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurRouge_4);

    SDL_SetRenderDrawColor(renderer, 255, 243 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurJaune_4);

    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &CouleurBleu_4);


    bool Choos = false;
    SDL_Log("Rentrez la nouvelle combinaison");
    do
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN :
                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&CouleurBleu_4))
                {
                    resultat = 3;
                    Choos = true;
                    SDL_Log("Bleu, Resultat = %d",resultat);

                }
                   if(SDL_HasIntersection(&Cursor,&CouleurRouge_4))
                {
                    resultat = 1;
                    Choos = true;
                    SDL_Log("Rouge, Resultat = %d",resultat);

                }
                   if(SDL_HasIntersection(&Cursor,&CouleurVert_4))
                {
                    resultat = 0;
                    Choos = true;
                    SDL_Log("Vert, Resultat = %d",resultat);

                }
                   if(SDL_HasIntersection(&Cursor,&CouleurJaune_4))
                {
                    resultat = 2;
                    Choos = true;
                    SDL_Log("Jaune, Resultat = %d",resultat);
                };
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

int choixcouleurDuo(resultat)
{
    bool Choos = false;

    SDL_Rect CouleurVert_4={1100, 140, 375, 380};
    SDL_Rect CouleurRouge_4={1510, 140, 390, 380};
    SDL_Rect CouleurJaune_4={1100, 560, 375, 380};
    SDL_Rect CouleurBleu_4={1510, 560, 375, 380};


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Choisir la couleur noir
    SDL_RenderClear(renderer); // Colorier en noir toutes la fenêtre

    SDL_SetRenderDrawColor(renderer, 0, 255 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurVert_4);

    SDL_SetRenderDrawColor(renderer, 255, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurRouge_4);

    SDL_SetRenderDrawColor(renderer, 255, 243 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurJaune_4);

    SDL_SetRenderDrawColor(renderer, 0, 0 , 255, 0);
    SDL_RenderFillRect(renderer, &CouleurBleu_4);



    SDL_Log("Faite le choix de votre couleur");
    do
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN :
                Cursor.x = event.motion.x;
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&CouleurBleu_4))
                {
                    resultat = 3;
                    Choos = true;
                    SDL_Log("Bleu, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurRouge_4))
                {
                    resultat = 1;
                    Choos = true;
                    SDL_Log("Rouge, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurVert_4))
                {
                    resultat = 0;
                    Choos = true;
                    SDL_Log("Vert, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurJaune_4))
                {
                    resultat = 2;
                    Choos = true;
                    SDL_Log("Jaune, Resultat = %d",resultat);
                };
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
