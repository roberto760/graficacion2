#include <iostream>
#include <graphics.h>

void bezier2D(int pc[][2], int n)
{   float x,y,u;
    setcolor(YELLOW);

     // Puntos de control
     for(int i=0; i<n; i++)
        circle(pc[i][0], pc[i][1],2);

     // Curva
     for(u=0; u<1; u+=0.005)
     {
         x=
         pc[0][0]*(1-u)*(1-u)*(1-u)*(1-u)*(1-u)+
         pc[1][0]*5*u*(1-u)*(1-u)*(1-u)*(1-u)    +
         pc[2][0]*5*u*u*(1-u)*(1-u)*(1-u)         +
         pc[3][0]*5*u*u*u*(1-u)*(1-u) +
         pc[4][0]*5*u*u*u*u*(1-u) +
         pc[5][0]*u*u*u*u*u;


         y=
         pc[0][1]*(1-u)*(1-u)*(1-u)*(1-u)*(1-u)+
         pc[1][1]*5*u*(1-u)*(1-u)*(1-u)*(1-u)    +
         pc[2][1]*5*u*u*(1-u)*(1-u)*(1-u)         +
         pc[3][1]*5*u*u*u*(1-u)*(1-u) +
         pc[4][1]*5*u*u*u*u*(1-u) +
         pc[5][1]*u*u*u*u*u;

         putpixel(x, y, WHITE);
     }
}

int main()
{
    int curva [6][2]=
    {
        {10,  180},
        {40,  40},
        {160, 160},
        {180, 20},
        {310, 310},
        {340, 340}

    };

    //initwindow(200,200,"Práctica Curva de Bezier 2D", 200, 50);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    bezier2D(curva,6);

   /* while( !kbhit() );
    closegraph( );*/

            delay(10000);
    return 0;
}
