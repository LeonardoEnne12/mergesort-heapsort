#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *Pvoto,int *Svoto,int *Tvoto,int inicio,int fim,int meio){
  int *vet,*vet1,*vet2,i,j,p1,p2,tam;
  int last1 = 0,last2 = 0;
  tam = fim - inicio + 1;
  p1=inicio;
  p2= meio + 1;
  vet = (int*) malloc(tam * sizeof(int));
  vet1 = (int*) malloc(tam * sizeof(int));
  vet2 = (int*) malloc(tam * sizeof(int));
    for (i = 0; i < tam ; i++) {
      if(last1 == 0 && last2 == 0){
        if (Pvoto[p1] < Pvoto[p2]){
          vet[i] = Pvoto[p1];
          vet1[i] = Svoto[p1];
          vet2[i] = Tvoto[p1];
          p1++;
        }
        else{
            vet[i] = Pvoto[p2];
            vet1[i] = Svoto[p2];
            vet2[i] = Tvoto[p2];
            p2++;
        }
        if(p1 > meio) last1=1;
        if(p2 > fim) last2=1;
      }else{
        if(last1 == 1){
        vet[i] = Pvoto[p2];
        vet1[i] = Svoto[p2];
        vet2[i] = Tvoto[p2];
        p2++;}
        if(last2 == 1){
          vet[i] = Pvoto[p1];
          vet1[i] = Svoto[p1];
          vet2[i] = Tvoto[p1];
          p1++;}
        }
    }
    for (i = 0 , j=inicio ; i < tam ; i++ , j++){
      Pvoto[j]= vet[i];
      Svoto[j]= vet1[i];
      Tvoto[j]= vet2[i];
    }
  free(vet);
  free(vet1);
  free(vet2);
}

void mergeSort(int *Pvoto,int *Svoto,int *Tvoto,int inicio,int fim) {

  if (inicio < fim){
    int meio;
    meio = floor((inicio+fim)/2);
    mergeSort(Pvoto,Svoto,Tvoto,inicio,meio);
    mergeSort(Pvoto,Svoto,Tvoto,meio + 1,fim);
    merge(Pvoto,Svoto,Tvoto,inicio,fim,meio);
  }
  return;
}



int main(){
  int Nelitores,Ncand,i,j,inicio=0,fim;
  float tam,val,val1=0.0,val2=0.0;
  scanf("%d %d",&Nelitores,&Ncand);

  int *Pvoto = (int*) malloc(Nelitores * sizeof(int));
  int *Svoto = (int*) malloc(Nelitores * sizeof(int));
  int *Tvoto = (int*) malloc(Nelitores * sizeof(int));
  int *count = (int*) malloc((Ncand) * sizeof(int));
  int *count1 = (int*) malloc((Ncand) * sizeof(int));
  float *count2 = (float*) malloc((Ncand) * sizeof(float));


  for (i=0;i<Nelitores;i++){
    scanf("%d %d %d",&Pvoto[i],&Svoto[i],&Tvoto[i]);
  }

  fim = Nelitores - 1;

  mergeSort(Pvoto,Svoto,Tvoto,inicio,fim);

  j=Ncand - 1;
  inicio = 0;
  fim = 0;
  count[0] == 0;

    for (i=0;i<Nelitores;i++){            //contagem de votos primero turno
      if (Pvoto[i]>=1 && Pvoto[i]<= Ncand){
        count[fim]= count[fim] + 1;
        count1[fim]=Pvoto[i];
        inicio++;}
      if(Pvoto[i] != Pvoto[i+1] && i <(Nelitores - 1)) fim++;
    }

    if (inicio != 0){
      for (i=0;i<Ncand;i++){
        tam = inicio;
        val=count[i];
        count2[i] = (val*100)/tam;
        if (count2[i] > val1){
          val1 = count2[i];
          fim = count1[i];}
      }
      printf("%d %.2f\n",fim,val1);

      for (i=0;i<Ncand;i++){
        if (count1[i] != fim){
          if (count2[i] > val2){
            val2 = count2[i];
            j=count1[i];}
        }
      }
      inicio = 0;
      count[0]=0;
      count[1]=0;
      if (val1 <= 50.00){
          for (i=0;i<Nelitores;i++){
            if(Pvoto[i] == fim || Pvoto[i] == j){
              inicio++;
              if (Pvoto[i] == fim){
                count[0] = count[0] + 1;}
              if (Pvoto[i] == j){
                count[1] = count[1] + 1;}
            }
            else if(Svoto[i] == fim || Svoto[i] == j){
              inicio++;
              if (Svoto[i] == fim){
                count[0] = count[0] + 1;}
              if (Svoto[i] == j){
                count[1] = count[1] + 1;}
            }
            else if(Tvoto[i] == fim || Tvoto[i] == j){
              inicio++;
              if (Tvoto[i] == fim){
                count[0] = count[0] + 1;}
              if (Tvoto[i] == j){
                count[1] = count[1] + 1;}
            }
          }
        tam = inicio;
        val=count[0];
        count2[0] = (val*100)/tam;
        val=count[1];
        count2[1] = (val*100)/tam;
        inicio = 0;
        if(count2[0] > count2[1]){
          printf("%d %.2f\n",fim,count2[0]);
          inicio++;}
        if(count2[1] > count2[0]){
          printf("%d %.2f\n",j,count2[1]);
          inicio++;}
        if(fim < j && inicio == 0) printf("%d %.2f\n",fim,count2[0]);
        if(fim > j && inicio == 0) printf("%d %.2f\n",j,count2[1]);
      }

      }
    else  printf("0\n");

  return 0;
}
