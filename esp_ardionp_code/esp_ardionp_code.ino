
#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3); //Pin 2 & 3 of Arduino as RX and TX. Connect TX and RX of ESP8266 respectively.
#define DEBUG true
#define led_pin 11 //LED is connected to Pin 11 of Arduino
#define led_1 8
#define led_2 9
#define led_3 7
#define led_4 6

String esp8266Serial(String command, const int timeout, boolean debug)
{
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  esp8266.begin(113000); //Baud rate for communicating with ESP8266. Your's might be different.  115200
  esp8266Serial("AT+RST\r\n", 5000, DEBUG); // Reset the ESP8266
 
   
  esp8266Serial("AT+CWMODE=1\r\n", 5000, DEBUG); //Set station mode Operation

  esp8266Serial("AT+CWJAP=\"FARABI\",\"ferb1234\"\r\n", 5000, DEBUG);//Enter your WiFi network's SSID and Password.
 ;

  while (!esp8266.find("OK"))
  {
  }
 
  esp8266Serial("AT+CIFSR\r\n", 5000, DEBUG);//You will get the IP Address of the ESP8266 from this command.
  
  //esp8266Serial("AT+CIFSR\r\n", 5000, DEBUG);
  
  esp8266Serial("AT+CIPMUX=1\r\n", 5000, DEBUG);
 
  esp8266Serial("AT+CIPSERVER=1,80\r\n", 5000, DEBUG);
  //digitalWrite(led_pin, HIGH);

  
  
 
}
int lp = 0;
void loop() {
  lp++;
    digitalWrite(led_4, HIGH);
    
  if (lp == 2000) digitalWrite(led_pin, LOW);

  if (esp8266.find("+IPD,")) {
    String msg;
    Serial.println(lp);
    esp8266.find("?");
    msg = esp8266.readStringUntil('E');
    Serial.println("before message");
    int it;
    Serial.println(msg);
    for (it = 0; it < msg.length(); it++)
    {
      if (msg[it] == '?')break;
    }
    //String command = msg.substring(it+1, it+3);
    String command = msg;
    Serial.println("\nIs This Working>?<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    Serial.println(command);
    Serial.println("\n  It should really be here\n");
    Serial.println("nope");
    // String command = msg.substring(1, 2);
    Serial.println(command);
    Serial.println("joltese ekhoni");
    if (command == "on0")
    {
      digitalWrite(led_pin, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON0");
    }
    else if (command == "of0")
    {
      digitalWrite(led_pin, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF0");

    }
    else if (command == "on1")
    {
      digitalWrite(led_1, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON1");
    }
    else if (command == "of1")
    {
      digitalWrite(led_1, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF1");

    }
    else if (command == "on2")
    {
      digitalWrite(led_2, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON2");
    }
    else if (command == "of2")
    {
      digitalWrite(led_2, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF2");

    }
    else if (command == "on3")
    {
      digitalWrite(led_3, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON3");
    }
    else if (command == "of3")
    {
      digitalWrite(led_3, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF3");

    }
    else if (command == "on4")
    {
      digitalWrite(led_4, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON4");
    }
    else if (command == "of4")
    {
      digitalWrite(led_4, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF4");

    }


  }






}
