/**
 * @file Estacao_metereologica.ino
 * Modificado por: Saulo Aislan
 * @brief Firmware responsável captar dados dos sensores e exibir no display OLED.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
*/
#include <Wire.h>
#include "BMP280.h"
#include "DHTesp.h"
#include "SSD1306.h"
#include "images.h"

#define SDA    2
#define SCL   14
#define RST   26 // Não usado
#define DISPLAY_ADDR 0x3c // Endereco do I2c do display
#define BMP280_ADDR 0x76 // Endereco do I2c do BMP280
#define P0 1013.25 // Pressão ao nível do mar
#define PIN_SENSOR_CHUVA A0
#define PIN_SENSOR_HUMIDADE 5 // DHT11
#define DELAYINLOOP 2000
#define TRANSITION_DUARTION 3000

BMP280 bmp;
DHTesp dht;

SSD1306  display(DISPLAY_ADDR, SDA, SCL, RST);

typedef void (*Demo)(void);

long timeSinceLastModeSwitch = 0;
int demoMode = 0;
double temperatura, alti, pressao;          
float humidade;

/* Prototipo da funcao */
void drawSun();
void drawCloud();
void getdados();
bool estaChovendo();
void printCloud();
void printTemp();
void printHumi();
void printPressao();
void printAltitude();

// Vetor com os endereco das funcoes
Demo demos[] = {printCloud, printTemp, printPressao, printAltitude, printHumi};
int demoLength = (sizeof(demos) / sizeof(Demo));

/**
 * @brief Setup
 */
void setup()
{
  Serial.begin(115200);
  pinMode(PIN_SENSOR_CHUVA, INPUT);
  dht.setup(PIN_SENSOR_HUMIDADE, DHTesp::DHT11);
  
  if(!bmp.begin(SDA, SCL))
  {
    Serial.println("BMP init failed!");
    while(1);
  }
  else Serial.println("BMP init success!");
  
  bmp.setOversampling(4); // Resolução das medidas

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.display();
}

/**
 * @brief Desenha no Display um sol
 */
void drawSun()
{
  display.clear();
  display.drawXbm(41, 0, SUN_WIDTH, SUN_HEIGHT, sun_icon);
  display.display();
}

/**
 * @brief Desenha no Display uma nuvem chuvosa
 */
void drawCloud()
{
  display.clear();
  display.drawXbm(41, 0, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_rain_icon);
  display.display();
}

/**
 * @brief Chama a funcao para verificar o clima e chama a
 * funcao para imprime o status
 */
void printCloud()
{
  display.setFont(ArialMT_Plain_16);
  display.clear();
  
  if(estaChovendo())
  {
    drawCloud();
    display.drawString(23, 48, "Chovendo...");
  }
  else
  {
    drawSun();
    display.drawString(23, 47, "Sem Chuva...");
  }
  
  display.display();        // update the display
}

/**
 * @brief Imprime a temperatura no display
 */
void printTemp()
{
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(18, 0, "Temperatura");
  display.setFont(ArialMT_Plain_24);
  if (temperatura < 0)
   display.drawString(15, 20, "-"+(String)temperatura+"  C" );
  else
   display.drawString(15, 20, " "+(String)temperatura+"  C");
   
  display.drawRect(89, 25, 5, 5); // Simbolo ( ° )
  display.display();
}

/**
 * @brief Imprime a humidade no Display
 */
void printHumi()
{
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(25, 0, "Humidade");
  display.setFont(ArialMT_Plain_24);
  display.drawString(15, 20, " "+(String)humidade+" %");
  display.display();
}

/**
 * @brief Imprime a pressão no Display
 */
void printPressao()
{
  display.setFont(ArialMT_Plain_10);
  display.clear();
  display.drawString(18, 5, "Pressão");
  display.drawString(60, 5, "Atmosférica");
  display.setFont(ArialMT_Plain_24);
  display.drawString(5, 20, (String)pressao+" hPa" );
  display.display();
}

/**
 * @brief Imprime a altitude no Display
 */
void printAltitude()
{
  Serial.println(alti);
  display.setFont(ArialMT_Plain_16);
  display.clear();
  display.drawString(37, 0, "Altitude");
  display.setFont(ArialMT_Plain_24);
  display.drawString(15, 20, (String)alti+" m" );
  display.display();        // update the display
}

/**
 * @brief Ler os sensores, armazena os dados nas variaveis e imprime na serial
 */
void getdados()
{
  char result = bmp.startMeasurment();
  double tempBMP;

  Serial.print("\n\n---------- Dados ----------\n");
  
  if(result!=0)
  {
    delay(result);
    result = bmp.getTemperatureAndPressure(tempBMP,pressao);
    
      if(result!=0)
      {
        alti = bmp.altitude(pressao,P0);
      }
      else
      {
        Serial.println("Error.");
      }
  }
  else
  {
    Serial.println("Error.");
  }

  humidade = dht.getHumidity();
  if (isnan(humidade))
  {
    Serial.println("Failed to read from DHT sensor!");
    humidade = 0;
  }
  else
  {
    Serial.print("Humidade: ");
    Serial.println(humidade);
  }

  float tempDHT = dht.getTemperature();
  
  if (isnan(tempDHT))
  { 
    Serial.println("Failed to read from DHT sensor!");
    tempDHT = 0;
    temperatura = tempBMP;
  }
  else
  {
    temperatura = (tempBMP + tempDHT) / 2; // Calcula uma temperatura media entre os dois sensores
  }

  Serial.print("Temperatura sensor DHT11: ");
  Serial.println(tempDHT);        
  Serial.print("Temperatura sensor BMP280:");
  Serial.print(tempBMP,2);
  Serial.println(" °C");
  Serial.print("Pressão: ");
  Serial.print(pressao,2);
  Serial.println(" hPa");
  Serial.print("Altitude: ");
  Serial.print(alti,2);
  Serial.println(" m");
  Serial.print("Sensor de Chuva: ");
  Serial.print(analogRead(PIN_SENSOR_CHUVA)); 
  Serial.println("  ");
  
  estaChovendo();
}

/**
 * @brief Verifica se esta chovendo, lendo o sinal analogico do sensor
 * @return bool Se esta chovendo ou nao
 */
bool estaChovendo()
{
  if (analogRead(PIN_SENSOR_CHUVA) > 900)
  {
    Serial.println("Não está chovendo...");
    return false;
  }
  else
  {
    Serial.println("Chovendo!!!");
    return true;
  }
}

/**
 * @brief Loop
 */
void loop()
{ 
  getdados();
  
  display.clear();   // Limpar o display
  demos[demoMode]();  // Vetor com os endereco das funcoes
  display.display();   // Atualiza o display com a nova tela

  if (millis() - timeSinceLastModeSwitch > TRANSITION_DUARTION)
  {
    demoMode = (demoMode + 1) % demoLength;
    timeSinceLastModeSwitch = millis();
  }

  delay(DELAYINLOOP);
}