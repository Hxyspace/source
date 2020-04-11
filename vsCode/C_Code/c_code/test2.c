#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>

#define width 600
#define length 800

int main(int argc,char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,length,width,SDL_WINDOW_SHOWN);
    SDL_Renderer* rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);



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
            else if(event.type == type)
            {
                /* data */
            }
        }

        SDL_RenderPresent(rend);  //显示rend

        SDL_Delay(5);     //延时，减轻cpu负担
    }
    SDL_DestroyWindow(window);  //删除窗口
    SDL_Quit();
    return 0;
}