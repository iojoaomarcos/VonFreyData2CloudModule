void connectNetwork(){
  //inicializacao do WifiManager e seus ajustes
  WiFiManager wifiManager;
  wifiManager.autoConnect("VonFreyModule SETUP");

  //O ESP estara preso ate estar conectado, logo apos essa etapa:
  Serial.println("Conectado com sucesso a rede.");
}
