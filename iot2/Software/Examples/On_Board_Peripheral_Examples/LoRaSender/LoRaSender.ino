/* 
  Basic test program, send date at the BAND you seted.
  
*/
#include <SPI.h>
#include <LoRa.h>

#define SCK     18    // GPIO5  -- SX127x's SCK
#define MISO    19   // GPIO19 -- SX127x's MISO
#define MOSI    23   // GPIO27 -- SX127x's MOSI
#define SS      5   // GPIO18 -- SX127x's CS
#define RST     27   // GPIO14 -- SX127x's RESET
#define DI0     16   // GPIO26 -- SX127x's IRQ(Interrupt Request)

#define BAND    868E6  //you can set band here directly,e.g. 868E6,915E6
#define PABOOST true

int counter = 0;

void setup() {
  pinMode(25,OUTPUT);
  
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI0);
  if (!LoRa.begin(BAND,PABOOST)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
  
  counter++;
  digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
