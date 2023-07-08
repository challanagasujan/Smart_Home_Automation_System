/*
* Smart Home: Using Arduino Uno & HC-05 Bluetooth 
* 
* Download the App : https://play.google.com/store/apps/details?id=appinventor.ai_ashishmarch12.Bluetooth_Voice

* This program lets you control home equipments using Relay controller
*/
//Libraries
#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

dht DHT;
String voice;                   // Variable for storing Voice data

#define DHT11_PIN 7            // DHT11 connected to PinOut 7 Arduino
#define BEDROOMLIGHT 8         // Relay IN1 connected to PinOut 8 Arduino
#define DININGROOMLIGHT 9      // Relay IN2 connected to PinOut 9 Arduino
#define BEDROOMFAN 10          // Relay IN3 connected to PinOut 10 Arduino
#define DININGROOMFAN 11       // Relay IN4 connected to PinOut 11 Arduino
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address.
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup() 
{                                            
  Serial.begin(9600);                    //Sets the baud for serial data transmission
  pinMode(BEDROOMLIGHT, OUTPUT);         // Defining Digital Pin Output
  pinMode(DININGROOMLIGHT, OUTPUT);
  pinMode(BEDROOMFAN, OUTPUT);
  pinMode(DININGROOMFAN, OUTPUT);
  
   digitalWrite(BEDROOMLIGHT,HIGH);      // Digital Pin High is Off by default
   digitalWrite(DININGROOMLIGHT,HIGH);
   digitalWrite(BEDROOMFAN,HIGH);
   digitalWrite(DININGROOMFAN,HIGH);
   
   lcd.begin(16,2);   // iInit the LCD for 16 chars 2 lines
   lcd.backlight();   // Turn on the backligt
   lcd.setCursor(0,0); //Display on first line
   lcd.print("---SMART ROOM---");
   delay(2000);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("       by       ");
   delay(1500);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("   Rounak Das   ");
   delay(2000);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("  Amitabh Raj   ");
   delay(2000);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("Rishav Chakraborty");
   delay(2000);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("Mohit K. Meena  ");
   delay(2000);
   lcd.setCursor(0,1); //Display on second line
   lcd.print("Challa N. Sujan ");
   delay(2000);
}

