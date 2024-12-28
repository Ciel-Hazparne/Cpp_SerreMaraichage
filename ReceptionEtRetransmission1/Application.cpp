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

Application::Application()
{
  MyWifi.WifiStatus();
}

void Application::run()
{
  while(1)
  {
    static long tempoMesures = 0;
    static long tempoHTTP = 0;
    int packetSize = MyLora.parsePacket();
    String values;
    String temperatureSerre;
    String humiditySerre;
    int i = 0;
    
    if(packetSize)
    {
      while(MyLora.available())
      {
        for (i = 0; i < packetSize; i++)
        {
          values.concat((char)MyLora.read());
        }
      }

      
  MyLora.SeperationOfData(temperatureSerre, humiditySerre, values, packetSize);
      Serial.print("[LoRa reçu]TemperatureSerre :");
      Serial.print(temperatureSerre);
      Serial.print("\n[LoRa reçu]HumiditySerre :");
      Serial.print(humiditySerre);
      Serial.print("\n");

      
     if (!clientMQTT.connected()) clientMQTT.reconnect();
      else 
      {
        clientMQTT.loop();
    
        long now1 = millis();
        if (now1 - tempoMesures > 3000) 
        {
          tempoMesures = now1;
          clientMQTT.publie( TOPIC3, String(temperatureSerre) );
          clientMQTT.publie( TOPIC4, String(humiditySerre) );
        }
      }
      
      long now2 = millis();
      if (now2 - tempoHTTP > 600000) 
      {
        tempoHTTP = now2;
        clientHTTP.requestPOST( temperatureSerre, "1" );
        clientHTTP.requestPOST( humiditySerre, "2" );
      }
    }
  }
}
