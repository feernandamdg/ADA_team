#include <iostream>
#include <limits.h>
#include <ctime>
#include <iomanip>
#include <cstdio>
using namespace std;

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

int setmini(int A[], int N) {
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (A[i] < mini) {
            mini = A[i];
        }
    }
    return mini;
}

int setmaxi(int A[], int N) {
    int maxi = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
    }
    return maxi;
}

void imprimirArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void medirTiempo(int A[], int N) {
    clock_t start, end;
    double tiempo;
    
    start = clock();
    int minimo = setmini(A, N);
    end = clock();
    tiempo = double(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(10);
    cout << "Tiempo para encontrar el mínimo: " << tiempo << " segundos" << endl;
    
    start = clock();
    int maximo = setmaxi(A, N);
    end = clock();
    tiempo = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo para encontrar el máximo: " << tiempo << " segundos" << endl;
}

int main() {
    int N;
    int tipoCaso;
    
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
    
    cout << "Elemento minimo: " << setmini(A, N) << endl;
    cout << "Elemento maximo: " << setmaxi(A, N) << endl;
    
    medirTiempo(A, N);
    
    return 0;
}
