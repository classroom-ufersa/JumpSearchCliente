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

