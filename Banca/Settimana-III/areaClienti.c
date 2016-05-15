#include <stdio.h>

void loginCliente(){
	char nome[16], cognome[16], password[16];
	printf("Inserisci il tuo nome: "); scanf("%s", &nome);
	printf("Inserisci il tuo cognome: "); scanf("%s", &cognome);
	printf("Inserisci la tua password: "); scanf("%s", &password);
	int cliente = selezionaDaAnagr(nome, cognome);
	if(cliente != -1){
		if(strcmp(password, prendiPassword(cliente)) == 0) printf("OK");
		else printf("Maninalto");
	}
	else printf("Non esistente");
}
