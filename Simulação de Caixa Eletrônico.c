#include <stdio.h>
#include <stdlib.h> //biblioteca padrão que contém funções úteis para manipulação de memória, controle de processos e conversões

// Função para começar o tabuleiro com os espaços vazios
void inicializar_tabuleiro(char **tabuleiro, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para mostrar o tabuleiro formatado no terminal
void mostrar_tabuleiro(char **tabuleiro, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < tamanho - 1) printf("|");
        }
        printf("\n");
        if (i < tamanho - 1) {
            for (int k = 0; k < tamanho; k++) {
                printf("---");
                if (k < tamanho - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Função para fazer uma jogada
int fazer_jogada(char **tabuleiro, int linha, int coluna, char jogador, int tamanho) {
    if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho) {
        printf("Posição inválida! Tente novamente.\n");
        return 0;
    }
    if (tabuleiro[linha][coluna] != ' ') {
        printf("Posição já ocupada! Escolha outra.\n");
        return 0;
    }
    tabuleiro[linha][coluna] = jogador;
    return 1;
}

// Função para verificar se tem um vencedor
int verificar_vencedor(char **tabuleiro, int tamanho) {
    // Verificar linhas e colunas
    for (int i = 0; i < tamanho; i++) {
        int linha_completa = 1, coluna_completa = 1;
        for (int j = 1; j < tamanho; j++) {
            if (tabuleiro[i][j] != tabuleiro[i][0] || tabuleiro[i][0] == ' ')
                linha_completa = 0;
            if (tabuleiro[j][i] != tabuleiro[0][i] || tabuleiro[0][i] == ' ')
                coluna_completa = 0;
        }
        if (linha_completa || coluna_completa) return 1;
    }

    // Verificar diagonais
    int diag1_completa = 1, diag2_completa = 1;
    for (int i = 1; i < tamanho; i++) {
        if (tabuleiro[i][i] != tabuleiro[0][0] || tabuleiro[0][0] == ' ')
            diag1_completa = 0;
        if (tabuleiro[i][tamanho - 1 - i] != tabuleiro[0][tamanho - 1] || tabuleiro[0][tamanho - 1] == ' ')
            diag2_completa = 0;
    }
    if (diag1_completa || diag2_completa) return 1;

    return 0;
}

// Função para ver se o tabuleiro está cheio (empate)
int verificar_empate(char **tabuleiro, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Função principal para escolher o tamanho do tabuleiro e iniciar o jogo
int main() {
    int tamanho;
    printf("Digite o tamanho do tabuleiro (3 para 3x3, 4 para 4x4, etc.): ");
    scanf("%d", &tamanho);

    // Alocar memória para o tabuleiro
    char **tabuleiro = (char **)malloc(tamanho * sizeof(char *));
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[i] = (char *)malloc(tamanho * sizeof(char));
    }

    inicializar_tabuleiro(tabuleiro, tamanho);

    char jogador_atual = 'X';
    int linha, coluna, jogadas_validas = 0;

    while (1) {
        mostrar_tabuleiro(tabuleiro, tamanho);
        printf("Jogador %c, digite sua jogada (linha e coluna): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        if (fazer_jogada(tabuleiro, linha - 1, coluna - 1, jogador_atual, tamanho)) {
            jogadas_validas++;
            // verfica se tem um vencedor
            if (verificar_vencedor(tabuleiro, tamanho)) {
                mostrar_tabuleiro(tabuleiro, tamanho);
                printf("Jogador %c venceu!\n", jogador_atual);
                break;
            }
            // verifica se o empate
            if (verificar_empate(tabuleiro, tamanho)) {
                mostrar_tabuleiro(tabuleiro, tamanho);
                printf("O jogo empatou!\n");
                break;
            }

            // Alternar jogador
            jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
        }
    }

    // Liberar memória alocada
    for (int i = 0; i < tamanho; i++) {
        free(tabuleiro[i]);
    }
    free(tabuleiro);

    return 0;
}
// tem uma coisa diferente nesse código, a parte de memória alocada que serve para ser mais facil de fazer variações como ter tamanhos de tabuleiros diferentes, e a parte de liberar serve para liberar a memória alocada, para não ficar com memória alocada que não será mais usada que acaba pesando no computador. Basicamente são vetores dinamicos ao invés de fixos e estáticos.