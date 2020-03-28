void calculateNuploud(){
  int rodent; //contador para calculo para cada roedor
  int aux; //auxiliar para ordenacao dos vetores de experimentos
  float q1;
  float median;
  float q3;

  for(rodent = 0; rodent < (rodentsqtty - 1); rodent++){
    int rodent_experimentqtty = 0; //quantidade de medidas feitas no roedor em analise
    
    lcd.clear();
    lcd.print("Processing...");
    lcd.setCursor(0, 1);
    lcd.print("rodent: "); lcd.print(rodent);

    for(int i = 0; i < (xpqtty - 1); i++){
      //conta quantos experimentos foram realizados, lembrando que vazio = -1
      //nao e tolerado valores negativos
      if(datacollected[rodent][i] > 0) rodent_experimentqtty++;
    }

    for (int atual = 0; atual < (rodent_experimentqtty - 1); atual++)
      /* ordenando o vetor para calculo da mediana e quartis, se o atual e maior
       * que o proximo, estes sao trocados */
      for (int proximo = atual + 1; proximo < rodent_experimentqtty; proximo++)
        if (datacollected[rodent][atual] > datacollected[rodent][proximo]){
          aux = datacollected[rodent][atual];
          datacollected[rodent][atual] = datacollected[rodent][proximo];
          datacollected[rodent][proximo] = aux;
        }

    if(rodent_experimentqtty % 2 == 0){
      //Se a quantidade for par...
      int empty_space = 0;
      for(int empty_counter; empty_counter < xpqtty; empty_counter++)
        if(datacollected[rodent][empty_counter] = -1) empty_space++;
    }
      

    for(int experiment = 0; experiment < rodent_experimentqtty; experiment++){

    
    }
  } //for rodents
} //void calculateNuploud

/*
  const int rodentsqtty = 25; //Quantidade de roedores
const int xpqtty = 5; //Quantidade de experimentos
float datacollected[rodentsqtty][xpqtty];

*/ 
