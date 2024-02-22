#include "cliente.c"

int main(void)
{
    //adciconando uma variavel para interagir com o menu
    char opcao;
    int qnt = 0;
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

            break;

            case '2':
                //algo
            break;

            case '3': 
                //algo
            break;

            case '4': 
                //algo
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

