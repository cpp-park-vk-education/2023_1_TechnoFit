#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>
#include "uartWIFI.h"

class INetworkController{
  virtual String post() = 0;
  virtual String get() = 0;
};

class ESP : public INetworkController{
  private:
    WIFI wifi;
  public:
    ESP(String ssid, String host, String password);
    String post() override;
    String get() override;

};

#endif