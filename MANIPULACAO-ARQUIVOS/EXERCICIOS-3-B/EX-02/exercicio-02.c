#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    FILE* arquivo = fopen("arquivo2.bin", "rb");
    
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int valor; // Correção: Mudamos de unsigned char para int
    int min = INT_MAX; // Correção: Inicia com o maior valor possível de um int
    int max = INT_MIN; // Correção: Inicia com o menor valor possível de um int
    long soma = 0;
    int contador = 0;

    // Correção: Agora lemos blocos do tamanho de um int (sizeof(int))
    while (fread(&valor, sizeof(int), 1, arquivo) == 1) {
        soma += valor;
        contador++;

        if (valor < min) min = valor;
        if (valor > max) max = valor;

        printf("Lido: %d\n", valor);
    }

    if (contador > 0) {
        printf("Minimo: %d\n", min);
        printf("Maximo: %d\n", max);
        printf("Media: %.2f\n", (float)soma / contador);
    } else {
        printf("Arquivo vazio ou erro na leitura.\n");
    }

    fclose(arquivo);
    return 0;
}