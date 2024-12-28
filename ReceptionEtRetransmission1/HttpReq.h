#ifndef HTTP
#define HTTP

class HttpReq 
{
  WiFiClient * clientWifi;
  const char * srvAdd;

  public:
  HttpReq(WiFiClient* clientWifi ,const char * srvAdd);

  void requestPOST(String valeur, String id);
};

#endif
