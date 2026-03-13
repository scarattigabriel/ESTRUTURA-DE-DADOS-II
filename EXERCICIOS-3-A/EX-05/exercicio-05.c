/*Contagem de Caracteres Específicos: Crie um programa que conte quantas vezes
um caractere específico aparece em um arquivo de texto. Permita que o usuário
especifique o caractere a ser contado.*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *arquivo;
    char letra;
    arquivo = fopen("arquivo.txt", "r");
    printf("Digite o caracter que desejas contar no arquivo: ");
    scanf("%c", &letra);
    if (arquivo == NULL)
    {
        printf("ERROR");
        return 1;
    }
    int contador = 0;
    char c;
    while(!feof(arquivo))
    {
        c = fgetc(arquivo);
        if(c == letra)
        {
            contador++;
        }
    }
    
    printf("%d", contador);

    return 0;
}