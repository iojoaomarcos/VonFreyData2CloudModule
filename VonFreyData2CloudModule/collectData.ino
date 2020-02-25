float collectData(){
  float last; //valor anterior ao da leitura atual
  float flagged; //possivel valor de reacao
  bool flinch = 0;
  do{
    last = UPDATEpressaoFilamento();

    if(pressaoFilamento > last) flagged = pressaoFilamento;
    if(last <= pressaoFilamento/2){
       
    }
        
  }while(flinch != 1);

  return flagged;
}
