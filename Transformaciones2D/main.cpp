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

            delay(1000);
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

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int flecha[7][2]=
    {
        {120,  170},
        {120,  130},
        {180,  130},
        {180,  110},
        {220, 150},
        {180,  190},
        {180,  170}
    };

  //  initwindow(230,150,"Práctica Dibujar Imagen 2D", 200, 50);
/*    dibujar(flecha,7);

    // trasladar(Objeto, totalVertices, tx, ty)
    trasladar(flecha, 7, 100, 50);

    // rotar(Objeto, totalVertices, angulo)
    rotar(flecha,7, 15);

    // escala(Objeto, totalVertices, sx, sy)
    escala(flecha,7, 0.5, 0.5);

    // sesgarX(Objeto, totalVertices, shx)
    sesgarX(flecha, 7, 1.2);
//rotar(flecha,7, 18);
   */
   /* while( !kbhit() );
    closegraph( );*/


    //La instrucción \n es un salto de línea Mostrando los textos separados

   string nombre;//En esta variable estará almacenado el nombre ingresado.
   cin >> nombre; //Se lee el nombre

   int alto=0;
    dibujar(flecha,7);
   while (alto ==0 ){
        cout << "Hola! Ingrese la opcion"  << "\n";
         cin >> nombre; //Se lee el nombre
         //izquieda
       if(nombre == "A"){
          trasladar(flecha, 7, -10, 0);
        // deecha
       }else if(nombre == "S"){
          trasladar(flecha, 7, 20, 0);
        // arriba
       }else if(nombre == "Q"){
          trasladar(flecha, 7, 0, -30);
        // abajo
       }else if(nombre == "Z"){
          trasladar(flecha, 7, 0, 40);
       }else{
           alto =1;
            cout << "Gracias por usar nuestra aplicación" << "\n";
       }

    }
   //         delay(10000);
    return 0;
}
