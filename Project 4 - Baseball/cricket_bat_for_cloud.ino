int buttonPin = 13;                   // Trigger button
GY521 sensor(0x68);                   // Sensor object
float x = 0, y = 0, z = 0;            // Accel readings

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);       // Enable the built in LED
  pinMode(buttonPin,INPUT_PULLUP);    // Setup the button
  Serial.begin(9600);                 // Begin serial
  Wire.begin();                       // Connect to the accelerometer bus
  delay(5000);                        // wait 10s as may not be connected to serial
  while (1) {
    if (sensor.wakeup()) {            //Is there an accel connection?
      Serial.println("Accellerometer connected");
      break; //and leave the loop
    } else {
      Serial.println("Accellerometer is not connected");
    }
  }
  Serial.println("Connected");        // Flash the built in LED to show everything is ready.
  for (int i = 0; i <10; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait 
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(200);                       // wait 
  }

}

void loop() {
  int buttonPressed = digitalRead(buttonPin);
  double readings[200];
  if (buttonPressed == LOW) {
    for (int counter = 0; counter < 200; counter++) {
      sensor.read();
      x = sensor.getAccelX();
      y = sensor.getAccelY();
      z = sensor.getAccelZ();
      Serial.print(x);
      Serial.print("\t");
      Serial.print(y);
      Serial.print("\t");
      Serial.print(z);
      Serial.print("\t");
      double gforce = sqrt(x*x+y*y*z*z);
      Serial.println(gforce);
      readings[counter] = gforce;
      CloudX = x;
      CloudY = y;
      CloudZ = z;
      CloudGForce = gforce;
      delay(50);
    }
  }
}

