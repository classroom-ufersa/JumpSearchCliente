#include "cliente.c"

int main(void)
{
    int QuantidadeDeAlunos = 0;
    Cliente *usuario = malloc(sizeof(usuario));

    FILE *entrada = fopen(ArquivoNome,"rt");

    if(entrada == NULL)
    {
        printf("Não foi possivel abrir este arquivo.\n");
    }
    
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
                VerClientes(&usuario,&QuantidadeDeAlunos);
            break;

            case '2':
                NovoCliente(&usuario,&QuantidadeDeAlunos);
            break;

            case '3': 
                
            break;

            case '4': 
                
            break;
            
            case '5':
                return 0;
            break;

            default:
                printf("Opcao invalida\n");
            break;
        
        }

    }while (opcao != '5');
    
    return 0;
}

