#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void dibujar(int fig[][2], int totalVertices)
{
    int i;

    for(i=0; i<totalVertices-1; i++)
        line(fig[i][0], fig[i][1], fig[i+1][0], fig[i+1][1]);

    line(fig[0][0], fig[0][1], fig[i][0], fig[i][1]);
}

void trasladar(int fig[][2], int totalVertices, int tx, int ty)
{
    int i;
    int r[totalVertices][2];

    for(i=0; i<totalVertices; i++)
    {
        r[i][0]=fig[i][0]+tx;
        r[i][1]=fig[i][1]+ty;
    }
    setcolor(GREEN);
    dibujar(r,totalVertices);
}

void rotar(int fig[][2], int totalVertices, float angulo)
{
    int i;
    int r[totalVertices][2];
    //pasar el angulo a radianes
    angulo= angulo*M_PI/180;
    for(i=0; i<totalVertices; i++)
    {
        r[i][0]=fig[i][0]*cos(angulo)-fig[i][1]*sin(angulo);
        r[i][1]=fig[i][0]*sin(angulo)+fig[i][1]*cos(angulo);
    }
    setcolor(YELLOW);
    dibujar(r,totalVertices);
}

void escala(int fig[][2], int totalVertices, float sx, float sy)
{
    int i;
    int r[totalVertices][2];

    for(i=0; i<totalVertices; i++)
    {
        r[i][0]=fig[i][0]*sx;
        r[i][1]=fig[i][1]*sy;
    }
    setcolor(LIGHTBLUE);
    dibujar(r,totalVertices);
}

void sesgarX(int fig[][2], int totalVertices, float shx)
{
    int i;
    int r[totalVertices][2];

    for(i=0; i<totalVertices; i++)
    {
        r[i][0]=fig[i][0]+fig[i][1]*shx;
        r[i][1]=fig[i][1];
    }
    setcolor(LIGHTRED);
    dibujar(r,totalVertices);
}

int main()
{
    int flecha[7][2]=
    {
        {20,  70},
        {20,  30},
        {80,  30},
        {80,  10},
        {120, 50},
        {80,  90},
        {80,  70}
    };

    initwindow(230,150,"Práctica Dibujar Imagen 2D", 200, 50);
    dibujar(flecha,7);

    // trasladar(Objeto, totalVertices, tx, ty)
    trasladar(flecha, 7, 100, 50);

    // rotar(Objeto, totalVertices, angulo)
    rotar(flecha,7, 15);

    // escala(Objeto, totalVertices, sx, sy)
    escala(flecha,7, 0.5, 0.5);

    // sesgarX(Objeto, totalVertices, shx)
    sesgarX(flecha, 7, 1.2);

    while( !kbhit() );
    closegraph( );
    return 0;
}
