#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

int main(int argc, char *argv[])
{
    int ChoixSwitch = 1;
    int Marche = 0;
    int Choix = 0;

    // rectangle invisible mets qui me permet d'utiliser le curseur pour jongler entre les menus
    SDL_Rect ButtonPlay={240,520,520,110}; //coordonnées du rectangle ( x.pos, y.pos, largeur, hauteur )
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0); // couleur affecter au renderer au début ( r, g, b, alpha)
    SDL_RenderFillRect(renderer, &ButtonPlay);

    SDL_Rect ButtonOption={290,680,390,100};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &ButtonOption);

    SDL_Rect ButtonEscap={30,880,170,170};
    SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 0);
    SDL_RenderFillRect(renderer, &ButtonEscap);

    MenuInscription(); // menu pour s'inscrire
    system("CLS"); // petite commande pour clean l'invite de commande

    init("Simon",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1980,1080, true); // Fonction pour initialisé et vérifier que tout marche correctement
    // ( nom de la fenetre, x pos, y pos, résolution x, résol y, variable qui indique si on veut se mettre en grand écran ou pas )
    init_ttf();
    // initialisation de la ttf

    depart(); // affichage de l'écran de départ
    Icone(); // Icone de la fenêtre

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // permet d'utiliser la transparence dans les rendus

    do
    {
        Cursor.h = 1; // pour diriger notre curseur, on applique un petit carré de taille min 1x1 sinon ca ne marche pas
        Cursor.w = 1;


        SDL_WaitEvent(&event); //commande qui attend un évènement pour s'actualiser contrairement a SDL_PollEvent qui s'actualise tout le temps
        switch(event.type)
        {
            case SDL_WINDOWEVENT : //évènement sur la croix de la fenetre pour la fermer
            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            Marche = 1;
            break;
            case SDL_MOUSEBUTTONDOWN: // gestion du boutton de la souris, s'active que quand on appuie sur le bouton
                Cursor.x = event.motion.x; // cursor.x et .y sont les coordonnées du rectangle qu'on a appliqué a la souris et donc bouge a chaque fois qu'on clic dessus
                Cursor.y = event.motion.y;
                if(SDL_HasIntersection(&Cursor,&ButtonPlay)) // Pour gerer les menus, si il y a une intersection entre le rect cursor et le rect ButtonPlay, la fonction nous renvoie un changement d'état et donc vérifie la condition
                {
                    Choix = 1;
                }
                   if(SDL_HasIntersection(&Cursor,&ButtonOption))
                {
                    Choix = 2;
                }
                   if(SDL_HasIntersection(&Cursor,&ButtonEscap))
                {
                    Choix = 3;
                }
            break;
            case SDL_MOUSEBUTTONUP : // si on relache le bouton de la souris, on arrive dans cette 'case'
                    Cursor.x = 0; // réinitialisation des coordonnées a chaque fois qu'on relache la souris
                    Cursor.y = 0;
            break;

        }
        switch(Choix) //switch pour gerer le menu
        {
        case 1 :
            MenuJoueur();
            break;
        case 2 :
            MenuOPTION();
            break;
        case 3 :
            Marche = 1;
            break;
        }

    Choix = 0; // réinitialisation des choix car sinon choix reste = a ce qu'on a choisi précédement
    }
    while(!Marche);
    stop(); // on ferme la fenetre en détruisant tout pour éviter une perte de la mémoir
}

