#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

char val; // Data received from the serial port
//int ledPin = 13; // Set the pin to digital I/O 13


const int DISPLAY_TIME = 1000;  // used in mainColors() to determine the 
// length of time each color is displayed.

void setup() {
  //pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
    Serial.println();
  }
  if (val == 'R') { // If R was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //RED
    colorWipe(strip.Color(255, 0, 0), 50); // Red

  }
  if (val == 'B') { // If G was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //GREEN
    colorWipe(strip.Color(0, 255, 0), 50); // Green
  }
  
   if (val == 'G') { // If B was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //BLUE
     colorWipe(strip.Color(0, 0, 255), 50); // Blue

   }
   
    if (val == 'W') { // If H was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //mainColors();        // Red, Green, Blue, Yellow, Cyan, Purple, White
   colorWipe(strip.Color(255, 255, 255), 50); // White
    }
    
    if (val == 'L') { // If H was received
    //digitalWrite(ledPin, HIGH); // turn the LED on
     //mainColors();        // Red, Green, Blue, Yellow, Cyan, Purple, White
    
      rainbowCycle(20);
      
  //  showSpectrum();    // Gradual fade from Red to Green to Blue to Red
 
  delay(1000); // Wait 100 milliseconds for next reading

 

}

}

// Define functions that set colours

// Fill the dots one after the other with a color

 void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



