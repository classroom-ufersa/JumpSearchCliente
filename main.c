#include "cliente.c"

int main(void)
{
    char nomedoarquivo[10] = "Lista.txt";
    int QuantidadeDeClientes = 0;
    int ordem = 0;

    char opcao;
    
    do
    {  

        ContarAlunos(nomedoarquivo,&QuantidadeDeClientes);//Contando quantos clientes existem na lista
        Cliente * usuario = (Cliente*)malloc(QuantidadeDeClientes * sizeof(Cliente));
        PassarDados(nomedoarquivo,&usuario,&QuantidadeDeClientes);//Passando os dados para as variaveis usuario;
        
        printf("QUANTIDADE DE CLIENTES DENTRO DO PROGAMA: %d\n\n",QuantidadeDeClientes);
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
            int tecla;
            case '1':
                system("clear");
                VerClientes(&usuario,&QuantidadeDeClientes);//Mostra os clientes
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '2':
                system("clear");
                AdicionarNovoCliente(nomedoarquivo, &usuario, &QuantidadeDeClientes);
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '3': 
                system("clear");
                int codigo = 0;
                printf("Qual cliente voce dejesa buscar?\n");
                scanf("%d",&codigo);
                int posicao = JumpSearchCod(&usuario, &QuantidadeDeClientes, &codigo);
                VerificaBusca(&usuario,&codigo,&posicao);
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '4': 
                system("clear");
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;
            
            case '5':
                printf("\n");
                free(usuario);
            break;

            default:
                printf("Opcao invalida\n");
            break;
        
        }
    
    }while (opcao != '5');
    
    printf("Progama encerrado com sucesso!\n");
    
    return 0;
}