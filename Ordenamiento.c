#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

// Función para imprimir los primeros N elementos de un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0)  // Imprimir en filas de 20 números
            printf("\n");
    }
    printf("\n");
}

// Función para copiar un arreglo
void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// Algoritmo de ordenamiento Burbuja
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Algoritmo de ordenamiento por Selección
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Algoritmo de ordenamiento Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int original[SIZE], arr[SIZE];
    srand(time(NULL));
    
    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 100000;
    }

    // Mostrar los primeros 100 elementos del arreglo original
    printf("Arreglo original (primeros 100 elementos):\n");
    imprimirArreglo(original, 10000);
    
    // Ordenamiento con Bubble Sort
    copiarArreglo(original, arr, SIZE);
    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();
    printf("Bubble Sort: %.4f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Ordenamiento con Selection Sort
    copiarArreglo(original, arr, SIZE);
    start = clock();
    selectionSort(arr, SIZE);
    end = clock();
    printf("Selection Sort: %.4f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Ordenamiento con Shell Sort
    copiarArreglo(original, arr, SIZE);
    start = clock();
    shellSort(arr, SIZE);
    end = clock();
    printf("Shell Sort: %.4f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
