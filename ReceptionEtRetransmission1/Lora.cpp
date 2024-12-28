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

Lora::Lora(): LoRaClass()
{
   if (!begin(868E6)) {
    Serial.println("Starting LoRa failed!");
  }
}


void Lora::SeperationOfData(String& TemperatureSerre, String& HumiditySerre, String& values, int packetSize)
{   
  if (values.substring(0, 12) == "Temp_Serre: ")
    {
      TemperatureSerre = values.substring(12, 17);
    }
  if (values.substring(17, 28) == "Hum_Serre: ")
    {   
      HumiditySerre = values.substring(28, 33);
    }
}
