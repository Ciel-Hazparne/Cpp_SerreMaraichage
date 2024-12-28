#ifndef APP
#define APP

class Application
{
  
  TheWifi MyWifi{SECRET_SSID, SECRET_PASS};
  
  WiFiClient clientWifiHttp;
  
  WiFiClient clientWifiMqtt;
  
  Lora MyLora;
  
  HttpReq clientHTTP {&clientWifiHttp, SERVER_ADDRESS};
  
  Mqtt    clientMQTT {&clientWifiMqtt, BROKER, 
                      PORT_MQTT, MQTT_USER, MQTT_PASSWORD};

                      

  public:
  Application();
  void run();
};

#endif
