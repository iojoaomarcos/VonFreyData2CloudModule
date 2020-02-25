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

//Bibliotecas WIFI:
#include <ESP8266WiFi.h>          
//https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          
//https://github.com/tzapu/WiFiManager

//Biblioteca para uso do Display
#include <Wire.h> //Para uso do protocolo I2C
#include <LiquidCrystal_I2C.h>  
//https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

//Bibliotecas e ajustes do MySQL:
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

char INSERT_EXPERIMENTOS[] = 
"INSERT INTO VonFreyDATA.Experimentos (DataSessao, Observacoes) VALUES (CURRENT_DATE(), '')";
char RETRIVE_SESSION[] = "SELECT MAX(IDexperimento) FROM VonFreyDATA.Experimentos";

char INSERT_MEDICOES[] = 
"INSERT INTO VonFreyDATA.Medicoes (INSERTTimestamp, Valor, IDExperimento) VALUES (NOW(), %f, %i)";

char query[256];
int IDExperimento;

/*
 * Apos passar por um transdutor e um conversor AD, a forca aplicada
 * na pata do roedor se torna digitalizada e salva temporariamente
 * na variavel pressaoFilamento
 */
float pressaoFilamento = 0;
float datacollected[26][5];

//Dados do SGBD MariaDB
IPAddress IPsql(157,56,178,227);
char user[] = "microcontroller";
char password[] = "8164886752";

WiFiClient client;  
MySQL_Connection conn((Client *)&client);

//Endereco do LCD (via I2C) eh definida por 0x27 e o display possui tamanho de 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Definicao de pinos para os botoes
const int Lbutton = 5;
const int Rbutton = 6;
const int Cancelbutton = 7;
const int OKbutton = 8;
int buttonpressed = -1;

void setup() {
  //Configuração da velocidade de escrita/leitura na saida serial (USB)
  Serial.begin(115200);

  //Inicializa display
  lcd.begin();
  lcd.backlight();
  lcd.print("Initializing...");

  connectNetwork();
  connectDatabase();

  //Iniciando nova sessao
  INSERTintoDB(INSERT_EXPERIMENTOS, '\0', '\0');
  
  row_values *row = NULL;
  // Iniciando a query...
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(RETRIVE_SESSION);
  column_names *columns = cur_mem->get_columns();

  // Le o resultado e o salva em IDExperimento
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      IDExperimento = atoi(row->values[0]);
    }
  } while (row != NULL);
  // Uma vez concluido, se libera a memoria
  delete cur_mem;
  Serial.print("O ID do Experimento = ");
  Serial.println(IDExperimento);

  //Preenche query com NULL
  memset(query, '\0', sizeof query); 

  lcd.setCursor(0,0);
  lcd.print("SYSTEM IS READY");
  lcd.setCursor(0,1);
  lcd.print("TO GET STARTED");
  delay(3000);
}

void loop() {
  lcd.clear();
  lcd.print("Select option:");
  lcd.setCursor(0, 1);
  lcd.print("Capture data >");

  while(1){
    buttonpressed = buttonReader();
    if(buttonpressed == Rbutton){
      buttonpressed = -1;
      uploadDataScreen();
      break;
    }
    if(buttonpressed == OKbutton){
      buttonpressed = -1;
      rodentSelector();
      break;
    }
  }
  
  INSERTintoDB(INSERT_MEDICOES, 1.50, IDExperimento); //////check for &&&&%%%%%
  
  delay(100000);
}
