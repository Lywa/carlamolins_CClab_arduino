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

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  // turn off autocalibrate on channel 1 - just as an example 


  Serial.begin(9600);

  
  
}


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


     // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

   
  
  }
}
