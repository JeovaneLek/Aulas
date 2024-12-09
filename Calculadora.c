#include <stdio.h>

void MostrarMenu() { // Mostra o menu de opções
    printf("\nEscolha a operação:\n");
    printf("[1] - Somar\n");
    printf("[2] - Subtrair\n");
    printf("[3] - Multiplicar\n");
    printf("[4] - Dividir\n");
    printf("[5] - Mostrar o histórico\n");
    printf("[6] - Sair\n");
}

float Somar(float num1, float num2) { // Função de soma dos numeros
    return num1 + num2;
}

float Subtrair(float num1, float num2) { // Função de subtração dos numeros
    return num1 - num2;
}

float Multiplicar(float num1, float num2) { // Função de multiplicação dos numeros
    return num1 * num2;
}

float Dividir(float num1, float num2) { // Função de divisão dos numeros
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
}

int main() { // Função principal
    float num1, num2, r;
    int op;
    float historico[100]; // Array para armazenar o histórico das operações
    int historicoIndex = 0; // Índice para controlar o histórico

    while (1) { // Laço infinito para o menu
        MostrarMenu();
        scanf("%d", &op);

        if (op == 6) { // Opção de saída
            printf("Saindo...\n");
            break;
        }

        if (op == 5) { // Mostrar o histórico
            printf("Histórico de resultados:\n");
            for (int i = 0; i < historicoIndex; i++) {
                printf("Resultado %d: %.1f\n", i + 1, historico[i]);
            }
            continue;
        }

        // Pedir os números para as operações
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        switch (op) {
            case 1:
                r = Somar(num1, num2); // Chama a função de soma
                printf("Resultado: %.1f\n", r);
                historico[historicoIndex++] = r;
                break;
            case 2:
                r = Subtrair(num1, num2); // Chama a função de subtração
                printf("Resultado: %.1f\n", r);
                historico[historicoIndex++] = r;
                break;
            case 3:
                r = Multiplicar(num1, num2); // Chama a função de multiplicação
                printf("Resultado: %.1f\n", r);
                historico[historicoIndex++] = r;
                break;
            case 4:
                r = Dividir(num1, num2); // Chama a função de divisão
                printf("Resultado: %.1f\n", r);
                historico[historicoIndex++] = r;
                break;
            default:
                printf("Opção inválida\n");
        }
    }

    return 0;
}
