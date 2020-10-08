PShape flecha;

void setup() {
  size(230, 160); //Tamaño de la ventana
  flecha=createShape();

  //Se definen los vertices de la figura
  flecha.beginShape();
  flecha.vertex(20, 70);
  flecha.vertex(20, 30);
  flecha.vertex(80, 30);
  flecha.vertex(80, 10);
  flecha.vertex(120, 50);
  flecha.vertex(80, 90);
  flecha.vertex(80, 70);
  flecha.endShape();
}

void draw() {
   background(20); //Color de fondo

   stroke(255); //Color del lápiz
   shape(flecha); //Dibuja la figura

   //Se aplican las trnaformaciones. Son sucesivas
   translate(100,50);
   shape(flecha);

   rotate(radians(15));
   shape(flecha);

   scale(0.5,0.5);
   shape(flecha); 
}
