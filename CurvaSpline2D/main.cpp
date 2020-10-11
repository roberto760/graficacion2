#include <iostream>
#include <graphics.h>

using namespace std;

void spline2D(int pc[][2], int n)
{
    float x,y,u;
    setcolor(YELLOW);
    for(int j=0; j<n; j++)
        circle(pc[j][0], pc[j][1],2);

    // Curva
    for(int i=3; i<n; i++)
    {
        for(u=0; u<1; u+=0.005)
        {
            x= (1-u)*(1-u)*(1-u)*pc[i-3][0]/6 +
               (3*u*u*u-6*u*u+4)*pc[i-2][0]/6  +
               (-3*u*u*u+3*u*u+3*u+1)*pc[i-1][0]/6 +
               u*u*u*pc[i][0]/6;

            y= (1-u)*(1-u)*(1-u)*pc[i-3][1]/6 +
               (3*u*u*u-6*u*u+4)*pc[i-2][1]/6  +
               (-3*u*u*u+3*u*u+3*u+1)*pc[i-1][1]/6 +
               u*u*u*pc[i][1]/6;
            //i%15+1 Asegura un id de color entre 1 y 15
            //i%15+1 Asegura un id de color entre 1 y 15
            putpixel(x, y, 1);
        }
    }
}

int main()
{
    int curva[10][2]=
    {

        {50,   80},
        {70,   100},
        {20,   20},
        {120,  80},
        {160, 140},
        {140, 180},
        {100, 190},
        {80,  140},
        {60,  120},
        {40,   60}
    };

    //initwindow(200,200,"Práctica Dibujar Curva Spline 2D", 200, 50);

    int gd = DETECT,gm;
    initgraph(&gd, &gm,NULL);
    spline2D(curva,10);

    /* while( !kbhit() );
    closegraph( );*/

            delay(10000);
    return 0;
}
