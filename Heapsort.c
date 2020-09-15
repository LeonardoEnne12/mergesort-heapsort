#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void heap(int *vet,int i,int fim){
  int aux = vet[i];
  int j = (i*2)+1;
  while (j<= fim) {
    if(j<fim){
      if (vet[j] < vet[j+1]){
        j=j+1;
      }
    }
    if (aux < vet[j]){
      vet[i] = vet[j];
      i=j;
      j = (i*2)+1;
    }else{
      j=fim+1;
    }
  }
  vet[i]=aux;
}

/*void heapsort(int *vet, int N) {
  int i, aux;
    for (i = (N-1)/2;i >=0;i--) {
      heap(vet,i,N-1);}
    for (i = N-1;i >=1;i--) {
      aux = vet[0];
      vet[0]=vet[i];
      vet[i]=aux;
      heap(vet,0,i-1);
    }
}*/


int main(){
    int Num,i,aux;
    char aux1[15];
    scanf("%d",&Num);
    int *Vet = (int*) malloc(Num * sizeof(int));

    for(i=0; i < Num; i++){
        scanf("%d",&Vet[i]);
    }

    for (i = (Num-1)/2;i >=0;i--) {
      heap(Vet,i,Num-1);}
    for(i=0; i < Num; i++){
      printf("%d ",Vet[i]);
    }

    for (i = Num-1;i >=1;i--) {
      aux = Vet[0];
      Vet[0]=Vet[i];
      Vet[i]=aux;
      heap(Vet,0,i-1);
    }
    printf("\n");
    for(i=0; i < Num; i++){
      printf("%d ",Vet[i]);
    }


  return 0;
}
