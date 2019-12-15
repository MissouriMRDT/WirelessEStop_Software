#include <ESP8266WiFi.h>
#include "RoveComm.h"

#ifndef STASSID
#define STASSID "<ID>"
#define STAPSK  "<PSSWD>"
#endif

RoveCommWifiUdp RoveComm;

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print('.');
    delay(500);
  }
  IPAddress ip(192,168,1,200);   
  IPAddress gateway(192,168,1,254);   
  IPAddress subnet(255,255,255,0);   
  WiFi.config(ip, gateway, subnet);

  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //read in any incoming packets, and display the data ids
  rovecomm_packet packet;
  packet = RoveComm.read();
  Serial.println(packet.data_id);


  RoveComm.writeTo(RC_BMSBOARD_SWESTOPs_DATAID, 1, 10, 192, 168, 1, RC_BMSBOARD_FOURTHOCTET, 11000)
}
