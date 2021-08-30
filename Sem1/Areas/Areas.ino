// Programa que obtiene las areas de superficies aleatorias

#define LIM_IZ_MIN 50
#define LIM_DER_MAX 150
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

double metodoTrapecio(double limIzq, double limDer){
    double ancho= limDer-limIzq;
    double area= ancho*(f(limIzq)+f(limDer))/2.0;
    return area;
}

double metodoTrapecioCompuesto(double limIzq, double limDer, int numPuntos){
    double paso= (limDer-limIzq)/numPuntos;
    double area= 0;
    for (int i=0; i<numPuntos-1; i++){
        area+= metodoTrapecio(limIzq+paso*i,limIzq+paso*(i+1));
    }
    return area;
}

void loop() {
  genera();
  Serial.print(" Lim izquierdo ");
  Serial.print(gLimIzq);
  Serial.print(" Lim Derecho ");
  Serial.print(gLimDer);
  Serial.print(" Numero de areas ");
  Serial.println(gNumP);
  double res = metodoTrapecioCompuesto(gLimIzq, gLimDer, gNumP);
  Serial.print(" Area total ");
  Serial.println(res);
  delay(4000);
}
