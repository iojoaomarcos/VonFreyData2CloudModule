void calculateNuploud(){
  int rodent; //contador para calculo para cada roedor

  for(rodent = 0; rodent < (rodentsqtty - 1); rodent++){
    int aux; //auxiliar para ordenacao dos vetores de experimentos
    float average = 0; //media simples dos resultados obtidos para o roedor n
    float q1; //primeiro quartil
    float median; //mediana (segundo quartil)
    float q3; //terceiro quartil
    int rodent_experimentqtty = 0; //quantidade de medidas feitas no roedor em analise
    int empty_space = 0; //valores que restaram em -1
    
    lcd.clear();
    lcd.print("Processing...");
    lcd.setCursor(0, 1);
    lcd.print("rodent: "); lcd.print(rodent);

    for(int i = 0; i < (xpqtty - 1); i++){
      //conta quantos experimentos foram realizados, lembrando que vazio = -1
      //nao e tolerado valores negativos
      if(datacollected[rodent][i] > 0) rodent_experimentqtty++;
      if(datacollected[rodent][i] == -1) empty_space++;
    }

    //Se todos os valores do roedor n forem -1, então ele pula para o proximo
    // a ser analisado (nao vai fazer o upload se roedor n não foi medido)
    if(empty_space == xpqtty) continue;

//-----------------Ordenando de forma crescente os resultados---------------------//
    for (int atual = 0; atual < (rodent_experimentqtty - 1); atual++)
      /* ordenando o vetor para calculo da mediana e quartis, se o atual e maior
       * que o proximo, estes sao trocados */
      for (int proximo = atual + 1; proximo < rodent_experimentqtty; proximo++)
        if (datacollected[rodent][atual] > datacollected[rodent][proximo]){
          aux = datacollected[rodent][atual];
          datacollected[rodent][atual] = datacollected[rodent][proximo];
          datacollected[rodent][proximo] = aux;
        }
        
//----------------------------Calculando a mediana--------------------------------//
    if(rodent_experimentqtty%2 == 0){
      /*Se a quantidade de experimentos feitos for par (sem resto na divisão por 2)
       *a mediana pode ser calculada pelo ponto médio dos dois pontos centrais
       *da amostra. É somada a quantidade de -1s que estao no inicio do vetor,
       *assim como descontado um, ja que datacollected esta organizado em uma
       *matriz, que por convencao comeca em 0
      */
      float a = datacollected[rodent][-1 + empty_space + rodent_experimentqtty/2];
      float b = datacollected[rodent][-1 + empty_space + 1 + rodent_experimentqtty/2];
      median = (a + b)/2;
    }else{
      /*
       * Se for impar, a mediana e justamente o ponto central. Da mesma forma,
       * e adicionada a quantidade de -1s e feito o desconto
       */
      int center = (((rodent_experimentqtty - 1)/2) + 1);
      median = datacollected[rodent][empty_space - 1 + center];
    }

//----------------------Calculando o primeiro quartil-------------------------//
    


//----------------------Calculando o segundo quartil--------------------------//


//-------------------Calculando a media dos resultados obtidos----------------// 
    for(int i = 0; i < rodent_experimentqtty; i++){
      average += datacollected[rodent][1 + empty_space + i];    
    }
    average /= rodent_experimentqtty;

    INSERTintoDB(INSERT_MEDICOES, average, IDExperimento);

    
  } //for rodents (calculating for each rodent

  lcd.clear();
  lcd.print("UPLOAD COMPLETED");
  lcd.setCursor(0, 1);
  lcd.print("NOW REBOOTING...");
  ESP.restart();
} //void calculateNuploud
