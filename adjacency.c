#include <stdio.h> 
#include <stdlib.h> 
#define MAX_NOS 11 
 void escreve_arq(int n_origin, int n_destin){
  FILE *fl;  
  
  fl = fopen("teste.txt", "r");
  
  if(fl == NULL){
        printf("The file was not opened\n");
        return ; 
  } 
  fprintf(fl, "%d %d\n",n_origin,n_destin);
  fclose(fl);
} 
int main() {   
    FILE   *file;  
    file = fopen("resultado.txt","a");
    if(file== NULL){
            printf("The file was not opened\n");
            return 0 ; 
    }
    int count = 0;
    int node_origin, node_destin ;   
    int **coordenadas = (int**)malloc(MAX_NOS * sizeof(int*)); 
    FILE *fl; 
    fl = fopen("teste.txt", "r");  
    for(int i = 0; i< MAX_NOS; i++) {
        coordenadas[i] = (int*)malloc(MAX_NOS * sizeof(int));
    }
    for(int i = 0 ; i < MAX_NOS ; i++){ 
        for(int j = 0 ; j< MAX_NOS; j++){  
            coordenadas[i][j] = 0 ; 
        }
    }   
    // texto  
    if(fl == NULL){
        printf("The file was not opened\n");
        return 0  ; 
    }
    while(!feof(fl)){      
        fscanf(fl,"%d %d",&node_origin, &node_destin);   
        printf(" %d-> %d\n",node_origin, node_destin);   
        if(feof(fl)) break ; 

        if(node_origin < MAX_NOS && node_destin < MAX_NOS){
            if (coordenadas[node_origin][node_destin] == 0 && coordenadas[node_destin][node_origin] == 0){  
                coordenadas[node_origin][node_destin] = 1 ; 
                coordenadas[node_destin][node_origin] = 1 ;   

            
            } 
        } 
        
    }  
    for(int i = 1; i < MAX_NOS ; i++){ 
        for(int j = 1 ;j < MAX_NOS; j++)
             printf("%d     ", coordenadas[i][j]);
        printf("\n");
    }
    for(int i = 1; i < MAX_NOS ; i++){ 
        for(int j = 1 ;j < MAX_NOS; j++)
             if(coordenadas[i][j] == 1 ) count++;
    
        
    } 


    printf("Count: %d", count); 

    for(int i=1;i<MAX_NOS;i++) {
        for(int j=1;j<MAX_NOS;j++) {
            fprintf(file,"%d ",coordenadas[i][j]);
    }
        fprintf(file,"\n"); 
    }

    return 0;
}

    //struct MatrizADJ *Matriz = memb_alloc(&matriz_memb);    
   
   
  
