#ifndef MESURES_H
#define MESURES_H
#define DHTPIN 3  
#define DHTTYPE DHT22
class Mesures
{
   DHT dht{DHTPIN, DHTTYPE};
     
  public :
    float lectTemp();
    float lectHum();
    Mesures();
};

#endif
