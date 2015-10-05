/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 8 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 8;        // pin that the LED is attached to
float baselineTemp = 20.0;

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  Serial.begin(9600);         //open serial port for debugging  
  Serial.println("Begin Calibration");  
  
  pinMode(3, OUTPUT);         // turn on LED to signal the start of the calibration period:
  digitalWrite(3, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  //Set baselineTemp
  baselineTemp = ((sensorMax + sensorMin)/2);
  //convert to voltage
  baselineTemp = (baselineTemp/1024.0) * 5.0;
  //convert the voltage to temperature in degrees
  baselineTemp = (baselineTemp - .5) * 100;
  
  
  Serial.print("Max temperature: ");
  Serial.print(sensorMax);
  Serial.print(", Min temperature: ");
  Serial.print(sensorMin);
  Serial.print(", baselineTemp (Temperature): ");
  Serial.print(baselineTemp);
  Serial.println("End Calibration");  
  
  // signal the end of the calibration period
  //digitalWrite(3, LOW);

  // init: turn off all leds
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // read the sensor:
  //sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  //sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  //sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  //analogWrite(ledPin, sensorValue);


  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);
  Serial.print(", baseLineTemp: ");
  Serial.println(baselineTemp);


  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);

}
