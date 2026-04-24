//! WiFiManager.cpp
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>
#include "secrets.h"



bool wifiEstaConectado()
{
    return WiFi.status() == WL_CONNECTED;
}

void conectarWifi()
{
  Serial.println("================================");
  Serial.println("Iniciando conexão WiFi...");
  Serial.println("================================");

  //Configura o ESP32 como station, ou seja
  //ele vai se conectar a roteador existente
  WiFi.mode(WIFI_STA); 

  //Inicia a conexão com SSID e senha 
  WiFi.begin(WIFI_SSID, WIFI_SENHA);

  Serial.println("Conectando");

  int tentativasWiFI = 0;
  const int maxTentatviasWiFi = 30;

  //Aguarda a conexão por até 30 tentativas
  while(WiFi.status() != WL_CONNECTED && tentativasWiFI < maxTentatviasWiFi);
  {
    delay(500);
    Serial.print(".");
    tentativasWiFI++;

  }

  Serial.println();
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WiFi conectado com sucesso!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
  }

  else
  {
    Serial.println("Falha ao conectar no WiFi.");
    Serial.println("Verifique SSID, Senha e Sinal de rede ");
  }
}

void garantirWifiConectado()
{
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi desconectado. Tentando reconectar...");
    conectarWifi();
  }

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Não foi possível reconectar ao WiFi.");
  }
}