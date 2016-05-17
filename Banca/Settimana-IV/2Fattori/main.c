#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	printf("Autenticazione a 2 fattori per Guglu Bank\n\n");
	printf("Inserisci il tuo codice cliente: "); 
	
	int cliente; scanf("%d", &cliente);
	
	char codice[9]; codice[8] = 0;
	
	//1. Caratteri di autenticità (primi 4)
	int n[5]; // a, b, c, d, k
	srand(time(NULL));
	n[4] = rand() % 64, n[0] = rand() % n[4], n[1] = rand() % n[4]; //k varia da 0 a 63 (rappresentabili in Base 64)	
	n[2] = n[4] - n[0], n[3] = n[4] - n[1];
	
	int i;
	for(i = 0; i < 4; i++) codice[i] = aBase64(n[i]);
	
	//2. Caratteri di validità (secondi 3)
	time_t data = time(NULL);
	struct tm *dataInfo = gmtime(&data);
	
	int giorno = dataInfo -> tm_mday, ora = dataInfo -> tm_hour, minuti = dataInfo -> tm_min;
	codice[4] = aBase64(giorno + n[4] / 2);
	codice[5] = aBase64(ora + n[4] / 2);
	codice[6] = aBase64(64 - minuti);
	
	//3. Carattere di identita
	codice[7] = aBase64(cliente + giorno / 2) ;
	
	printf("\nIl tuo codice e': %s. Utilizzalo attraverso la piattaforma centrale entro il minuto.", codice);
	
	return 0;
}
