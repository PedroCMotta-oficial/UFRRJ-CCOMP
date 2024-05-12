// Importar as bibliotecas necessárias para a execução do programa
#include <stdio.h>
#include <stdlib.h>

void main() {
    // Criação de todo o fibonnaci até o 60ésimo número
    long long int fibo[61];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i=2; i<61; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    // criação de um vetor secundário
    int *vet, N;
    scanf("%d", &N);
    vet = (int*)malloc(N*sizeof(int));

    // alocação dos dados no vetor secundário manualmente
    for (int j = 0; j<N; j++) {
        scanf("%d", &vet[j]);
    }

    // print do que foi pedido no exercício
    for (int k = 0; k<N; k++) {
        printf("Fib(%d) = %lld\n", vet[k], fibo[vet[k]]);
    }
}
