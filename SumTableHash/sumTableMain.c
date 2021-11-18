#include <stdio.h>
#include <stdlib.h>
#include "sumTable.c"

int main(){
    Hash* vetorA = NULL;
    Hash* vetorB = NULL;
    Hash* vetorC = NULL;
    
    int escolha = 0,opcao = 0;

    do{
       menu();
    printf("Escolha um numero do Menu:");
    scanf("%d", &opcao);

    switch(opcao){
         case 0:
             printf("Tabela Hash finalizado com sucesso");
                 break;
         case 1:
             vetorA = tableA(vetorA);
             vetorB = tableB(vetorB);
             vetorC = tableC(vetorC); 
                 break;
         case 2:
             menuInsere();
             scanf("%d",&escolha);
             
             if(escolha == 0)
                 printf("Saindo...");
             if(escolha == 1)
                 vetorA = insere(vetorA);
             else if(escolha == 2)
                 vetorB = insere(vetorB); 
             else
                 printf("Erro: Digite um valor valido na proxima vez!");       
                 break; 
         case 3:
             vetorA = remover(vetorA);
                 break; 
         case 4:
              busca(vetorA);
                 break;
         case 5:
              join(vetorC,vetorA);
              join(vetorC,vetorB);
              
              //juntaTabelas(vetorA,vetorB,vetorC); 
                 break; 
         case 6:
             vetorA = imprime(vetorA);
             vetorB = imprime(vetorB);
             vetorC = imprime(vetorC);
                 break;
        case 7:
             imprimeTabelaC(vetorC);                                            
    }

    }while (opcao != 0);

    return 1;
}