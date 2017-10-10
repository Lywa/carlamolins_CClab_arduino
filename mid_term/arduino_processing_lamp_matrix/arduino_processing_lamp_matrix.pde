/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port
PFont font;

void setup() 
{
  size(500, 500);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  println(Serial.list());
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  font= createFont ("roboto.ttf",34);
}

void draw() {
  background(255);
  if (mouseOverRectWhite() == true) {  // If mouse is over square,
    fill(204);                    // change color and
    myPort.write('W');    // send an W to indicate mouse is over square white (ON)
    println("W");
  } 
  
  if (mouseOverRectRed() == true) {  // If mouse is over square,
    fill(255,0,0,90);                    // change color and
    myPort.write('R');    // send an R to indicate mouse is over square Red
     println("R");
  } 
  
  if (mouseOverRectGreen() == true) {  // If mouse is over square,
    fill(0,255,0,90);                  // change color and
    myPort.write('G');    // send an W to indicate mouse is over square green 
     println("G");
  } 
  
  if (mouseOverRectBlue() == true) {  // If mouse is over square,
    fill(0,0,255,90);                    // change color and
    myPort.write('B');    // send an B to indicate mouse is over square blue
   println("B");
  } 
  
  if (mouseOverRectOff() ==true) {                        // If mouse is not over square,
    fill(204);                      // change color and
    myPort.write('L');              // send an L otherwise
   println("L");
  }
  noStroke();
  fill(255);
  rect(0, 0, 100, 500);  
  fill (255,0,0);
  rect(100,0,300,167);
  fill(0,255,0);
  rect(100,167,300,167);
  fill(0,0,255);
  rect(100,333,300,167);
  fill(0);
  rect(400,0,100,500);
  textFont(font);
  text("ON",30,250);
  fill(255);
  text("OFF",427,250);
  
  // Draw a square
}

boolean mouseOverRectWhite() { // Test if mouse is over square white
  return ((mouseX >= 0) && (mouseX <= 100) && (mouseY >= 00) && (mouseY <= 500));
}

boolean mouseOverRectRed(){ // Test if mouse is over square red

  return ((mouseX >= 100) && (mouseX <= 400) && (mouseY >= 00) && (mouseY <= 166));
 
}

boolean mouseOverRectGreen() { // Test if mouse is over square green
  return ((mouseX >= 100) && (mouseX <= 400) && (mouseY >= 166) && (mouseY <= 333));
}

boolean mouseOverRectBlue(){ // Test if mouse is over square blue

  return ((mouseX >= 100) && (mouseX <= 400) && (mouseY >= 333) && (mouseY <= 500));
 
}

boolean mouseOverRectOff() { // Test if mouse is over square black
  return ((mouseX >= 400) && (mouseX <= 500) && (mouseY >= 00) && (mouseY <= 500));
}



/*
  // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 
 char val; // Data received from the serial port
 int ledPin = 4; // Set the pin to digital I/O 4
 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 while (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'H') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 } else {
 digitalWrite(ledPin, LOW); // Otherwise turn it OFF
 }
 delay(100); // Wait 100 milliseconds for next reading
 }
 
 */