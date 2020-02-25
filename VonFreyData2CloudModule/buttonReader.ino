int buttonReader(){
  while(1){
    if(Rbutton == HIGH) return Rbutton;
    if(Lbutton == HIGH) return Lbutton;
    if(Cancelbutton == HIGH) return Cancelbutton;
    if(OKbutton == HIGH) return OKbutton;
  }
}
