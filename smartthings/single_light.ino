#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>
#include <SPI.h>

int BUTTON = 8;
int LED = 4;

char server[] = "graph.api.smartthings.com";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(10,0,0,1);

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
  
  pinMode(BUTTON,INPUT);
  pinMode(LED,OUTPUT); 
}

void loop()
{
  if(digitalRead(BUTTON) == HIGH)
  {
    if (client.connect(server, 80)) {
      Serial.println("connected");
      client.println("GET /api/smartapps/installations/ADD_YOUR_THING_HERE HTTP/1.1");
      client.println("Host: graph.api.smartthings.com");
      client.println("User-Agent: Mozilla/5.0");
      client.println("Connection: close");
      client.println();
      
      // Added to reduce repeated connections
      delay(5000);
 
      client.stop();
  } 
  else {
    Serial.println("connection failed");
  }
    // Light LED to show command registered 
    digitalWrite(LED,HIGH);
  }
  else
  {
    // LED not on if no button press
    digitalWrite(LED,LOW); 
  }
}
