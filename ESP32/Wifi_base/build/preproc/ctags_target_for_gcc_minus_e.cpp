# 1 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino"
# 2 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino" 2
# 3 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino" 2
# 4 "h:\\GIT\\ESP32\\Wifi_base\\Wifi_base.ino" 2

String wifiname ="Caoina";
String wifipass ="caoyinan";



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
