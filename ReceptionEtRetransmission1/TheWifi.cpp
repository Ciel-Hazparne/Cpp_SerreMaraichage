#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <PubSubClient.h>
#include <LoRa.h>

#include "Constantes.h"
#include "Lora.h"
#include "TheWifi.h"
#include "HttpReq.h"
#include "Mqtt.h"
#include "Application.h"

TheWifi::TheWifi(const char* lessid, const char* lepass): ssid{lessid}, pass{lepass},WiFiClass()
{
  begin(ssid, pass);
}

void TheWifi::WifiStatus()
{
  while (status() != WL_CONNECTED) {
    // failed, retry
    Serial.print("[WiFi] Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    Serial.println("\n");
    delay(3000);
  }
  Serial.println("");
  Serial.print("[WiFi] You're connected to the network\n");
}
