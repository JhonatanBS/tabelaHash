/*Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include "sumTable.c"

/*Função Principal*/
int main(){
    /*Ponteiros*/
    Hash* vetorA = NULL;
    Hash* vetorB = NULL;
    Hash* vetorC = NULL;
    int escolha = 0,opcao = 0;/*Variáveis*/

    do{/*Faça*/
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
             printf("Deseja inserir em qual Tabela?");
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
             menuBusca();
             printf("Deseja remover em qual Tabela?");
             scanf("%d",&escolha);
             
             if(escolha == 0)
                 printf("Saindo...");
             if(escolha == 1)
                 vetorA = remover(vetorA);
             else if(escolha == 2)
                 vetorB = remover(vetorB);
             else if(escolha == 3)
                 vetorC = remover(vetorC);    
             else
                 printf("Erro: Digite um valor valido na proxima vez!");
                 break; 
         case 4:
             menuBusca();
             printf("Deseja buscar em qual Tabela?");
             scanf("%d",&escolha);
             
             if(escolha == 0)
                 printf("Saindo...");
             if(escolha == 1)
                 busca(vetorA);
             else if(escolha == 2)
                 busca(vetorB); 
             else if(escolha == 3)
                 busca(vetorC);    
             else
                 printf("Erro: Digite um valor valido na proxima vez!");
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

    }while (opcao != 0);/*Fim do while*/

    return 1;
}