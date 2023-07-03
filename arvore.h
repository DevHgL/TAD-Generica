#ifndef AB_H

#define AB_H

typedef struct arvore{

  void* info;
  struct arvore *esq;
  struct  arvore *dir;
    
} arvore;

arvore* criarArvore(void *info);

arvore* inserirElemento(arvore *no, void* info, int parente,char pos);

arvore* procurarElemento(arvore *no, int key);

void* encontraElemento(arvore *no, int key);

int balanceada(arvore *no);

int altura(arvore *no);

void imprimirArvore(arvore *no);

void freeArvore(arvore *no);

#endif  // AB_H