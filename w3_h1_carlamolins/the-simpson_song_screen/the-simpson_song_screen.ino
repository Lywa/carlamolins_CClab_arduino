/*
  Melody + liquid crystal

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 6

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone


  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

Modified by Carla Molins
September 17 2017

  
*/

#include <CapacitiveSensor.h>
CapacitiveSensor cs_4_2 = CapacitiveSensor(7,8); 
// 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil

// include the library code:
#include "LiquidCrystal.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "pitches.h"

int const piezoPin = 6;

int bpm = 100;
int bps = bpm / 60;
int fullNoteMs = 1000 / bps;
int halfNoteMs = fullNoteMs / 2;
int quarterNoteMs = halfNoteMs / 2;
int eighthNoteMs = quarterNoteMs / 2;

int note = 0;
int duration = 0;

void setup() {

   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  // turn off autocalibrate on channel 1 - just as an example 

  
  Serial.begin(9600); 
}

//The Simpson's main theme plays: C-E-F#-A-G-E-C-G-F#-F#-F#-G
//The tune rises for the first 4 notes, then from the G goes down to the G an octave lower. Three fast F#'s and back to the G.
int simpsons[] = {HALF, NOTE_C4, QUARTER, NOTE_E4, NOTE_FS4, EIGHTH, NOTE_A4, HALF, NOTE_G4, QUARTER, NOTE_E4, NOTE_C4, NOTE_G3, EIGHTH, NOTE_FS3, NOTE_FS3, NOTE_FS3, QUARTER, NOTE_G3};
int numNotes = sizeof(simpsons)/sizeof(int);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("The Simpson theme");

void loop() {

  
  //  LCD screen
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

  
  //Capacitive sensor
   long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30);
  Serial.print(millis() - start); 
  // check on performance in milliseconds
  Serial.print("\t");
 // tab character for debug window spacing
  Serial.println(total1); 
  // print sensor output 1
  
  delay(10); 
  // arbitrary delay to limit data to serial port


  if (total1 < 180){
    
       noTone(piezoPin);
 
  
  
  }

  else if (total1 > 200){


  if (note < numNotes) {
    if (simpsons[note] == HALF) {
      duration = halfNoteMs;
      note++;
      return;
    }
    if (simpsons[note] == QUARTER) {
      duration = quarterNoteMs;
      note++;
      return;
    }
    if (simpsons[note] == EIGHTH) {
      duration = eighthNoteMs;
      note++;
      return;
    }
    
    if (simpsons[note] == SILENCE) {
      noTone(piezoPin);
      delay(duration);
    } else { 
      tone(piezoPin, simpsons[note]);
      delay(duration);
      noTone(piezoPin);
    }
    Serial.print("\t");
    Serial.println(simpsons[note]);
    note++;
  }

  else if (note == numNotes) {

    note=0;

  }

  
}

}

