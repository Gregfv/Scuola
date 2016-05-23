#include <stdio.h>
#include <stdlib.h>

const char chiave[16] = "Guglupullumunito"; 

char* prendiChiave(){
	return chiave;
}

char* cripta(char* k, char* p, int buffer){
      int i;
      char *output = malloc(buffer + 1);
      for(i=0; i < buffer; i++){
        output[i] = k[i] - p[i];
      }  
      output[16] = '\0';
      return output;
}

char* decripta(char* k, char* c, int buffer){
      int i;
      char *output = malloc(buffer + 1);
      for(i=0; i < buffer; i++){
        output[i] = k[i] - c[i];
      }  
      output[16] = '\0';
      return output;
}
