float[][] flecha=
{
{20, 70, 1}, 
{20, 30, 1}, 
{80, 30, 1}, 
{80, 10, 1}, 
{120, 50, 1}, 
{80, 90, 1}, 
{80, 70, 1} };

float[][] Escala={
{0.5, 0, 0},
{0, 0.5, 0}, 
{0, 0, 1} };

float[][] Traslacion={
{1, 0, 0}, 
{0, 1, 0},
{100, 50, 1} };

float[][] Rotacion={
{ 0.966, 0.259, 0},
{-0.259, 0.966, 0},
{ 0, 0, 1} };

float[][] R={
{0, 0, 0}, 
{0, 0, 0}, 
{0, 0, 0},
{0, 0, 0},
{0, 0, 0},
{0, 0, 0},
{0, 0, 0}};

void setup() {
  size(630, 660); //Tamaño de la ventana
}

void draw() {
  background(0); //Color de fondo
  stroke(255); //Color del lápiz
  
  dibuja(flecha, 7);
  
  /*mult(flecha, Traslacion, 7);
  //dibuja(R, 7);
  //inicializa(7);
  
  mult(flecha, Rotacion, 7);
  dibuja(R, 7);
  inicializa(7);
  
  mult(flecha, Escala, 7);
  dibuja(R, 7);
  inicializa(7);*/
}


void keyPressed() {
  if (key == 'A') {
    mult(flecha, Traslacion, 7);
    dibuja(R, 7);
    inicializa(7);
  } else if (key == 'S') {
    
    mult(flecha, Traslacion, 3);
    dibuja(R, 7);
    inicializa(7);
  }
}
void mult(float[][] A, float[][] B, int n)
{
   int i, j, k;
   
   for (i=0; i<n; i++)
     for (j=0; j<3; j++)
       for (k=0; k<3; k++)
         R[i][k]+=A[i][j]*B[j][k];
}

void inicializa(int n)
{ 
  int i, j;
  for (i=0; i<n; i++)
   for (j=0; j<3; j++)
     R[i][j]=0;
}

void dibuja(float[][] X, int n)
{ 
  int i, j;
  
  for (i=0; i<n-1; i++)
    line(X[i][0], X[i][1], X[i+1][0], X[i+1][1]);
    
  line(X[0][0], X[0][1], X[i][0], X[i][1]);
}
