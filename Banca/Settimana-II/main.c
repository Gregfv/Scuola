#include <stdio.h>
#include <stdlib.h>

const char nomeBanca[] = "Guglu' Bank";

int main(int argc, char *argv[])
{
  int i, scelta;
  inizializza();
    
  //Barra di benvenuto
  for(i = 0; i < 80; i++) printf("=");
  printf("\n%s\n", nomeBanca);
  for(i = 0; i < 80; i++) printf("=");
  
  printf("\n\tCliente principale: %s", prendiNome());
  printf("\n\tBenvenuto in %s, la Banca di Dariol & Missaglia.\n\n", nomeBanca);
  printf("\t1. Verifica codice carta\n");
   
  printf("\n\tA quale servizio vuole accedere? ");
  scanf("%d", &scelta);
  
  switch(scelta){
               case 1: controlloCodice(); break;             
  }
  
  system("PAUSE");	
  return 0;
}
