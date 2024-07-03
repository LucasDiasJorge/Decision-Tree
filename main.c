#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar um nó da árvore de decisão
typedef struct Node {
    char *question;
    char *answer;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node* createNode(char *question, char *answer) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->question = question ? strdup(question) : NULL;
    newNode->answer = answer ? strdup(answer) : NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para adicionar perguntas e respostas a um nó
void addQuestion(Node *parent, char *question, char *yesAnswer, char *noAnswer) {
    parent->question = strdup(question);
    parent->left = createNode(NULL, yesAnswer);
    parent->right = createNode(NULL, noAnswer);
}

// Função para liberar a memória da árvore
void freeTree(Node *root) {
    if (root == NULL) return;
    if (root->question) free(root->question);
    if (root->answer) free(root->answer);
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Função principal
int main() {
    // Cria o nó raiz da árvore de decisão
    Node *root = createNode("Is it an animal?", NULL);

    // Adiciona perguntas e respostas
    addQuestion(root, "Is it an animal?", "Yes", "No");

    // Subárvore para "Yes"
    root->left->question = strdup("Does it fly?");
    root->left->left = createNode(NULL, "Bird");
    root->left->right = createNode(NULL, "Dog");

    // Subárvore para "No"
    root->right->question = strdup("Is it electronic?");
    root->right->left = createNode(NULL, "Computer");
    root->right->right = createNode(NULL, "Chair");

    // Exemplo de uso
    Node *current = root;
    while (current->question != NULL) {
        char answer[4];
        printf("%s (yes/no): ", current->question);
        scanf("%3s", answer);
        if (strcmp(answer, "yes") == 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("Answer: %s\n", current->answer);

    // Liberação de memória
    freeTree(root);

    return 0;
}
