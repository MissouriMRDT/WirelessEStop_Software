#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <RoveComm.h>
#include <RoveCommManifest.h>
#include <RoveCommPacket.h>

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "ScrewYouEli"
#define STAPSK  "69696969"
#endif

RoveCommWifiUdp RoveComm;

void setup() 
{
  Serial.begin(115200);
  //WiFi.mode(WIFI_STA);
  IPAddress ip(192,168,137,45);   
  WiFi.config(ip);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print('.');
    delay(500);
  }

  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //read in any incoming packets, and display the data ids
  //rovecomm_packet packet;
  //packet = RoveComm.read();
  //Serial.println(packet.data_id);
  Serial.println("Boo");

  //RoveComm.writeTo(RC_BMSBOARD_SWESTOPs_DATAID, 1, 10, 192, 168, 137, 1, 11000);
}
