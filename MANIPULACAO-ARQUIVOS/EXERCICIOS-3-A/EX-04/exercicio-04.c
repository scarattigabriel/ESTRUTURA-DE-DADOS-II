//4) Leitura e Impressão de Linhas Específicas: Escreva um programa que leia um
//arquivo de texto linha por linha e imprima apenas as linhas que começam com uma
//determinada letra ou palavra especificada pelo usuário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>z
/*
int main(){
    FILE *arquivo;
    char linha[500];
    char letra;
    printf("digite a letra ou palavra para filtrar as linhas:\n");
    scanf("%c", &letra);
    int num = sizeof(letra);
    arquivo = fopen("exer1.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        exit (1);
    }
    while(fgets(linha, sizeof(linha), arquivo)){
        for(int i = 0; i < num; i++){
            if(linha[i] == letra){
                printf("%s", linha);
            }
        }
    }
    fclose(arquivo);
    return 0;

}
*/

int main(){
    FILE *arquivo;
    char linha[500];
    char letra[500];
    printf("Digite uma letra ou uma palavra para filtrar a exibição de linhas do arquivo:\n");
    scanf("%s", letra);
    int num = strlen(letra);
    arquivo = fopen("exer1.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        exit (1);
    }
    int i;
    while(fgets(linha, sizeof(linha), arquivo)){
        for(i = 0; i < num; i++){
            if(linha[i] != letra[i]){
                break;
            }
        }
        if(i == num){
            printf("%s", linha);
        }
    }
    fclose(arquivo);
    return 0;

}