#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ArquivoNome "Lista.txt"

//definindo uma struct para armazenar os dados dos clientes;
typedef struct cliente Cliente;

//função criada para mostrar os usuarios cadastrados;
void VerClientes(Cliente** usuario,int *quantidade);

//função adicionada para adicionar um novo cliente
void NovoCliente(Cliente** usuario,int *quantidade);

//função para contar a quantidades de alunos;
void ContarAlunos(char *NomeDoArquivo, int *linhas); 

//função criada para passar os dados do arquivo e passar para a variavel do cogigo principal;
void PassarDados(char *NomeDoArquivo, Cliente** pessoa, int *quantidade);

//função criada para adicionar um novo cliente;
void AdicionarNovoCliente(char *NomeDoArquivo, Cliente** usuario, int *quantidade);

//função criada para buscar os ususarios pelo codigo, esta função utiliza o algoritmo de busca jumpsearch;
int jumpSearch(Cliente** usuarios, int *n, int *codigo);