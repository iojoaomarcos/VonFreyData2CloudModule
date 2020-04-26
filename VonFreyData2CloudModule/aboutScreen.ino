void aboutScreen(){
  while(1){
    lcd.clear();
    lcd.print("Select option:");
    lcd.setCursor(0, 1);
    lcd.print("< about");  
  
    while(1){
      if(digitalRead(Lbutton) == HIGH) return;
      if(digitalRead(OKbutton) == HIGH){
        lcd.clear();
        lcd.print("Developed by iojoaomarcos");
        lcd.setCursor(0, 1);
        lcd.print("iojoaomarcos @ Universidade Sao Francisco // Modulo de IoT para equipamento de Von Frey Eletronico // Projeto de iniciacao cientifica 2019/2020. ");  

        //<- Permite exibir todo o texto acima no display, movendo o texto para a esquerda <-
        while(digitalRead(OKbutton) == LOW){
          lcd.scrollDisplayLeft();
          delay(150);
        }
        break;
      }
    }
  }
}
