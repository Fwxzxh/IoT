// Programa que mide el tiempo que se preciona un boton.

#define buttonPin 2 // pin del boton

int buttonState = 0;     // estado actual del boton
int lastButtonState = 0; // estado anterior del boton
int startPressed = 0;    // el momento en el cual el boton fue apretado
int endPressed = 0;      // el momento en cual el boton fue soltado.
int holdTime = 0;        // el tiempo en el cual el boton fue apretado
int idleTime = 0;        // el tiempo en el cual el boton no fue apretado.

void setup() {
    pinMode(buttonPin, INPUT);
    Serial.begin(9800);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    
    if (buttonState != lastButtonState) {
        updateState();
    }
    
    lastButtonState = buttonState;
}

void updateState() {
    if (buttonState == HIGH) {
        // el boton fue precionado
        startPressed = millis();
        idleTime = startPressed - endPressed;
    }
    else {
        // el boton acaba de ser soltado.
        endPressed = millis();
        holdTime = endPressed - startPressed;
        
        Serial.print("Tiempo precionado: ");
        Serial.println(holdTime);
    }
}
