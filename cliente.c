    #include "cliente.h"

    struct cliente
    {
        char Nome[20];
        char Endereco[20];
        int CodigoCliente;
    };

    void VerClientes(Cliente** usuario,int *quantidade)
    {
        int ordem = 0;
        for(ordem = 0; ordem < *quantidade; ordem++)
        {
            printf("Dados\n");
            printf("Nome: %s\n",(*usuario)[ordem].Nome);
            printf("Endereco: %s\n",(*usuario)[ordem].Endereco);
            printf("Codigo: %d\n",(*usuario)[ordem].CodigoCliente);    
        }
    }

    void ContarAlunos(char *nome_arquivo, int *linhas) 
    {

        FILE *arquivo = fopen(nome_arquivo, "r");

        if (arquivo == NULL) 
        {
            printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
            exit(1);
        }
       
        else
        {
            printf("aquivo lido com sucesso\n");
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
