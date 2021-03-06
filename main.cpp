
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>
#include "Sho.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background, *fondo_pausa;
SDL_Rect rect_background, rect_pausa;


int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1024/*WIDTH*/, 768/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    fondo_pausa = IMG_LoadTexture(renderer,"fondo_pausa.png");
    SDL_QueryTexture(fondo_pausa, NULL, NULL, &w, &h);
    rect_pausa.x = 290;
    rect_pausa.y = 270;
    rect_pausa.w = w;
    rect_pausa.h = h;


    Sho sho(renderer);
//    EnemigoAzul e(renderer);

    //Main Loop
    int frame=0;
    int animacion_sho = 0;
    bool pause=false;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        if(currentKeyStates[SDL_SCANCODE_P])
            pause=true;

        if(currentKeyStates[SDL_SCANCODE_D])
            pause=false;


        if(pause==false)
            sho.act();

        SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);

        // Clear the entire screen to our selected color.

        if(pause==false){

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, background, NULL, &rect_background);
            sho.draw(renderer);
            //e.draw(renderer);
        }else{
           SDL_RenderCopy(renderer, fondo_pausa, NULL, &rect_pausa);
        }


        SDL_RenderPresent(renderer);

        frame++;
    }

	return 0;
}




