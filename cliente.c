#include "cliente.h"

struct cliente
{
    char Nome[30];
    char Endereco[30];
    int CodigoCliente;
};

void VerClientes(Cliente **usuario, int *quantidade)
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

void ContarCliente(char *NomeDoArquivo, int *linhas)
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
            *linhas += 1;
        }
    }

    fclose(arquivo);
}

void PassarDados(char *NomeDoArquivo, Cliente **pessoa, int *quantidade)
{

    FILE *arquivo = fopen(NomeDoArquivo, "rt");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", NomeDoArquivo);
        exit(1);
    }

    for (int ordem = 0; ordem < *quantidade; ordem++)
    {
        fscanf(arquivo, "%s %s %d\n", (*pessoa)[ordem].Nome, (*pessoa)[ordem].Endereco, &(*pessoa)[ordem].CodigoCliente);
    }
}

void AdicionarNovoCliente(char *NomeDoArquivo, Cliente **usuario, int *quantidade)
{
    FILE *arquivo = fopen(NomeDoArquivo, "at");

    Cliente verifica;
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", NomeDoArquivo);
        exit(1);
    }

    *quantidade += 1;
    *usuario = realloc(*usuario, *quantidade * sizeof(Cliente));

    printf("Digite o nome do usuario:\n");
    scanf("%s", verifica.Nome);
    for(int ordem = 0; ordem < *quantidade;ordem ++)
    {
        if(strcmp((*usuario)[ordem].Nome, verifica.Nome) == 0)
        {
            while(strcmp((*usuario)[ordem].Nome, verifica.Nome) == 0)
            {
                printf("Esse nome ja foi digitado, tente outro nome!\nNome:");
                scanf("%s",verifica.Nome);
                printf("\n");
            }
        }
    }
    strcpy((*usuario)[*quantidade].Nome, verifica.Nome);
    printf("Digite o endereco do usuario:\n");
    scanf("%s", (*usuario)[*quantidade].Endereco);
    printf("Digite o codigo do usuario:\n");
    scanf("%d", &verifica.CodigoCliente);
    for(int ordem = 0; ordem < *quantidade;ordem ++)
    {
        if((*usuario)[ordem].CodigoCliente == verifica.CodigoCliente)
        {
            while((*usuario)[ordem].CodigoCliente == verifica.CodigoCliente)
            {
                printf("Esse codigo ja foi digitado, tente outro codigo!\ncodigo:");
                scanf("%d",&verifica.CodigoCliente);
                printf("\n");
            }
        }
    }
    (*usuario)[*quantidade].CodigoCliente = verifica.CodigoCliente;
    fprintf(arquivo, "\n%s %s %d", (*usuario)[*quantidade].Nome, (*usuario)[*quantidade].Endereco, (*usuario)[*quantidade].CodigoCliente);
    printf("Novo usuario adicionado!\n");

    fclose(arquivo);
}

int JumpSearchCod(Cliente **usuarios, int *QuantidadeDeCliente, int *codigo)
{

    int posicaoAtual = 0;
    int salto = sqrt(*QuantidadeDeCliente); //N1 - função dominante n^1/2 -> raiz quadrada;
    
    qsort((*usuarios), *QuantidadeDeCliente, sizeof(Cliente), comparar_codigo); 
    
    while (posicaoAtual < *QuantidadeDeCliente) //N2 -N(o);
    {
        if ((*usuarios)[posicaoAtual].CodigoCliente < *codigo)
        {
            posicaoAtual += salto;
        }
        else
        {
            break;
        }
    }

    for (int PosicaoLinear = posicaoAtual - salto; PosicaoLinear < *QuantidadeDeCliente; PosicaoLinear++) //N3 -N(o);
    {
        if ((*usuarios)[PosicaoLinear].CodigoCliente == *codigo)
        {
            return PosicaoLinear;
        }
    }

    return -1; 
}

int jumpSearchNome(Cliente** cliente, int *QuantidadeDeClientes, char *nome)
{
    int salto = sqrt(*QuantidadeDeClientes);//N1 - função dominante n^1/2 -> raiz quadrada;
    int i = 0, j = 0;

    qsort((*cliente), *QuantidadeDeClientes, sizeof(Cliente), comparar_nome);

    while (i < *QuantidadeDeClientes && strcmp((*cliente)[i].Nome, nome) < 0)//N2  -N(o);
    {
        i += salto;
    }
    if (i >= *QuantidadeDeClientes || strcmp((*cliente)[i].Nome, nome) > 0)
    {
        i -= salto;
        for (j = i; j < i + salto && j < *QuantidadeDeClientes; j++)//N3 -N(o);
        {
            if (strcmp((*cliente)[j].Nome, nome) == 0)
            {
                return j;
            }
        }
        return -1;
    }
    else if (strcmp((*cliente)[i].Nome, nome) == 0)
    {
        return i;
    }
    return -1;
}

int comparar_codigo(const void *a, const void *b)
{
    Cliente *clientea = (Cliente *)a;
    Cliente *clienteb = (Cliente *)b;
    return clientea->CodigoCliente - clienteb->CodigoCliente;
}

int comparar_nome(const void *a, const void *b)
{
    Cliente *clientea = (Cliente *)a;
    Cliente *clienteb = (Cliente *)b;
    return strcmp(clientea->Nome,clienteb->Nome);
}

void VerificaBuscaCod(Cliente **usuario, int *codigo, int *retorno)
{
    if (*retorno == -1)
    {
        printf("Nao foi possivel encontrar o cliente");
    }
    else
    {
        printf("O usuario do codigo %d esta na posicao %d\nSeu nome e %s\n", *codigo, *retorno + 1, (*usuario)[*retorno].Nome);
    }
}

void VerificaBuscaNome(Cliente **usuario, int *retorno)
{
    if (*retorno == -1)
    {
        printf("Nao foi possivel encontrar o cliente\n");
    }
    else
    {
        printf("O usuario do nome %s Seu codigo e %d\n", (*usuario)[*retorno].Nome, (*usuario)[*retorno].CodigoCliente);
    }
}