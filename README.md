# Projeto de Árvore de Decisão em C

Este projeto implementa uma árvore de decisão em C, que é usada para fazer escolhas baseadas em uma série de perguntas. Cada nó da árvore contém uma pergunta ou uma resposta.

## Estrutura de Dados

A estrutura principal usada neste projeto é um nó (`Node`), que pode conter uma pergunta ou uma resposta e referências para os nós filhos (esquerda e direita).

## Funcionalidades

### Criação de Nó

Função que cria um novo nó, podendo ser uma pergunta ou uma resposta.

### Adição de Perguntas e Respostas

Função que adiciona perguntas e respostas a um nó existente, criando subárvores para as respostas "sim" e "não".

### Liberação de Memória

Função que libera a memória alocada para a árvore, garantindo que não haja vazamentos de memória.

## Uso do Programa

### Estrutura da Árvore

O programa inicializa uma árvore de decisão com a seguinte estrutura:

- Pergunta raiz: "Is it an animal?"
  - Se sim:
    - Pergunta: "Does it fly?"
      - Se sim: Resposta: "Bird"
      - Se não: Resposta: "Dog"
  - Se não:
    - Pergunta: "Is it electronic?"
      - Se sim: Resposta: "Computer"
      - Se não: Resposta: "Chair"

### Execução

O programa percorre a árvore de decisão com base nas respostas do usuário (`yes` ou `no`) às perguntas apresentadas, até alcançar uma resposta final.

### Exemplo de Execução

Quando o programa é executado, ele faz uma série de perguntas ao usuário e segue para o próximo nó com base na resposta do usuário.

```sh
Is it an animal? (yes/no): yes
Does it fly? (yes/no): no
Answer: Dog
```