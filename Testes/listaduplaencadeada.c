#include <stdio.h>
#include <stdlib.h>

typedef struct P{

    int dado;
    struct P *next;
    struct P *previous;

} P;

typedef struct {

    P *start;
    P *end;
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
    lista.end = NULL;
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

    P *pNovo;
    pNovo = (P*)malloc(sizeof(P));

    pNovo->next = NULL;
    pNovo->previous = NULL;
    scanf("%d", &pNovo->dado);
    getchar();

    if (lista->start == NULL) {

        lista->start = pNovo;
        lista->end = pNovo;
        
    }
    else {

        lista->start->previous = pNovo;
        pNovo->next = lista->start;
        lista->start = pNovo;

    }

    lista->tamanho++;

}

void imprimeLista(Lista *lista) {

    P *pStart = lista->start;

    if (lista->start == NULL) {

        printf("\nLista vazia;\n");
        
    }
    else {

        printf("\n");
        while(pStart != NULL) {

            printf("%d; ", pStart->dado);
            pStart = pStart->next;
            
        }
        printf("\n");

    }

}

void insereFim(Lista *lista) {

    P *pNovo;
    pNovo = (P*)malloc(sizeof(P));

    pNovo->next = NULL;
    pNovo->previous = NULL;
    scanf("%d", &pNovo->dado);
    getchar();


    if (lista->start == NULL) {

        lista->start = pNovo;
        lista->end = pNovo;

    }
    else {
        
        lista->end->next = pNovo;
        pNovo->previous = lista->end;
        lista->end = pNovo;

    }

    lista->tamanho++;

}

void limpa(Lista *lista) {

    int i;
    P *auxiliar, *p;

    p = lista->start;

    while (p != NULL ) {

        auxiliar = p;
        p = p->next;

        free(auxiliar);
    }
    
}