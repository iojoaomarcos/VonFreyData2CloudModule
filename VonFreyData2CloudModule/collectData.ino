void collectData(int rodentNumber){
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
      }
  }while(!flinch);

}
