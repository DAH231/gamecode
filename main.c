#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


int main ( int argc, char** argv )
{


TTF_Font *font;

SDL_Surface *ecran;
SDL_Surface *image;
SDL_Surface *image1;
SDL_Surface *image2;
SDL_Surface *image3;
SDL_Surface *image4;
SDL_Surface *imageNO;
SDL_Surface *imageYES;
SDL_Surface *imagep;
SDL_Surface *images;
SDL_Surface *imagec;
SDL_Surface *imagex;
SDL_Surface *imagesolo;
SDL_Surface *imageduo;
SDL_Surface *imagechap1;
SDL_Surface *imagechap2;
SDL_Surface *imagechap3;
SDL_Surface *imageback2;
SDL_Surface *imageyesf;
SDL_Surface *imagenof;
SDL_Surface *play; 
SDL_Surface *sett; 
SDL_Surface *cred; 
SDL_Surface *exit; 
SDL_Surface *unmute; 
SDL_Surface *f3; 
SDL_Surface *mute; 
SDL_Surface *f4;



SDL_Surface *background,*perso;
SDL_Rect posbackground;
int boucle = 0;
int jouer;
minimap m;
SDL_Rect posperso,camera;
Time temps;
int valscore=0;
char nomjoueur[20];


int quitter=1;
int Mode=0;
int detect=0;
int menu=0;
int detectp=0;
int detects=0;
int detectcr=0;
int detectx=0;
int volume=350;
int sonn=1;
int chap1=0;


SDL_Rect posp;
SDL_Rect poss;
SDL_Rect posc;
SDL_Rect posx;
SDL_Rect posf3;
SDL_Rect posunmute;
SDL_Rect posmute;
SDL_Rect posf4;
SDL_Rect posecranimg;
SDL_Rect posecranimg1;
SDL_Rect posecranimg2;
SDL_Rect posecranimg3;
SDL_Rect posecranimg4;
SDL_Rect posecranimgNO;
SDL_Rect posecranimgYES;
SDL_Rect posecranimgp;
SDL_Rect posecranimgs;
SDL_Rect posecranimgc;
SDL_Rect posecranimgx;
SDL_Rect posecransolo;
SDL_Rect posecranduo;
SDL_Rect posecranchap3;
SDL_Rect posecranchap2;
SDL_Rect posecranchap1;
SDL_Rect posecranback2;
SDL_Rect posecrannof;
SDL_Rect posecranyesf;

    background = IMG_Load("03.png");
    perso=IMG_Load("hero.png");
    posbackground.x = 0;
    posbackground.y = 0;
    initmap(  &m);
    inittemps(&temps);


    camera.x=0;
    camera.y=0;
    camera.w=0;
    camera.h=0;
    posperso.x=0;
    posperso.y=275;





SDL_Color textColor;


SDL_Event event;

SDL_Init( SDL_INIT_VIDEO) ;
SDL_Init( SDL_INIT_VIDEO| SDL_INIT_AUDIO ) ;
TTF_Init();

Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
Mix_Music *music;
Mix_Chunk *son;
son=Mix_LoadWAV("motion.wav");


if(son==NULL)
printf("%s",Mix_GetError());


	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	
	}
	
	ecran = SDL_SetVideoMode(1200, 730, 32,SDL_HWSURFACE | SDL_SRCALPHA);
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de creation de la fenetre de 300*300: %s.\n", SDL_GetError());
		return 1;
	}
	
	
	image=IMG_Load("menu.jpg");
	image1=IMG_Load("playsurfc.png");
	image2=IMG_Load("settingsbg.png");
	image3=IMG_Load("creditsbg.png");
	image4=IMG_Load("exitbg.png");
	imagep=IMG_Load("play.png");
	images=IMG_Load("settings.png");
	imagec=IMG_Load("credits.png");
	imagex=IMG_Load("exit.png");
	imageYES=IMG_Load("yesexit.png");
	imageNO=IMG_Load("noexit.png");
	imagesolo=IMG_Load("soloP.png");
	imageduo=IMG_Load("duoP.png");
	imagechap1=IMG_Load("chap1.png");
	imagechap2=IMG_Load("chap2.png");
	imagechap3=IMG_Load("chap3.png");
	imageback2=IMG_Load("back2.png");
	imagenof=IMG_Load("fullno.png");
	imageyesf=IMG_Load("fullyes.png");
		
	
	
	posecranimg.x=0;
	posecranimg.y=0;
	posecranimg.w=image->w;
	posecranimg.h=image->h;
	
	posecranimg1.x=0;
	posecranimg1.y=0;
	posecranimg1.w=image1->w;
	posecranimg1.h=image1->h;
	
	posecranimg2.x=0;
	posecranimg2.y=0;
	posecranimg2.w=image->w;
	posecranimg2.h=image->h;
	
	posecranimg3.x=0;
	posecranimg3.y=0;
	posecranimg3.w=image3->w;
	posecranimg3.h=image3->h;
	
	posecranimg4.x=0;
	posecranimg4.y=0;
	posecranimg4.w=image4->w;
	posecranimg4.h=image4->h;
	
	posecranimgp.x=204;
	posecranimgp.y=267;
	posecranimgp.w=imagep->w;
	posecranimgp.h=imagep->h;
	
	posecranimgs.x=207;
	posecranimgs.y=355;
	posecranimgs.w=images->w;
	posecranimgs.h=images->h;
	
	posecranimgc.x=204;
	posecranimgc.y=444;
	posecranimgc.w=imagec->w;
	posecranimgc.h=imagec->h;

	posecranimgx.x=205;
	posecranimgx.y=526;
	posecranimgx.w=imagex->w;
	posecranimgx.h=imagex->h;
	
	posecranimgNO.x=638;
	posecranimgNO.y=414;
	posecranimgNO.w=imageNO->w;
	posecranimgNO.h=imageNO->h;
	
	posecranimgYES.x=414;
	posecranimgYES.y=417;
	posecranimgYES.w=imageYES->w;
	posecranimgYES.h=imageYES->h;

	posecransolo.x=284;
	posecransolo.y=142;
	posecransolo.w=imagesolo->w;
	posecransolo.h=imagesolo->h;
	
	posecranduo.x=617;
	posecranduo.y=137;
	posecranduo.w=imageduo->w;
	posecranduo.h=imageduo->h;
	
	posecranchap1.x=452;
	posecranchap1.y=244;
	posecranchap1.w=imagechap1->w;
	posecranchap1.h=imagechap1->h;
	
	posecranchap2.x=450;
	posecranchap2.y=372;
	posecranchap2.w=imagechap2->w;
	posecranchap2.h=imagechap2->h;
	
	posecranchap3.x=455;
	posecranchap3.y=500;
	posecranchap3.w=imagechap3->w;
	posecranchap3.h=imagechap3->h;
	
	
	posecranback2.x=18;
	posecranback2.y=15;
	posecranback2.w=imageback2->w;
	posecranback2.h=imageback2->h;
	
	posecranyesf.x=612;
	posecranyesf.y=370;
	posecranyesf.w=imageyesf->w;
	posecranyesf.h=imageyesf->h;
	
	posecrannof.x=755;
	posecrannof.y=370;
	posecrannof.w=imagenof->w;
	posecrannof.h=imagenof->h;
	
	

	posp.x=115;
	posp.y=295;
	poss.x=115;
	poss.y=385;
	posc.x=115;
	posc.y=475;
	posx.x=107;
	posx.y=565;
	posmute.x=570;
	posmute.y=215;
	posunmute.x=700;
	posunmute.y=215;
	posf3.x=570;
	posf3.y=320;
	posf4.x=700;
	posf4.y=320;
	
	
        
        textColor.r=104;
	textColor.g=7;
	textColor.b=30;
	
	
	
	font = TTF_OpenFont( "buttonfont.otf", 20 );
	
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        initialiser_audio(music);
	

      	
      	play= TTF_RenderText_Solid(font, "Press P",textColor );
      	sett= TTF_RenderText_Solid(font, "Press S",textColor );
      	cred= TTF_RenderText_Solid(font, "Press C",textColor );
      	exit= TTF_RenderText_Solid(font, "Press ESC",textColor );
      	mute= TTF_RenderText_Solid(font, "Press '-'",textColor );
      	unmute= TTF_RenderText_Solid(font, "Press '+'",textColor );
      	f3= TTF_RenderText_Solid(font, "Press F3",textColor );
      	f4= TTF_RenderText_Solid(font, "Press F4",textColor );
      
     	if (menu==0)
     	{
     	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
     	
     	}
     	
	if (menu==1)
	{
	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
	
	}
	
	if (menu==2)
	{
	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	
	}
	
	if (menu==3)
	{
	SDL_BlitSurface(image3, NULL, ecran, &posecranimg3);
	
	}
	
	
	if (menu==4)
	{
	SDL_BlitSurface(image4, NULL, ecran, &posecranimg4);
	}

	while(quitter) 
	{
	SDL_PollEvent(&event); 
	
	switch (event.type)
         { 
        
		case SDL_QUIT: 
		quitter = 0;
        	break;
        
        
        
        	case SDL_KEYDOWN:
        	
        	switch(event.key.keysym.sym)
        	{
        	case SDLK_KP_MINUS:
        	sonn=0;
        	break;
        	
        	case SDLK_KP_PLUS:
        	sonn=1;
        	break;
        	
        	case SDLK_F3:
        	volume-=30;
        	setMusicVolume(volume);
        	break;
        	
        	case SDLK_F4:
        	volume+=30;
        	setMusicVolume(volume);
        	break;
        	
        	
        	case SDLK_ESCAPE:
        	quitter=0;
        	break;  
        	
        	case SDLK_p:
        	if (menu==0)
        	{
        	menu=1;
        	}
        	break;
        	
        	case SDLK_s:
        	if (menu==0)
        	{
        	menu=2;
        	}
        	break;
        	
        	case SDLK_c:
        	if (menu==0)
        	{
        	menu=3;
        	}
        	break;
        	
        	
        	case SDLK_SPACE:
        	if (menu==1)
        	{
        	menu=0;
        	}

        	if (menu==2)
        	{
        	menu=0;
        	}

        	if (menu==3)
        	{
        	menu=0;
        	}
        	
        	if (menu==4)
        	{
        	menu=0;
        	}
        	break;

        	}
        	
        	
        	case SDL_MOUSEMOTION:
        if (menu==0)
	{
		if (event.motion.x>=204 && event.motion.x<=404 && event.motion.y>=267 && event.motion.y<=356)
        	{
        	detect=1;
        	
        	}
        	else if (event.motion.x>=207 && event.motion.x<=407 && event.motion.y>=355 && event.motion.y<=435)
        	{
        	detect=2;
        	}
        	else if (event.motion.x>=204 && event.motion.x<=404 && event.motion.y>=444 && event.motion.y<=524)
        	{
        	detect=3;
        	}
        	else if (event.motion.x>=205 && event.motion.x<=405 && event.motion.y>=525 && event.motion.y<=605)
        	{
        	detect=4;
        	}
        	else 
        	{
        	detect=0;
        	}
	}
	if (menu==1)
	{
		if (event.motion.x>=359 && event.motion.x<=584 && event.motion.y>=196 && event.motion.y<=271)
        	{
        	detectp=1;

        	}
        	else if (event.motion.x>=599 && event.motion.x<=823 && event.motion.y>=196 && event.motion.y<=271)
        	{
        	detectp=2;
        	}
        	else if (event.motion.x>=452 && event.motion.x<=652 && event.motion.y>=244 && event.motion.y<=324)
        	{
        	detectp=3;
        	}
        	else if (event.motion.x>=450 && event.motion.x<=650 && event.motion.y>=372 && event.motion.y<=452)
        	{
        	detectp=4;
        	}
        	else if (event.motion.x>=455 && event.motion.x<=655 && event.motion.y>=500 && event.motion.y<=580)
        	{
        	detectp=5;
        	}
        	else if (event.motion.x>=18 && event.motion.x<=218 && event.motion.y>=15 && event.motion.y<=95)
        	{
        	detectp=6;
        	}
        	
	}
        if (menu==2)
	{
		if (event.motion.x>=30 && event.motion.x<=60 && event.motion.y>=30 && event.motion.y<=60)
        	{
        	detects=1;  
        	}
        	else if (event.motion.x>=30 && event.motion.x<=70 && event.motion.y>=30 && event.motion.y<=60)
        	{
        	detects=2;  
        	}
		else if (event.motion.x>=18 && event.motion.x<=218 && event.motion.y>=15 && event.motion.y<=95)
        	{
        	detects=3;  
        	}
        	else if (event.motion.x>=570 && event.motion.x<=623 && event.motion.y>=215 && event.motion.y<=285)
        	{
        	detects=4;  
        	}
        	else if (event.motion.x>=700 && event.motion.x<=752 && event.motion.y>=215 && event.motion.y<=285)
        	{
        	detects=5;   
        	}
        	else if (event.motion.x>=570 && event.motion.x<=623 && event.motion.y>=350 && event.motion.y<=400)
        	{
        	detects=6;  
        	}
        	else if (event.motion.x>=700 && event.motion.x<=752 && event.motion.y>=350 && event.motion.y<=400)
        	{
        	detects=7;  
        	}
        	else
        	{
        	detects=0;
        	}
	}
	if (menu==3)
	{
		if (event.motion.x>=18 && event.motion.x<=218 && event.motion.y>=15 && event.motion.y<=95)
        	{
        	detectcr=1;
        	}
        	else
        	{
        	detectcr=0;
        	}
	}
	if (menu==4)
	{
		if (event.motion.x>=414 && event.motion.x<=614 && event.motion.y>=417 && event.motion.y<=497)
        	{
        	detectx=1;
        	}
        	else if (event.motion.x>=638 && event.motion.x<= 838 && event.motion.y>=414 && event.motion.y<=494)
        	{
        	detectx=2;
        	}
        	else
        	{
        	detectx=0;
        	}

	}		
        	
        	
        
         	case SDL_MOUSEBUTTONDOWN:
         	
         	if (menu==0)
         	{
         	if (event.motion.x>=204 && event.motion.x<=404 && event.motion.y>=267 && event.motion.y<=356 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=1;
        	
        	}
        	if (event.motion.x>=207 && event.motion.x<=407 && event.motion.y>=355 && event.motion.y<=435 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=2;
        	}
        	if (event.motion.x>=204 && event.motion.x<=404 && event.motion.y>=444 && event.motion.y<=524 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=3;
        	}
        	if (event.motion.x>=205 && event.motion.x<=405 && event.motion.y>=525 && event.motion.y<=605 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=4;
        	}
         	}
         	
         	if (menu==1)
         	{
         	if (event.motion.x>=30 && event.motion.x<=272 && event.motion.y>=30 && event.motion.y<=93 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=0;
        	}
		if (event.motion.x>=452 && event.motion.x<=652 && event.motion.y>=244 && event.motion.y<=324 && event.button.button==SDL_BUTTON_LEFT)
		{
		chap1=1;
		}
         	}
         	
         	if (menu==2)
         	{
         	if (event.motion.x>=18 && event.motion.x<=218 && event.motion.y>=15 && event.motion.y<=95 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=0;
        	}
        	else if (event.motion.x>=30 && event.motion.x<=70 && event.motion.y>=30 && event.motion.y<=60 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	
        	SetFull(ecran, &Mode);
        	SaveScreenMode(ecran, &Mode);
        	}
        	else if (event.motion.x>=30 && event.motion.x<=70 && event.motion.y>=30 && event.motion.y<=60 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	
        	SetNorm(ecran, &Mode);
        	SaveScreenMode(ecran, &Mode);
        	}
        	else if (event.motion.x>=570 && event.motion.x<=623 && event.motion.y>=350 && event.motion.y<=400 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	volume-=30;
        	setMusicVolume(volume);
        	}
        	else if (event.motion.x>=700 && event.motion.x<=752 && event.motion.y>=350 && event.motion.y<=400 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	volume+=30;
        	setMusicVolume(volume);
        	}
        	else if (event.motion.x>=570 && event.motion.x<=623 && event.motion.y>=215 && event.motion.y<=285 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	sonn=0;
        	} 
        	else if (event.motion.x>=700 && event.motion.x<=752 && event.motion.y>=215 && event.motion.y<=285 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	sonn=1;
        	}
        	else 
        	{
        	detects=0;
        	}
        	
         	}
         	
         	if (menu==3)
         	{
         	if (event.motion.x>=18 && event.motion.x<=218 && event.motion.y>=15 && event.motion.y<=95 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=0;
        	}
         	}
         	
         	if (menu==4)
         	{
         	if (event.motion.x>=414 && event.motion.x<=614 && event.motion.y>=417 && event.motion.y<=497 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	quitter=0;
        	}
        	if (event.motion.x>=638 && event.motion.x<= 838 && event.motion.y>=414 && event.motion.y<=494 && event.button.button==SDL_BUTTON_LEFT)
        	{
        	menu=0;
        	}
         	}
         	
	 }
	if (menu==0)
	{
	if (detect==1)
	{
	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
	SDL_BlitSurface(imagep, NULL, ecran, &posecranimgp);
	SDL_BlitSurface(play, NULL, ecran, &posp);
       
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
	
	else if (detect==2)
	{
	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
	SDL_BlitSurface(images, NULL, ecran, &posecranimgs);
	SDL_BlitSurface(sett, NULL, ecran, &poss);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	
	}
	else if (detect==3)
	{
	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
	SDL_BlitSurface(imagec, NULL, ecran, &posecranimgc);
	SDL_BlitSurface(cred, NULL, ecran, &posc);
	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	
	}
	else if (detect==4)
	{
	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
	SDL_BlitSurface(imagex, NULL, ecran, &posecranimgx);
	SDL_BlitSurface(exit, NULL, ecran, &posx);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
	}
	else
	{
	SDL_BlitSurface(image, NULL, ecran, &posecranimg);
	}
	}
	
	if (menu==1)
	{
	if (detectp==1)
	{
	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
	SDL_BlitSurface(imagesolo, NULL, ecran, &posecransolo);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
	}
        else if (detectp==2)
       	{
       	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
       	SDL_BlitSurface(imageduo, NULL, ecran, &posecranduo);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detectp==3)
       	{
printf("test");
       	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
       	SDL_BlitSurface(imagechap1, NULL, ecran, &posecranchap1);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detectp==4)
    	{
    	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
       	SDL_BlitSurface(imagechap2, NULL, ecran, &posecranchap2);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detectp==5)
       	{
        SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
       	SDL_BlitSurface(imagechap3, NULL, ecran, &posecranchap3);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detectp==6)
       	{  
       	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);	
       	SDL_BlitSurface(imageback2, NULL, ecran, &posecranback2);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else 
       	{
       	SDL_BlitSurface(image1, NULL, ecran, &posecranimg1);
       	}
	}
	
        if (menu==2)
	{
	if (detects==1)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
       	SDL_BlitSurface(imagenof, NULL, ecran, &posecrannof);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detects==2)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
       	SDL_BlitSurface(imageyesf, NULL, ecran, &posecranyesf);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}		
       	else if (detects==3)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
       	SDL_BlitSurface(imageback2, NULL, ecran, &posecranback2);
        if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detects==4)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	SDL_BlitSurface(mute, NULL, ecran, &posmute);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
	}
	else if (detects==5)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	SDL_BlitSurface(unmute, NULL, ecran, &posunmute);
       	
	}
	else if (detects==6)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	SDL_BlitSurface(f3, NULL, ecran, &posf3);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
	}
	else if (detects==7)
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	SDL_BlitSurface(f4, NULL, ecran, &posf4);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
	}
       	else 
       	{
       	SDL_BlitSurface(image2, NULL, ecran, &posecranimg2);
	}
	}
	
	if (menu==3)
	{
	if (detectcr==1)
       	{
       	SDL_BlitSurface(image3, NULL, ecran, &posecranimg3);
       	SDL_BlitSurface(imageback2, NULL, ecran, &posecranback2);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
        }
        else 
        {
        SDL_BlitSurface(image3, NULL, ecran, &posecranimg3);
        }
	}


	if (menu==4)
	{
	if (detectx==1)
       	{
       	SDL_BlitSurface(image4, NULL, ecran, &posecranimg4);
       	SDL_BlitSurface(imageYES, NULL, ecran, &posecranimgYES);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else if (detectx==2)
       	{
       	SDL_BlitSurface(image4, NULL, ecran, &posecranimg4);
       	SDL_BlitSurface(imageNO, NULL, ecran, &posecranimgNO);
       	if (sonn==1)
       	{
       	Mix_PlayChannel( -1, son, 0 );
       	}
       	}
       	else 
       	{
       	SDL_BlitSurface(image4, NULL, ecran, &posecranimg4);
       	}
	}

	if (chap1==1)
	{
	while(!boucle) {

		jouer=0;			
		SDL_PollEvent(&event);
		switch (event.type)
        		 {
       				 
					case SDL_QUIT:
						 boucle = 1;
      					  break;
       					 case SDL_KEYDOWN:
        				switch(event.key.keysym.sym)
       						{
           		 			case SDLK_ESCAPE: 
						boucle =1;
           					 break;
           					 case SDLK_s:
						 update_score(&valscore);
						 jouer=1;
            					break;
           	
      			 			
       					 break;
					case SDLK_LEFT:
                			  posperso.x-=5;
               				break;
               				case SDLK_RIGHT:
                     			  posperso.x+=5;
               				break;
              				case SDLK_UP:
                      			  posperso.y-=5;
               				break;  
               				case SDLK_DOWN:
                     			 posperso.y+=5;
              				 break;  
           				 }
           				 break;


			}
				update_time(&temps);
			 	SDL_BlitSurface(background, NULL,ecran, &posbackground);
				SDL_BlitSurface(perso,NULL,ecran,&posperso);
				
				afficherminimap ( m,  ecran);
 				MAJMinimap(posperso ,  &m, camera, 16);
				displaytime(temps,ecran);
				
				SDL_Flip(ecran);
				SDL_Delay(100);


}
	}
	
	SDL_Flip(ecran);
	}
	
		
		
	SDL_FreeSurface(image);
	SDL_FreeSurface(imagep);
	SDL_FreeSurface(images);
	SDL_FreeSurface(imagec);
	SDL_FreeSurface(imagex);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);
	SDL_FreeSurface(image4);
	SDL_FreeSurface(imageYES);
	SDL_FreeSurface(imageNO);
	SDL_FreeSurface(imagechap3);
	SDL_FreeSurface(imagechap2);
	SDL_FreeSurface(imagechap1);
	SDL_FreeSurface(imageduo);
	SDL_FreeSurface(imagesolo);
	SDL_FreeSurface(imageback2);
	SDL_FreeSurface(imageyesf);
	SDL_FreeSurface(imagenof);
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_FreeSurface(play);
	SDL_FreeSurface(sett);
	SDL_FreeSurface(cred);
	SDL_FreeSurface(exit);
	SDL_FreeSurface(mute);
	SDL_FreeSurface(f3);
	SDL_FreeSurface(unmute);
	SDL_FreeSurface(f4);
	TTF_CloseFont(font);
	Mix_FreeChunk(son);
	freeTexttime(temps.temps);
	TTF_Quit();
	return 0;
}

