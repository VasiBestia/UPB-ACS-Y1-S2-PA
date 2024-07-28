#include "morse.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Node* createNode(char lit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->lit = lit;
    newNode->code = (char*)malloc(10 * sizeof(char)); // Allocate memory for the code
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a Morse tree
Node* createTree(Node* root) {
    root = createNode('_');
    root->left = createNode('e');
    root->right = createNode('t');
    root->left->left = createNode('i');
    root->left->right = createNode('a');
    root->right->left = createNode('n');
    root->right->right = createNode('m');
    root->left->left->left = createNode('s');
    root->left->left->right = createNode('u');
    root->left->right->left = createNode('r');
    root->left->right->right = createNode('w');
    root->right->left->left = createNode('d');
    root->right->left->right = createNode('k');
    root->right->right->left = createNode('g');
    root->right->right->right = createNode('o');
    root->left->left->left->left = createNode('h');
    root->left->left->left->right = createNode('v');
    root->left->left->right->left = createNode('f');
    root->left->right->left->left = createNode('l');
    root->left->right->right->left = createNode('p');
    root->left->right->right->right = createNode('j');
    root->right->left->left->left = createNode('b');
    root->right->left->left->right = createNode('x');
    root->right->left->right->left = createNode('c');
    root->right->left->right->right = createNode('y');
    root->right->right->left->left = createNode('z');
    root->right->right->left->right = createNode('q');
    return root;
}

// Function to set Morse codes for each node in the tree
void codmorse(Node* root) {
    strcpy(root->code, "___");
    strcpy(root->left->code, ".");
    strcpy(root->right->code, "-");
    strcpy(root->left->left->code, "..");
    strcpy(root->left->right->code, ".-");
    strcpy(root->right->left->code, "-.");
    strcpy(root->right->right->code, "--");
    strcpy(root->left->left->left->code, "...");
    strcpy(root->left->left->right->code, "..-");
    strcpy(root->left->right->left->code, ".-.");
    strcpy(root->left->right->right->code, ".--");
    strcpy(root->right->left->left->code, "-..");
    strcpy(root->right->left->right->code, "-.-");
    strcpy(root->right->right->left->code, "--.");
    strcpy(root->right->right->right->code, "---");
    strcpy(root->left->left->left->left->code, "....");
    strcpy(root->left->left->left->right->code, "...-");
    strcpy(root->left->left->right->left->code, "..-.");
    strcpy(root->left->right->left->left->code, ".-..");
    strcpy(root->left->right->right->left->code, ".--.");
    strcpy(root->left->right->right->right->code, ".---");
    strcpy(root->right->left->left->left->code, "-...");
    strcpy(root->right->left->left->right->code, "-..-");
    strcpy(root->right->left->right->left->code, "-.-.");
    strcpy(root->right->left->right->right->code, "-.--");
    strcpy(root->right->right->left->left->code, "--..");
    strcpy(root->right->right->left->right->code, "--.-");
}

int height(Node*root){
	int hs, hd;
	if (root==NULL) return -1; 
	hs = height(root->left); 
	hd = height(root->right); 
	return 1+((hs>hd) ? hs:hd); 
}	

void printLevel(Node* root, int level){
	if (root == NULL)   return;
	if (level == 0) printf("%c ", root->lit);   
	else if (level > 0) {
		printLevel(root->left, level-1);
		printLevel(root->right, level-1);
	}
}

void levelOrderTraversal(Node* root){
	int h = height(root); 
	int i;
	for (i=0; i<=h; i++){ 
		printLevel(root, i);
		printf("\n");
	}
	return;
} 

void printLevelcode(Node* root, int level){
	if (root == NULL)   return;
	if (level == 0) printf("%c ", root->lit);   
	else if (level > 0) {
		printLevelcode(root->left, level-1);
		printLevelcode(root->right, level-1);
	}
}

void levelOrderTraversalcode(Node* root){
	int h = height(root); 
	int i;
	for (i=0; i<=h; i++){ 
		printLevelcode(root, i);
		printf("\n");
	}
	return;
} 

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add a node to the queue
void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to remove a node from the queue
Node* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    Node* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to create a new linked list element
Elem* createElem(char lit, char* code) {
    Elem* newNode = (Elem*)malloc(sizeof(Elem));
    newNode->lit = lit;
    newNode->code = strdup(code); // Duplicate the code string
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the linked list
void createList(Elem** list) {
    *list = NULL;
}

// Function to add an element to the beginning of the list
void addAtBeginning(Elem** head, char lit, char* code) {
    Elem* newNode = createElem(lit, code);
    newNode->next = *head;
    *head = newNode;
}

// Function to perform BFS and populate the linked list
Elem* bfs(Node* root, Elem** size) {
    if (root == NULL) return *size;
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isQueueEmpty(queue)) {
        Node* currentNode = dequeue(queue);
        addAtBeginning(size, currentNode->lit, currentNode->code);
        if (currentNode->left != NULL) enqueue(queue, currentNode->left);
        if (currentNode->right != NULL) enqueue(queue, currentNode->right);
    }
    return *size;
}

// Function to print the linked list
void stackPrint(Elem** list) {
    Elem* current = *list;
    printf("Lista este: ");
    while (current != NULL) {
        printf("%c: %s | ", current->lit, current->code);
        current = current->next;
    }
    printf("\n");
}
char* codificare(Node* root, char* word, Elem** size,char *codul) {
      codul[0]='\0';
    for (int i = 0; i < strlen(word); i++) {
        Elem *temp=*size;
        while (temp != NULL && word[i] != temp->lit) temp = temp->next;
        if (temp != NULL && word[i] == temp->lit) {
            strcat(codul,temp->code);
        }
    }
    return codul;
}

// Function to free the Morse tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root->code);
    free(root);
}

