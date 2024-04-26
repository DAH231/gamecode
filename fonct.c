#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include "fonction.h"



void setMusicVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

void initialiser_audio(Mix_Music *music)
{
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
   printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(30);
}



void SaveScreenMode(SDL_Surface *ecran, int *Mode)
{
    if (*Mode == 0)
    {
        SDL_Flip(ecran);
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//mode normal
    }
    else
    {
        SDL_Flip(ecran);
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);//mode fullscren
    }
    
}

void SetFull(SDL_Surface *ecran, int *Mode)
{
    *Mode = 1;
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
}

void SetNorm(SDL_Surface *ecran, int *Mode)
{
    *Mode = 0;
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}



SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}
int collisionPP( Personne p, SDL_Surface * Masque)
{
SDL_Color col;
if(p.direction==1)//imin
col=GetPixel(Masque,p.posperso.x+p.perso->w,p.posperso.y+(p.perso->h/2));
if(p.direction==2)//isar
col=GetPixel(Masque,p.posperso.x,p.posperso.y+(p.perso->h/2));
//lfou9
//col=GetPixel(Masque,p.posperso.x+(p.perso->w/2) ,p.posperso.y); 
//louta 
   // col=GetPixel(Masque,p.posperso.x+(p.perso->w/2),p.posperso.y+p.perso->h); 
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1;
}
else return 0;

}

void initmap( minimap * m){
m->miniload=IMG_Load("miniphoto.png");
m->persomini=IMG_Load("miniperso.png");
m->posmini.x=0;
m->posmini.y=-20;
m->pospermini.x=0;
m->pospermini.y=0;
}


    void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
    {
      SDL_Rect posJoueurABS;
      posJoueurABS.x = posJoueur.x + camera.x;
      posJoueurABS.y = posJoueur.y + camera.y;
      m->pospermini.x=(posJoueurABS.x * redimensionnement/100);
      m->pospermini.y=(posJoueurABS.y * redimensionnement/100)-48;
    }



void  afficherminimap (minimap m, SDL_Surface * screen)
{
SDL_BlitSurface(m.miniload,NULL,screen,&m.posmini);
SDL_BlitSurface(m.persomini,NULL,screen,&m.pospermini);
}

    void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *police)
    {
    SDL_Surface *chrono = NULL;
    SDL_Rect positionChrono;
    SDL_Color couleur = {0,0,0};

    int min=0,sec=0;
    char texteChrono [10] = "";

    positionChrono.x = 250;
    positionChrono.y = 50;
    (*temps)=SDL_GetTicks();
    (*temps)/=1000;
    min=((*temps)/60);
    sec=(*temps) - (60*min);

    sprintf(texteChrono,"%02d:%02d",min,sec);

    chrono = TTF_RenderText_Solid(police,texteChrono,couleur);
    SDL_BlitSurface(chrono,NULL,screen,&positionChrono);
    }





/*void initialiser_score (int valscore, score *s )
{
SDL_Surface *texte1=NULL;
SDL_Surface *number1=NULL; 
TTF_Font *police=NULL;

s->police = TTF_OpenFont("text.TTF", 60);

SDL_Color couleur={0,0,0}; 


s->position_number.x=490;
s->position_number.y=300;

s->position_texte.x=340;
s->position_texte.y=300;
char texte[20];

strcpy(texte,"Score :"); //l'affichage du message score sur l ecran 

char number[20]; //tableau de chaine de c ou on va stocker la valeur du score 



sprintf(number, "%d ", valscore);
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
TTF_CloseFont(police);

}

// AFFICHAGE
/*void afficher_score(score *s,SDL_Surface *screen,int valscore)
{
SDL_Color couleur={255,255,255};
char texte[20];
strcpy(texte,"Score :"); // variable pouur l'affichage du message score sur l ecran 

char number[20]; //tableau de chaine de c ou on va stocker la valeur du score 
sprintf(number, "%d ", valscore);
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
 SDL_BlitSurface(s->texte1, NULL, screen,&s->position_texte);
SDL_BlitSurface(s->number1, NULL, screen,&s->position_number);
}*/

//UPDATE

void update_score  (int *valscore)
{
  
	(*valscore)+=5;	

}


/*void free_score( score s)
{
SDL_FreeSurface(s.texte1);
SDL_FreeSurface(s.number1);

}
*/

void Timer(int *tempsdebut)
{
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
    }
}

void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps); 
}

int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255; 

    
    T->positionText.x = 770;
    T->positionText.y = 30; 
    testload=loadFonttime(T,"police.ttf");
    T->textSurface=NULL;
    return testload;   
}

int loadFonttime(Text* T, char* path)
{
    

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->font= TTF_OpenFont(path,30);
    if (T->font == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt," time: 0%d:0%d ",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt," time: 0%d:%d ",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt," time: %d:0%d ",T->mm,T->ss);

    T->temps.textSurface=TTF_RenderText_Solid(T->temps.font,T->temps.txt,T->temps.couleurTxt);
}
void displaytime(Time T,SDL_Surface *screen)
{
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));
}

void freeTexttime(Text T)
{
    TTF_CloseFont(T.font); 
    TTF_Quit();    
}






