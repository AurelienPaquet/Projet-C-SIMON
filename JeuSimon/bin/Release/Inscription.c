#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define taille 100

#include "Header.h"

// Rajoute les nouveaux compte avec la struct compte
void ajouter(struct compte tab[], int position)
{
     fflush(stdin);
     printf("\n\t - Entrez votre nouveau compte : \n");
     fgets(tab[position].pseudo, 25, stdin);
     fflush(stdin);
     printf("\n\t - Entrez votre mot de passe : \n");
     fgets(tab[position].mdp, 25, stdin);
}


void afficher_compte(struct compte e)
{
     printf("\t - Pseudo : %s\t\t - Mot de passe : %s \n\n", e.pseudo, e.mdp);
}

// affiche une liste de tous les comptes présent
void afficher(struct compte tab[], int position)
{
     int i;
     for(i=0; i < position; i++)
     {
        afficher_compte(tab[i]);
     }
}

// permet d'enregistrer
void enregistrer(struct compte tab[], int position)
{
     FILE *fichier;
     int i;

     fichier = fopen("Comptes.dat", "w");
        for(i=0; i < position; i++)
     fwrite(&tab[i], sizeof(struct compte), 1, fichier);
     fclose(fichier);
}

// permet de lire le fichier
int lire(struct compte tab[])
{
     int i=0;
     FILE *fichier=fopen("Comptes.dat", "r");

     while(fread(&tab[i], sizeof(struct compte), 1, fichier) && !feof(fichier))
        i++;
     return i;
}

// utiliser dans le menu pour se connecter, ca permet de rechercher un mdp et un pseudo pour voir s'ils correspondent avec ceux dans le fichier
int recherche(struct compte tab[], int position)
{
     char pseudo[25], mdp[25];
     int trouve = 0;
     int i = 0;

     fflush(stdin);
     printf("\n\t-\tEntrez le Pseudo : \n");
     fgets(pseudo, 25, stdin);

     fflush(stdin);
     printf("\n\t-\tEntrez le Mot de passe : \n");
     fgets(mdp, 25, stdin);

     while(trouve == 0 && i < position)
     {
         if(strcmp(tab[i].pseudo, pseudo) == 0 && strcmp(tab[i].mdp, mdp) == 0)
             {
                trouve=1;
             }
                i++;
             }
         if(trouve == 0)
            printf("Compte inconnu\n");
         return trouve;
}

// menu de l'inscription
int inscription(void)
{
    int choixMenu1; /* il manquait un point virgule */

         printf("\n****************************************************************************************************************");
    printf("\n*                                                                                                              *");
    printf("\n*                                            ---  JEU SIMON ---                                                *");
    printf("\n*                                                                                                              *");
    printf("\n****************************************************************************************************************");
    printf("\n*                                                                                                              *");
    printf("\n*                                  1. S'inscrire :                                                             *");
    printf("\n*                                                                                                              *");
    printf("\n*                                  2. Se connecter :                                                           *");
    printf("\n*                                                                                                              *");
    printf("\n****************************************************************************************************************");
    printf("\n\n\n\t Votre Choix  :  \n\n");
    scanf("%d",&choixMenu1);
    return choixMenu1;

}


//Fonction utiliser dans le main.c avec une condition, si on est pas connecter on reste dans la boucle
// Il y a la touche 9 qui permet de vérifier les comptes dans le fichier
// La touche 8 permet aussi de se connecter directement, c'est un raccourci pour éviter a chaque fois qu'on voulait test le code de retaper nos identifiants


int MenuInscription()
{
    struct compte tableau[taille];
    int indice = 0;
    int result, trouve, i, compteur = 1, continuer;
    bool isconnect = false;

    indice = lire(tableau);

    do{
         switch(inscription()) // Traitement des choix possibles :
         {
             case 1 :
                 if(indice < taille-1)
                 {
                     ajouter(tableau, indice);
                     enregistrer(tableau, indice);
                     indice++;
                 }
                 else
                 printf("Tableau plein\n");
                 enregistrer(tableau, indice);
                 break;
              case 2 :
                printf("Connectez vous :\n");
                result = recherche(tableau, indice);
                if(result == 1)
                    isconnect=true;
                    Marche=0;
                    system("CLS");

                break;

              // case permettant de vérifier si les comptes sont bien enregistré
              case 9 :
                 system("CLS");
                 printf("Liste des Compte :\n");
                 afficher(tableau, indice);
                 break;

             // case évitant a chaque fois de se connecter
             case 8 :
                 isconnect=1;
                 break;

             default :
                printf("Choix non valide\n");
         }
    }while(isconnect != true);
}
