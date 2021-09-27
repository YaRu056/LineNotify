
#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"




const byte LED=12;//宣告針腳LED
const byte trigpin=9;
const byte echopin=10;
unsigned long d;
int i;
int status=WL_IDLE_STATUS;
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

int port=443;
char host[] = "maker.ifttt.com";

WiFiClient client;



void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  Serial.begin(9600);
  while (status!=WL_CONNECTED && i<=10) {
      Serial.print("嘗試連線第 ");
      Serial.print(i);
      Serial.println("次...");
      status=WiFi.begin(ssid,pass);
      if (status!=WL_CONNECTED)
         Serial.println("無法連線");
      else 
         Serial.println("成功連線");
      i++;
      delay(5000);//每5秒嘗試一次
    }
}

// the loop function runs over and over again forever
void loop() {

 digitalWrite(trigpin,HIGH);
 delay(0.005);
 digitalWrite(trigpin,LOW);
 d= pulseIn(echopin,HIGH)/58;

 if(d<=10){
  
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    String message = "檢測你家寵物出逃啦!趕緊帶回家!";
    Serial.println("\nStarting connection to server...");
    Serial.println(message);
    
  
    if (!client.connect(host,80)) {
       Serial.println("connected fail");
     }
     else{
        Serial.println("connected successful");
        String getStr_line = "POST /trigger/IFTTT_LINE01/with/key/vfBbZOhGB5g02_pVl1GCj HTTP/1.1\r\nHost: maker.ifttt.com\r\nUser-Agent: BuildFailureDetectorESP32\r\nConnection: close\r\n\r\n";
        client.print(getStr_line);
        client.stop();
  
        delay(1000);
      }
    
  }
  else{
    digitalWrite(LED, LOW);
  }
 Serial.print(d);
 Serial.print("cm");
 Serial.println(); 
 delay(500);

}
