#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#include "Constantes.h"
#include "DHT.h"
#include "Mesures.h"
#include "Lora.h"
#include "Application.h"

Lora::Lora(): LoRaClass()
{
  begin(868E6);
}

void Lora::SendTemperatureAndHumidity(float Temp, float Hum)
{
  beginPacket();
  print("Temp_Serre: " + String(Temp));
  print("Hum_Serre: " + String(Hum));
  endPacket();
}

void Lora::SendHumidity(float Hum)
{
  beginPacket();
  print(Hum);
  endPacket();
}
