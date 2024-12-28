#ifndef LORA1_H
#define LORA1_H

class Lora: public LoRaClass
{  
  public:
    Lora();
    void SeperationOfData(String& TemperatureSerre, String& HumiditySerre, String& val , int);
};
#endif
