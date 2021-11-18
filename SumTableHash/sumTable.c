/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "sumTable.h"
/*Constantes*/
enum { Max = 50};
#define tam 30

/*Função que gera a tabela A*/
Hash* tableA(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));/*Gera um vetor com 50 posições*/

    for(int i=0;i<Max;i++){/*Percorre toda a tabela*/
      vetor[i].chave = h;/*Faz todas as posições do vetor receberem NULL*/
    }
  return vetor;/*Retorna a tabela A como um vetor*/
}

/*Função que gera a tabela B*/
Hash* tableB(Hash* h){
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));/*Gera um vetor com 50 posições*/

    for(int i=0;i<Max;i++){/*Percorre toda a tabela*/
      vetor[i].chave = h;/*Faz todas as posições do vetor receberem NULL*/
    }
  return vetor;/*Retorna a tabela B como um vetor*/
}

/*Função que gera a tabela C*/
Hash* tableC(Hash* h){ 
    Hash* vetor = (Hash*)calloc(Max,sizeof(Hash));/*Gera um vetor com 50 posições*/

    for(int i=0;i<Max;i++){/*Percorre toda a tabela*/
      vetor[i].chave = h;/*Faz todas as posições do vetor receberem NULL*/
    }
  return vetor;/*Retorna a tabela C como um vetor*/
}
/*Função que calcula e pega o resto da divisão*/
int modulo(int numero){
    int resto = numero % Max;/*Pega o número aleatório e divide ele pelo tamanho do vetor*/

    return resto;/*Retorna o resto da divisão*/
}

/*Função que insere valores dentro da posição do vetor e nas listas*/
Hash* insere(Hash* h){
    Hash* aux = h;/*Ponteiro auxiliar que apontar para a tabela*/
    int escolha,numero,mod;/*Variáveis*/
    
    /*Pergunta ao usuário quantos numeros quer inserir na tabela*/
    printf("\nQuantos numeros quer adicionar na tabela?");
    scanf("%d", &escolha);

    for(int i=0;i<escolha;i++){/*Percorre até o limite escolhido pelo o usuário*/
      numero = rand() % 100;/*Faz a variavel receber um número aleatório*/
      mod = modulo(numero);/*Recebe o resto da divisão do número aleatório*/
      
    if(aux[mod].chave == NULL){/*Se for NULL, não tem nenhum valor dentro do indice i do vetor*/
          aux[mod].chave = numero;/*Faz a tabela no indice i(resto) receber o número*/
          aux[mod].prox = NULL;/*Faz a posição i tabela apontar para NULL*/
    }
    else if(aux[mod].chave != NULL){/*Se não for NULL, significa que existe elemento dentro da posição i da tabela*/
      Hash* conflito = (Hash*)malloc(sizeof(Hash));/*Aloca um espaço na memória*/

      if(conflito == NULL){/*Verifica se alocação foi feita*/
         printf("Erro: Sem espaco na memoria!");
         printf("\nPrograma encerrado por falta de memoria!");
         exit(1);
      }
      
      conflito->chave = numero;/*Faz o elemento da lista receber um valor*/
      conflito->prox = NULL;/*O elemento aponta para NULL*/

      if(aux[mod].prox == NULL ){/*Se for NULL, a tabela não tem nenhum conflito*/
         aux[mod].prox = conflito;/*Faz a tabela no indice i, apontar para o primeiro conflito*/
      }
      else if(aux[mod].prox != NULL){/*Se não for NULL, tabela possui conflitos */
           Hash* atual = aux[mod].prox;/*Cria um ponteiro auxiliar e faz ele apontar para o primeiro conflito da tabela*/
           while(atual->prox != NULL){/*Percorre a lista ate chegar na ultima posição da lista*/
           atual = atual->prox;/*Faz o ponteiro avançar*/
      } 
           atual->prox = conflito;/*O ultimo elemento da lista aponta para o novo conflito gerado*/
      }
    }
}    
    return h;/*Retorna a tabela*/
}
/*Função auxiliar para ajudar na inserção das dua tabelas em C*/
Hash* insereC(Hash* h,int numero){
    Hash* aux = h;/*Ponteiro auxiliar que apontar para a tabela*/
    int mod;/*Variável*/

    mod = modulo(numero);/*Recebe o resto da divisão do número aleatório*/
      
    if(aux[mod].chave == NULL){/*Se for NULL, não tem nenhum valor dentro do indice i do vetor*/
          aux[mod].chave = numero;/*Faz a tabela no indice i(resto) receber o número*/
          aux[mod].prox = NULL;/*Faz a posição i tabela apontar para NULL*/
    }
    else if(aux[mod].chave != NULL){/*Se não for NULL, significa que existe elemento dentro da posição i da tabela*/
      Hash* conflito = (Hash*)malloc(sizeof(Hash));/*Aloca um espaço na memória*/

      if(conflito == NULL){/*Verifica se alocação foi feita com sucesso*/
         printf("Erro: Sem espaco na memoria!");
         printf("\nPrograma encerrado por falta de memoria!");
         exit(1);
      }

      conflito->chave = numero;/*Faz o elemento da lista receber um valor*/
      conflito->prox = NULL;/*Faz a tabela no indice i, apontar para o primeiro conflito*/

      if(aux[mod].prox == NULL ){/*Se for NULL, a tabela não tem nenhum conflito*/
         aux[mod].prox = conflito;/*Faz a tabela no indice i, apontar para o primeiro conflito*/
      }
      else if(aux[mod].prox != NULL){/*Se não for NULL, tabela possui conflitos */
           Hash* atual = aux[mod].prox;/*Cria um ponteiro auxiliar e faz ele apontar para o primeiro conflito da tabela*/
           while(atual->prox != NULL){/*Percorre a lista ate chegar na ultima posição da lista*/
           atual = atual->prox;/*Faz o ponteiro avançar*/
      } 
           atual->prox = conflito;/*O ultimo elemento da lista aponta para o novo conflito gerado*/
      }
    }
   
    return h;/*Retorna a tabela*/
}

