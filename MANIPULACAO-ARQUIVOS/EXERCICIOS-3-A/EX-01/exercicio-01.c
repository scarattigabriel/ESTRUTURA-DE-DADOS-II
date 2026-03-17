/*Contagem de Palavras em um Arquivo: Escreva um programa que abra um arquivo
de texto, conte o número de palavras nele e exiba o resultado na tela. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    //Criando um descritor
    FILE *arquivo;
    char caractere;
    int contador = 0;
    int dentro_palavra = 0;
    //abre o arquivo em modo de leitura
    arquivo = fopen("arquivo.txt", "r");
    //verifica se abriu corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    //caractere recebe código do caractere ou a contante EOF
    //enquanto for diferente de EOF(final do arquivo) o laço continua
    while(!feof(arquivo)){
        caractere = fgetc(arquivo);
        if((caractere == ' ' || caractere == '\n' || caractere == '\t') && dentro_palavra == 1){  
            dentro_palavra = 0;
            contador++;
        }
        else if(dentro_palavra==0 && (caractere != ' ' && caractere != '\n' && caractere != '\t')){
            dentro_palavra = 1;
        }
    }
    
    printf("Numero de palavras: %d\n", contador);

    fclose(arquivo);

    return 0;
}
/*
int main(){

    //Criando um descritor
    FILE *arquivo;
    char caractere;
    int contador = 0;
    int dentro_palavra = 0;
    //abre o arquivo em modo de leitura
    arquivo = fopen("arquivo.txt", "r");
    //verifica se abriu corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    //caractere recebe código do caractere ou a contante EOF
    //enquanto for diferente de EOF(final do arquivo) o laço continua
    while(!feof(arquivo)){
        caractere = fgetc(arquivo);
        if(isspace(caractere) && dentro_palavra == 1){  
            dentro_palavra = 0;
            contador++;
        }
        else if(dentro_palavra==0 && !isspace(caractere)){
            dentro_palavra = 1;
        }
    }
    
    contador++;
    
    printf("Numero de palavras: %d\n", contador);

    fclose(arquivo);

    return 0;
}
*/