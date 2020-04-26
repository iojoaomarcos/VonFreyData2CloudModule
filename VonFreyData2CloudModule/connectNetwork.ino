void connectNetwork(){
  //inicializacao do WifiManager e seus ajustes

  lcd.clear();
  lcd.print("AP Mode");
  lcd.setCursor(0, 1);
  lcd.print("Choose network");
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("VonFreyModule SETUP");

  //O ESP estara preso ate estar conectado, logo apos essa etapa:
  Serial.println("Conectado com sucesso a rede.");
  lcd.clear();
  lcd.print("Connected to the");
  lcd.setCursor(0, 1);
  lcd.print("wireless network");
  delay(1000); //aguarda um segundo
}
