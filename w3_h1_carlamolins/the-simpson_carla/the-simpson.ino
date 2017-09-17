/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include <CapacitiveSensor.h>
CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); 
// 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil


#include "pitches.h"

int const piezoPin = 8;

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

void loop() {

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


  if (total1 < 50){
    
       noTone(8);
 
  
  
  }

  else if (total1 > 30){


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
 
    note++;
  }

  
}

}

