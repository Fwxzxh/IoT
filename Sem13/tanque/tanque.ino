// Tanque:
// Monitoreo de nivel de tanque cilíndrico en posición horizontal: 
// reportar porcentaje al que está lleno el tanque.

const int pinLectura = A0;
int valorLectura;

void setup() {
    Serial.begin(9600);
}

int calculaPorcentaje(int lectura) {
    // 1023 == 100% del tanque.
    int porcentaje = lectura * 100 / 1023;
    return porcentaje;
}

void loop() {
    // Leemos del sensor de capacidad.
    valorLectura = analogRead(pinLectura);
    // Calculamos el porcentaje deacuerdo a los valores posibles.
    int porcentaje = calculaPorcentaje(valorLectura);

    Serial.print("La cantidad actual del tanque es: ");
    Serial.print(porcentaje);
    Serial.println(" %");
}
