// -------- NODE 1 : TRANSMITTER --------

void setup() {
  Serial.begin(9600);   // Start serial communication
}

void loop() {

  int sensorValue = analogRead(A0);     // Read potentiometer
  float voltage = sensorValue * (5.0 / 1023.0) * 50.0;  
  // Scale factor 50 simulates 0–250V range

  // Send structured packet
  Serial.print("<V:");
  Serial.print(voltage);
  Serial.println(">");

  delay(1000);   // Send every 1 second
}
