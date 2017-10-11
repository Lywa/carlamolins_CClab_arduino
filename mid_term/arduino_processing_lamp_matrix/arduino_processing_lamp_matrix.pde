/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Wiring / Arduino program that follows below.
 */

// Constants
int Y_AXIS = 1;
int X_AXIS = 2;
color a1, a2, b1, b2, c1, c2, d1,d2, e1, e2 , f1, f2;

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
  
  // Define colors
  
  a1= color (255,0,0);
  a2= color (255,255,0);
  b1 = color(255,255,0);
  b2 = color(0,255,0);
  c1 = color(0,255,0);
  c2 = color(0, 255, 255);
  d1= color(0, 255, 255);
  d2= color (0, 0,255);
  e1= color (0,0,255);
  e2 = color (255,0,255);
  
}

void draw() {
  background(255);
  if (mouseOverRectWhite() == true) {  // If mouse is over square,
    fill(204);                    // change color and
    myPort.write('W');    // send an W to indicate mouse is over square white (ON)
    println("W");
  } 
  
  if (mouseOverRectRed() == true) {  // If mouse is over square,
    myPort.write('R');    // send an R to indicate mouse is over square Red
     println("R");
  } 
  
  if (mouseOverRectYellow() == true) {  // If mouse is over square,
    fill(255,0,0,90);                    // change color and
    myPort.write('Y');    // send an R to indicate mouse is over square Yellow
     println("Y");
  } 
  
  if (mouseOverRectGreen() == true) {  // If mouse is over square,
    fill(0,255,0,90);                  // change color and
    myPort.write('G');    // send an W to indicate mouse is over square green 
     println("G");
  } 
  
   if (mouseOverRectCyan() == true) {  // If mouse is over square,
    fill(0,255,0,90);                  // change color and
    myPort.write('C');    // send an W to indicate mouse is over square green 
     println("C");
  } 
  
  if (mouseOverRectBlue() == true) {  // If mouse is over square,
    fill(0,0,255,90);                    // change color and
    myPort.write('B');    // send an B to indicate mouse is over square blue
   println("B");
  } 
  
  if (mouseOverRectPink() == true) {  // If mouse is over square,
    fill(0,0,255,90);                    // change color and
    myPort.write('P');    // send an B to indicate mouse is over square blue
   println("P");
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
  fill(255,255,0);
  rect(250,0,300,167);
  fill(0,255,0);
  rect(100,167,300,167);
  fill(0,255,255);
  rect(250,167,300,167);
  fill(0,0,255);
  rect(100,333,300,167);
  fill(255,0,255);
  rect(250,333,300,168);
  
  setGradient(400, 0, 100, 100, a1, a2, Y_AXIS);
  setGradient(400, 100, 100, 100, b1, b2, Y_AXIS);
  setGradient(400, 200, 100, 100, c1, c2, Y_AXIS);
  setGradient(400, 300, 100, 100, d1, d2, Y_AXIS);
  setGradient(400, 400, 100, 100, e1, e2, Y_AXIS);
  
  //fill(0);
  //rect(400,0,100,500);
  fill(0);
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

  return ((mouseX >= 100) && (mouseX <= 250) && (mouseY >= 00) && (mouseY <= 166));
 
}

boolean mouseOverRectYellow(){ // Test if mouse is over square Yellow

  return ((mouseX >= 250) && (mouseX <= 400) && (mouseY >= 00) && (mouseY <= 166));
 
}


boolean mouseOverRectGreen() { // Test if mouse is over square green
  return ((mouseX >= 100) && (mouseX <= 250) && (mouseY >= 166) && (mouseY <= 333));
}

boolean mouseOverRectCyan() { // Test if mouse is over square Cyan
  return ((mouseX >= 250) && (mouseX <= 400) && (mouseY >= 166) && (mouseY <= 333));
}

boolean mouseOverRectBlue(){ // Test if mouse is over square blue

  return ((mouseX >= 100) && (mouseX <= 250) && (mouseY >= 333) && (mouseY <= 500));
 
}

boolean mouseOverRectPink(){ // Test if mouse is over square pink

  return ((mouseX >= 250) && (mouseX <= 400) && (mouseY >= 333) && (mouseY <= 500));
 
}


boolean mouseOverRectOff() { // Test if mouse is over square gradient colors
  return ((mouseX >= 400) && (mouseX <= 500) && (mouseY >= 00) && (mouseY <= 500));
}

void setGradient(int x, int y, float w, float h, color c1, color c2, int axis ) {

  noFill();

  if (axis == Y_AXIS) {  // Top to bottom gradient
    for (int i = y; i <= y+h; i++) {
      float inter = map(i, y, y+h, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(x, i, x+w, i);
    }
  }  
  else if (axis == X_AXIS) {  // Left to right gradient
    for (int i = x; i <= x+w; i++) {
      float inter = map(i, x, x+w, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(i, y, i, y+h);
    }
  }
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