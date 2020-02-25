void aboutScreen(){
  while(1){
    lcd.clear();
    lcd.print("Select option:");
    lcd.setCursor(0, 1);
    lcd.print("< about");  
  
    while(1){
      buttonpressed = buttonReader();
      if(buttonpressed = Lbutton) return;
      if(buttonpressed = OKbutton){
        buttonpressed = -1;
        lcd.clear();
        lcd.print("Developed by");
        lcd.setCursor(0, 1);
        lcd.print("Joao Marcos");  
        delay(5000); //aguarda 5 segundos
        break;
      }
    }
  }
}
