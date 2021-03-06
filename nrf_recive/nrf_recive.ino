//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>
//RF24 radio(4, 5);
//const byte address[6] = "00001";
//
//
//
//void setup() 
//{
//pinMode(6, OUTPUT);
//Serial.begin(9600);
//radio.begin();
//radio.openReadingPipe(0, address); 
//radio.setPALevel(RF24_PA_MIN);       
//radio.startListening();              
//}
//
//
//
//void loop()
//{
//if (radio.available())            
//{
//char text[32] = "";                 
//radio.read(&text, sizeof(text));  
//Serial.println(text);}
//delay(5);
//}











#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
RF24 radio(4, 5);
const byte address[6] = "00001";

 
void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.startListening();              //This sets the module as receiver
}
 
void loop()
{
  if ( radio.available() ) 
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    }
    delay(10);
}
