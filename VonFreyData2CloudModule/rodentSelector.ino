void rodentSelector(){
    int rodentNum = 1;
    int experimentTime;
    int colunalivre;
  
    while(1){
      lcd.clear();
      lcd.print("Select the");
      lcd.setCursor(0, 1);
      lcd.print("rodent: "); lcd.print(rodentNum);

      // Aumentando/diminuindo o seletor e controlando para se manter no espetro
      if((digitalRead(Lbutton) == HIGH) && (rodentNum >= 2)) rodentNum--;
      if((digitalRead(Rbutton) == HIGH) && (rodentNum <=(rodentsqtty -1))) rodentNum++;

      if(digitalRead(Cancelbutton) == HIGH) return; //retorna ao menu anterior
      
      if(digitalRead(OKbutton == HIGH)){
        for(colunalivre = 0; colunalivre < xpqtty; colunalivre++){ 
          //verificando se existe espaco para armazenar mais um experimento
          if(datacollected[rodentNum][colunalivre] == -1) experimentTime = colunalivre;
          else if(colunalivre == (xpqtty - 1)) {
            lcd.clear();
            lcd.print("ERROR 1:");
            lcd.setCursor(0, 1);
            lcd.print("No space left :(");
            delay(3000); //aguarda 3 segundos
          }
        }
        collectData(rodentNum, colunalivre);
        return;
      }
    }
}