/*Função que remove qualquer valor da tabela, seja conflito ou não*/
Hash* remover(Hash* h){
     Hash* aux = h,*atual,*pos,*ant;/*Ponteiros Auxialiares para manipulaçaõ*/
     int numero,mod;/*Variáveis*/
     
    if(h == NULL){/*Sem valores na tabela*/
       printf("Tabela Vazia");
       return h;
    }

     /*Pergunta ao usuário qual valor quer excluir da tabela*/
     printf("\nQual numero deseja excluir da Tabela?");
     scanf("%d",&numero);

     mod = modulo(numero);/*Recebe o resto do valor escolhido*/

    if(numero == aux[mod].chave){/*Se o valor que o usuário escolheu está nos indices do vetor*/
       if(aux[mod].prox == NULL)/*Se o valor que quero excluir não tiver conflitos*/
          aux[mod].chave = NULL;/*Faz a posição do vetor receber NULL*/
       else{/*Caso Tenha Conflitos*/
          atual = aux[mod].prox;/*Faz o ponteiro para o conflito ou a primeira posição da lista*/
          pos = atual->prox;/*Faz o ponteiro apontar para o segundo conflito da lista*/
          aux[mod].chave = atual->chave;/*Faz o vetor no indice i receber o valor do primeiro conflito*/
          aux[mod].prox = pos;/*O vetor no indice i aponta para o segundo conflito*/
       }   
       printf("\nO numero %d foi removido da Tabela Hash no indice [%d] .",numero,mod);
       
      }    
    else if(aux[mod].prox != NULL){/*Se não for NULL, que dizer que existe conflitos dentro do meu vetor no indice i*/
          atual = aux[mod].prox;/*Ponteiro aponta para o primeiro conflito ou lista do vetor no indice i*/
          ant = aux;/*Ponteiro aponta para a tabela*/
          
          if(atual->prox == NULL && atual->chave == numero){/*Se for igual a NULL e o valor que está no conflito for igual o que o usuario*/
            aux[mod].prox = NULL;/*Vetor indice i recebe NULL*/
            free(atual);/*Libera o conflito*/
            return h;/*Retorna a tabela*/
          }
          else if(atual->prox != NULL && atual->chave == numero){/*Se não for NULL, existe mais de um conflito*/
            aux[mod].prox = atual->prox;/*O indice i aponta para o segundo conflito da lista*/
            free(atual);/*Libera o primeiro conflito*/
            return h;/*Retorna a tabela*/
          }

          while(atual != NULL && atual->chave != numero){/*Percorre até achar o número para excluir*/
            ant = atual;/*Guarda o atual*/
            atual = atual->prox;/*Guarda o posterior*/
          }

          if(atual == NULL && ant->prox == NULL){/*Se atual chegar até NULL, o elemento não está na tabela*/
            printf("O elemento nao foi encontrado");
            return h;/*Retorna a tabela*/
          }
          else if(atual->prox == NULL){/*Exclui o ultimo elemento da lista*/
            ant->prox = NULL;/*Ponteiro anterior aponta para NULL*/
            free(atual);/*Libera o ultimo conflito*/
            return h;  /*Retorna a tabela*/
          }
          else if(atual->prox != NULL){/*Remove o elemento no meio da lista ou conflito*/
            ant->prox = atual->prox;/*O ponteiro anterior aponta para o ponteiro posterior*/
            return h;/*Retorna a tabela*/
          }
            
          
    }
    else if(aux[mod].prox == NULL && aux[mod].chave != numero)/*Caso o elemento não esteja na tabela*/
         printf("O numero %d nao esta alocado na tabela.",numero);
     
  return h;/*Retorna a tabela*/
}

