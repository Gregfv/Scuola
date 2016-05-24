#include <stdio.h>
#include <time.h>

int daBase64(char c){
	if(c < '9') return c + 52 - '0';
	if(c < 'Z') return c - 'A';
	if(c < 'z') return c + 26 - 'a';
	if(c == '+') return 62;
	if(c == '/') return 63;
}
char aBase64(int n){
	if(n <= 25) return 'A' + n;
	if(n <= 51) return n - 26 + 'a';
	if(n <= 61) return n  - 52 + '0';
	if(n == 62) return '+';
	if(n == 63) return '/';
}

int dueFattori(char* codice){
	int k = daBase64(codice[0]) + daBase64(codice[2]);
	if(k != daBase64(codice[1] + daBase64(codice[3]))) return 1;
	
	time_t data = time(NULL);
	struct tm *dataInfo = gmtime(&data);
	
	int giorno = dataInfo -> tm_mday, ora = dataInfo -> tm_hour, minuti = dataInfo -> tm_min;
	if(aBase64(giorno + k / 2) != codice[4]) return 1;
	if(aBase64(ora + k / 2) != codice[5]) return 1;
	if(aBase64(64 - minuti) != codice[6]) return 1;
	
	return 0;
}


void loginCliente(){
	char nome[16], cognome[16], password[16], codice[8];
	printf("Inserisci il tuo nome: "); scanf("%s", &nome);
	printf("Inserisci il tuo cognome: "); scanf("%s", &cognome);
	printf("Inserisci la tua password: "); scanf("%s", &password);
	printf("Inserisci il tuo codice: "); scanf("%s", &codice);
	int cliente = selezionaDaAnagr(nome, cognome);
	if(cliente != -1){
		if(strcmp(password, prendiPassword(cliente)) == 0 && dueFattori(codice) == 0) menuMutuo();
		else printf("Maninalto");
	}
	else printf("Non esistente");
}

void menuMutuo(){
  	for(i = 0; i < 80; i++) printf("=");
  	printf("%s\t\t\t\t\t%s", nomeBanca, asctime(localtime(&attuale)));
  	for(i = 0; i < 80; i++) printf("=");
  	
       printf("\t0. Mutuo\n");
  	   printf("\t1. Capitale\n");
       printf("\t2. ...\n");
       
       printf("\n\tA quale servizio vuole accedere? ");
  	scanf("%d", &scelta);
  	
  	switch(scelta){
  		case 0: mutuo); break;
    	case 1: (); break;
  	}
       
  	
}
