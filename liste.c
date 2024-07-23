#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float maximlcol(float a[5][5],int i){
   int max=a[0][i];
    for(int j=1;j<5;j++)
       if(a[j][i]>max)
       max=a[j][i];

    return max;
}

float mincol(float a[5][5],int i){
   float min=a[0][i];
    for(int j=1;j<5;j++)
       if(a[j][i]<min)
       min=a[j][i];

    return min;
}

int main() {
    srand(time(NULL));
    float a[5][5];
    float max[5],min[5];
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            a[i][j] = rand();
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<5;i++){
        max[i]=maximlcol(a,i);
        min[i]=mincol(a,i);
    printf("%f %f \n",max[i],min[i]);
    }


   for(int i=0;i<5;i++){
     for(int j=0;j<5;j++)
     a[i][j]=(a[i][j]-min[j])/(max[j]-min[j])+0;
   }
   

    printf("\n dupa scalare\n");

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
