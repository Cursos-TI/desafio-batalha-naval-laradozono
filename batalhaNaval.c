#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
// -------------------------------
    // 1. DECLARAÇÃO DO TABULEIRO
    // -------------------------------
    // Matriz 10x10 representando o oceano.
    // 0 = água
    // 3 = parte do navio
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializar o tabuleiro com zeros (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------
    // 2. NAVIOS (vetores unidimensionais)
    // -------------------------------
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    // Coordenadas iniciais 
    int linhaH = 2, colunaH = 1;  // Navio horizontal começará em (2,1)
    int linhaV = 5, colunaV = 6;  // Navio vertical começará em (5,6)

    // -------------------------------
    // 3. VALIDAÇÃO DO NAVIO HORIZONTAL
    // -------------------------------
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // -------------------------------
    // 4. VALIDAÇÃO DO NAVIO VERTICAL
    // -------------------------------
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // -------------------------------
    // 5. VERIFICAÇÃO DE SOBREPOSIÇÃO
    // -------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Navio horizontal sobrepõe outro navio.\n");
            return 1;
        }
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    }

    // -------------------------------
    // 6. POSICIONAR O NAVIO HORIZONTAL
    // -------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // -------------------------------
    // 7. POSICIONAR O NAVIO VERTICAL
    // -------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // -------------------------------
    // 8. EXIBIR O TABULEIRO
    // -------------------------------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

