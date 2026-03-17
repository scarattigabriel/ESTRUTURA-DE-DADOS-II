/*Cópia de Arquivo: Crie um programa que copie o conteúdo de um arquivo de texto
para outro arquivo. Certifique-se de que o arquivo de destino seja criado se ainda
não existir.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *origem;
    FILE *destino;
    char linha[100]; // Espaço físico para guardar cada linha lida

    //  ABRE O ARQUIVO DE ORIGEM EM MODO LEITURA
    origem = fopen("arquivo.txt", "r");
    if (origem == NULL) {
        printf("Erro: O arquivo de origem não existe!\n");
        return 1;
    }

    // ABRE O ARQUIVO DE DESTINO EM MODO DE ESCRITA
    // SE O ARQUIVO NÃO EXISTIR, ELE SERÁ CRIADO
    destino = fopen("arquivo2.txt", "w");
    if (destino == NULL) {
        printf("Erro ao criar o arquivo de destino!\n");
        //SE NÃO FOR POSSÍVEL ABRIR O ARQUIVO DE DESTINO, FECHA O ARQUIVO DE ORIGEM
        fclose(origem); 
    }

    //fgets le cada linha(ou ate p sizeof de linha) do origem
    //armazena na variavel linha
    //laço acontece enquanto fgets não retorna NULL 
    while(fgets(linha, sizeof(linha), origem) != NULL)
    {
        //fputs escreve a strig do linha no arquivo destino
        fputs(linha, destino);
    }

    fclose(origem);
    fclose(destino);
    
    return 0;
}