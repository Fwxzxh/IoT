// programa de arduino que arma una matriz aleatoria y obtiene su inversa.

#define SIZE 3  // array m

int mat[SIZE][SIZE];
int count = 0;
unsigned long tim = 0;

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));
}

void generateMatrix() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
          int x = random(9);
          mat[i][j] = x;
        }
    }
}

void printMatrix() {
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
          Serial.print(mat[i][j]);
          Serial.print(" ");
        }
        Serial.println(";");
    }
}

float finDeterminant() {
    float det = 0;
    for (int i = 0; i < SIZE; i++) {
        det = det + (mat[0][i] * 
                    (mat[1][(i + 1)%SIZE] * mat[2][(i + 2)%SIZE] - 
                    mat[1][(i + 2)%SIZE] * mat[2][(i + 1)%SIZE]));
    }
    return det;
}

void getInverse(float det) {
    for (int i=0; i<=SIZE; i++){
        for (int j=0; j< SIZE; j++){
          float n = ((mat[(j + 1)%SIZE][(i + 1)%SIZE] * mat[(j + 2)%SIZE][(i + 2)%SIZE]) -
                    (mat[(j + 1)%SIZE][(i + 2)%SIZE] * mat[(j + 2)%SIZE][(i + 1)%SIZE]))
                    / det;
          Serial.print(n);
          Serial.print(" ");
        }
      Serial.println(";");
    }
}

void loop() {
    Serial.println("as");
    generateMatrix();
    delay(4000);
    printMatrix();
    float det = finDeterminant();
    Serial.print("Determinante: ");
    Serial.println(det);
    Serial.println("Matriz inversa");
    getInverse(det);
    delay(4000);
}
