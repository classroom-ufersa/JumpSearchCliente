    #include "cliente.h"

    struct cliente
    {
        char Nome[30];
        char Endereco[30];
        int CodigoCliente;
    };

    void VerClientes(Cliente** usuario, int *quantidade)
    {
        for (ordem = 0; ordem < *quantidade; ordem++)
        {
            printf("Dados\n");
            printf("Nome: %s\n", (*usuario)[ordem].Nome);
            printf("Endereço: %s\n", (*usuario)[ordem].Endereco);
            printf("Código: %d\n", (*usuario)[ordem].CodigoCliente);
    }
}


    void ContarAlunos(char *nome_arquivo, int *linhas) 
    {

        FILE *arquivo = fopen(nome_arquivo, "rt");

        if (arquivo == NULL) 
        {
            printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
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

    void PassarDados(char *nome_arquivo, Cliente** pessoa, int *quantidade) 
    {

        FILE *arquivo = fopen(nome_arquivo, "rt");

        if (arquivo == NULL) 
        {
            printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
            exit(1);
        }

        for(int ordem = 0; ordem < *quantidade; ordem ++)
        {
            fscanf(arquivo, "%s %s %d\n", (*pessoa)[ordem].Nome, (*pessoa)[ordem].Endereco, &(*pessoa)[ordem].CodigoCliente);
        }

    }