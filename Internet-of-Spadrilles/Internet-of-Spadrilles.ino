//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int contador = 0;

float Distancia;
float Tempo;
float Calorias;
float Velocidade;
float Aceleracao;
float Temperatura;
float Rendimento;

int Paradas;
float Giroscopio;

String Envio = "";


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {

  Distancia = random(500);
  Tempo = random(5);
  Calorias = random(500);
  Velocidade = random(40);
  Aceleracao = random(20);
  Temperatura = random(60);
  Rendimento = random(100);
  Paradas = random(10);
  
  Envio = String(Distancia);
  Envio = Envio + ",";
  Envio = Envio + String(Tempo);
  Envio = Envio + ",";
  Envio = Envio + String(Calorias);
  Envio = Envio + ",";
  Envio = Envio + String(Velocidade);
  Envio = Envio + ",";
  Envio = Envio + String(Aceleracao);
  Envio = Envio + ",";
  Envio = Envio + String(Temperatura);
  Envio = Envio + ",";
  Envio = Envio + String(Rendimento);
  Envio = Envio + ",";
  Envio = Envio + String(Paradas);

 // SerialBT.print(Envio);

  delay(1500);
//  


  
  if (Serial.available()){
    Serial.println(Envio);
    SerialBT.print(Envio);
  }
  

 
  if (SerialBT.available()) 
  {
    int recebido = SerialBT.read();
    Serial.write(recebido);
  }

  delay(20);
}
