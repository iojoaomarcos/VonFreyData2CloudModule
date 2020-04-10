void calculateNuploud(){
  int rodent; //contador para calculo para cada roedor

  for(rodent = 0; rodent < (rodentsqtty - 1); rodent++){
    float average = 0; //media simples dos resultados obtidos para o roedor n
    int rodent_experimentqtty = 0; //quantidade de medidas feitas no roedor em analise
    int empty_space = 0; //valores que restaram em -1
    
    lcd.clear();
    lcd.print("Processing...");
    lcd.setCursor(0, 1);
    lcd.print("rodent: "); lcd.print(rodent);

    for(int i = 0; i < (xpqtty - 1); i++){
      //conta quantos experimentos foram realizados no @rodent, lembrando que vazio = -1
      //nao e tolerado valores negativos
      if(datacollected[rodent][i] > 0) rodent_experimentqtty++;
      if(datacollected[rodent][i] == -1) empty_space++;
    }

    //Se todos os valores do roedor n forem -1, então ele pula para o proximo
    // a ser analisado (nao vai fazer o upload se roedor n não foi medido)
    if(empty_space == xpqtty) continue;

//-------------------Calculando a media dos resultados obtidos----------------// 
    for(int i = 0; i < rodent_experimentqtty; i++){
      average += datacollected[rodent][1 + empty_space + i];    
    }
    average /= rodent_experimentqtty;

    INSERTintoDB(INSERT_MEDICOES, average, IDExperimento);

    
  } //for rodents (calculating for each rodent)

  lcd.clear();
  lcd.print("UPLOAD COMPLETED");
  lcd.setCursor(0, 1);
  lcd.print("NOW REBOOTING...");
  ESP.restart();
} //void calculateNuploud
