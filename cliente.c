    #include "cliente.h"

    struct cliente
    {
        char Nome[20];
        char Endereco[20];
        int CodigoCliente;
    };

    void VerClientes(Cliente** usuario,int *quantidade)
    {
        for(int ordem = 0; ordem < *quantidade;ordem++)
        {
            printf("Dados\n");
            printf("Nome: %s\n",(*usuario)[ordem].Nome);
            printf("Endereco: %s\n",(*usuario)[ordem].Endereco);
            printf("Codigo: %d\n\n",(*usuario)[ordem].CodigoCliente);    
        }
    }

    void NovoCliente(Cliente** usuario, int *quantidade)
    {
        *quantidade = *quantidade + 1;
        *usuario = realloc(*usuario, (*quantidade) * sizeof(Cliente));

        printf("Diga o nome do novo usuario: \n");
        scanf("%s", (*usuario)[*quantidade].Nome);
        printf("Endereco: \n");
        scanf("%s", (*usuario)[*quantidade].Endereco);
        printf("Codigo: \n");
        scanf("%d", &(*usuario)[*quantidade].CodigoCliente);
    }
