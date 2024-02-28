#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ArquivoNome "Lista.txt"

//definindo uma struct para armazenar os dados dos clientes;
typedef struct cliente Cliente;

//função criada para mostrar os usuarios cadastrados;
void VerClientes(Cliente** usuario,int *quantidade);

//função para contar a quantidades de Clientes;
void ContarCliente(char *NomeDoArquivo, int *linhas); 

//função criada para passar os dados do arquivo e passar para a variavel do cogigo principal;
void PassarDados(char *NomeDoArquivo, Cliente** pessoa, int *quantidade);

//função criada para adicionar um novo cliente;
void AdicionarNovoCliente(char *NomeDoArquivo, Cliente** usuario, int *quantidade);

//função criada para buscar os ususarios pelo codigo, esta função utiliza o algoritmo de busca jumpsearch;
int JumpSearchCod(Cliente** usuarios, int *n, int *codigo);

//função criada para verificar o resuldado da busca jumpsearch por codigo;
void VerificaBuscaCod(Cliente **usuario, int *codigo, int *retorno, double *tempo);

//função criada para verificar o resuldado da busca jumpsearch por nome;
void VerificaBuscaNome(Cliente **usuario, int *retorno, double *tempo);

//função auxiliar para ordenar pelo codigo;
int comparar_codigo(const void *a, const void *b);

//função auxiliar para ordenar pelo nome;
int comparar_nome(const void *a, const void *b);
