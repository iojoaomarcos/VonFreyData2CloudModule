float collectData(){
  float last; //valor anterior ao da leitura atual
  float flagged = 0; //possivel valor de reacao
  bool flinch = false;
  do{
      UPDATEpressaoFilamento();
  
      if(pressaoFilamento > flagged) flagged = pressaoFilamento;
      
      if(pressaoFilamento <= flagged/2){
        dataFormatter(flagged);
        lcd.clear();
        lcd.print(formattedPressure);
        lcd.setCursor(0, 1);
        lcd.print("...is valid?");
        
        while(1){
          if(buttonpressed == OKbutton){
            
          }

          if(buttonpressed == Cancelbutton) flagged = 0;
        }
      }

      
      lcd.clear();
      dataFormatter(last);
      lcd.print("Current: "); lcd.print(formattedPressure);
      lcd.setCursor(0, 1);
      dataFormatter(flagged);
      lcd.print("Flagged: "); lcd.print(formattedPressure);
  }while(!flinch);

  return flagged;
}
