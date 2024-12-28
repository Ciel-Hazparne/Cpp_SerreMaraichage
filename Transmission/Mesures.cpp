#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#include "Constantes.h"
#include "DHT.h"
#include "Mesures.h"
#include "Lora.h"
#include "Application.h"


Mesures::Mesures()
{
  dht.begin();
  delay(5000);
}

float Mesures::lectTemp()
{
  float res = dht.readTemperature();
  Serial.print("Temperature: "); Serial.println(res);
  return res;
}

float Mesures::lectHum()
{
  float res = dht.readHumidity();
  Serial.print("Humidite: "); Serial.println(res);
  return res;
}
