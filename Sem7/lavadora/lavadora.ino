// Ciclos de lavado
// Ciclo normal, Planchado permanente, Ciclo delicado, 
// llena --> Detergente --> work --> Desagua --> llena --> suavizante --> work --> Desagua ==> Seca 

enum Estados {
    Llena,
    Detergente,
    Work,
    Desagua,
    Suavizante,
    Seca
};

Estados cicloDefault[9] = {Llena, Detergente, Work, Desagua, Llena, Suavizante, Work, Desagua, Seca};
int estadoActual = 0;

void setup() {
    Serial.begin(9800);
}

void proceso(Estados estado){
    bool doneDetergent = false;
    bool doneSuavizante = false;

    switch (estado) {
        case Llena:
            Serial.println("Llenando lavadora...");
            delay(1500);
            Serial.println("Se ha llenado la lavadora.");
            break;
        
        case Detergente:
            Serial.println("La lavadora esta lista para recibir el Detergente...");
            Serial.println("Ingrese y para indicar que ya se ha agregado el detergente.");
            while (!doneDetergent) {
                String rsp = Serial.readString();
                if (rsp == "y\n") {
                    Serial.println("Agregando Detergente.");
                    doneDetergent = true;
                }
            }

            Serial.println("Detergente OK.");
            delay(1000);
            break;

        case Work:
            Serial.println("Lavando..");
            delay(4000);
            Serial.println("Se ha terminado de lavar.");
            break;

        case Desagua:
            Serial.println("Desaguando la lavadora...");
            delay(2000);
            Serial.println("Se ha terminado de desaguar.");
            break;

        case Suavizante:
            Serial.println("La lavadora esta lista para recibir el Suavizante...");
            Serial.println("Ingrese 'y'  para indicar que ya se ha agregado el Suavizante.");
            while (!doneSuavizante) {
                String rspSuavizante = Serial.readString();
                if (rspSuavizante == "y\n"){
                    Serial.println("Se esta agregando el Suavizante.");
                    doneSuavizante = false;
                }
            }

            Serial.println("Suavizante OK.");
            delay(1000);
            break;

        case Seca:
            Serial.println("Empezando el proceso de exprimido centrifugo de la ropa.");
            Serial.println("Secando...");
            delay(2000);
            Serial.println("Se ha terminado de exprimir la ropa.");
            break;
    }
}

void loop() {
    proceso(cicloDefault[estadoActual]);
    if (estadoActual < 9) {
        estadoActual++;
    }
}
