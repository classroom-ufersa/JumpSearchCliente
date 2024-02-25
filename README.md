<h1 align="center">Grupo 05: Busca de clientes com Jump Search</h1>

## Componentes da equipe
- [Éverson Alisson Queiroz Silva](https://github.com/Everson-Alisson)
- [Francisco Lailson de Almeida](https://github.com/lailsonzw)
- [Luiz Eduardo de A. Rodrigues](https://github.com/LuizEdu-AR)
- [Tobias Fernandes Figueiredo](https://github.com/Tobias-fernandes)


### Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

## Sobre o projeto

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

## O que seria o Jump Search

O jump search é basicamente um algoritmo de busca eficiente para encontrar um determinado elemento em um array que está ordenado.

Também conhecido como Pesquisa por Salto, ele é chamado assim pois ao invés de pesquisar um elemento de forma linear, ele "salta" entre diferentes posições de um array com base em um cálculo matemático.

Permitindo, assim, que seja encontrado um elemento dentro de um array realizando um número menor de comparações do que em uma busca simples.

## Quais as etapas desse algoritmo

  - 1-  A pesquisa sempre começa no início do array.
  - 2-  Defina o tamanho do salto:
    Para pesquisar utilizando este algoritmo, primeiramente é necessário definir um tamanho para este salto para determninar para qual posição do array pular a cada iteração. Geralmente desse valor é definido usando a raiz quadrada do tamanho total do array (ex. Se um array possui 100 posições, a cada iteração o algoritmo saltará 10 posições no array ).
  - 3-  Compare os elementos com o valor desejado: Caso o valor desejado for igual ao valor lido ma posição do array, a pesquisa terminará e o valor será encontrado.
  - 4-  Calcule a próxima posição de salto: Se o elemento na posição atual não for igual ao valor desejado, algoritmo calcula a próxima posição de salto usando o tamanho do salto.
  - 5-  Caso o valor na posição atual do array for maior do que o valor que está sendo procurado, o algoritmo volta à posição do salto anterior e começa uma busca linear no array.
