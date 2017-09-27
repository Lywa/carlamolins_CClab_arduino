

char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
//const int WHITE_PIN = 0;

//const int RED_PIN2 = 1;
//const int GREEN_PIN2 = 2;
//const int BLUE_PIN2 = 3;

const int DISPLAY_TIME = 1000;  // used in mainColors() to determine the 
// length of time each color is displayed.

void setup() {
  //pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  //pinMode(WHITE_PIN, OUTPUT);
  //pinMode(RED_PIN2, OUTPUT);
  //pinMode(GREEN_PIN2, OUTPUT);
  //pinMode(BLUE_PIN2, OUTPUT);
}

void loop() {
  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
    Serial.println();
  }
  if (val == 'R') { // If R was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //RED
    analogWrite(RED_PIN, HIGH);
    analogWrite(GREEN_PIN, LOW);
    analogWrite(BLUE_PIN, LOW);
    //analogWrite(WHITE_PIN, LOW);
    //analogWrite(RED_PIN2, HIGH);
    //analogWrite(GREEN_PIN2, LOW);
    //analogWrite(BLUE_PIN2, LOW);

  }
  if (val == 'B') { // If G was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //GREE
    analogWrite(RED_PIN, LOW);
    analogWrite(GREEN_PIN, HIGH);
    analogWrite(BLUE_PIN, LOW);
    //analogWrite(WHITE_PIN, LOW);
    //analogWrite(RED_PIN2, LOW);
    //analogWrite(GREEN_PIN2, HIGH);
    //analogWrite(BLUE_PIN2, LOW); 
  }
  
   if (val == 'G') { // If B was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //BLUE
    analogWrite(RED_PIN, LOW);
    analogWrite(GREEN_PIN, LOW);
    analogWrite(BLUE_PIN, HIGH);
    //analogWrite(WHITE_PIN, LOW);
    //analogWrite(RED_PIN2, LOW);
    //analogWrite(GREEN_PIN2, LOW);
    //analogWrite(BLUE_PIN2, HIGH);
   }
   
    if (val == 'W') { // If H was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //mainColors();        // Red, Green, Blue, Yellow, Cyan, Purple, White
   analogWrite(RED_PIN, HIGH);
   analogWrite(GREEN_PIN, HIGH);
   analogWrite(BLUE_PIN, HIGH);
    //analogWrite(RED_PIN2, HIGH);
    //analogWrite(GREEN_PIN2, HIGH);
    //analogWrite(BLUE_PIN2, HIGH);
   // analogWrite(WHITE_PIN, HIGH);
    }
    
    if (val == 'L') { // If H was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //mainColors();        // Red, Green, Blue, Yellow, Cyan, Purple, White
    analogWrite(RED_PIN, LOW);
    analogWrite(GREEN_PIN, LOW);
    analogWrite(BLUE_PIN, LOW);
    //analogWrite(WHITE_PIN, LOW);
    //analogWrite(RED_PIN2, LOW);
    //analogWrite(GREEN_PIN2, LOW);
    //analogWrite(BLUE_PIN2, LOW);
     
  //  showSpectrum();    // Gradual fade from Red to Green to Blue to Red
  } else {
    //analogWrite(RED_PIN, LOW);
    //analogWrite(GREEN_PIN, LOW);
    //analogWrite(BLUE_PIN, LOW);
   // analogWrite(RED_PIN2, LOW);
    //analogWrite(GREEN_PIN2, LOW);
   // analogWrite(BLUE_PIN2, LOW);
     
  }
  delay(1000); // Wait 100 milliseconds for next reading
}





