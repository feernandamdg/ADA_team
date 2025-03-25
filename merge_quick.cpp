#include <iostream>
#include <limits.h>
#include <ctime>
#include <iomanip>
#include <cstdio>
#include <vector>
using namespace std;

// Funciones para generar los casos
void array_Mejorcaso(int A[], int N) {
    for (int i = 0; i < N; i++) {
        A[i] = i + 1; // Orden ascendente (mejor caso para algoritmos como Quicksort)
    }
}

void array_Casomedio(int A[], int N) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100000; // Números aleatorios (caso medio)
    }
}

void array_Peorcaso(int A[], int N) {
    for (int i = 0; i < N; i++) {
        A[i] = N - i; // Orden descendente (peor caso para algoritmos como Quicksort)
    }
}

// Algoritmo MergeSort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Algoritmo QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir el arreglo
void imprimirArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Función para medir el tiempo de ejecución de un algoritmo
void medirTiempo(int A[], int N, void (*sortFunction)(vector<int>&, int, int)) {
    clock_t start, end;
    double tiempo;
    
    // Convertir el arreglo A a un vector
    vector<int> arr(A, A + N);
    
    start = clock();
    sortFunction(arr, 0, N - 1);  // Usar el algoritmo de ordenamiento
    end = clock();
    tiempo = double(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(10);
    cout << "Tiempo de ordenamiento: " << tiempo << " segundos" << endl;
    
    // Imprimir el arreglo ya ordenado
    cout << "Array ordenado: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    int tipoCaso, algoritmo;
    
    cout << "Dime de cuantos numeros es tu array: ";
    cin >> N;
    
    int A[N];
    
    cout << "Elige el caso para el array: " << endl;
    cout << "1 - Mejor caso (orden ascendente)" << endl;
    cout << "2 - Caso medio (valores aleatorios)" << endl;
    cout << "3 - Peor caso (orden descendente)" << endl;
    cin >> tipoCaso;
    
    switch (tipoCaso) {
        case 1:
            array_Mejorcaso(A, N);
            break;
        case 2:
            array_Casomedio(A, N);
            break;
        case 3:
            array_Peorcaso(A, N);
            break;
        default:
            cout << "Opcion no valida. Se generara un caso medio por defecto." << endl;
            array_Casomedio(A, N);
    }
    
    cout << "Array generado: ";
    imprimirArray(A, N);
    
    // Elegir el algoritmo de ordenamiento
    cout << "Elige el algoritmo de ordenamiento: " << endl;
    cout << "1 - QuickSort" << endl;
    cout << "2 - MergeSort" << endl;
    cin >> algoritmo;
    
    // Medir el tiempo usando el algoritmo elegido
    if (algoritmo == 1) {
        cout << "Ordenando con QuickSort..." << endl;
        medirTiempo(A, N, quickSort);
    } else if (algoritmo == 2) {
        cout << "Ordenando con MergeSort..." << endl;
        medirTiempo(A, N, mergeSort);
    } else {
        cout << "Opcion no valida. Se utilizara MergeSort por defecto." << endl;
        medirTiempo(A, N, mergeSort);
    }
    
    return 0;
}
