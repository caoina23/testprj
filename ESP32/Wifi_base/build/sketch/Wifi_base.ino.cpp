#line 1 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
#include <Arduino.h>
#include <WiFi.h>
#include <Ticker.h>

String wifiname ="Caoina";
String wifipass ="caoyinan";



#line 10 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
void smartWIFI();
#line 27 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
void setup();
#line 35 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
void loop();
#line 10 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
void smartWIFI()
{
  WiFi.mode(WIFI_MODE_STA);
  WiFi.beginSmartConfig();
  while (1)
  {
    if(WiFi.smartConfigDone())
    {
      Serial2.println("ok");
      Serial2.printf("SSID:%s",WiFi.SSID().c_str());
      Serial2.printf("PSW:%s",WiFi.psk().c_str());
    }
  }
    
}


void setup() {
  Serial2.begin(19200);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.beginSmartConfig();
  
}


void loop() {
  if(WiFi.smartConfigDone())
    {
      Serial2.println("ok");
      Serial2.printf("SSID:%s",WiFi.SSID().c_str());
      Serial2.printf("PSW:%s",WiFi.psk().c_str());
    }
  else
    Serial2.println(".");
  delay(1000);

}

