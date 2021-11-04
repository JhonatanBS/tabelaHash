struct sumTable{
   int chave;
   struct sumTable *prox;
};

typedef struct sumTable Hash;

Hash* tableA(Hash* h);
Hash* tableB(Hash* h);
Hash* tableC(Hash* h);
int modulo(int);
Hash* insere(Hash* h);
int* imprime(Hash* h);