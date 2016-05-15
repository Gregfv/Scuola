#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTI 20

//Peso unitario massimo: 80 bytes
struct cliente {
       char nome[16]; 
       char cognome[16];
       char password[16];
       double credito;
       double reddito;
       char cartaCredito[16];
       int haMutuo;
};

struct cliente clienti[MAX_CLIENTI]; //Array di clienti (contiene oggetti-struttura cliente)
char* prendiNome(int i){
	return clienti[i-1].nome;
}
char* prendiCognome(int i){
	return clienti[i-1].cognome;
}
char* prendiCarta(int i){
	return clienti[i-1].cartaCredito;
}
char* prendiPassword(int i){
	return clienti[i-1].password;
}
int selezionaDaAnagr(char* nome, char* cognome){
	int i;
	for(i = 0; i < MAX_CLIENTI; i++){
		if(strcmp(clienti[i].cognome, cognome) == 0 && strcmp(clienti[i].nome, nome) == 0) return i + 1;
	}
	return -1;
}
double prendiCapitale(int i){
	return clienti[i-1].credito;
}

int inizializza(){
	printf("%s", "\t\tBenvenuto in Guglu Bank\n\n");
	printf("%s", "Inizializzazione del client...\n");
  	
  	printf("\t1. Ottengo i dati dei clienti...\n");
  	printf("\t\tUtilizzo il formato standard: [Nome, Cognome, Password, Capitale, Reddito, CC, Mutuo?]\n");
	
    FILE *dbClienti;
    dbClienti = fopen("Database/clienti.txt", "r+");
    if (dbClienti == NULL) return 1;
    else {    
         char infoClienti[89]; //88 = lunghezza unitaria cliente + caratteri di controllo
         
         //Ciclo per ogni riga (per ogni cliente)
         int i = 0;
         while (fgets(infoClienti, 100, dbClienti) != NULL){
         		printf("\t\tParsing del cliente num. %d: %s", i + 1, infoClienti);
               struct cliente nuovoCliente; //Istanzio un nuovo cliente temporaneo da compilare
               
               //Ciclo per ogni campo o separatore (per ogni info di ogni cliente)
               int datoCorrente = 0, //Indica il field che si sta leggendo dal file (nome? cognome? credito? ...)
			   cursore = 1; //Itera per ogni carattere della riga
               while(datoCorrente < 5) {
               	
                    char campoTemp[16] = { 0 }; //Stringa temporanea da leggere  
                       
                    //Ciclo per ogni carattere (per ogni carattere di ogni info di ogni cliente)
                    int primoCarattereVuoto = 0; //Indica qual'è il primo indice vuoto del field temporaneo 
					int	fine = 0; //Sentinella per fine della sezione
						
                    while(fine == 0 ){
                       	if(infoClienti[cursore] == ']' || infoClienti[cursore] == ',') fine = 1;
                       	else{
                        		
                       		campoTemp[primoCarattereVuoto] = infoClienti[cursore];
                       		primoCarattereVuoto++;  	
						}
						cursore++;
                    }
					              
                    
						
					switch(datoCorrente){
						case 0: strcpy(nuovoCliente.nome, campoTemp); break;
						case 1: strcpy(nuovoCliente.cognome, campoTemp); break;
						case 2: strcpy(nuovoCliente.password, campoTemp); break;
						case 3: nuovoCliente.credito = atof(campoTemp); break;
						case 4: nuovoCliente.reddito = atoi(campoTemp); break;
						case 5: strcpy(nuovoCliente.cartaCredito, campoTemp); break;
						case 6: nuovoCliente.haMutuo = atoi(campoTemp); break;
					}
                
					datoCorrente++;
               }
               clienti[i] = nuovoCliente;
               i++;
         }
         
    }
    
    printf("\t2. Controllo i getters\n");
    char nome[16] = "Alfio";
	char cognome[16] = "Missaglia";
    printf("\t\tIl nome del cliente num. 3 e': %s\n", prendiNome(3));
    printf("\t\tIl capitale del cliente num. 5 e': %f\n", prendiCapitale(5));
    printf("\t\tIl capitale del cliente %s %s e': %f\n", nome, cognome, prendiCapitale(selezionaDaAnagr(nome, cognome)));
    
    printf("\t3. Controllo l'algoritmo di crittografia...\n");
	const char chiave[16] = "Guglupullumunito"; 
  	char crittografa[17] = "4023517788763452\0";
  	printf("\t\tStringa di partenza: %s\n", crittografa);
  	printf("\t\tStringa criptata: %s\n", cripta(chiave, crittografa, 16));
  	printf("\t\tStringa decriptata: %s\n", decripta(chiave, cripta(chiave, crittografa, 16), 16));
  	printf("\t\tIl processo inverso funziona correttamente?\n");
  	
  	
  	printf("\nPremi un tasto per continuare verso l'area clienti... "); getch();
    system("cls");
}
