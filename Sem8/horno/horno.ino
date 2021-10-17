// horno de microondas.
// dos botones para arranque de tiempos de 5, 10 y 20.
// La puerta se bloquea durante el arranque.
// al final se desbloquea la puerta.

#define Time5 = 13
#define Time10 = 14
#define Time20 = 15
#define DoorBlock = 17

void setup() {
    Serial.begin(9600);
    pinMode(13, INPUT);
    pinMode(14, INPUT);
    pinMode(15, INPUT);
    pinMode(16, INPUT);
    pinMode(17, OUTPUT);
}

void Work(int Time) {
    Serial.println("Bloqueando puerta.");
    digitalWrite(17, HIGH);
    Serial.println("Cocinando por " + Time);
    for (int i = 0; i <= Time; i++) {
        Serial.println(".");
        delay(1000);
    }
    digitalWrite(17, LOW);
    Serial.println("Desbloqueando puerta.");
}

void loop() {
    if (digitalRead(13 == 1)) {
        Work(5);
    }
    else if (digitalRead(14 == 1)) {
        Work(10);
    }
    else if (digitalRead(15 == 1)) {
        Work(20);
    }
}
