void aboutScreen(){
  while(1){
    lcd.clear();
    lcd.print("Select option:");
    lcd.setCursor(0, 1);
    lcd.print("< about");  
  
    while(1){
      if(digitalRead(Lbutton) == HIGH) return;
      if(digitalRead(OKbutton) == HIGH){
        buttonpressed = -1;
        lcd.clear();
        lcd.print("Developed by");
        lcd.setCursor(0, 1);
        lcd.print("Joao Marcos");  
        delay(3000); //aguarda 3 segundos
        break;
      }
    }
  }
}
