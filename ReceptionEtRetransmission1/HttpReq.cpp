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



HttpReq::HttpReq(WiFiClient * clientWifi, const char * srvAdd):
                                            clientWifi(clientWifi),
                                            srvAdd(srvAdd)
                                            {}



void HttpReq::requestPOST(String valeur, String id)
{
   if (clientWifi->connected()) clientWifi->stop();
  IPAddress ip(10,0,52,254);  
 
  if (clientWifi->connect(ip, 80))
     {
        String requete = "{\"valeur\": " + valeur + ",\"maintenance\":\"non\"" + ",\"libelleMesures\":\"/api/libelle_mesures/" + id + "\"}";
        String path = "/api/mesures HTTP/1.1";
        String hostName = "10.0.52.254";
        
        clientWifi->print("POST ");  
        clientWifi->println("/api/mesures HTTP/1.1");  
        clientWifi->print("Host: ");  
        clientWifi->println(hostName);  //Obligatoire
        clientWifi->println("Content-Type: application/json");
        clientWifi->println("Cache-Control: no-cache");  
        clientWifi->println("access-control-allow-origin: *");
        clientWifi->println("User-Agent: Flavio");
        clientWifi->println("accept: */*");
        clientWifi->println("Connection: close");
        clientWifi->print("Content-Length: ");
        clientWifi->println(requete.length());
        clientWifi->println();
        clientWifi->println(requete);
        Serial.print("aa\n");
     }
}
