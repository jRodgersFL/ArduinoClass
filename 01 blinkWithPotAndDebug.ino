/*
  Blink with Potentiometer
  Enable DEBUG mode (outputs the potValue to serial) by leaving it commented in.
  Disable DEBUG mode by commenting the line out.

  This code uses millis() to tell time so that we don't have to pause with delays.
*/

#define DEBUG           // Comment out this line to disable DEBUG mode
#define POT_PIN A0      // Pin for the potentiometer
#define LED_PIN 12      // Pin for the LED

int potValue = 0;       // Variable to store the potentiometer value
long lastTime = 0;      // Variable to store the previous time value
long thisTime = 0;      // Varialbe to store the current time value
bool ledStatus = false; // Variable used to toggle the LED status

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_PIN, OUTPUT); // Enables the LED pin as OUTPUT
  pinMode(POT_PIN, INPUT);  // Enables the potentiometer pin as INPUT
  #ifdef DEBUG              // If DEBUG is defined this code will run
    Serial.begin(9600);     // Enables the serial port
  #endif                    // Ends the "ifdef" statement
}

// the loop function runs over and over again forever
void loop() {
  // Reads the potentiometer position and uses map() to condition the output
  potValue = map(analogRead(POT_PIN), 0, 1023, 5, 5000);

  #ifdef DEBUG                // If DEBUG is defined this code will run
    Serial.println(potValue); // Prints the potentiometer value to the serial monitor
    delay(1);                 // Slight delay so that the values are readable via the monitor
  #endif                      // Ends the "ifdef" statement

  thisTime = millis(); // Sets thisTime to the current millisecond of runtime
  if(thisTime - lastTime > potValue){ // Subtracks last millisecond reading from current, then compares to the potentiometer value
    if(ledStatus) digitalWrite(LED_PIN, HIGH);  // If ledStatus is true the LED will be turned on
    else digitalWrite(LED_PIN, LOW);            // Else the LED will be turned off
    ledStatus = !ledStatus;                     // Toggles the LED status to be true or false each time this is called
    lastTime = thisTime;                        // Sets the previous millisecond time
  }
}
