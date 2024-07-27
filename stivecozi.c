#include<stdio.h>
#include<stdlib.h>
#include "cozi.h"
#include "cozi_miercuri.c"
#include<time.h>

int generateRandomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main(){

    srand(time(NULL));

    Queue *intai,*doi;
    int ok1=0,ok2=0;

    intai=createQueue();
    doi=createQueue();

    int n1,n2;
    n1=generateRandomInRange(70,90);
    n2=generateRandomInRange(70,90);
    
    for(int i=1;i<=n1;i++)
    enQueue(intai,i);

    for(int i=1;i<=n2;i++)
    enQueue(doi,i);
   
   if(n1>n2){
   enQueue(doi,0);
   ok2=1;
   }
   else{
   enQueue(intai,0);
   ok1=1;
   }
  printf("cozile inainte:\n");
  printQueue(intai);
  printQueue(doi);

   int i1,i2;
   i1=generateRandomInRange(1,7);
   i2=generateRandomInRange(1,7);

   n1=n1-i1;
   n2=n2-i2;

   for(int i=0;i<i1;i++)
     deQueue(intai);

    for(int i=0;i<i2;i++)
     deQueue(doi);

    if(n1>n2){
        if(ok2==0)
        enQueue(doi,0);
        deQueuerear(intai);
    }
    else {
        if(ok1==0)
        enQueue(intai,0);
        deQueuerear(doi);
    }

   printf("cozile dupa:\n");
   printQueue(intai);
   printQueue(doi);
   if(intai->rear->val==0)
     printf("numar masini ramase banda 1 este:%d",n1);
     else
      printf("numar masini ramase banda 2 este:%d",n2);
}