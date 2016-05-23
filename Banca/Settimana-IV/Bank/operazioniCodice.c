#include <stdio.h>
#include <conio.h>

int controlloCodiceLuhn(){
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

char* calcolaCodiceFiscale(char* nome, char* cognome, char* giorno, char* mese, char* anno, char sesso, char* comune){
	char[16] output;
	int i;
	const int stdBuffer = 16;
	
	//La funzione strlen(char*, int) ha come argomenti: stringa e buffer. 
	for(i = 0; i < strlen(nome, stdBuffer); i++) if(nome[i] >= 97 && nome[i] <= 122) nome[i] -= 32;
	for(i = 0; i < strlen(cognome, stdBuffer); i++) if(cognome[i] >= 97 && cognome[i] <= 122) cognome[i] -= 32;
	
	//Da questo punto, nome e cognome sono normalizzati in caratteri MAIUSCOLI.
	//1. Prelevare le tre consonanti del cognome
	
		//1.1. Le consonanti non sono almeno 3? Fillare con le vocali.
		
		//1.2. Non ci sono abbastanza vocali? Fillare con le X.
	
	//2. Prelevare le tre consonanti del nome
		
		//2.1. Le consonanti sono più di 3? Saltare la seconda consonante.
		
		//2.2. Le consonanti non sono almeno 3? Fillare con le vocali.
		
		//2.3. Non ci sono abbastanza vocali? Fillare con le X.
		
	//3. Data di nascita
	
		//3.1. Prelevare le ultime due cifre dell'anno.
		
		//3.2. Scegliere la lettera corrispondente al mese.
		const char indice[] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};
		//Prova a relazionare la posizione delle lettere nell'array con il numero del mese!
		
		//3.3. A seconda del sesso lascia inalterato il giorno di nascita (uomo) o innalzalo di 40 (donna).
		if(sesso == 'F') giorno[0] += //Completa tu questa parte senza usare atoi().
		
	//4. Codice Belfiore
		 
		 //4.1. Caricare da file l'elenco catastale
		 
		 //4.2. Prelevare il valore dalla chiave
		 
	//5. Codice di controllo
	
	return //Completa tu.
}
