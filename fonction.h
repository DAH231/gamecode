#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 730
#define SCREEN_W 1200


void SetFull(SDL_Surface *ecran, int *Mode);
void SetNorm(SDL_Surface *ecran, int *Mode);
void SaveScreenMode(SDL_Surface *ecran, int *Mode);

void setMusicVolume(int volume);
void initialiser_audio(Mix_Music *music);




typedef struct{
SDL_Surface *persomini,*miniload;
SDL_Rect pospermini,posmini;
}minimap;

typedef struct
{
SDL_Surface *perso;
SDL_Rect posperso;
int direction;
}Personne;

struct text {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* font;
};
typedef struct text Text; 

typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;


//void save (int valeur_score);
//void load (int valeur_score);

void initmap( minimap * m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *font);
void saisirnom(SDL_Surface screen,char nomjoueur[]);
//void initialiser_score (int valscore, score *s );//initialiser score
void update_score (int *valscore);//mettre a jour score

//void afficher_score(score *s,SDL_Surface *screen,int valscore);
//void free_score(score s);

void inittemps(Time *t);
void Timer(int *tempsdebut); 
int initTexttime(Text* T);
int loadFonttime(Text* T, char* path);
void update_time(Time* T); 
void displaytime(Time T,SDL_Surface *screen);
void freeTexttime(Text T);

#endif
