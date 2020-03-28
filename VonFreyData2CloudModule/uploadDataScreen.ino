void uploadDataScreen(){
  while(1){
    lcd.clear();
    lcd.print("Select option:");
    lcd.setCursor(0, 1);
    lcd.print("< UPLOAD Data >");
  
    while(1){
      if(digitalRead(Lbutton) == HIGH) return;
      if(digitalRead(Rbutton) == HIGH){
        aboutScreen();
        break;
      }
      if(digitalRead(OKbutton) == HIGH){
        calculateNuploud();
        break;
      }
    } // buttons read
  } //lcd prints
} // void uploadDataScreen
