<h1 align="center">Grupo 05: Busca de clientes com Jump Search</h1>

## Doscente da turma
- [Rosana Cibely Batista Rego](https://github.com/roscibely)

## Componentes da equipe
- [Éverson Alisson Queiroz Silva](https://github.com/Everson-Alisson)
- [Francisco Lailson de Almeida](https://github.com/lailsonzw)
- [Luiz Eduardo de A. Rodrigues](https://github.com/LuizEdu-AR)
- [Tobias Fernandes Figueiredo](https://github.com/Tobias-fernandes)


## Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

### Sobre o projeto

Implemente um algoritmo que manipula um tipo estruturado Clientes e possui a funcionalidade de buscar clientes em um arquivo.

Os clientes devem ter os atributos básicos:
  - Nome;
  - Endereço;
  - Código do cliente;

Requisitos
  - A cada execução do programa, ele deve carregar os dados (Armazenados em um arquivo texto);
  - O programa deve perguntar ao usuário qual cliente ele deseja buscar por nome ou código com o algoritmo Jump Search;
  - Compute o tempo de execução do processo de busca;
  - Informe a complexidade do algoritmo Jump Search;

### O que seria o Jump Search

O jump search é basicamente um algoritmo de busca eficiente para encontrar um determinado elemento em um array que está ordenado.

Também conhecido como Pesquisa por Salto, ele é chamado assim pois ao invés de pesquisar um elemento de forma linear, ele "salta" entre diferentes posições de um array com base em um cálculo matemático.

Permitindo, assim, que seja encontrado um elemento dentro de um array realizando um número menor de comparações do que em uma busca simples.

<img src="https://github.com/classroom-ufersa/JumpSearchCliente/blob/main/assets/image3.png" />


### Quais as etapas desse algoritmo

  - 1-  A pesquisa sempre começa no início do array.
  - 2-  Defina o tamanho do salto:
    Para pesquisar utilizando este algoritmo, primeiramente é necessário definir um tamanho para este salto para determninar para qual posição do array pular a cada iteração. Geralmente desse valor é definido usando a raiz quadrada do tamanho total do array (ex. Se um array possui 100 posições, a cada iteração o algoritmo saltará 10 posições no array ).
  - 3-  Compare os elementos com o valor desejado: Caso o valor desejado for igual ao valor lido ma posição do array, a pesquisa terminará e o valor será encontrado.
  - 4-  Calcule a próxima posição de salto: Se o elemento na posição atual não for igual ao valor desejado, algoritmo calcula a próxima posição de salto usando o tamanho do salto.
  - 5-  Caso o valor na posição atual do array for maior do que o valor que está sendo procurado, o algoritmo volta à posição do salto anterior e começa uma busca linear no array.

### Vantagens
 - Mais eficiente que a busca linear: O Jump Search é mais eficiente que a busca linear, pois realiza menos comparações em média.
 - Menos eficiente que a busca binária: O Jump Search é menos eficiente que a busca binária, mas é mais fácil de implementar.
 
### Desvantagens
 - Menos eficiente que a busca binária: O Jump Search é menos eficiente que a busca binária, especialmente para arrays grandes.
 - Pior caso: O pior caso do Jump Search é O(n), o mesmo que a busca linear.

## Implementação

  ## Pesquisa por código:

    
  <img src="https://github.com/classroom-ufersa/JumpSearchCliente/blob/main/assets/JSC-codigo.png" />
    
  #### Declaração de variáveis:

  usuarios: Array que armazena os dados dos usuários.
  n: Tamanho do array "usuarios".
  salto: Tamanho do salto a ser utilizado na busca.
  codigo: Código do usuário que está sendo buscado.
  posicao: Posição do usuário encontrado no array.

  #### Cálculo do salto:

  A variável "salto" é calculada como a raiz quadrada do tamanho do array "usuarios" (n). Essa fórmula garante um bom     equilíbrio entre a eficiência da busca e a simplicidade do código.

  #### Busca usando loop while:

  Um loop while é usado para percorrer o array "usuarios" de forma eficiente.
  A condição do loop verifica se a posição atual (posicao) é menor que o código desejado (codigo).
  Se a condição for verdadeira, o loop realiza as seguintes ações:
  A variável "posicao" é incrementada em "salto".
  Se a nova posição for maior que o tamanho do array, o loop é encerrado.

  #### Busca linear:

  Se o loop while não encontrar o código desejado, uma busca linear é realizada para verificar se o código está presente em     algum dos elementos restantes do array.
  A busca linear percorre o array elemento por elemento, comparando o código de cada elemento com o código desejado.
  
  #### Retorno do resultado:

  Se o código for encontrado, a função retorna a posição do elemento encontrado no array.
  Se o código não for encontrado, a função retorna -1.

  ## Pesquisa por nome:

    
<img src="https://github.com/classroom-ufersa/JumpSearchCliente/blob/main/assets/JSC-nome.png" />

  #### Parâmetros:

  cliente: Ponteiro para um array de structs do tipo Cliente.
  QuantidadeDeClientes: Ponteiro para um inteiro que armazena o número de clientes no array.
  nome: Ponteiro para uma string que armazena o nome do cliente que está sendo buscado.
  Funcionamento:

  #### Cálculo do salto: 

  A função calcula o tamanho do salto a ser utilizado na busca como a raiz quadrada do número de clientes (QuantidadeDeClientes).

  #### Ordenação do array: 

  A função ordena o array de clientes por nome usando a função qsort. Essa ordenação é necessária para que a busca binária funcione corretamente.

  #### Busca binária: 

  A função realiza uma busca binária no array ordenado para encontrar o cliente com o nome especificado.

  A busca binária compara o nome do cliente com o nome do cliente no meio do array.
  Se o nome do cliente for menor que o nome do cliente no meio do array, a busca continua na metade inferior do array.
  Se o nome do cliente for maior que o nome do cliente no meio do array, a busca continua na metade superior do array.
  A busca continua até que o cliente seja encontrado ou que se determine que o cliente não existe no array.

  #### Retorno do resultado:

  Se o cliente for encontrado, a função retorna a posição do cliente no array.
  Se o cliente não for encontrado, a função retorna -1.

## Conclusão
Após desenvolver o algoritmo para busca de clientes por nome ou código utilizando o método Jump Search, podemos concluir que esta abordagem oferece uma maneira eficiente de localizar informações em grandes conjuntos de dados. 

Durante a execução do programa, pudemos observar que o tempo necessário para encontrar o cliente desejado foi relativamente rápido, mesmo em arquivos de tamanho considerável. Isso demonstra a eficácia do algoritmo Jump Search em otimizar o processo de busca, resultando em uma experiência mais ágil para o usuário.

Ao analisar a complexidade do algoritmo, percebemos que o Jump Search possui uma complexidade de tempo de O(√n), onde 'n' é o número de elementos no arquivo de clientes. Isso significa que, apesar de não ser tão eficiente quanto algoritmos de busca como o Binary Search (O(log n)), o Jump Search ainda oferece um desempenho bastante satisfatório, especialmente em conjuntos de dados não ordenados.

Em suma, a implementação do algoritmo Jump Search nos permitiu criar um programa capaz de buscar clientes de forma rápida e eficiente, proporcionando uma experiência mais fluida ao usuário durante a utilização do sistema.
