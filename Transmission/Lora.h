#ifndef LORA1_H
#define LORA1_H

class Lora: public LoRaClass
{
  public:
    Lora();
    void SendTemperatureAndHumidity(float Temp, float Hum);
    void SendHumidity(float Hum);
};
#endif
