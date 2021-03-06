struct sumTable{/*Registro que armazena e controla os elementos da tabela*/
   int chave;/*Valor que será inserido dentro tabela*/
   struct sumTable *prox;/*Ponteiro para controlar os conflitos na forma de lista*/
};

typedef struct sumTable Hash;/*Sinônimo para a struct*/
/*Funções Principais*/
Hash* tableA(Hash* h);
Hash* tableB(Hash* h);
Hash* tableC(Hash* h);
int modulo(int);
Hash* insere(Hash* h);
Hash* insereC(Hash* h,int);
Hash* remover(Hash* h);
void busca(Hash*h);
void join(Hash* C, Hash* table);
int* imprime(Hash* h);
/*Funções para o Menu*/
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);
void criaLinhaHorizontal(int tamx);
void menu();