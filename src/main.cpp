/*
Autor: Lucas Todesco
Programa: Conexão WiFi
Descrição: Funcionamento de um programa que conecta o Wifi
Data: 15/04/2026
Versão: 1.0
*/



#include <Arduino.h>
#include "WiFiManager.h"


void setup()
{
  Serial.begin(9600);
  conectarWifi();
}

void loop() 
{
   garantirWifiConectado();
}
