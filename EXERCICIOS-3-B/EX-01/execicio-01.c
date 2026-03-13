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

    FILE *desc_origem, *desc_destino;
    desc_origem = fopen(nome_origem,"r");
    desc_destino = fopen(nome_destino, "w");
    if(desc_origem == NULL || desc_destino == NULL)
    {
        printf("Erro ao abrir os arquivos! ");
    }

    
    //Move o ponteiro para o final do arquivo

    fseek(desc_origem, 0, SEEK_END);
    char linha[500];

    //enquanto nao cheguei no inicio do arquivo
    //while nao encontrar um \n fseek vai lendo de tras pra frente
    // encontrei o \n eu leio toda linha e salvo no arquivo destino
    int pos = (ftell(desc_origem));
    int i = 0;
    while(pos >= 0)
    {
        while (fgetc(desc_origem) != "\n")
        {   
            i--;
            fseek(desc_origem, i, SEEK_END);
            pos--;
        }
        fgets(linha, sizeof(linha), desc_destino);
        fputs(linha, desc_destino);

    }

    fclose(desc_origem);
    fclose(desc_destino);

    return 0;
}






















/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arq_origem[100], arq_destino[100], buffer[1024];
    long pos, fim_da_linha, inicio_da_linha;

    // ... (mesma leitura de nomes de arquivo e fopens do código anterior) ...
    printf("Digite o nome do arquivo de origem: ");
    fgets(arq_origem, sizeof(arq_origem), stdin);
    arq_origem[strcspn(arq_origem, "\n")] = '\0';

    printf("Digite o nome do arquivo de destino: ");
    fgets(arq_destino, sizeof(arq_destino), stdin);
    arq_destino[strcspn(arq_destino, "\n")] = '\0';

    FILE *f_in = fopen(arq_origem, "r");
    FILE *f_out = fopen(arq_destino, "w");

    if (!f_in || !f_out) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    // Move para o final do arquivo
    fseek(f_in, 0, SEEK_END);
    fim_da_linha = ftell(f_in);
    printf("%ld", fim_da_linha);

    // Percorre o arquivo de trás para frente procurando por '\n'
    for (pos = fim_da_linha - 1; pos >= 0; pos--) {
        fseek(f_in, pos, SEEK_SET);
        char c = fgetc(f_in);

        // Se achou uma quebra de linha ou chegou no início do arquivo
        if (c == '\n' || pos == 0) {
            // Define o início da linha (se for pos 0, começa no 0, senão no pos+1)
            inicio_da_linha = (pos == 0) ? 0 : pos + 1;
            
            // Lê a linha e escreve no destino
            fseek(f_in, inicio_da_linha, SEEK_SET);
            if (fgets(buffer, sizeof(buffer), f_in)) {
                fputs(buffer, f_out);
                // Se a última linha do arquivo original não tinha \n, adicionamos um
                if (buffer[strlen(buffer)-1] != '\n') {
                    fputc('\n', f_out);
                }
            }
            
            // Atualiza o fim da próxima linha que vamos ler (está antes deste \n)
            fim_da_linha = pos;
        }
    }

    printf("Arquivo invertido linha por linha com sucesso!\n");
    fclose(f_in);
    fclose(f_out);
    return 0;
}*/