/*Função que busca algum valor na tabela*/
void busca(Hash*h){
    int numero,mod;/*variáveis*/
    Hash* aux = h,*atual;/*Ponteiros auxiliares*/
    
    if(h == NULL){/*Sem valores na tabela*/
       printf("Tabela Vazia");
       return h;
    }
    
    /*Pergunta ao usuário qual valor buscar na tabela*/
    printf("\nQual numero deseja procurar na Tabela?");
    scanf("%d",&numero);

    mod = modulo(numero);/*Guarda o resto do número de busca*/

    if(numero == aux[mod].chave)/*O número está nos indice i do vetor*/
       printf("O numero %d pertence a Tabela Hash no indice [%d]",numero,mod);
    else if(aux[mod].prox != NULL){/*O número para busca esta nos conflitos*/
       atual = aux[mod].prox;/*Ponteiro aponta para o primeiro conflito ou lista*/

       while(atual->prox != NULL && atual->chave != numero)/*Percorre até achar o valor de busca*/
             atual = atual->prox;/*Avançando até o último valor*/

       if(atual->prox == NULL)/*Se o ponteiro chegar no final, o valor não foi encontrado*/     
             printf("Nao encontrado o %d na Tabela!",numero);
       else/*Valor encontrado*/
             printf("Encontrado o numero %d na Tabela",numero);       
    }else{/*Não existe o valor*/
      printf("O %d nao esta alocado na tabela",numero);
    }   
}

/*void juntaTabelas(Hash* A,Hash* B,Hash* C){
     Hash *auxA = A,*auxB = B;
         if(A == NULL || B == NULL){
           printf("Por favor, insera valores nas duas tabelas!");
               return C;
                                   }

   for(int i=0;i<Max;i++){
       if(A[i].chave != NULL){
           C[i].chave = A[i].chave;
           C[i].prox = NULL;

           if(A[i].prox != NULL){
             auxA = A[i].prox;

               while (auxA != NULL){
                 Hash* conflitoA = (Hash*)malloc(sizeof(Hash));

                   conflitoA->chave = auxA->chave;
                   conflitoA->prox = NULL;

                   if(C[i].prox == NULL ){
                     C[i].prox = conflitoA;
                                         }
                   else if(C[i].prox != NULL){
                     Hash* atual = C[i].prox;
                         while(atual->prox != NULL)
                           atual = atual->prox;
               
                           atual->prox = conflitoA;
                                             }
                             auxA = auxA->prox;
                                     }
         
                                }     
       }
       
       int contador = 0;
       if(B[i].chave != NULL){//Verifica se na posição i do vetor existe algum valor
           if(C[i].chave == NULL){
             C[i].chave = B[i].chave;
             C[i].prox = NULL;
             contador++;
           }
           if(B[i].prox != NULL){
           if(C[i].chave != NULL){
             
             
              auxB = B[i].prox;

               while (auxB != NULL){
                 Hash* conflitoB = (Hash*)malloc(sizeof(Hash));
                   
                   if(contador == 0){
                     conflitoB->chave = B[i].chave;
                     conflitoB->prox = NULL;
                   }
                   else{
                   conflitoB->chave = auxB->chave;
                   conflitoB->prox = NULL;
                   
                   }

                   if(C[i].prox == NULL ){
                     C[i].prox = conflitoB;
                                         }
                   else if(C[i].prox != NULL){
                     Hash* atual = C[i].prox;
                         while(atual->prox != NULL)
                           atual = atual->prox;
               
                           atual->prox = conflitoB;
                                             }
                             auxB = auxB->prox;
                                     }
         
                                } 
           }

    
       }                    
   }
}*/

