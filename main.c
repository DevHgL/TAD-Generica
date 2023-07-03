#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void exibirMenu(){

    printf("Escolha uma opcao:\n");
    printf("1. Inserir elemento\n");
    printf("2. Verificar se um elemento existe\n");
    printf("3. Buscar um elemento\n");
    printf("4. Verificar se a Arvore e balanceada\n");
    printf("5. Calcular a altura da Arvore\n");
    printf("6. Imprimir a Arvore em largura\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

int main(){

    arvore* raiz = NULL;

    int opcao = -1;
    while (opcao != 0){

        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){

            case 1:{

                int* info = (int*)malloc(sizeof(int));
                int parente;
                char pos;
                printf("Digite o valor do elemento a ser inserido: ");
                scanf("%d", info);
                printf("Digite o valor do no pai (-1 para o primeiro elemento): ");
                scanf("%d", &parente);
                printf("Digite a posicao ('e' para esquerda, 'd'para direita): ");
                scanf(" %c", &pos);

                raiz = inserirElemento(raiz, info, parente, pos);
                break;
            }
            case 2:{

                int key;
                printf("Digite a chave do elemento a ser verificado: ");
                scanf("%d", &key);

                arvore* elemento = procurarElemento(raiz, key);
                if (elemento != NULL) {
                    printf("O elemento com chave %d existe na arvore.\n", key);
                } else {
                    printf("O elemento com chave %d nao existe na arvore.\n", key);
                }
                break;
            }
            case 3:{

                int key;
                printf("Digite a chave do elemento a ser buscado: ");
                scanf("%d", &key);

                void* elemento = encontraElemento(raiz, key);
                break;
            }
            case 4:{

                if (balanceada(raiz)){

                    printf("A arvore e balanceada.\n");
                } else {
                    printf("A arvore nao e balanceada.\n");
                }
                break;
            }
            case 5:{
              
                int alt = altura(raiz);
                printf("Altura da Arvore: %d\n", alt);
                break;
            }
            case 6:{
              
                printf("Arvore em largura: ");
                imprimirArvore(raiz);
                printf("\n");
                break;
            }
            case 0:{

                printf("Saindo do programa.\n");
                break;
            }
            default:{

                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }

        printf("\n");
    }

    freeArvore(raiz);

    return 0;
}
