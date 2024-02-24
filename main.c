#include "cliente.c"

int main(void)
{
    char nomedoarquivo[10] = "Lista.txt";
    int QuantidadeDeAlunos = 0;
    int ordem = 0;

    ContarAlunos(nomedoarquivo,&QuantidadeDeAlunos);
    
    printf("quantidade: %d",QuantidadeDeAlunos);
    
    Cliente * usuario = (Cliente*)malloc(QuantidadeDeAlunos * sizeof(usuario));


    
    char opcao;
    
    { 
        printf("====MENU====\n\n");
        printf("1 - Adicionar cliente");
        printf("2 - ver clientes\n");
        printf("3 - buscar cliente pelo codigo\n");
        printf("4 - buscar cliente pelo nome\n");
        printf("5 - encerrar o progama\n\n");
        printf("============\n");
       
        printf("Opcao: ");
        scanf(" %c",&opcao);

        switch(opcao)
        {
            case '1':

            break;

            case '2': 
                VerClientes(&usuario, &QuantidadeDeAlunos);
                int tecla = 0;
                printf("Digite qualquer tecla para sair");
                scanf("%d",&tecla);
                system("clear");               
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

