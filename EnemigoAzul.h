#ifndef ENEMIGOAZUL_H
#define ENEMIGOAZUL_H


class EnemigoAzul : public Enemigo
{
    public:
        EnemigoAzul(SDL_Renderer* renderer);
        virtual ~EnemigoAzul();

        void act()=0;
    protected:
    private:
};

#endif // ENEMIGOAZUL_H
