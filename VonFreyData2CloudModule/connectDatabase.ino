void connectDatabase(){
  Serial.println("Agora conectando ao banco de dados (MariaDB)...");
  if(conn.connect(IPsql, 3306, user, password)){
    Serial.println("... conexao feita com sucesso.");
  }
  else{
    Serial.println("... nao foi possivel conectar :(");
    Serial.println("Rebooting...");
    ESP.restart();
  }
}
