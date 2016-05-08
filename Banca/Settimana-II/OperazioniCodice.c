int controlloCodice(){
  const int lunghCodice = 16;
  const int lunghGruppo = 4;
  int codice[lunghCodice], i, j, luhn = 0, temp = 0;
  
  printf("\n\n");
  for(i = 0; i < 80; i++) printf("=");
  
  printf("Questo sottoprogramma controlla la validita' di un codice di carta di credito / debito.\nLe cifre devono essere inserite a gruppi di 4.\n\n");
  
  //Ciclo per ogni gruppo
  for(i = 0; i < lunghCodice / lunghGruppo; i++){
        printf("Inserisci il %d gruppo... ", i + 1);
        scanf("%d", &temp);
        
        //Ciclo per ogni cifra del gruppo
        int divisore = 1000, j = 0;
        while(j < lunghGruppo){
           codice[4 * i + j] = (temp / divisore) % 10;
           divisore /= 10;
           j++;
        }
  }
  
  //Accumulo numero di Luhn
  for(i = 0; i < lunghCodice; i++){
        temp = codice[i];
        if(i % 2 == 0){
             temp *= 2;
             if(temp >= 10) temp = temp / 10 + temp % 10;     
        }
        luhn += temp;
  }
  //Controllo validità e output
  if(luhn % 10 == 0) printf("Valido");
  else printf("Non valido");  
  
  printf("\n\n");
  for(i = 0; i < 80; i++) printf("=");
}
