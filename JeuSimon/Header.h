#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

SDL_Rect Cursor;
SDL_Event event;

bool Marche;
int i,tab[100],switchJoueur,Compt;

// Fonction du fichier Inscription.c

struct compte
{
     char pseudo[25];
     char mdp[25];
};

void ajouter(struct compte tab[], int position);
void afficher_compte(struct compte e);
void afficher(struct compte tab[], int position);
void enregistrer(struct compte tab[], int position);
int inscription(void);
int lire(struct compte tab[]);
int recherche(struct compte tab[], int position);
int MenuInscription();

//  Fonction du fichier Initialisation.c

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Surface *icone;

SDL_Color* NOIR; // Couleur ( faut pas faire attention au nom )

void init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen);
void init_ttf();
void stop();
void Icone();

// Fonction du fichier Menu.c
// fonction pour charger les images

SDL_Surface *Depart;
SDL_Surface *Multi;
SDL_Surface *Difficulte;
SDL_Surface *MenuOption;

SDL_Texture *tDepart;
SDL_Texture *tMulti;
SDL_Texture *tDifficulte;
SDL_Texture *tOption;

void depart();
void multi();
void difficulte();
void OPTION();
// différent menu du jeu
void MenuJoueur();
void MenuDifficulte();
void MenuOPTION();

// Fonction du Fichier Jeu_4_Couleur.c

SDL_Surface *Initial_4;
SDL_Surface *JAUNE_4;
SDL_Surface *VERT_4;
SDL_Surface *ROUGE_4;
SDL_Surface *BLEU_4;
SDL_Surface *PERDU_4;

SDL_Texture *tInitial_4;
SDL_Texture *tPerdu_4;
SDL_Texture *tROUGE_4;
SDL_Texture *tBLEU_4;
SDL_Texture *tVERT_4;
SDL_Texture *tJAUNE_4;

void Vert_4();
void Jaune_4();
void Rouge_4();
void Bleu_4();
void couleur_4();
void jouer_4();
void affichagecouleur_4();
int choixcouleur_4(resultat);


// Fonction du fichier Jeu_5_couleur.c

SDL_Surface *Initial_5;
SDL_Surface *JAUNE_5;
SDL_Surface *VERT_5;
SDL_Surface *ROUGE_5;
SDL_Surface *BLEU_5;
SDL_Surface *PERDU_5;
SDL_Surface *ORANGE_5;

SDL_Texture *tInitial_5;
SDL_Texture *tPerdu_5;
SDL_Texture *tROUGE_5;
SDL_Texture *tBLEU_5;
SDL_Texture *tVERT_5;
SDL_Texture *tJAUNE_5;
SDL_Texture *tORANGE_5;

void Vert_5();
void Jaune_5();
void Rouge_5();
void Bleu_5();
void Orange_5();
void couleur_5();
void affichagecouleur_5();
void Perdu_5();
void jouer_5();
int choixcouleur_5(resultat);

// Fonction du fichier Jeu_6_Couleur.c

SDL_Surface *Initial_6;
SDL_Surface *JAUNE_6;
SDL_Surface *VERT_6;
SDL_Surface *ROUGE_6;
SDL_Surface *BLEU_6;
SDL_Surface *PERDU_6;
SDL_Surface *ORANGE_6;
SDL_Surface *VIOLET_6;

SDL_Texture *tInitial_6;
SDL_Texture *tPerdu_6;
SDL_Texture *tROUGE_6;
SDL_Texture *tBLEU_6;
SDL_Texture *tVERT_6;
SDL_Texture *tJAUNE_6;
SDL_Texture *tORANGE_6;
SDL_Texture *tVIOLET_6;

void Vert_6();
void Jaune_6();
void Rouge_6();
void Bleu_6();
void Orange_6();
void Violet_6();
void couleur_6();
void affichagecouleur_6();
void Perdu_6();
void jouer_6();
int choixcouleur_6(resultat);



// Fonction du fichier Score.c

struct score
{
     char nom[25];
     int score;
};

void affichagecores();
void score(compteur);
void MenuScore(compteur);

SDL_Surface *SurfaceScore;
SDL_Texture *textureScore;
TTF_Font* police;

SDL_Surface *ImageScore;
SDL_Texture *ImageTScore;
#endif // HEADER_H_INCLUDED
