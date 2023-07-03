#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>


arvore* criarArvore(void* info) {

    arvore* novoNo = (arvore*)malloc(sizeof(arvore));
    novoNo->info = info;
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

arvore* inserirElemento(arvore* no, void* info, int parente, char pos){
    
    if (no == NULL){
        no = criarArvore(info);
        return no;
    }

    arvore* noPai = procurarElemento(no, parente);

    if (noPai == NULL){
        printf("Nó pai não encontrado, não é possível inserir.\n");
        return no;
    }

    arvore* novoNo = criarArvore(info);

    if (pos == 'e'){
        if (noPai->esq != NULL){
            printf("Posição esquerda já ocupada, não é possível inserir.\n");
            return no;
        }
        noPai->esq = novoNo;
    } else if (pos == 'd') {
        if (noPai->dir != NULL){
            printf("Posição direita já ocupada, não é possível inserir.\n");
            return no;
        }
        noPai->dir = novoNo;
    } else{
        printf("Posição inválida, não é possível inserir.\n");
        return no;
    }

    return no;
}

arvore* procurarElemento(arvore* no, int key){

    if (no == NULL || *(int*)no->info == key)
        return no;

    if (key < *(int*)no->info)
        return procurarElemento(no->esq, key);

    return procurarElemento(no->dir, key);
}

void* encontraElemento(arvore* no, int key){

    arvore* node = procurarElemento(no, key);
    if (node != NULL){
        printf("Chave encontrada: %d\n", *(int*)node->info);
        return node->info;
    }
    printf("Chave não encontrada.\n");
    return NULL;
}

int balanceada(arvore* no){

    if (no == NULL)
        return 1;

    int alturaEsq = altura(no->esq);
    int alturaDir = altura(no->dir);

    if (abs(alturaEsq - alturaDir) <= 1 && balanceada(no->esq) && balanceada(no->dir))
        return 1;

    return 0;
}

int altura(arvore* no){

    if (no == NULL)
        return 0;

    int alturaEsq = altura(no->esq);
    int alturaDir = altura(no->dir);

    return (alturaEsq > alturaDir) ? (alturaEsq + 1) : (alturaDir + 1);
}

void imprimirArvore(arvore* no){

    if (no == NULL)
        return;

    printf("%d ", *(int*)no->info);

    imprimirArvore(no->esq);
    imprimirArvore(no->dir);
}

void freeArvore(arvore* no){
  
    if (no == NULL)
        return;

    freeArvore(no->esq);
    freeArvore(no->dir);

    free(no);
}