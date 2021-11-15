#include <stdio.h>
#include <stdlib.h>
#include "sumTable.h"
enum { Max = 50};
#define tam 30

Hash* tableA(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));

    for(int i=0;i<Max;i++){
      vetor[i].chave = h;
    }
  return vetor;
}

Hash* tableB(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));

    for(int i=0;i<Max;i++){
      vetor[i].chave = h;
    }
  return vetor;
}

Hash* tableC(Hash* h){ 
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));

    for(int i=0;i<Max;i++){
      vetor[i].chave = h;
    }
  return vetor;
}

int modulo(int numero){
    int resto = numero % Max;

    return resto;
}

Hash* insere(Hash* h){
    Hash* aux = h;
    
    printf("Quantos numeros quer adicionar na tabela");
    for(int i=0;i<Max;i++){
      int numero = rand() % 10;
      int mod = modulo(numero);
      printf(" mod: %d num: %d",mod,numero);
    if(aux[mod].chave == NULL){
          aux[mod].chave = numero;
          aux[mod].prox = NULL;
    }
    else if(aux[mod].chave != NULL){
      Hash* conflito = (Hash*)malloc(sizeof(Hash));

      if(conflito == NULL){
         printf("Erro: Sem espaco na memoria!");
         printf("\nPrograma encerrado por falta de memoria!");
         exit(1);
      }

      conflito->chave = numero;
      conflito->prox = NULL;

      if(aux[mod].prox == NULL ){
         aux[mod].prox = conflito;
      }
      else if(aux[mod].prox != NULL){
           Hash* atual = aux[mod].prox;
           while(atual->prox != NULL){
           atual = atual->prox;
      } 
           atual->prox = conflito;
      }
    }
}    
    return h;
}

int* imprime(Hash* h){
    Hash* aux = h,*conflito;
    
    for(int i = 0;i<Max;i++){
        printf("\nHash[%d] = %d",i,aux[i].chave);

        if(aux[i].chave != NULL){
             conflito = aux[i].prox;
             while(conflito != NULL){
                  printf("Lista:%d",conflito->chave);
                  conflito = conflito->prox;
             }
             
        }
    }
    return aux;
}

void criarLinhaSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i;
    printf("%c",201);
    for(i = 0;i<tam;i++){
        if(i == 3){
          printf("%c",203);
        }
        printf("%c",205);
    }
    printf("%c\n",187);
}

void criarLinhaRodape(int tamx){//Criar linhas duplas em baixo do Menu
    int i;
    printf("%c",200);
    for(i = 0;i<tamx;i++){
        if(i == 3){
          printf("%c",202);
        }
        printf("%c",205);
    }
    printf("%c\n",188);
}

void CriarMenu(int tamx,char str[]){//Criar linhas duplas nas laterais do Menu
   int i,contador=0;
   for(i = 0;i<tamx;i++){
       if(str[i] == '\0')
       break;
       else
          contador++;
       }
       printf("%c",186);
        for(i = 0; i<contador;i++){
            printf("%c",str[i]);
            if(i == 2)
              printf("%c",186);
        }
     while(contador<tamx){
         printf("%c",32);
         contador++;
     }
    
    printf("%c\n",186);
}

void criaLinhaHorizontal(int tamx){
    int i;
    printf("%c", 204);
    for(i=0;i<tamx;i++){
        if(i == 3){
          printf("%c", 206);
        }
        printf("%c", 205);
    }
    printf("%c\n", 185);
}

void menu(){
   system("color  06");//Define a cor do terminal (4->Fundo e 0->Cor das letras)
   printf("\n");
   criarLinhaSuperior(tam);
   CriarMenu(tam," H        TABELA HASH");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 0  Sair");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 1  CRIA AS TABELAS");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 2  INSERE NAS TABELAS");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 3  EXCLUIR CHAVE NAS TABELAS");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 4  BUSCA DE CHAVE NA TABELAS");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 5  JUNTA AS TABELAS");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 6  IMPRIME AS TABELAS");
   criarLinhaRodape(tam);
}



