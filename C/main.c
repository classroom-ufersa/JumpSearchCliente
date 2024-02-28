#include "cliente.c"

int main(void)
{
    char nomedoarquivo[10] = "Lista.txt";
    int QuantidadeDeClientes = 0;
    int ordem = 0;
    clock_t inicio;
    double tempo;

    char opcao;
    char verificarOpcao[50];
    
    do
    {  

        ContarCliente(nomedoarquivo,&QuantidadeDeClientes);
        Cliente * usuario = (Cliente*)malloc(QuantidadeDeClientes * sizeof(Cliente));
        PassarDados(nomedoarquivo,&usuario,&QuantidadeDeClientes);
        
        printf("QUANTIDADE DE CLIENTES DENTRO DO PROGAMA: %d\n\n",QuantidadeDeClientes);
        printf("====MENU====\n\n");
        printf("1 - ver clientes\n");
        printf("2 - Adicionar um cliente novo\n");
        printf("3 - buscar cliente pelo codigo\n");
        printf("4 - buscar cliente pelo nome\n");
        printf("5 - encerrar o progama\n\n");
        printf("============\n");
       
        printf("Opcao: ");
        scanf(" %s", verificarOpcao);

        opcao = verificarOpcao[0];

        switch(opcao)
        {
            int tecla;
            case '1':
                system("clear");
                VerClientes(&usuario,&QuantidadeDeClientes);
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
                printf("Digite o codigo do usuario que voce deseja buscar\nCodigo: ");
                scanf("%d",&codigo);
                printf("\n");
                inicio = clock();
                int posicaocod = JumpSearchCod(&usuario, &QuantidadeDeClientes, &codigo);
                tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
                tempo = tempo * 1000; 
                VerificaBuscaCod(&usuario,&codigo,&posicaocod,&tempo);
                printf("Digite qualquer tecla para retornar ao menu\n");
                scanf("%d",&tecla);
            break;

            case '4': 
                system("clear");
                char nome[30];
                printf("Digite o nome do usuario que voce buscar\nNome: ");
                scanf("%s",nome);
                printf("\n");
                inicio = clock();
                int posicaoname = jumpSearchNome(&usuario, &QuantidadeDeClientes,nome);
                tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
                tempo = tempo * 1000; 
                VerificaBuscaNome(&usuario,&posicaoname,&tempo);
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
