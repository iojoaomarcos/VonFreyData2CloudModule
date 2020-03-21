void rodentSelector(){
    int rodentNum = 1;
    int experimentTime;
  
    while(1){
      lcd.clear();
      lcd.print("Select the");
      lcd.setCursor(0, 1);
      lcd.print("rodent: "); lcd.print(rodentNum);

      // Aumentando/diminuindo o seletor
      if((digitalRead(Lbutton) == HIGH) && (rodentNum >= 2)) rodentNum--;
      if((digitalRead(Rbutton) == HIGH) && (rodentNum <=24)) rodentNum++;

      if(digitalRead(Cancelbutton) == HIGH) return;
      if(digitalRead(OKbutton == HIGH)){
        for(int i = 0; i < xpqtty; i++){
          if(datacollected[rodentNum][i] == -1) experimentTime = i;
          else{
            lcd.clear();
            lcd.print("Select the");
            lcd.setCursor(0, 1);
            lcd.print("rodent: ");
          }
        }
        collectData(rodentNum);  
      }
    }
}
