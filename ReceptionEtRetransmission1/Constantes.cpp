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

const char * SECRET_SSID {"SNIR"};
const char * SECRET_PASS {"bts-snir"};

const char * SERVER_ADDRESS {"https://flavio1.free.beeceptor.com"};


const char * BROKER {"185.182.169.30"};
const char * TOPIC1 {"maraichage/Temp_champ"};
const char * TOPIC2 {"maraichage/Humid_champ"};
const char * TOPIC4 {"maraichage/Humid_serre"};
const char * TOPIC3 {"maraichage/Temp_serre"};
const char * CLIENT_ID {"ArduinoSerre-"};
const char * MQTT_USER {""};
const char * MQTT_PASSWORD {""};
const unsigned short PORT_MQTT = 1883;
const char * FREQUENCY = "868E6" ;
const char *  HOST_NAME {"flavio1.free.beeceptor.com"};
