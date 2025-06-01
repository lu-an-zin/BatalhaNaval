#include <stdio.h>

int main() {
    // Declarando a matriz do tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Navio 1 na horizontal
    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }

    // Navio 2 na vertical
    for (int j = 3; j < 6; j++) {
        tabuleiro[j][7] = 3;
    }

    // Navio 3 na diagonal
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio 4 na diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    // Matrizes de habilidades (5x5)

    // Habilidade Cone
    int cone[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Habilidade Cruz
    int cruz[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Habilidade Octaedro
    int octaedro[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Definir a forma de octaedro (losango)
            if (i + j >= 2 && i + j <= 6 && j - i >= -2 && j - i <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Definir ponto de origem para cada habilidade (no tabuleiro)
    int linhaOrigemCone = 4, colOrigemCone = 4;
    int linhaOrigemCruz = 3, colOrigemCruz = 3;
    int linhaOrigemOctaedro = 5, colOrigemOctaedro = 5;

    // Aplicando as habilidades no tabuleiro

    // Aplicar habilidade Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int novaLinha = linhaOrigemCone + i - 2;
                int novaCol = colOrigemCone + j - 2;
                if (novaLinha >= 0 && novaLinha < 10 && novaCol >= 0 && novaCol < 10) {
                    tabuleiro[novaLinha][novaCol] = 5;
                }
            }
        }
    }

    // Aplicar habilidade Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int novaLinha = linhaOrigemCruz + i - 2;
                int novaCol = colOrigemCruz + j - 2;
                if (novaLinha >= 0 && novaLinha < 10 && novaCol >= 0 && novaCol < 10) {
                    tabuleiro[novaLinha][novaCol] = 5;
                }
            }
        }
    }

    // Aplicar habilidade Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int novaLinha = linhaOrigemOctaedro + i - 2;
                int novaCol = colOrigemOctaedro + j - 2;
                if (novaLinha >= 0 && novaLinha < 10 && novaCol >= 0 && novaCol < 10) {
                    tabuleiro[novaLinha][novaCol] = 5;
                }
            }
        }
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro com Navios e Habilidades Aplicadas:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");
            }
        }
        printf("\n");
    }

    return 0;
}