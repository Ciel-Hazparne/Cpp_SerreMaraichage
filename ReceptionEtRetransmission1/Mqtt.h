#ifndef MQTT
#define MQTT

class Mqtt: public PubSubClient
{
  WiFiClient * clientWifi;
  const char * broker;
  unsigned short portMqtt;
  const char * mqttUser;
  const char * mqttPassword;
  
 public:
    Mqtt(WiFiClient *clientWifi, const char * broker,
          unsigned short portMqtt, const char * mqttUser, 
          const char * mqttPassword);
    
    void publie(String topic, String valeur);
    void reconnect();
    void deconnecte();  
};

#endif
