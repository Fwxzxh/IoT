// Programa que obtiene las areas de superficies aleatorias

#define LIM_IZ_MIN 0
#define LIM_DER_MAX 100
#define LIM_AREAS 100

int gLimIzq;
int gLimDer;
int gNumP;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void genera(){
  gLimIzq = random(LIM_IZ_MIN);
  gLimDer = random(LIM_DER_MAX);
  gNumP = random(LIM_AREAS);
}

double f(double x) {
  double y = -((x-7)*(x-7))+19;
  return y;
}

double calcula(double limIzq, double limDer, int numPuntos){
  double h= (limDer-limIzq)/numPuntos;
  double area= 0;
  for (int i=1; i<numPuntos-2; i++){
      area+= f(limIzq+ancho*i);
  }
  area+= h/2*(area+f(limIzq)+f(limDer))
  return area;
}

void loop() {
  genera();
  Serial.println("Lim izquierdo " + limIzq + "Lim Derecho " + limDer + " Numero de areas " + gNumP);
  res = calcula(gLimIzq, gLimDer, gNumP);
  Serial.println("Area total: " + res);
  delay(4000);
}
