#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  //int array[] = { -5, 2, 5, 6, 7, 98, 112, 234, 685, 2648};
  
  printf("Questo programma ricerca in modo dicotomico un intero in un array gia' ordinato di interi fornito.\n\n");
  
  const int max; int i;
  
  printf("Inserire la lunghezza dell'array dove cercare... "); scanf("%d", &max);
  int array[max];
  
  for(i = 0; i < max; i++){
        printf("Inserire l'elemento %d... ", i);
        scanf("%d", &array[i]);      
  }
  
  int ricercato;
  printf("Inserire l'intero ricercato... "); scanf("%d", &ricercato);
  
  int lim1 = 0, lim2 = sizeof(array)/4, mediana, trovato = -1;
  
  printf("\n\n");
  
  mediana = lim2 / 2; i = 0;
  while(trovato == -1 && i < sizeof(array)/4){
        if(ricercato == array[mediana]) trovato = i;
        else if(ricercato > array[mediana]) lim1 = mediana;
        else if(ricercato < array[mediana]) lim2 = mediana;
        mediana = (lim2+lim1)/2;
        i++;
  }
  
  if(trovato != -1) printf("L'elemento %d e' stato trovato al posto %d.", ricercato, trovato);
  else printf("L'elemento %d non e' stato trovato.", ricercato);
  
  
  system("PAUSE");	
  return 0;
}
