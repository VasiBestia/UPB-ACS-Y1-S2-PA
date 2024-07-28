#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  float val;
  struct Node *left, *right;
} Node;

Node* newNode(float val) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->left = node->right = NULL;
  return node;
}

Node* insert(Node* root, float val) {
  if (root == NULL)
    return newNode(val);
  if (val < root->val)
    root->left = insert(root->left, val);
  else if (val > root->val)
    root->right = insert(root->right, val);
  return root;
}

Node* search(Node* root, float val) {
  if (root == NULL || root->val == val)
    return root;
  if (root->val < val)
    return search(root->right, val);
  return search(root->left, val);
}

Node* RotateRight(Node* root) {
  Node* newNode = root->left;
  Node* tempNode = newNode->right;
  newNode->right = root;
  root->left = tempNode;
  return newNode;
}

Node* RotateLeft(Node* root) {
  Node* newNode = root->right;
  Node* tempNode = newNode->left;
  newNode->left = root;
  root->right = tempNode;
  return newNode;
}

Node* RotateRightLeft(Node* root) {
  root->right = RotateRight(root->right);
  return RotateLeft(root);
}

Node* RotateLeftRight(Node* root) {
  root->left = RotateLeft(root->left);
  return RotateRight(root);
}

void preorder(Node* root) {
  if (root != NULL) {
    printf("%.2f ", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}

int height(Node* root) {
  int hs, hd;
  if (root == NULL)
    return -1;
  hs = height(root->left);
  hd = height(root->right);
  return 1 + ((hs > hd) ? hs : hd);
}

float max(float a, float b) {
  return (a >= b) ? a : b;
}

float min(float a, float b) {
  return (a <= b) ? a : b;
}

int isBST(Node* root, float min, float max) {
  if (root == NULL)
    return 1;
  if (root->val < min || root->val > max)
    return 0;
  return isBST(root->left, min, root->val) &&
         isBST(root->right, root->val, max);
}

int isBalanced(Node* root) {
  if (root == NULL)
    return 1;
  int hs = height(root->left);
  int hd = height(root->right);
  return (abs(hs - hd) <= 1) && isBalanced(root->left) &&
         isBalanced(root->right);
}

void printLevel(Node* root, int level) {
  if (root == NULL) {
    printf("_ ");
    return;
  }
  if (level == 0)
    printf("%.2f ", root->val);
  else if (level > 0) {
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
  }
}

void levelOrderTraversal(Node* root) {
  int h = height(root);
  int i;
  for (i = 0; i <= h; i++) {
    printLevel(root, i);
    printf("\n");
  }
  printf("\n");
  return;
}

void redistributeWealth(Node* root,
                        float value_to_add,
                        int maxVal,
                        int newWealth) {
  if (root == NULL)
    return;

  if (root->val == maxVal) {
    root->val = newWealth;
  }

  root->val += value_to_add;
  redistributeWealth(root->left, value_to_add, maxVal, newWealth);
  redistributeWealth(root->right, value_to_add, maxVal, newWealth);
}

int main() {
  int averi[8] = {12, 10, 32, 24, 16, 22, 19, 23};

  Node* root = NULL;
  for (int i = 0; i < 8; i++)
    root = insert(root, averi[i]);

  levelOrderTraversal(root);

  Node *p, *c;
  p = search(root, 24);
  c = search(root, 16);
  p->left = RotateLeft(c);

  levelOrderTraversal(root);

  p = search(root, 32);
  c = search(root, 24);
  p->left = RotateRight(c);

  levelOrderTraversal(root);

  p = search(root, 12);
  c = search(root, 32);
  p->right = RotateRight(c);

  levelOrderTraversal(root);

  p = search(root, 22);
  c = search(root, 32);
  p->right = RotateRight(c);

  levelOrderTraversal(root);

  root = RotateLeft(root);

  levelOrderTraversal(root);

  int maxVal = averi[0];
  int minVal = averi[0];
  for (int i = 1; i < 8; i++) {
    maxVal = max(maxVal, averi[i]);
    minVal = min(minVal, averi[i]);
  }

  printf("Max value: %d\n", maxVal);

  int percentage = 40;
  int num_of_elements = 8;

  float newWealth = maxVal - (float)(percentage * maxVal) / 100;

  printf("new Wealth: %.2f\n", newWealth);

  float value_to_add = (float)(percentage * maxVal) / 100 / num_of_elements;

  printf("Value to add: %.2f\n", value_to_add);

  redistributeWealth(root, value_to_add, maxVal, newWealth);

  levelOrderTraversal(root);

  int isAVLTRee = isBalanced(root) && isBST(root, maxVal, minVal);

  if (isAVLTRee)
    printf("The tree is an AVL tree\n");
  else
    printf("The tree is not an AVL tree\n");

  return 0;
}