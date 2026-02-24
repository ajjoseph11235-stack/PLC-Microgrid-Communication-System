// -------- NODE 2 : RECEIVER --------

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

String inputString = "";
bool dataReady = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(8, OUTPUT);   // Relay pin
  digitalWrite(8, LOW);
}

void loop() {

  while (Serial.available()) {
    char incoming = (char)Serial.read();
    inputString += incoming;

    if (incoming == '>') {
      dataReady = true;
    }
  }

  if (dataReady) {

    // Extract voltage value
    int startIndex = inputString.indexOf(":") + 1;
    int endIndex = inputString.indexOf(">");
    float voltage = inputString.substring(startIndex, endIndex).toFloat();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage:");
    lcd.setCursor(0, 1);
    lcd.print(voltage);
    lcd.print(" V");

    // Relay control (threshold 120V)
    if (voltage > 120.0) {
      digitalWrite(8, HIGH);   // Relay ON
    } else {
      digitalWrite(8, LOW);    // Relay OFF
    }

    inputString = "";
    dataReady = false;
  }
}
