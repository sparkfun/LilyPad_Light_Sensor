/******************************************************************************

LilyPad Light Sensor Trigger - Automatic Night Light
SparkFun Electronics

Adapted from Digital Sandbox Experiment 11: Automatic Night Light

This example code reads the input from a LilyPad Light Sensor compares it to
a set threshold named 'dark'. If the light reading is below the threshold,
an LED will turn on.

Light Sensor connections:
   * S pin to A3
   * + pin to A5
   * - to -

Connect an LED to pin 5 or use the built-in LED on pin 13

******************************************************************************/
// The dark variable determines when we turn the LEDs on or off. 
// Set higher or lower to adjust sensitivity.
const int darkLevel = 50;

// Create a variable to hold the readings from the light sensor.
int lightValue;

// Set which pin the Signal output from the light sensor is connected to
// If using the LilyPad Development Board, change this to A6
int sensorPin = A3;

// Set which pin the LED is connected to. 
// Set to 13 if you'd rather use the LilyPad Arduino's built-in LED.
int ledPin = 5;

void setup()
{
    // Set sensorPin as an INPUT
    pinMode(sensorPin, INPUT);

    // Set LED as outputs
    pinMode(ledPin, OUTPUT);

    // Set pin A5 to use as a power pin for the light sensor
    // If using the LilyPad Development Board, comment out these lines of code
    pinMode(A5, OUTPUT);
    digitalWrite(A5, HIGH);

    // Initialize Serial, set the baud rate to 9600 bps.
    Serial.begin(9600);
}

void loop()
{
    // Read the light sensor's value and store in 'lightValue'
    lightValue = analogRead(sensorPin);

    // Print some descriptive text and then the value from the sensor
    Serial.print("Light value is:");
    Serial.println(lightValue);

    // Compare "lightValue" to the "dark" variable
    if (lightValue <= darkLevel) // If the reading is less then 'darkLevel'
    {
        digitalWrite(ledPin, HIGH); // Turn on LED
    }
    else // Otherwise, if "lightValue" is greater than "dark"
    {
        digitalWrite(ledPin, LOW);  // Turn off LED
    }

    // Delay so that the text doesn't scroll to fast on the Serial Monitor. 
    // Adjust to a larger number for a slower scroll.
    delay(100);
}