void loop() {

  //--- DHT11 Temperature Humidity Data ---//

  int readData = DHT.read11(DHT11_PIN);
  int temperature = DHT.temperature;
  int humidity = DHT.humidity;
   lcd.setCursor(0,0);
   lcd.print("---SMART ROOM---");
   lcd.setCursor(0,1);
   lcd.print("Temp:");
   lcd.print(temperature);
   lcd.print("C ");
   lcd.setCursor(9,1);
   lcd.print("Hum:");
   lcd.print(humidity);
   lcd.print("%");
   delay(4000);
  
  while (Serial.available())   //Check if there is an available byte to read
  {                          
  delay(10);                   //Delay added to make things stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  }
  
  if (voice.length() > 0) {
    Serial.println(voice);
  
  //---------- Control Relay ----------// 

  //------ Turning On Statements ------//
  
  if(voice == "turn on bedroom lights" || voice == "turn on bedroom light" ||voice == "bedroom lights on" || voice == "turn bedroom lights on")
    {
    digitalWrite(BEDROOMLIGHT,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Bedroom  ");
    lcd.setCursor(0,1);
    lcd.print("  Lights On  ");
    delay(4000);
    }  
  else if(voice == "turn on dining room lights" || voice == "turn on dining room light" || voice == "dining room lights on" || voice == "turn dining room lights on")
    {
    digitalWrite(DININGROOMLIGHT,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Dining Room  ");
    lcd.setCursor(0,1);
    lcd.print("  Lights On  ");
    delay(4000);
    }
  else if(voice == "turn on bedroom fan" || voice == "turn on bedroom fans" || voice == "bedroom fan on" || voice == "turn bedroom fan on")
    {
    digitalWrite(BEDROOMFAN,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Bedroom  ");
    lcd.setCursor(0,1);
    lcd.print("  Fan On  ");
    delay(4000);
    }
    else if(voice == "turn on dining room fan" || voice == "turn on dining room fans" || voice == "dining room fan on" || voice == "turn dining room fan on")
    {
    digitalWrite(DININGROOMFAN,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Dining Room  ");
    lcd.setCursor(0,1);
    lcd.print("  Fan On  ");
    delay(4000);
    }
  else if(voice == "turn on all lights" || voice == "turn on all light" || voice == "turn all lights on" || voice == "all lights on")
    {
    digitalWrite(BEDROOMLIGHT,LOW);
    digitalWrite(DININGROOMLIGHT,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  All Lights On  ");
    delay(4000);
    }
  else if(voice == "turn on all fans" || voice == "turn on all fan" || voice == "turn all fans on" || voice == "all fans on")
    {
    digitalWrite(BEDROOMFAN,LOW);
    digitalWrite(DININGROOMFAN,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  All Fans On  ");
    delay(4000);
    }
  else if(voice == "turn on everything" || voice == "turn everything on" || voice == "everything on")
    {
    digitalWrite(BEDROOMLIGHT,LOW);
    digitalWrite(DININGROOMLIGHT,LOW);
    digitalWrite(BEDROOMFAN,LOW);
    digitalWrite(DININGROOMFAN,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   Everything   ");
    lcd.setCursor(0,1);
    lcd.print("   Turned On   ");
    delay(4000);
    }
  
   //------ Turning Off Statements ------//
  
  else if(voice == "turn off bedroom lights" || voice == "turn off bedroom light" ||voice == "bedroom lights off" || voice == "turn bedroom lights off")
    {
    digitalWrite(BEDROOMLIGHT,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Bedroom  ");
    lcd.setCursor(0,1);
    lcd.print("  Lights Off  ");
    delay(4000);
    }  
  else if(voice == "turn off dining room lights" || voice == "turn off dining room light" || voice == "dining room lights off" || voice == "turn dining room lights off")         
    {
    digitalWrite(DININGROOMLIGHT,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Dining Room  ");
    lcd.setCursor(0,1);
    lcd.print("  Lights Off  ");
    delay(4000);
    }
  else if(voice == "turn off bedroom fan" || voice == "turn off bedroom fans" || voice == "bedroom fan off" || voice == "turn bedroom fan off")                 
    {
    digitalWrite(BEDROOMFAN,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Bedroom  ");
    lcd.setCursor(0,1);
    lcd.print("  Fan Off  ");
    delay(4000);
    }
    else if(voice == "turn off dining room fan" || voice == "turn off dining room fans" || voice == "dining room fan off" || voice == "turn dining room fan off")                         
    {
    digitalWrite(DININGROOMFAN,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Dining Room  ");
    lcd.setCursor(0,1);
    lcd.print("  Fan Off  ");
    delay(4000);
    }
  else if(voice == "turn off all lights" || voice == "turn off all light" || voice == "turn all lights off" || voice == "all lights off")
    {
    digitalWrite(BEDROOMLIGHT,HIGH);
    digitalWrite(DININGROOMLIGHT,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  All Lights Off  ");
    delay(4000);
    }
  else if(voice == "turn off all fans" || voice == "turn off all fan" || voice == "turn all fans off" || voice == "all fans off")
    {
    digitalWrite(BEDROOMFAN,HIGH);
    digitalWrite(DININGROOMFAN,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  All Fans Off  ");
    delay(4000);
    }
  else if(voice == "turn off everything" || voice == "turn everything off" || voice == "everything off")
    {
    digitalWrite(BEDROOMLIGHT,HIGH);
    digitalWrite(DININGROOMLIGHT,HIGH);
    digitalWrite(BEDROOMFAN,HIGH);
    digitalWrite(DININGROOMFAN,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   Everything   ");
    lcd.setCursor(0,1);
    lcd.print("   Turned Off   ");
    delay(4000);
    }
  
voice="";                                                       //Reset the variable after initiating
  }
  }
