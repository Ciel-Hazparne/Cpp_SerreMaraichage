#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#include "Constantes.h"
#include "DHT.h"
#include "Mesures.h"
#include "Lora.h"
#include "Application.h"

Application::Application()
{
}

void Application::run()
{
  while(1)
  {
    MyLora.SendTemperatureAndHumidity(mesures.lectTemp(), mesures.lectHum());
    delay(5000);
  }
}
