#include <stdio.h>
#include <stdlib.h>
#include "sumTable.h"
enum { Max = 50};

Hash* tableA(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));
  return vetor;
}

Hash* tableB(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));
  return vetor;
}

Hash* tableC(Hash* h){ 
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));
  return vetor;
}

int modulo(int numero){
    int resto = numero % Max;

    return resto;
}

Hash* insere(Hash* h){
    int numero = 101;//rand() % 1000;
    int mod = modulo(numero);
    Hash* aux = h;
    printf(" mod: %d num: %d",mod,numero);
    aux[mod].chave = numero;
    return h;
}

int* imprime(Hash* h){
    Hash* aux = h;
    for(int i = 0;i<Max;i++){
        printf("Hash[%d] = %d\n",i,aux[i].chave);
    }
    return aux;
}

