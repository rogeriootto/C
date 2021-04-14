#include <stdio.h>
#include <stdlib.h>

typedef struct P{

    int dado;
    struct P *next;

} P;

typedef struct {

    P *start;
    int tamanho;

}Lista;

void insereInicio (Lista *lista);
void imprimeLista(Lista *lista);
void insereFim(Lista *lista);
void limpa(Lista *lista);

int main () {

    Lista lista;
    int sel;
    lista.start = NULL;
    lista.tamanho = 0;


    do {

        printf("\nMenu do programa:\n");
        printf("1- Inserir no inicio;\n");
        printf("2- Inserir no Final;\n");
        printf("3- Printar;\n");
        printf("4- Sair;\n");
        scanf("%d", &sel);
        getchar();

        switch (sel) {

            case 1:
                insereInicio(&lista);
                break;

            case 2:
                insereFim(&lista);
                break;

            case 3:
                imprimeLista(&lista);
                break;

            case 4:
                limpa(&lista);
                break;

            default:
                printf("Digite um valor valido;\n");
        }

    }while(sel != 4);
}

void insereInicio (Lista *lista) {

    int aux;

    P *pNovo;
    pNovo = (P*)malloc(sizeof(P));

    scanf("%d", &aux);
    pNovo->dado = aux;
    pNovo->next = lista->start;
    lista->start = pNovo;
    lista->tamanho++;

}

void imprimeLista(Lista *lista) {

    P *pStart = lista->start;

    printf("\n");
    while(pStart != NULL) {
        printf("%d; ", pStart->dado);
        pStart = pStart->next;
    }
    printf("\n");

}

void insereFim(Lista *lista) {

    int aux;

    P *pNovo, *auxiliar;
    pNovo = (P*)malloc(sizeof(P));

    scanf("%d", &aux);

    pNovo->dado = aux;
    pNovo->next = NULL;

    if (lista->start == NULL) {

        lista->start = pNovo;

    }
    else {
        
        auxiliar = lista->start;

        while (auxiliar->next != NULL ) {
            auxiliar = auxiliar->next;
        }

        auxiliar->next = pNovo;
    }

    lista->tamanho++;

}

void limpa(Lista *lista) {

    int i;
    P *auxiliar;

    for(i = 0; i < lista->tamanho; i++) {

        auxiliar = lista->start;
        while (auxiliar->next != NULL ) {
            auxiliar = auxiliar->next;
        }
        free(auxiliar);
    }

}