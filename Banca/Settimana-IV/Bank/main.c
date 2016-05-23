#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char nomeBanca[] = "Guglu' Bank";

int main(int argc, char *argv[])
{
  
  
  time_t attuale = time(NULL);
    
  int i, scelta;
  inizializza();
  char continuaOEsci;
  
  do{
  	system("cls");
	//Barra di benvenuto
  	for(i = 0; i < 80; i++) printf("=");
  	printf("%s\t\t\t\t\t%s", nomeBanca, asctime(localtime(&attuale)));
  	for(i = 0; i < 80; i++) printf("=");
  
  	printf("\n\tBenvenuto in %s, la Banca di Dariol & Missaglia.\n\n", nomeBanca);
  
  	printf("\t0. Accesso cliente\n");
  	printf("\t1. Verifica codice carta\n");
  	printf("\t2. Algoritmo di crittografia\n");
  	
   
  	printf("\n\tA quale servizio vuole accedere? ");
  	scanf("%d", &scelta);
  
  	switch(scelta){
  		case 0: loginCliente(); break;
    	case 1: controlloCodiceLuhn(); break;
  	}
  	
  	
  	printf("\nVuoi chiudere (x) o continuare (c) la sessione? ");
  	continuaOEsci = getch();
  }
  while (continuaOEsci != 'x');
   
  return 0;
}
