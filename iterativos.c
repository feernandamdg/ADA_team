#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stockSpan(int precios[], int n, int span[]) {
    int pila[n], tope = -1;
    int iteraciones = 0; // Contador de iteraciones
    for (int i = 0; i < n; i++) {
        iteraciones++; // Incrementa por cada iteración del ciclo externo
        while (tope != -1 && precios[pila[tope]] <= precios[i]) {
            iteraciones++; // Incrementa por cada iteración del ciclo interno
            tope--;
        }
        span[i] = (tope == -1) ? (i + 1) : (i - pila[tope]);
        pila[++tope] = i;
    }
    printf("Iteraciones en el Stock Span: %d\n", iteraciones);
}

void torreHanoiIterativa(int n) {
    int movimientos = (1 << n) - 1;
    int iteraciones = 0; // Contador de iteraciones
    for (int i = 1; i <= movimientos; i++) {
        iteraciones++; // Incrementa por cada movimiento
        int desde = (i & i - 1) % 3 + 1;
        int hacia = ((i | i - 1) + 1) % 3 + 1;
        printf("Mover disco de la torre %d a la torre %d\n", desde, hacia);
    }
    printf("Iteraciones en Torre de Hanoi: %d\n", iteraciones);
}

int josephusIterativo(int n, int k) {
    int resultado = 0;
    int iteraciones = 0; // Contador de iteraciones
    for (int i = 2; i <= n; i++) {
        iteraciones++; // Incrementa por cada iteración
        resultado = (resultado + k) % i;
    }
    printf("Iteraciones en Josephus: %d\n", iteraciones);
    return resultado + 1;
}

int main() {
    int n, k;
    
    // Inicializar la semilla de números aleatorios
    srand(time(NULL));
    
    // Entrada para el problema de Stock Span
    printf("Ingrese la cantidad de precios: ");
    scanf("%d", &n);
    int precios[n], span[n];
    
    // Llenar precios aleatoriamente entre 1 y 100
    printf("Precios generados aleatoriamente: ");
    for (int i = 0; i < n; i++) {
        precios[i] = rand() % 100 + 1;
        printf("%d ", precios[i]);
    }
    printf("\n");
    
    stockSpan(precios, n, span);
    printf("Resultado del Stock Span: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");
    
    // Entrada para el problema de Torre de Hanoi
    printf("Ingrese la cantidad de discos para la Torre de Hanoi: ");
    scanf("%d", &n);
    printf("Movimientos de la Torre de Hanoi:\n");
    torreHanoiIterativa(n);
    
    // Entrada para el problema de Josephus
    printf("Ingrese la cantidad de personas en el círculo: ");
    scanf("%d", &n);
    printf("Ingrese el valor de k (cada k-ésima persona es eliminada): ");
    scanf("%d", &k);
    printf("La posición segura en el problema de Josephus es: %d\n", josephusIterativo(n, k));
    
    return 0;
}
