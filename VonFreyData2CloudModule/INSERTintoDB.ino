template <typename T, typename U> void INSERTintoDB(char querytemplate[], T d1, U d2){
  //Objeto do Prompt do banco de dados
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  //Preenchendo a query com os valores devidos: se a query nao ter 
  // argumentos, o coringa "\0" deve ser passado para d1
  if(d1 = '\0') strcpy(query, INSERT_EXPERIMENTOS);
  else sprintf(query, querytemplate, d1, d2);
  
  //Executando a query
  cur_mem->execute(query);

  Serial.println("Novos dados foram enviados ao MariaDB.");
  
  //Apos sua execucao, limpando o cursor para liberar memoria
  delete cur_mem;
  memset(query, '\0', sizeof query); 
}
