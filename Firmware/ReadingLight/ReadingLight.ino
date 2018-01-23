/******************************************************************************

LilyPad Light Sensor Example
SparkFun Electronics

This example code reads the input from a LilyPad Light Sensor and displays in
the Serial Monitor.

Light Sensor connections:
   * S pin to A3
   * + pin to A5
   * - to -

******************************************************************************/

// Set which pin the Signal output from the light sensor is connected to
// If using the LilyPad Development Board, change this to A6
int sensorPin = A3;
// Create a variable to hold the light reading
int lightValue;

void setup()
{
    // Set sensorPin as an INPUT
    pinMode(sensorPin, INPUT);

    // Set pin A5 to use as a power pin for the light sensor
    // If using the LilyPad Development Board, comment out these lines of code
    pinMode(A5, OUTPUT);
    digitalWrite(A5, HIGH);

    // Initialize Serial, set the baud rate to 9600 bps.
    Serial.begin(9600);
}

void loop()
{

   // Get the current light level
    lightValue = analogRead(sensorPin);

   // Print some descriptive text and then the value from the sensor
    Serial.print("Light value is:");
    Serial.println(lightValue);

    // Delay so that the text doesn't scroll too fast on the Serial Monitor. 
    // Adjust to a larger number for a slower scroll.
    delay(200);
}
