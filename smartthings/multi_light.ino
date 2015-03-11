#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>
#include <SPI.h>

int BUTTON_DESK_LOWER= 7;
int BUTTON_DESK_UPPER = 8;
int BUTTON_SLIDING = 9;

char server[] = "graph.api.smartthings.com";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(192,168,0,174);

EthernetClient client;

void setup()
{
  Serial.begin(9600);
   while (!Serial) {
    ;
  }
  
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
 
  delay(1000);
  
  pinMode(BUTTON_DESK_LOWER,INPUT);
  pinMode(BUTTON_DESK_UPPER,INPUT);
  pinMode(BUTTON_SLIDING,INPUT);
}

void loop()
{
  if(digitalRead(BUTTON_DESK_LOWER) == HIGH)
  {
    if (client.connect(server, 80)) 
    {
      Serial.println("connected");
      client.println("GET /api/smartapps/installations/REPLACE HTTP/1.1");
      client.println("Host: graph.api.smartthings.com");
      client.println("User-Agent: Mozilla/5.0");
      client.println("Connection: close");
      client.println();
      
      delay(5000);
 
      client.stop();
     } 
    else 
    {
      Serial.println("connection failed");
    }
  }
  if(digitalRead(BUTTON_DESK_UPPER) == HIGH)
  {
    if (client.connect(server, 80)) 
    {
      Serial.println("connected");
      client.println("GET /api/smartapps/installations/REPLACE HTTP/1.1");
      client.println("Host: graph.api.smartthings.com");
      client.println("User-Agent: Mozilla/5.0");
      client.println("Connection: close");
      client.println();
      
      delay(5000);
 
      client.stop();
     } 
    else 
    {
      Serial.println("connection failed");
    }
  }
  if(digitalRead(BUTTON_SLIDING) == HIGH)
  {
    if (client.connect(server, 80)) 
    {
      Serial.println("connected");
      client.println("GET /api/smartapps/installations/REPLACE HTTP/1.1");
      client.println("Host: graph.api.smartthings.com");
      client.println("User-Agent: Mozilla/5.0");
      client.println("Connection: close");
      client.println();
      
      delay(5000);
 
      client.stop();
     } 
    else 
    {
      Serial.println("connection failed");
    }
  }
}
