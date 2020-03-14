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
        if(datacollected[0][0] == NULL){
          lcd.clear();
          lcd.print("There is no");
          lcd.setCursor(0, 1);
          lcd.print("data to upload");
          delay(5000);
          break;
        }
        else{
          calculateNuploud();
          break;
        }
      }
    }
  }
}
