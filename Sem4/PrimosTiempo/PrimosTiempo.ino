// Programa que calcula los números primos desde 1 a 30000 y mide el tiempo que tarda en buscarlos.

unsigned long time;

void setup() {
    Serial.begin(9800);
    time = millis();
}

bool isPrime(int num) {
    if (num == 0 || num == 1 || num == 4) return false;
    for (int x = 2; x < num; x ++) {
        if (num % x == 0) return false;
    }

    return true;
}

void searchPrimos(){
    for (int x = 0; x <= 3000; x++){
        if (isPrime(x)) {
            Serial.println(x);
        }
    }
}

void loop() {
    Serial.print("Inicio timer");
    Serial.println(time);
    searchPrimos();
    time = millis();
    Serial.print("Terminado en:");
    Serial.println(time);
    delay(4000);
    Serial.println("END");
}
