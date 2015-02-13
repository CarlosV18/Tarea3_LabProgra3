#include "Sho.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<Iostream>

using namespace std;

Sho::Sho(SDL_Renderer* renderer)
{
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion_sho = 0;
    velocidadY = 0;
    aceleracionY = 0;
    gravedadY = 20;
}

void Sho::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sho_standing[animacion_sho], NULL, &rect);
    if(frame%300==0)
    {
        animacion_sho++;
        if(animacion_sho>=sho_standing.size())
            animacion_sho=0;
    }
    frame++;
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
   if(currentKeyStates[SDL_SCANCODE_UP])
    {
        while(rect.y>40){
            rect.y--;
            cout<<"entro al ciclo"<<endl;
            cout<<"y Up: "<<endl;
            cout<<rect.y<<endl;
        }

        if(rect.y==40){
            top=true;
        }
        cout<<"y Up: "<<endl;
        cout<<rect.y<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_LEFT] && (rect.x>-41 && rect.y==250))
    {
        rect.x--;
        cout<<"x left: "<<endl;
        cout<<rect.x<<endl;
    }

    if(top==true && rect.y!=250)
    {
        rect.y++;
        if(rect.y==250){
            top=false;
        }
        cout<<"y down: "<<endl;
        cout<<rect.y<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_RIGHT] && (rect.x<845 && rect.y==250))
    {
        rect.x++;
        cout<<"x right: "<<endl;
        cout<<rect.x<<endl;
    }

     if((currentKeyStates[SDL_SCANCODE_LEFT]&& currentKeyStates[SDL_SCANCODE_LCTRL]) && rect.x>-41)
    {
        rect.x-=2;
        cout<<"x left: "<<endl;
        cout<<rect.x<<endl;
    }

     if((currentKeyStates[SDL_SCANCODE_RIGHT] && currentKeyStates[SDL_SCANCODE_LCTRL]) && rect.x<845)
    {
        rect.x+=2;
        cout<<"x right: "<<endl;
        cout<<rect.x<<endl;
    }

    /*velocidadY+=aceleracionY;
    rect.y+=velocidadY;

    //Gravedad

    aceleracionY-=0.10;
    if(rect.y<=250){
        velocidadY=0;
        aceleracionY=0;
        rect.y=250;
    }*/

}



Sho::~Sho()
{
    //dtor
}
