/*
1) Escreva um programa em C que inverte o conteúdo de um arquivo de texto, ou seja, o programa lerá o arquivo de trás para frente e escreverá em um novo arquivo. 
- 
O nome do arquivo pode ser informado manualmente, tanto do arquivo de entrada como do arquivo de saída. 
O Programa abrirá o arquivo de entrada em modo somente para leitura; 
Usando a função fseek, o programa moverá o ponteiro de arquivo para o final do arquivo de entrada; 
O programa lerá o arquivo de entrada de trás para frente, linha por linha, usando a função fseek para mover o ponteiro do arquivo para a posição desejada. 
Cada linha lida será escrita no arquivo de saída. 
Ao final, o programa fechará os arquivos. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nome_origem[100], nome_destino[100];
    printf("Digite o nome do arquivo de origem: \n");
    fgets(nome_origem, sizeof(nome_origem), stdin);
    printf("Digite o nome do arquivo de destino: \n");
    fgets(nome_destino, sizeof(nome_destino), stdin);


    nome_origem[strcspn(nome_origem, "\n")] = '\0';
    nome_destino[strcspn(nome_destino, "\n")] = '\0';

    FILE *desc_origem = fopen(nome_origem, "r");
    FILE *desc_destino = fopen(nome_destino, "w");

    if(desc_origem == NULL || desc_destino == NULL)
    {
        printf("Erro ao abrir os arquivos!\n");
        return 1; 
    }

    fseek(desc_origem, 0, SEEK_END);
    long pos = ftell(desc_origem); 
    char linha[500];

    while (pos > 0)
    {
        pos--; 
        fseek(desc_origem, pos, SEEK_SET); 
        char caractere = fgetc(desc_origem);
        if (caractere == '\n') 
        {
            fseek(desc_origem, pos + 1, SEEK_SET); 
            fgets(linha, sizeof(linha), desc_origem);
            fputs(linha, desc_destino);
            fseek(desc_origem, pos, SEEK_SET); 
        }
    }
    fseek(desc_origem, 0, SEEK_SET);
    fgets(linha, sizeof(linha), desc_origem);
    fputs(linha, desc_destino);
    
    fclose(desc_origem);
    fclose(desc_destino);

    printf("Arquivo invertido com sucesso!\n");

    return 0;
}