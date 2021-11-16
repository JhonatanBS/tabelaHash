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
    int escolha,numero,mod;

    printf("Quantos numeros quer adicionar na tabela");
    scanf("%d", &escolha);

    for(int i=0;i<escolha;i++){
      numero = rand() % 100;
      mod = modulo(numero);
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

Hash* remover(Hash* h){
     Hash* aux = h,*atual,*pos,*ant;
     int numero,mod;

     printf("Qual numero deseja excluir da Tabela?");
     scanf("%d",&numero);

     mod = modulo(numero);

    if(numero == aux[mod].chave){
       if(aux[mod].prox == NULL)
          aux[mod].chave = NULL;
       else{
          atual = aux[mod].prox;
          pos = atual->prox;
          aux[mod].chave = atual->chave;
          aux[mod].prox = pos;
       }   
       printf("\nO numero %d foi removido da Tabela Hash no indice [%d] .",numero,mod);
       
      }    
    else if(aux[mod].prox != NULL){    
          atual = aux[mod].prox;
          ant = aux;
          
          if(atual->prox == NULL){
            aux[mod].prox = NULL;
            free(atual);
            return h;
          }
          else if(atual->prox != NULL && atual->chave == numero){
            aux[mod].prox = atual->prox;
            free(atual);
            return h;
          }

          while(atual != NULL && atual->chave != numero){
            ant = atual;
            atual = atual->prox;
          }

          if(atual == NULL && ant->prox == NULL){
            printf("O elemento nao foi encontrado");
            return h;
          }
          else if(atual->prox == NULL){
            ant->prox = NULL;
            free(atual);
            return h;  
          }
          else if(atual->prox != NULL){
            ant->prox = atual->prox;
            //free(atual);
            return h;
          }
            
      // printf("O numero %d foi removido com sucesso da Tabela",numero);      
    }
    else if(aux[mod].prox == NULL && aux[mod].chave != numero)
         printf("O numero %d nao esta alocado na tabela.",numero);
     
  return h;
}

void busca(Hash*h){
    int numero,mod;
    Hash* aux = h,*atual;
    
    if(h == NULL){
       printf("Tabela Vazia");
       return h;
    }

    printf("Qual numero deseja procurar na Tabela?");
    scanf("%d",&numero);

    mod = modulo(numero);

    if(numero == aux[mod].chave)
       printf("O numero %d pertence a Tabela Hash no indice [%d]",numero,mod);
    else if(aux[mod].prox != NULL){
       atual = aux[mod].prox;
       while(atual->prox != NULL && atual->chave != numero)
             atual = atual->prox;
       if(atual->prox == NULL)     
             printf("Nao encontrado o %d na Tabela!",numero);
       else
             printf("Encontrado o numero %d na Tabela",numero);       
    }else{
      printf("O %d nao esta alocado na tabela",numero);
    }   
}

Hash* juntaTabelas(Hash* A,Hash* B,Hash* C){
    Hash *auxA = A,*auxB = B;
    
    if(A == NULL || B == NULL){
      printf("Por favor, insera valores nas duas tabelas!");
      return C;
    }

    for(int i=0;i<Max;i++){
       if(A[i].chave != NULL){
            C[i].chave = A[i].chave;
            C[i].prox = NULL;
       }
    }
      
}

int* imprime(Hash* h){
    Hash* aux = h,*conflito;
    
       if(h == NULL){
           printf("Tabela Vazia");
       return h;
    }

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

void menuInsere(){
   
   printf("\n");
   criarLinhaSuperior(tam);
   CriarMenu(tam," ?       TABELAS ");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 0  Sair");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 1  TABELA A");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 2  TABELA B");
   criarLinhaRodape(tam);

   printf("Deseja inserir em qual Tabela?");
}


