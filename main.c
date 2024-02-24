#include "cliente.c"

int main(void)
{
    char nomedoarquivo[10] = "Lista.txt";
    int QuantidadeDeClientes = 0;
    int ordem = 0;

    ContarAlunos(nomedoarquivo,&QuantidadeDeClientes);
    
    printf("quantidade: %d\n",QuantidadeDeClientes);
    
    Cliente * usuario = (Cliente*)malloc(QuantidadeDeClientes * sizeof(usuario));

    PassarDados(nomedoarquivo,&usuario,&QuantidadeDeClientes);
    
    char opcao;
    
    do
    {  
        printf("====MENU====\n\n");
        printf("1 - ver clientes\n");
        printf("2 - Adicionar um cliente novo\n");
        printf("3 - buscar cliente pelo codigo\n");
        printf("4 - buscar cliente pelo nome\n");
        printf("5 - encerrar o progama\n\n");
        printf("============\n");
       
        printf("Opcao: ");
        scanf(" %c",&opcao);

        switch(opcao)
        {
            case '1':
                system("clear");
                int tecla;
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;
                system("clear");
                int tecla;
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            case '2':
                system("clear");
                int tecla;
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '3': 
                system("clear");
                int tecla;
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '4': 
                system("clear");
                int tecla;
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;
            
            case '5':
                return 0;
            break;

            default:
                printf("Opcao invalida\n");
            break;
        
        }

    }while (opcao != '5');
    
    free(usuario);
    printf("Progama encerrado.\n");
    
    return 0;
}

