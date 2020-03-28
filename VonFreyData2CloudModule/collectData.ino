void collectData(int rodentNumber, int colunalivre){
  float last; //valor anterior ao da leitura atual
  float flagged = 0; //possivel valor de reacao
  bool flinch = false;
  
  do{
      UPDATEpressaoFilamento();
  
      if(pressaoFilamento > flagged) flagged = pressaoFilamento;
      
      if(digitalRead(Lbutton) == HIGH) return;
      if(digitalRead(Cancelbutton) == HIGH) flagged = 0;
      
      lcd.clear();
      dataFormatter(last);
      lcd.print("Current: "); lcd.print(formattedPressure);
      lcd.setCursor(0, 1);
      dataFormatter(flagged);
      lcd.print("Flagged: "); lcd.print(formattedPressure);

      if(digitalRead(OKbutton) == HIGH){
        lcd.clear();
        dataFormatter(flagged); lcd.print(formattedPressure);
        lcd.print("Save it?");
        while(!flinch || digitalRead(Cancelbutton) == LOW){
          //fica no aguardo de uma resposta
          if(digitalRead(OKbutton) == HIGH) flinch == true;
        } 
      }
  }while(!flinch);

  lcd.clear();
  lcd.print("Saving in the");
  lcd.setCursor(0, 1);
  lcd.print("memory...");

  datacollected[rodentNumber][colunalivre];
  delay(2000); //waits 2 secs
  
  lcd.clear();
  lcd.print("Saved. Remember");
  lcd.setCursor(0, 1);
  lcd.print("2upload the data");

  delay(2000); //waits 2 secs
}
