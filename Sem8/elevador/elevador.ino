// Elevador.
// Dos niveles.
// El elevador se bloquea cuando esta en movimiento o esperando gente.
// x f F
// f 1 2
// w 1 2
// W 2 1

#define MotorUp 13
#define MotorDown 14
#define Button1 15 // Se utiliza para llamar al elevador en la planta 1
#define Button2 16 // Llamar al elevador en la planta 2
#define Doors 17 // Puertas del elevador OFF/close ON/open

enum Estados{
    Floor,
    Working,
    Wait,
};

enum Plantas{
    Planta1,
    Planta2
};

Estados listaEstados[3] = {Floor, Wait, Working};

Estados estadoActual;
Estados estadoAnterior;

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, INPUT);
    pinMode(16, INPUT);
    pinMode(17, OUTPUT);
}

void states(Estados estado) {
    switch (estado) {
        case Floor:
            Serial.println("Elevador en Planta ");
            delay(500);
            Serial.println("Abriendo puertas...");
            digitalWrite(17, HIGH);
            Serial.println("Puertas abiertas.");
            break;

        case Working:
            Serial.println("Cerrando Puertas.");
            delay(1000);
            Serial.println("Elevador trabajando");
            delay(1000);
            break;

        case Wait:
            Serial.println("Elevador en espera...");
            Serial.print("Wating");
            for (size_t i = 0; i < 3; i++) {
                delay(1000);
                Serial.print(".");
            }
            Serial.print("\n");
            break;

        default:
            Serial.println("ERROR");
            break;
    }
}

void loop() {
    for (int i = 0; i < 3; i++){
        listaEstados[i];
        if(digitalRead(Button1) == 1 || digitalRead(Button2) == 1) {
            i ++;
            if (i == 2){
                i = 0;
            }
        }
        else {
            i == 0;
        } 
    }
}
