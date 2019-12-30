/* 
 *  MODULO DE GRAVACAO DE DADOS PARA A NUVEM PARA
 *  EQUIPAMENTO DE VON FREY ELETRONICO
 *  
 *  Joao Marcos Santos @ Universidade Sao Francisco
 *  2019/2020
 *  
 *  Projeto de Iniciacao Cientifica:
 *  MACHINE LEARNING PARA DELINEAMENTO 
 *  EXPERIMENTAL EM ESTUDOS DA DOR.
 *  Fabio Andrijauskas
 */

//Bibliotecas WIFI
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

//Bibliotecas e ajustes do MySQL
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
char INSERT_EXPERIMENTOS[] = 
"INSERT INTO VonFreyDATA.Experimentos (DataSessao, Observacoes) VALUES (CURRENT_DATE(), '%c')";
char INSERT_MEDICOES[] = 
"INSERT INTO VonFreyDATA.Medicoes (INSERTTimestamp, Valor, IDExperimento) VALUES (NOW(), '%f','%i')";
char query[256];
int IDExperimento = 0;

/*
 * Apos passar por um transdutor e um conversor AD, a forca aplicada
 * na pata do roedor se torna digitalizada e salva temporariamente
 * na variavel pressaoFilamento
 */
float pressaoFilamento = 0;

//Dados do MySQL Server
IPAddress IPsql(157,56,178,227);
char user[] = "microcontroller";
char password[] = "8164886752";

WiFiClient client;  
MySQL_Connection conn((Client *)&client);

void connectNetwork(){
  //inicializacao do WifiManager e seus ajustes
  WiFiManager wifiManager;
  wifiManager.autoConnect("VonFreyModule SETUP");

  //O ESP estara preso ate estar conectado, logo apos essa etapa:
  Serial.println("Conectado com sucesso a rede.");
}

void connectDatabase(){
  Serial.println("Agora conectando ao banco de dados...");
  if(conn.connect(IPsql, 3306, user, password)){
    Serial.println("... conexao feita com sucesso");
  }
  else{
    Serial.println("... nao foi possivel conectar :(");
    Serial.println("Rebooting...");
    ESP.restart();
  }
}

template <typename T> void INSERTintoDB(char querytemplate[], T d1, T d2){
  //Objeto do Prompt do banco de dados
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  //Preenchendo a query com os valores devidos: se a query nao ter um segundo
  // argumento, o coringa "\n" deve ser passado para d2
  if(d2 = '\n') sprintf(query, querytemplate, d1);
  else sprintf(query, querytemplate, d1, d2);
  
  //Executando a query
  cur_mem->execute(query);

  //Apos sua execucao, limpando o cursor para liberar memoria
  delete cur_mem;
}

void setup() {
  //Setup da velocidade de escrita na saida serial
  Serial.begin(115200);

  connectNetwork();
  connectDatabase();

  //Iniciando nova sessao
  INSERTintoDB(INSERT_EXPERIMENTOS, '\0', '\n');
}
/*
float UPDATEpressaoFilamento(){
  int i = 0;
  float valor = 0;
  while (i = 0){
    valor = analogRead(0);
    if(
  }
  valor = map(valor, 0, 1023, 0, 255);
}
*/


void loop() {
  INSERTintoDB(INSERT_MEDICOES, 10, 5); //////////////////////check for &&&&%%%%%
  
  delay(100000);
}
