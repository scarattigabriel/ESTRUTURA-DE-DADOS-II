#include <stdio.h>

int main() {
    FILE* arquivo = fopen("arquivo2.bin", "wb"); // "wb" para escrever em binário
    
    if(arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    // Vamos gravar 5 números inteiros: 10, 20, 30, 40, 50
    int numeros[] = {10, 20, 30, 40, 50};
    
    // Gravando o array inteiro de uma vez (5 itens de tamanho int)
    fwrite(numeros, sizeof(int), 5, arquivo);

    fclose(arquivo);
    printf("Arquivo 'arquivo.bin' criado com sucesso!\n");
    
    return 0;
}