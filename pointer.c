#include<stdio.h>
#include<stdlib.h>

int *elemmedian(int *v){
    int aux;
    for(int i=0;i<7;i++)
     if(v[i]>v[i+1]){
        aux=v[i];
        v[i]=v[i+1];
        v[i+1]=aux;
     }
   return &v[3];
}

void stergere(int *v){
    for(int i=3;i<7;i++)
      v[i]=v[i+1];
}

int main(){
   int* v=(int *)malloc(7*sizeof(int));
   int *elem;
   int i=0;

   if(v==NULL)
   printf("memorie esuata");

     while (i < 7) {
        int value;
        scanf("%d", &value);

        if (value == 0) {
            break;  // Oprirea citirii la 0
        }

        v[i] = value;
        i++;
    }
   elem=elemmedian(v);


   printf("\n %d",*elem);

   v=(int*)realloc(v,6*sizeof(int));
   stergere(v);

   if(v==NULL)
    printf("realocare esuata");

    for(int j=0;j<6;j++)
    printf("%d ",v[j]);

    free(v);
}