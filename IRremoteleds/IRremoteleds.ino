#include <IRremote.h>

// Define the decimal values for the remote buttons
#define up 4194696705
#define down 4211408385
#define power 4278255105
#define all 4177985025

// Define the IR receiver pin
const int IR_PIN = 2;

// Define the Led pins
int greenLed = 5;
int yellowLed = 6;

// Initialise the results
decode_results results;

// Define the IR receiver object
IRrecv irrecv(IR_PIN);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(greenLed, OUTPUT); 
  pinMode(yellowLed, OUTPUT);
}

void loop() {
  // Check if the IR receiver has received a signal
  if (irrecv.decode()){
    long unsigned int results = irrecv.decodedIRData.decodedRawData;
    Serial.println(results);
    if (results == up){
      digitalWrite(yellowLed, HIGH);
    }
    else if(results == down){
      digitalWrite(greenLed, HIGH);
    }
    else if(results == all){
      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, HIGH);
    }
    else if(results == power){
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
    }
    irrecv.resume();
  }
  delay(1000);
}