
// Manually blink using push button

int led=13;
int buttonPin= 2;
int buttonState = 0;

 // put your setup code here, to run once:
void setup() {

  //initialize the pinModes

  pinMode(led,OUTPUT);
  pinMode(buttonPin,INPUT);
 

}

// put your main code here, to run repeatedly:
void loop() {
  //read the button
  buttonState = digitalRead(buttonPin);
  //Perform different actions depending on the state of the button

  if (buttonState == HIGH){
    digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(50); //wait for a second
    
   }else{
    digitalWrite(led,LOW); //turn the LED off by making the Voltage LOW
    delay(50); 
   }
  

}
