#include <stdio.h>
#include <stdlib.h>

#define LINHA 10
#define COLUNA 10

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[LINHA][COLUNA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio fixo no tabuleiro (valor 3)
void posicionarNavio(int tabuleiro[LINHA][COLUNA]) {
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[5][5] = 3;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[LINHA][COLUNA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para sobrepor matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[LINHA][COLUNA], int habilidade[7][7], int origemLinha, int origemColuna) {
    int tamanho = 7;
    int meio = tamanho / 2;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemLinha + (i - meio);
                int y = origemColuna + (j - meio);

                if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA) {
                    if (tabuleiro[x][y] == 0) { 
                        tabuleiro[x][y] = 5; // Marca como área afetada
                    }
                }
            }
        }
    }
}

// Função para criar habilidade em forma de cone
void criarCone(int cone[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (j >= 3 - i && j <= 3 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar habilidade em forma de cruz
void criarCruz(int cruz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 3 || j == 3) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar habilidade em forma de octaedro (losango)
void criarOctaedro(int octaedro[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (abs(i - 3) + abs(j - 3) <= 3) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[LINHA][COLUNA];
    int cone[7][7], cruz[7][7], octaedro[7][7];

    // Criar matrizes de habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // ----------- Tabuleiro com Cone -----------
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    printf("Tabuleiro com habilidade CONE:\n");
    imprimirTabuleiro(tabuleiro);

    // ----------- Tabuleiro com Cruz -----------
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);
    aplicarHabilidade(tabuleiro, cruz, 4, 4);
    printf("Tabuleiro com habilidade CRUZ:\n");
    imprimirTabuleiro(tabuleiro);

    // ----------- Tabuleiro com Octaedro -----------
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);
    aplicarHabilidade(tabuleiro, octaedro, 4, 4);
    printf("Tabuleiro com habilidade OCTAEDRO:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
