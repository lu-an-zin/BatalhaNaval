#include <stdio.h>

int main(){

        //declarando a matriz
    int tabuleiro[10][10]= {0};

    //navio 1 na horizontal
    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }

    //navio 2 na vertical

    for (int j = 3; j < 6; j++) {
        tabuleiro[j][7] = 3;
    }

    // navio 3 na diagonal
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][i] = 3;
    }

    // navio 4 na diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    // print da matriz
    for(int i=0; i <10; i++){
        for(int j=0; j<10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}