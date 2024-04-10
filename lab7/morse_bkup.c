#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct N {
  char lit;
  struct N *left, *right;
};
typedef struct N Node;

Node* createNode(char lit) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->lit = lit;
  newNode->left = newNode->right = NULL;
  return newNode;
}

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

int height(Node* root) {
  int hs, hd;
  if (root == NULL)
    return -1;
  hs = height(root->left);
  hd = height(root->right);
  return 1 + ((hs > hd) ? hs : hd);
}

void printLevel(Node* root, int level) {
  if (root == NULL)
    return;
  if (level == 0)
    printf("%c ", root->lit);
  else if (level > 0) {
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
  }
}

char* getLevel(Node* root, int level, char* arr, int* index) {
  if (root == NULL)
    return arr;
  if (level == 0) {
    arr[*index] = root->lit;
    (*index)++;
  } else if (level > 0) {
    getLevel(root->left, level - 1, arr, index);
    getLevel(root->right, level - 1, arr, index);
  }
}

// void levelOrderTraversal(Node* root) {
//   int h = height(root);
//   int i;
//   for (i = 0; i <= h; i++) {
//     // printLevel(root, i);
//     char* level = (char*)malloc(100 * sizeof(char));
//     int index = 0;
//     getLevel(root, i, level, &index);
//     for (int j = 0; j < index; j++)
//       printf("%c ", level[j]);
//     printf("\n");
//   }
//   return;
// }

// EFFICIENT ROUTE

void encodeAlphabet(Node* root, char** morseCode, char* code, int depth) {
  if (root == NULL)
    return;
  if (root->lit != '_') {
    code[depth] = '\0';
    morseCode[root->lit - 'a'] = malloc((strlen(code) + 1) * sizeof(char));
    strcpy(morseCode[root->lit - 'a'], code);
  }
  code[depth] = '.';
  encodeAlphabet(root->left, morseCode, code, depth + 1);
  code[depth] = '-';
  encodeAlphabet(root->right, morseCode, code, depth + 1);
}

char* encodeWord(char** morseCode, char* word) {
  char* res = (char*)malloc(100 * sizeof(char));
  for (int i = 0; word[i]; i++) {
    // printf("%s ", morseCode[word[i] - 'a']);
    strcat(res, morseCode[word[i] - 'a']);
  }
  return res;
}

// INEFFICIENT ROUTE

// char* encodeLetter(Node* root, char letter, char* code, int depth) {
//   if (root == NULL)
//     return NULL;

//   if (root->lit == letter) {
//     code[depth] = '\0';
//     return code;
//   }

//   code[depth] = '.';
//   char* left = encodeLetter(root->left, letter, code, depth + 1);
//   if (left != NULL)
//     return left;

//   code[depth] = '-';
//   char* right = encodeLetter(root->right, letter, code, depth + 1);
//   if (right != NULL)
//     return right;

//   return NULL;
// }

// char* encodeString(Node* root, char* message) {
//   int i;
//   char* res = (char*)malloc(100 * sizeof(char));
//   char* code = (char*)malloc(100 * sizeof(char));
//   for (i = 0; i < strlen(message); i++) {
//     code = encodeLetter(root, message[i], code, 0);
//     strcat(res, code);
//   }
//   return res;
// }

//     bool
//     sameEncoding(char* word1, char* word2, Node* root) {
//   if (strcmp(encodeString(root, word1), encodeString(root, word2)) == 0)
//     return true;
//   return false;
// }
int main() {
  Node* root = NULL;
  root = createTree(root);
  // levelOrderTraversal(root);

  char* morseCode[26];
  char code[100];
  encodeAlphabet(root, morseCode, code, 0);

  for (int i = 0; i < 26; i++)
    printf("%c: %s\n", i + 'a', morseCode[i]);

  char* encodedWord = encodeWord(morseCode, "hello");
  printf("Encoded message for hello is \n%s\n", encodedWord);

  // char* message = "hello";
  // char* encodedMessage = encodeString(root, message);

  // printf("Encoded message for %s is \n%s\n", message, encodedMessage);

  // char* cites = "cites";
  // char* tribe = "tribe";

  // if (sameEncoding(cites, tribe, root))
  //   printf("The word %s with the word %s have the same morse code\n", cites,
  //          tribe);
  // else
  //   printf("The word %s has a different morse code than %s\n", cites, tribe);

  return 0;
}