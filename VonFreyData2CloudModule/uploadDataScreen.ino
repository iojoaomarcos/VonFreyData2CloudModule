void uploadDataScreen(){
  while(1){
    lcd.clear();
    lcd.print("Select option:");
    lcd.setCursor(0, 1);
    lcd.print("< UPLOAD Data >");
  
    while(1){
      buttonpressed = buttonReader();
      if(buttonpressed == Lbutton) return;
      if(buttonpressed == Rbutton){
        buttonpressed = -1;
        aboutScreen();
        break;
      }
      if(buttonpressed == OKbutton){
        buttonpressed = -1;
        //////////////////////////////////////////////
      }
    }
  }
}
