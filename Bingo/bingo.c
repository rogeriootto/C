#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    char bingo[5] = "bingo";
    int random, stopFlag = 1, rounds = 1;

    printf("Programa de Bingo!!\n");
    printf("----------------------------\n");

    do{
        printf("\nRodada %d\n", rounds);
        system("pause");
        random = rand() % 5;

        switch (bingo[random]) {

            case 'b':

                random = rand() % 15 + 1;
                printf("\nO numero eh:\n");
                printf("B-%d\n", random);

            break;

            case 'i':

                random = rand() % 15 + 1 + (15);
                printf("\nO numero eh:\n");
                printf("I-%d\n", random);

            break;

            case 'n':

                random = rand() % 15 + 1 + (2*15);
                printf("\nO numero eh:\n");
                printf("N-%d\n", random);

            break;

            case 'g':

                random = rand() % 15 + 1 + (3*15);
                printf("\nO numero eh:\n");
                printf("G-%d\n", random);

            break;

            case 'o':

                random = rand() % 15 + 1 + (4*15);
                printf("\nO numero eh:\n");
                printf("O-%d\n", random);

            break;

        }

        printf("\nQuer seguir? 1-Y 0-N\n");
        scanf("%d", &stopFlag);
        getchar();
        rounds++;

    }while(stopFlag != 0);
}