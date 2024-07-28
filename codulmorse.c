#include "morse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Node* root = NULL;
    char *word1,*word2;
    char*codul1,*codul2;
    Elem*size=NULL;

    word1=(char *)malloc(12*sizeof(char));
    createList(&size);
    codul1=(char *)malloc(50*sizeof(char));

    word2=(char *)malloc(12*sizeof(char));
    codul2=(char *)malloc(50*sizeof(char));

    printf("cuvantul 1 este :");
    scanf("%s",word1);

    printf("cuvantul 2 este :");
    scanf("%s",word2);

    root = createTree(root);
    codmorse(root);

    bfs(root,&size);
    
    
    printf("codul este:\n");
    codificare(root,word1,&size,codul1);
    codificare(root,word2,&size,codul2);

    printf("%s //// %s",codul1,codul2);

    if(strcmp(codul1,codul2)==0)
     printf("la fel");
     else
     printf("diferite");

    freeTree(root);
    free(word1);
    free(word2);
    free(codul1);
    free(codul2);
    return 0;
}
