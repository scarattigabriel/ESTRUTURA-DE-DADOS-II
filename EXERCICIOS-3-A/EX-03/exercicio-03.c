/*Edição de Arquivo: Desenvolva um programa que permita ao usuário editar um
arquivo de texto. Ele deve solicitar ao usuário que insira o texto que deseja adicionar
ao arquivo existente e, em seguida, deve adicionar esse texto ao final do arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char texto[1000];
    arquivo = fopen("arquivo.txt", "a");
    if(arquivo == NULL)
    {
        printf("ERRO");
        return 1;
    }

    printf("Digite o texto que deseja adicionar ao arquivo: ");
    fgets(texto, sizeof(texto), stdin);
    fputs(texto, arquivo);

    fclose(arquivo);



    return 0;
}