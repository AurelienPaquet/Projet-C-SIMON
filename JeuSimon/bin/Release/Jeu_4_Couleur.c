#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

// chargement de toutes les images pour faciliter le code
void Vert_4()
{
    VERT_4 = SDL_LoadBMP("CouleurVERT_4.bmp");
    tVERT_4 = SDL_CreateTextureFromSurface(renderer, VERT_4);
    SDL_FreeSurface(VERT_4);

    SDL_RenderCopy(renderer, tVERT_4, NULL, NULL);
    SDL_RenderPresent(renderer);

}
void Jaune_4()
{
    JAUNE_4 = SDL_LoadBMP("CouleurJAUNE_4.bmp");
    tJAUNE_4 = SDL_CreateTextureFromSurface(renderer, JAUNE_4);
    SDL_FreeSurface(JAUNE_4);

    SDL_RenderCopy(renderer, tJAUNE_4, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Rouge_4()
{
    ROUGE_4 = SDL_LoadBMP("CouleurROUGE_4.bmp");
    tROUGE_4 = SDL_CreateTextureFromSurface(renderer, ROUGE_4);
    SDL_FreeSurface(ROUGE_4);

    SDL_RenderCopy(renderer, tROUGE_4, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void Bleu_4()
{
    BLEU_4 = SDL_LoadBMP("CouleurBLEU_4.bmp");
    tBLEU_4 = SDL_CreateTextureFromSurface(renderer, BLEU_4);
    SDL_FreeSurface(BLEU_4);

    SDL_RenderCopy(renderer, tBLEU_4, NULL, NULL);
    SDL_RenderPresent(renderer);
}

// image quand on a perdu
void Perdu_4()
{
    PERDU_4 = SDL_LoadBMP("JeuPerdu_4.bmp");
    tPerdu_4 = SDL_CreateTextureFromSurface(renderer, PERDU_4);
    SDL_FreeSurface(PERDU_4);

    SDL_RenderCopy(renderer, tPerdu_4, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}
// fonction principale du jeu
void jouer_4()
{
    int continuer = 0;
    int compteur = 1, resultat;
    srand(time(NULL));

    SDL_Event event;

    // boucle pour créer un tableau avec des nombres aléatoires entre 0 et 3
    for(i=0;i<100;i++)
    {
        tab[i]=rand()%4;
    }
    affichagecouleur_4(); // affichage du jeu initial

    SDL_Log("bienvenu"); // pour vérifier dans la console si il y a eu un soucis et si oui a quelle niveau
    SDL_Log("Tour n 1");
    printf("\n");

    while(continuer!=1) // boucle du jeu, si on perd on quitte la boucle sinon on reste dedans
    {
                        affichagecouleur_4();
                        SDL_Delay(500); // delai de 0.5s car sinon l'image s'affiche et se décharge immédiatement
                                for(i=0;i<compteur;i++)
                                {
                                couleur_4(tab[i]); // fonction permettant d'afficher les couleurs suivant la boucle aléatoire qu'on a fait précédement
                                SDL_Delay(500);
                                affichagecouleur_4(); // réaffichage du jeu initial pour éviter que quand 2 fois la meme couleur s'affiche, on ne voit pas la différence
                                SDL_Delay(500);
                                }

                                for(i=0;i<compteur;i++)
                                        {

                                            resultat = choixcouleur_4(resultat); // on fait le choix de la couleur avec le curseur dans cette fonction qui nous retourne une valeur qu'on implémente dans une variable
                                            couleur_4(resultat-1); // affichage des couleurs qu'on a choisi
                                            SDL_Delay(500);
                                            affichagecouleur_4();
                                            SDL_Delay(500);
                                            if(tab[i]+1==resultat) // vérification a chaque fois si on a la meme couleur ou pas, si oui continuer = 0, sinon on perd
                                            {
                                                continuer=0;
                                            }
                                            else
                                            {
                                               SDL_Log("Vous avez Perdu !");
                                               Perdu_4(); // affichage du menu perdu
                                               SDL_Delay(2000);
                                               MenuScore(compteur);
                                               continuer=1;
                                            break;
                                            }
                                        }



            compteur++; // a chaque tour on ajoute +1 a la variable compteur
            affichagecouleur_4();
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
void affichagecouleur_4()
{
    Initial_4 = SDL_LoadBMP("JeuInitial_4.bmp");
    tInitial_4 = SDL_CreateTextureFromSurface(renderer, Initial_4);
    SDL_FreeSurface(Initial_4);

    SDL_RenderCopy(renderer, tInitial_4, NULL, NULL);
    SDL_RenderPresent(renderer);
}
void couleur_4() // fonction qui affiche les couleurs suivant soit le tableau aléatoire, soit le choix qu'on fait quand on joue
{
    if(tab[i]==0)
    {
    Vert_4();
    SDL_Log("Vert");

    }
    if(tab[i]==1)
    {

    Rouge_4();
    SDL_Log("Rouge");

    }
    if(tab[i]==2)
    {

    Jaune_4();
    SDL_Log("Jaune");

    }
    if(tab[i]==3)
    {
    Bleu_4();
    SDL_Log("Bleu");
    }
}
int choixcouleur_4(resultat) // choix de la couleur
{
    bool Choos = false;

    SDL_Rect CouleurVert_4={1100, 140, 375, 380};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurVert_4);

    SDL_Rect CouleurRouge_4={1510, 140, 390, 380};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurRouge_4);

    SDL_Rect CouleurJaune_4={1100, 560, 375, 380};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &CouleurJaune_4);

    SDL_Rect CouleurBleu_4={1510, 560, 375, 380};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
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
                    resultat = 4;
                    Choos = true;
                    SDL_Log("Bleu, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurRouge_4))
                {
                    resultat = 2;
                    Choos = true;
                    SDL_Log("Rouge, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurVert_4))
                {
                    resultat = 1;
                    Choos = true;
                    SDL_Log("Vert, Resultat = %d",resultat);
                }
                   if(SDL_HasIntersection(&Cursor,&CouleurJaune_4))
                {
                    resultat = 3;
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
