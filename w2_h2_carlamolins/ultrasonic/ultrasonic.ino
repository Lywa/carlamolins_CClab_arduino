/* This not working right know, needs to solved both the sensor and the button */



int buttonPin = 0;     // the number of the pushbutton pin
int ledPin =  2;      // the number of the LED pin
int trigPin = 7;     // the triggering pin of the ultrasonic sensor
int echoPin =6;      // the echo pin of the ultrasonic sensor

int buttonState = 0; // Sets button to 0

//Set up, runs only once

void setup() {
   // initialize serial communication:
   Serial.begin(9600);
   // initialize the LED pin as an output:
   pinMode(ledPin, OUTPUT);
   // initialize the pushbutton pin as an input:
   pinMode(buttonPin, INPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
}

//Loop part, it runs over and over again
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH turn on the led to check if it works
  if (buttonState == LOW) {
    // LED switch on:
    digitalWrite(ledPin, HIGH);
    delay(500); 
    }
   
    //  LED switch off
    if(buttonState= HIGH){
    digitalWrite(ledPin, LOW);    
     delay(500);
    }
  }

  void ultrasonic(){
   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);

   if (echoPin < 10) {
    // LED switch on:
    digitalWrite(ledPin, HIGH);
    delay(1000); 
    Serial.println("be careful");
    }
   
    //  LED switch off
    else if(echoPin>10){
    digitalWrite(ledPin, LOW);    
     delay(1000);
     
    }

  
  

  // a delay in time in order to avoid unstable behavior 
  delay(100);
  }




