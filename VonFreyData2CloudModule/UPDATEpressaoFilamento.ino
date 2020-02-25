float UPDATEpressaoFilamento(){
  while(Serial.available() == 0){ //Aguarda o recebimento do dado
  }  
  pressaoFilamento = Serial.parseFloat();
  return pressaoFilamento;
}
