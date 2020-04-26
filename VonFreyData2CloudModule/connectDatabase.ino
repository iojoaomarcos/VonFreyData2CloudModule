void connectDatabase(){
  Serial.println("Agora conectando ao banco de dados (MariaDB)...");
  lcd.clear();
  lcd.print("Connecting to");
  lcd.setCursor(0, 1);
  lcd.print("database server");
  if(conn.connect(IPsql, 3306, user, password)){
    Serial.println("... conexao feita com sucesso.");
      lcd.clear();
      lcd.print("Successfully");
      lcd.setCursor(0, 1);
      lcd.print("Connected to DB");
  }
  else{
    Serial.println("... nao foi possivel conectar :(");
    Serial.println("Rebooting...");
    lcd.clear();
    lcd.print("ERR: Connection");
    lcd.setCursor(0, 1);
    lcd.print("failed :(");
    delay(5000);
    ESP.restart();
  }
}
