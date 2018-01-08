/* Project Wireless Lightswitch
 *  Purpose: wirelessly turn off LED's on top of 2 game stations
 *  How it works: USB connected to lightswitch outlet will output 5V or 0V.
 *  Upon receiving 5V, transmit RF signal to turn on 2 outlets (that have
 *  LED's connected). Upon 5V -> 0V, transmit RF signal to turn them off.
*/

const int ledPin = 13;       // number of LED pin
//const int signalPin = A0;    // the number of the pushbutton pin

float input_voltage = 0.0;
float temp          = 0.0;
float r1            = 90900.0;
float r2            = 10000.0;
int   analog_value  = 0;
bool  lightsAreOn   = false;

void setup() {               // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output
  pinMode(A0, INPUT);        // initialize signal pin as input
  digitalWrite(ledPin, LOW); // turn LED off
}

void loop() { // put your main code here, to run repeatedly:

  // read & calculate input voltage
  analog_value  = analogRead(A0); // A0 is where the signal pin connects
  temp          = (analog_value * 5.0) / 1024.0; 
  input_voltage = temp / (r2/(r1+r2));

  if (input_voltage < 1) {
     input_voltage=0.0;
     // send RF signal to turn lights off
     // turn LED off
     digitalWrite(ledPin, LOW);
     lightsAreOn = false;
   } else if (input_voltage < 6) { 
     // send RF signal to turn lights on
     // turn LED on
     digitalWrite(ledPin, HIGH);
     lightsAreOn = true;
   }

   
}
