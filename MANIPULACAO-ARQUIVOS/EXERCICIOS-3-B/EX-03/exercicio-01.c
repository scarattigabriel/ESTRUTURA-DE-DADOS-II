#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para usar strcpy (copiar strings)

int main() {
    FILE *arq_notas;
    char nome[50];
    float nota;

    // Variáveis para calcular a média e achar a maior nota
    float soma_notas = 0.0;
    int contador = 0;
    float maior_nota = -1.0;
    char melhor_aluno[50];

    arq_notas = fopen("arquivo.txt", "r");
    
    if(arq_notas == NULL) {
        printf("Erro ao abrir o arquivo! Verifique se 'arquivo.txt' existe.\n");
        return 1;
    } 

    // O fscanf retorna a quantidade de itens que ele conseguiu ler com sucesso.
    // Como queremos ler 1 nome e 1 nota, ele deve retornar 2.
    // Quando chegar no fim do arquivo, ele não vai retornar 2, e o while para.
    while(fscanf(arq_notas, "%49s %f", nome, &nota) == 2) {
        
        // 1. Somar para a média
        soma_notas += nota;
        contador++;

        // 2. Verificar se é a maior nota
        if(nota > maior_nota) {
            maior_nota = nota;
            // Salva o nome do aluno que tem essa nota
            strcpy(melhor_aluno, nome); 
        }
    }

    // Só faz os cálculos se o arquivo não estiver vazio
    if (contador > 0) {
        float media = soma_notas / contador;
        printf("Media da turma: %.2f\n", media);
        printf("Estudante com a maior nota: %s (Nota: %.2f)\n", melhor_aluno, maior_nota);
    } else {
        printf("O arquivo esta vazio ou o formato esta incorreto.\n");
    }

    fclose(arq_notas);
    
    return 0;
}