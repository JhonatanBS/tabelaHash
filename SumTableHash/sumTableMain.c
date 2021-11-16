#include <stdio.h>
#include <stdlib.h>
#include "sumTable.c"

int main(){
    Hash* vetorA = NULL;
    Hash* vetorB = NULL;
    Hash* vetorC = NULL;
    int escolha = 0;

    do{
       menu();
    printf("Escolha um numero do Menu:");
    scanf("%d", &escolha);

    switch(escolha){
         case 0:
             printf("Tabela Hash finalizado com sucesso");
                 break;
         case 1:
             vetorA = tableA(vetorA);
             vetorB = tableB(vetorB);
             vetorC = tableC(vetorC); 
                 break;
         case 2:
             vetorA = insere(vetorA);
                 break; 
         case 3:
             vetorA = remover(vetorA);
                 break; 
         case 4:
              busca(vetorA);
                 break;
         case 5:
           
                 break; 
         case 6:
             vetorA = imprime(vetorA);
             //vetorB = imprime(vetorB);
             //vetorC = imprime(vetorC);
                 break;                                  
    }

    }while (escolha != 0);

    return 1;
}