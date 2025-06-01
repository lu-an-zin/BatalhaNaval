#include <stdio.h>

int main(){

        //declarando a matriz
    int tabuleiro[10][10]= {0};

    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }

    for (int j = 7; j < 10; j++) {
        tabuleiro[j][7] = 3;
    }

    for(int i=0; i <10; i++){
        for(int j=0; j<10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}