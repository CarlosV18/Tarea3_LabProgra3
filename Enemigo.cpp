#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texturas[animacion_enemigo], NULL, &rect);
    if(frame%300==0)
    {
        animacion_enemigo++;
        if(animacion_enemigo>=textruras.size())
            animacion_enemigo=0;
    }
    frame++;
}
