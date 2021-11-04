// Al precionar un botón enciende 2s Lampara A
// AL precional de nuevo el botón, enciende 2s la lampara C
// AL precionar de nuevo el boton enciende 2s la lampara D.

#define LamparaA = 13
#define LamparaC = 14
#define LamparaD = 15
#define Boton = 16

int Lamparas[] = { 13, 14, 15 }
int pos = 0;

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, INPUT);
}

void Power(int lamp) {
    digitalWrite(lamp, HIGH);
    delay(2000);
}

void loop() {
    if (digitalRead(16 == 1)) {
        Power(Lamparas[pos])
        if (pos == 2) {
            pos = 0;
        }
        else {
            pos++;
        }
    }
}
