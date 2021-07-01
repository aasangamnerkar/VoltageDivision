/*
 * Project Lab5
 * Description:
 * Author:
 * Date:
 */

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
uint16_t value;
uint16_t max_thresh = 0;
uint16_t min_thresh = 4096;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D5, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // read sensor
  value = analogRead(A5);
  Serial.println(value);

  // calibrate
  max_thresh = max(max_thresh, value);
  min_thresh = min(min_thresh, value);

  // change light
  uint16_t intensity = map(value, min_thresh, max_thresh, 0, 255);
  analogWrite(D5, intensity);
  delay(300);
}