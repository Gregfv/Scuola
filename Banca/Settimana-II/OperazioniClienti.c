#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
       char nome[16]; 
       char cognome[16];
       double credito;
       double reddito;
       char cartaCredito[16];
       int haMutuo;
};

struct cliente clienti[10]; //Array di clienti (contiene oggetti-struttura cliente)

int inizializza(){
    FILE *dbClienti;
    dbClienti = fopen("Database/clienti.txt", "r+");
    if (dbClienti == NULL) return 1;
    else {    
         char infoClienti[100]; //L'intero database di clienti viene copiato qui
         
         //Ciclo per ogni riga (per ogni cliente)
         int i = 0;
         while (fgets(infoClienti, 100, dbClienti) != NULL){
               struct cliente nuovoCliente; //Istanzio un nuovo cliente temporaneo da compilare
               
               //Ciclo per ogni campo o separatore (per ogni info di ogni cliente)
               int datoCorrente = 0, //Indica il field che si sta leggendo dal file (nome? cognome? credito? ...)
			   cursore = 1; //Itera per ogni carattere della riga
               while(datoCorrente < 6) {
               	
                    char campoTemp[16] = { 0 }; //Stringa temporanea da leggere  
                       
                    //Ciclo per ogni carattere (per ogni carattere di ogni info di ogni cliente)
                    int primoCarattereVuoto = 0, //Indica qual'è il primo indice vuoto del field temporaneo 
					fine = 0; //Sentinella per fine della sezione
						
                    while(fine == 0 && infoClienti[cursore] != ';'){
                    	
                       	if(infoClienti[cursore] == '[' || infoClienti[cursore] == ']' || infoClienti[cursore] == ',') fine = 1;
                       	else{
                        		
                       		campoTemp[primoCarattereVuoto] = infoClienti[cursore];
                       		primoCarattereVuoto++;  	
						}
						cursore++;
                    }
					campoTemp[primoCarattereVuoto] = '\0';               
                    
						
					switch(datoCorrente){
						case 0: strcpy(nuovoCliente.nome, campoTemp); break;
						case 1: strcpy(nuovoCliente.cognome, campoTemp); break;
						case 2: nuovoCliente.credito = atoi(campoTemp); break;
						case 3: nuovoCliente.reddito = atoi(campoTemp); break;
						case 4: strcpy(nuovoCliente.cartaCredito, campoTemp); break;
						case 5: nuovoCliente.haMutuo = atoi(campoTemp); break;
					}
                
					datoCorrente++;
               }
               clienti[i] = nuovoCliente;
               i++;
         }
         
    }
}

char* prendiNome(){
	return clienti[2].nome;
}
