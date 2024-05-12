#include <stdio.h>
#include <stdlib.h>

void main() {
    long long int fibo[61];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i=2; i<61; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int *vet, N;
    scanf("%d", &N);
    vet = (int*)malloc(N*sizeof(int));
    
    for (int j = 0; j<N; j++) {
        scanf("%d", &vet[j]);
    }
    
    for (int k = 0; k<N; k++) {
        printf("Fib(%d) = %lld\n", vet[k], fibo[vet[k]]);
    }
}