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

Mqtt::Mqtt(WiFiClient* clientWifi, const char * broker,
           unsigned short portMqtt, const char * mqttUser,
           const char * mqttPassword): PubSubClient(*clientWifi), clientWifi(clientWifi)
{
  broker = broker;
  portMqtt = portMqtt;
  mqttUser = mqttUser;
  mqttPassword = mqttPassword;

  setServer(broker, portMqtt);
}

void Mqtt::publie(String topic, String data)
{
  publish(topic.c_str(), data.c_str());
  Serial.print("\nPublish Topic :");
  Serial.println(topic);
  Serial.print("\nPublish :");
  Serial.println(data);
}

void Mqtt::reconnect()
{
  // Loop until we're reconnected
  //while (!connected()) {
    Serial.print("\nAttempting MQTT connection...");

    // Create a random client ID
    String clientId = "ArduinoSerre-";
    clientId += String(random(0xffff), HEX);

    // Attempt to connect
    if (connect(clientId.c_str())) {
      Serial.println("\nconnected");
      loop();
      // ... and resubscribe
      //subscribe(TOPIC2);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(state());
      Serial.println(" try again in 5 seconds\n");
      // Wait 5 seconds before retrying
      delay(5000);
    }
    //}
}


  void Mqtt::deconnecte()
  {
    disconnect();
    clientWifi->stop();
  }
