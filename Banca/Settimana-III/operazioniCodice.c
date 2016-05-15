#include <stdio.h>
#include <conio.h>

int controlloCodice(){
  const int numeroGruppi = 4;
  const int lunghGruppo = 4;
  int i, j, luhn = 0;
  char codice[numeroGruppi * lunghGruppo];
  
  system("cls");  
  
  printf("Questo sottoprogramma controlla la validita' di un codice di carta di credito / debito.\nLe cifre devono essere inserite a gruppi di 4.\n\n");
  printf("Primo\t\tSecondo\t\tTerzo\t\tQuarto\n");
  
  for(i = 0; i < numeroGruppi; i++){
  	  for(j = 0; j < lunghGruppo; j++){
  		codice[i * 4 + j] = getche();
	  }
	  printf("\t\t");
  }
  
  //Accumulo numero di Luhn
  for(i = 0; i < numeroGruppi * lunghGruppo; i++){
        j = codice[i] - '0';
        if(i % 2 == 0){
             j *= 2;
             if(j >= 10) j = j / 10 + j % 10;     
        }
        luhn += j;
  }
  
  printf("\n\n");
  
  printf("La carta ");
  for(i = 0; i < numeroGruppi; i++){
  	for(j = 0; j < lunghGruppo; j++) printf("%c", codice[i * 4 + j]);
  	printf(" ");
  }
  
  //Controllo validità e output
  if(luhn % 10 == 0){
  	printf("e' valida e appartiene al circuito: ");
  	
  	//Controllo del circuito
	switch(codice[0] - '0'){
		case 4: printf("Visa"); break;
		case 5: printf("MasterCard"); break;
		case 3: printf("American Express"); break;
		case 6: printf("Discover Card"); break;
		default: printf("Corto Circuito"); break;
	}
  }
  else printf("non e' valida");
  
  printf(".\n\n");
}
