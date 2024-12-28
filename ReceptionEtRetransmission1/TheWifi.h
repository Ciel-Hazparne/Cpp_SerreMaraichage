#ifndef THEWIFI_H
#define THEWIFI_H

class TheWifi : public WiFiClass
{
  const char* ssid;
  const char* pass;
      
  public:
    TheWifi(const char* ssid, const char* pass);
    void WifiStatus();
};

#endif
