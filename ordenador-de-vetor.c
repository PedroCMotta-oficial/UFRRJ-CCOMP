/*
Código feito sem funções secundárias ou recursivas
*/ 

#include <stdio.h>

void main() {
  int vetor[10], vetor2[10];

  int menor=999, menorPos;

  for (int i=0; i<10; i++) {
    scanf("%d", &vetor[i]);
  }

  for (int j=0; j<10; j++) {
    for (int k=0; k<10; k++) {
      if (vetor[k]<menor) {
        menor = vetor[k];
        menorPos = k;
      }
    }
    vetor2[j] = menor;
    vetor[menorPos] = 999;
    menor = 999;
  }

  for (int m=0; m<10; m++) {
    printf("%d ", vetor[m]);
  }
}


/*
Código feito com funções secundárias normais, nenhuma recursiva
*/

#include <stdio.h>

int achaMenor(int j, int *vetor);
void trocaVetor(int j, int menorPos, int *vetor);

void main() {
  int vetor[10], menorPos;

  for (int i=0; i<10; i++) {
    scanf("%d", &vetor[i]);
  }

  for(int j=0; j<10;j++) {
    menorPos = achaMenor(j, vetor);
    trocaVetor(j, menorPos, vetor);
  }

  for (int l=0; l<10; l++) {
    printf("%d ", vetor[l]);
  }
}

int achaMenor(int j, int *vetor) {
  int menor=999;
  int position;
  for (int k=j; k<10; k++) {
    if (vetor[k]<menor) {
      menor = vetor[k];
      position=k;
    }
  }
  return(position);
}

void trocaVetor(int j, int menorPos, int *vetor) {
  int verde;
  verde = vetor[j];
  vetor[j] = vetor[menorPos];
  vetor[menorPos] = verde;
}



/*
Código feito com funções recursívas ou não
*/

#include <stdio.h>

int menor(int *vetor, int i, int m);

void main() {
  int vetor[10];

    for (int l=0; l<10; l++) {
        scanf("%d", &vetor[l]);
    }

  for (int j=0; j<10; j++) {
    int m = menor(vetor, 10, vetor[10]);
    for (int k=0; k<10; k++) {
        if (vetor[k] == m) {
            vetor[k] = 999;
        }
    }
    printf("%d ",m);
  }

  return 0;
}

int menor(int *vetor, int i, int m) {
  if(i < 0) {
    return m;
  }
  if(vetor[i] < m) {
    m = vetor[i];
  }
  return menor(vetor, i-1, m);
}