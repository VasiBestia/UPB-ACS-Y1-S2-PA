#ifndef MORSE_H
#define MORSE_H

typedef struct N {
    char lit;
	char *code;
    struct N *left, *right;
} Node;

typedef struct E {
    char lit;
	char *code;
    struct E *next;
} Elem;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

// Structura pentru coadă
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Node* createNode(char lit);
Node* createTree(Node* root);
int height(Node* root);
void printLevel(Node* root, int level);
void levelOrderTraversal(Node* root);
void codmorse(Node*root);
void levelOrderTraversalcode(Node* root);
void printLevelcode(Node* root, int level);
void freeTree(Node* root);
Queue* createQueue() ;
void enqueue(Queue* queue, Node* treeNode);
Node* dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);
Elem* createelem(char lit,char *code);
void createList(Elem **List);
void addAtBeginning(Elem **head, char v,char *code);
Elem*bfs(Node*root,Elem**size);
void stackPrint(Elem **List);
char* codificare(Node*root,char*word,Elem**size,char*codul);
#endif // MORSE_H
