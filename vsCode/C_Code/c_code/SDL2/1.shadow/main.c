#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>

#define width 600
#define length 800

int main(int argc,char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("标题",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,length,width,SDL_WINDOW_SHOWN);
	SDL_Renderer* rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	
	SDL_Surface* personSurface = SDL_LoadBMP("小黄人.bmp");
	SDL_Surface* blackSurface = SDL_LoadBMP("背景.bmp");
	SDL_SetColorKey(personSurface,SDL_TRUE,SDL_MapRGB(personSurface->format,6,248,228));
	SDL_Texture* black = SDL_CreateTextureFromSurface(rend, blackSurface);
	SDL_Texture* person = SDL_CreateTextureFromSurface(rend, personSurface);
	
	SDL_SetTextureBlendMode(person,SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(black,SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(black,50);
	
	SDL_Rect rect;
	SDL_Rect rectwindow;
	rect.h = personSurface->h;
	rect.w = personSurface->w;
	rect.x = 0;
	rect.y = 0;
	
	rectwindow.h = width;
	rectwindow.w = length;
	rectwindow.x = 0;
	rectwindow.y = 0;
	
	bool quit = false;
	SDL_Event event;
	while(quit == false)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if(event.type == SDL_MOUSEMOTION)
			{
				rect.x = event.motion.x - rect.w/2;
				rect.y = event.motion.y - rect.h/2;
			}
		}
		
		SDL_RenderCopy(rend,black,NULL,&rectwindow);
		SDL_RenderCopy(rend,person,NULL,&rect);
		SDL_RenderPresent(rend);
		
		SDL_Delay(5);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
