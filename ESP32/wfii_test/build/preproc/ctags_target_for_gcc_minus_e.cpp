# 1 "h:\\GIT\\ESP32\\wfii_test\\wifitest.ino"
# 2 "h:\\GIT\\ESP32\\wfii_test\\wifitest.ino" 2
# 3 "h:\\GIT\\ESP32\\wfii_test\\wifitest.ino" 2

void mySmartWifiConfig()
{
  WiFi.mode(WIFI_MODE_STA);
  Serial2.println("开启智能配网:");
  WiFi.beginSmartConfig();
  while (1)
  {
    Serial2.print(".");
    delay(500);
    if (WiFi.smartConfigDone())
    {
      Serial2.println("配网成功");
      Serial2.printf("SSID:%s", WiFi.SSID().c_str());
      Serial2.printf("PSW:%s", WiFi.psk().c_str());
      break;
    }
  }
}

bool autoConfig()
{
  WiFi.disconnect(true,true);
  WiFi.begin();
  for (size_t i = 0; i < 20; i++)
  {
    int wifiStatus = WiFi.status();
    if (wifiStatus == WL_CONNECTED)
    {
      Serial2.println("自动连接成功!");
      return 1;
    }
    else
    {
      delay(1000);
      Serial2.println("等待自动配网中...");
    }
  }
  Serial2.println("无法自动配网!");
  return 0;
}

void setup()
{
  Serial2.begin(115200);
  WiFi.disconnect();
  delay(5000);
  if (!autoConfig())
  {
    mySmartWifiConfig();
  }
}
void loop()
{
  if (WiFi.isConnected())
  {
    Serial2.println("网络已连接");
    delay(1000);
  }
}
