// Implementación de quick sort en Arduino.

#define N 100

int a[N];

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));
}

void genera() {
    int i;
    for (i=0; i<N; ++i) a[i] = random(100);
}

void imprime() {
    int i;
    for(i=0; i<N; i+=10) { // imprimir un valor cada 10 elem
        if(a[i] < 10) Serial.print(" ");
        Serial.print(a[i]); Serial.print(" ");
        if((i+10) % 100 == 0) Serial.println("");
    }

    Serial.println("");
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void loop() {
  genera();
  Serial.println("Datos originales");
  imprime();
  quickSort(a, 0,  N-1);
  Serial.println("Datos ordenados");
  imprime();
  Serial.println(" ");
  delay(4000);
}
