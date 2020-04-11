#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>

#define width 600
#define length 800

int main(int argc,char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);	//初始化
	
	//创建SDL窗口
	SDL_Window* window = SDL_CreateWindow("标题",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,length,width,SDL_WINDOW_SHOWN);
	
	SDL_Renderer* rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);	//创建renderer，所有画图都是在renderer上画
	
	SDL_Surface* personSurface = SDL_LoadBMP("小黄人.bmp");			//加载图片
	SDL_Surface* blackSurface = SDL_LoadBMP("背景.bmp");
	SDL_SetColorKey(personSurface,SDL_TRUE,SDL_MapRGB(personSurface->format,6,248,228));		//把图片中指定颜色设置成透明
	
	//把图片转成Texture,用于添加到rend上面
	SDL_Texture* black = SDL_CreateTextureFromSurface(rend, blackSurface);
	SDL_Texture* person = SDL_CreateTextureFromSurface(rend, personSurface);
	
	SDL_SetTextureBlendMode(person,SDL_BLENDMODE_BLEND);		//设置模式 ，SDL_BLENDMODE_BLEND支持半透明
	SDL_SetTextureBlendMode(black,SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(black,50);		//透明度
	
	SDL_Rect rect;			//定义方形变量
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
	SDL_Event event;	//创建事件
	while(quit == false)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)		//关闭窗口事件
			{
				quit = true;
			}
			else if(event.type == SDL_MOUSEMOTION)	//鼠标移动事件
			{
				rect.x = event.motion.x - rect.w/2;
				rect.y = event.motion.y - rect.h/2;
			}
		}
		
		SDL_RenderCopy(rend,black,NULL,&rectwindow);		//把图片复制到rend上
		SDL_RenderCopy(rend,person,NULL,&rect);
		SDL_RenderPresent(rend);						//显示rend
		
		SDL_Delay(5);		//延时，减轻cpu负担
	}
	SDL_DestroyWindow(window);		//删除窗口
	SDL_Quit();
	return 0;
}
