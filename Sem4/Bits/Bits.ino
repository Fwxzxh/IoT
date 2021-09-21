// Programa que cuenta los bits en una palabra.

void setup() {
    Serial.begin(9600);
}

void loop() {
    int num = random(32000);

    int bits[8] = {};

    for (int i = 8; i > 0; i--) {
        bits[i] = num%2;
        num=num/2;
    }

    int count = 0;
    for (int i = 0; i <= 8; i++) {
        if (bits[i] == 1) {
            count++;
        }
    }

    Serial.print(count);
    Serial.println(" bits valen 1");
    delay(4000);
}
