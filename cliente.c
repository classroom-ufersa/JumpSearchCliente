#include "cliente.h"

    struct cliente
    {
        char Nome[30];
        char Endereco[30];
        int CodigoCliente;
    };

    void VerClientes(Cliente** usuario, int *quantidade)
    {
        for (int ordem = 0; ordem < *quantidade; ordem++)
        {
            printf("Dados\n");
            printf("Nome: %s\n", (*usuario)[ordem].Nome);
            printf("Endereço: %s\n", (*usuario)[ordem].Endereco);
            printf("Código: %d\n", (*usuario)[ordem].CodigoCliente);
        }
        printf("\n");
    }

    void ContarAlunos(char *NomeDoArquivo, int *linhas) 
    {

        FILE *arquivo = fopen(NomeDoArquivo, "rt");

        if (arquivo == NULL) 
        {
            printf("Erro ao abrir o arquivo: %s\n", NomeDoArquivo);
            exit(1);
        }
       
        else
        {
            printf("Aquivo lido com sucesso\n");
        }

        *linhas = 0;

        char verificador;

        while ((verificador = fgetc(arquivo)) != EOF) 
        {
            if (verificador == '\n') 
            {
            *linhas+= 1;
            }
        }   

        fclose(arquivo);
    }

    void PassarDados(char *NomeDoArquivo, Cliente** pessoa, int *quantidade) 
    {

        FILE *arquivo = fopen(NomeDoArquivo, "rt");

        if (arquivo == NULL) 
        {
            printf("Erro ao abrir o arquivo: %s\n", NomeDoArquivo);
            exit(1);
        }

        for(int ordem = 0; ordem < *quantidade; ordem ++)
        {
            fscanf(arquivo, "%s %s %d\n", (*pessoa)[ordem].Nome, (*pessoa)[ordem].Endereco, &(*pessoa)[ordem].CodigoCliente);
        }

    }

    void AdicionarNovoCliente(char *NomeDoArquivo, Cliente** usuario, int *quantidade)
    {
        FILE *arquivo = fopen(NomeDoArquivo, "at");

        if(arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo: %s\n", NomeDoArquivo);
            exit(1);
        }

        *quantidade += 1;
        *usuario = realloc(*usuario, *quantidade * sizeof(Cliente));
    
     

        printf("Digite o nome do usuario:\n");
        scanf("%s", (*usuario)[*quantidade].Nome);
        printf("Digite o endereco do usuario:\n");
        scanf("%s", (*usuario)[*quantidade].Endereco);
        printf("Digite o codigo do usuario:\n");
        scanf("%d", &(*usuario)[*quantidade].CodigoCliente);

        fprintf(arquivo, "%s %s %d\n", (*usuario)[*quantidade].Nome, (*usuario)[*quantidade].Endereco, (*usuario)[*quantidade].CodigoCliente);
        printf("Novo usuario adicionado!\n");

        fclose(arquivo);
    }

    int jumpSearch(Cliente** usuarios, int *QuantidadeDeCliente, int *codigo) 
    {
        
        int posicaoAtual = 0;
        int salto = sqrt(*QuantidadeDeCliente);//definindo o tamanho dos saltos com a raiz quadrada do numero;
        
        while (posicaoAtual < *QuantidadeDeCliente)// Percorrer o array com saltos 
        {
            if ((*usuarios)[posicaoAtual].CodigoCliente < *codigo)// Se o código do usuário for menor que o código na posição atual, pular 
            {
                posicaoAtual += salto;
            } 
            else    
            {
                break;
            }
        }

        if (posicaoAtual >= *codigo)// Se a posição atual ultrapassou o limite do array, retornar -1
        {
            return -400;
        }
        
        for (int PosicaoLinear = posicaoAtual - salto; PosicaoLinear < *QuantidadeDeCliente; PosicaoLinear++)// Busca linear no bloco atual 
        {
            if ((*usuarios)[PosicaoLinear].CodigoCliente == *codigo) 
            {
                return PosicaoLinear;
            }
        }

        return -1000;// Retornar -1 se o código não for encontrado

    }