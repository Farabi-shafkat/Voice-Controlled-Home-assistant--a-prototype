
#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3); //Pin 2 & 3 of Arduino as RX and TX. Connect TX and RX of ESP8266 respectively.
#define DEBUG true
#define led_pin 11 //LED is connected to Pin 11 of Arduino
#define led_1 8
#define led_2 9
#define led_3 7
#define led_4 6
int state[5];

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

  esp8266Serial("AT+CWJAP=\"FARABI\",\"ferb1234\"\r\n", 5000, DEBUG);//Enter WiFi network's SSID and Password.


  while (!esp8266.find("OK"))
  {
  }

  esp8266Serial("AT+CIFSR\r\n", 5000, DEBUG);//You will get the IP Address of the ESP8266 from this command.

  //esp8266Serial("AT+CIFSR\r\n", 5000, DEBUG);

  esp8266Serial("AT+CIPMUX=1\r\n", 5000, DEBUG);

  esp8266Serial("AT+CIPSERVER=1,80\r\n", 5000, DEBUG);
  //digitalWrite(led_pin, HIGH);
  memset(state, 0, sizeof(state));



}

void loop() {

  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  sleep(4);
   digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  // if (lp == 2000) digitalWrite(led_pin, LOW);

  if (esp8266.find("+IPD,")) {
    String msg;
    // Serial.println(lp);
    esp8266.find("?");
    msg = esp8266.readStringUntil('E');

    int it;
    Serial.println(msg);
    for (it = 0; it < msg.length(); it++)
    {
      if (msg[it] == '?')break;
    }
    //String command = msg.substring(it+1, it+3);
    String command = msg;

    // String command = msg.substring(1, 2);
    Serial.println(command);
    Serial.println("joltese ekhoni");
    if (command == "on0")
    {
      digitalWrite(led_pin, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);

      esp8266.print("ON0");
      state[0] = true;
    }
    else if (command == "of0")
    {
      digitalWrite(led_pin, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF0");
      state[0] = false;
    }
    else if (command == "on1")
    {
      digitalWrite(led_1, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON1");
      state[1] = true;
    }
    else if (command == "of1")
    {
      digitalWrite(led_1, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF1");
      state[1] = false;
    }
    else if (command == "on2")
    {
      digitalWrite(led_2, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON2");
      state[2] = true;
    }
    else if (command == "of2")
    {
      digitalWrite(led_2, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF2");
      state[2] = false;

    }
    else if (command == "on3")
    {
      digitalWrite(led_3, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON3");
      state[3] = true;
    }
    else if (command == "of3")
    {
      digitalWrite(led_3, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF3");
      state[3] = false;
    }
    else if (command == "on4")
    {
      digitalWrite(led_4, HIGH);

      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ON4");
      state[4] = true;
    }
    else if (command == "of4")
    {
      digitalWrite(led_4, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFF4");
      state[4] = false;
    }
    else if (command == "sta")
    {
      String str = "";
      for (int i = 0; i < 5; i++)
      {
        str += '0' + state[i];
      }
      Serial.println(str);
      esp8266Serial("AT+CIPSEND=0,10\r\n", 5000, DEBUG);
      esp8266.print(str);
    }
    else if (command == "al1")
    {
      digitalWrite(led_pin, HIGH);
      digitalWrite(led_1, HIGH);
      digitalWrite(led_2, HIGH);
      digitalWrite(led_3, HIGH);
      digitalWrite(led_4, HIGH);
      esp8266Serial("AT+CIPSEND=0,3\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("ONA");
      state[0] = 1;
      state[1] = 1;
      state[2] = 1;
      state[3] = 1;
      state[4] = 1;
    }
    else if (command == "al0")
    {
      digitalWrite(led_pin, LOW);
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      digitalWrite(led_3, LOW);
      digitalWrite(led_4, LOW);
      esp8266Serial("AT+CIPSEND=0,4\r\n", 5000, DEBUG);
      //esp8266Serial("AT+CIPSEND=0,5\r\n", 5000, DEBUG)
      //+IPD,0,2:on
      esp8266.print("OFFA");
      state[4] = false;
      state[0] = 0;
      state[1] = 0;
      state[2] = 0;
      state[3] = 0;
      state[4] = 0;
    }


  }






}
