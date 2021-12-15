#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00001";

void setup() 
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  radio.begin();                 
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); 
  radio.stopListening();  
}


void loop()
{
  digitalWrite(4, HIGH);
  const char text1[] = "[0] [101] [111] [ok]";
  Serial.println("1");
  radio.write(&text1, sizeof(text1));
  delay(10);
  digitalWrite(4, LOW);
  const char text2[] = "0000000000000000000000000";
  Serial.println("0");
  radio.write(&text2, sizeof(text2));
  delay(10);
}
