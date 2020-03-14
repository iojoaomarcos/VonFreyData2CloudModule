void rodentSelector(){
    int rodentNum = 1;
  
    while(1){
      lcd.clear();
      lcd.print("Select the");
      lcd.setCursor(0, 1);
      lcd.print("rodent: "); lcd.print(rodentNum);

      // Aumentando/diminuindo o seletor
      if((digitalRead(Lbutton) == HIGH) && (rodentNum >= 2)) rodentNum--;
      if((digitalRead(Rbutton) == HIGH) && (rodentNum <=24)) rodentNum++;

      if(digitalRead(OKbutton == HIGH)){
        
      }
    }
}