/*Função que pega os elementos da tabela e aplica na tabela C*/
void join(Hash* C, Hash* table){

  for(int i = 0; i < Max;i++){/*Percorre cada indice da tabela C*/
         Hash* auxTable = table[i].prox;/*Ponteiro aponta para o primeiro conflito*/
         
         if(table[i].chave != NULL){/*Verifica se a tabela possui elementos*/

            C = insereC(C,table[i].chave);/*Insere no primeiro valor do indice i da tabela C*/
           
         while(auxTable != NULL){/*Percorre todos os conflitos da tabela para inserção na tabela C*/
           C = insereC(C,auxTable->chave);/*Insere os conflitos*/
           auxTable = auxTable->prox;/*Avança até chegar no último*/
         }
         }
          
  }

}

/*Função que imprime as tabelas*/
int* imprime(Hash* h){
    Hash* aux = h,*conflito;/*Ponteiros auxiliares*/
    
       if(h == NULL){/*Verifica se a tabela está vazia*/
           printf("Tabela Vazia");
       return h;/*Retorna a tabela*/
    }

    for(int i = 0;i<Max;i++){
        printf("\nHash[%d] = %d",i,aux[i].chave);

        if(aux[i].prox != NULL){
             conflito = aux[i].prox;
             while(conflito != NULL){
                  printf("Lista:%d",conflito->chave);
                  conflito = conflito->prox;
             }
             
        }
    }
    printf("\n");
    return aux;
}

void superiorC(int cima){
     int i =0;
     
         printf("%c",218);
     for(int i = 0;i<cima;i++){
        
        printf("%c",196);
    }    
         printf("%c\n",191);
}

void inferiorC(int baixo){
    int i;
    printf("%c",192);
    for(i = 0;i<baixo;i++){
        printf("%c",196);
    }
    printf("%c\n",217);
}

void horizontalC(int reto){
    int i;
    printf("%c", 195);
    for(i=0;i<reto;i++){
        printf("%c", 196);
    }
    printf("%c\n", 180);
}

void imprimeTabela(Hash* C){
    Hash* conflito;

           if(C == NULL){/*Verifica se a tabela está vazia*/
           printf("Tabela Vazia");
       return C;/*Retorna a tabela*/
    }
    superiorC(10);
    for(int i = 0; i<Max;i++){
       printf("%c",186);
       printf("    %d",C[i].chave);
       if(C[i].chave >= 0 && C[i].chave <= 9)
           printf("     ");
       else if(C[i].chave >= 10 && C[i].chave <= 99)
           printf("    ");
       else if(C[i].chave >= 110 && C[i].chave <= 999)
           printf("   ");        
       printf("%c",186);
       if(C[i].chave != NULL){
             conflito = C[i].prox;
             while(conflito != NULL){
                  printf(" -> %d",conflito->chave);
                  conflito = conflito->prox;
             }
             printf(" -> NULL");
       }
       printf("\n");
       horizontalC(10);
    }
    inferiorC(10);
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
}

void menuBusca(){
   printf("\n");
   criarLinhaSuperior(tam);
   CriarMenu(tam," ?       TABELAS ");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 0  Sair");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 1  TABELA A");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 2  TABELA B");
   criaLinhaHorizontal(tam);
   CriarMenu(tam," 3  TABELA C");
   criarLinhaRodape(tam);
}


