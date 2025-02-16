void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // 4 = Trig
  pinMode(2, INPUT); // 2 = Echo
  pinMode(10, OUTPUT); // ledPin
}

void loop() {
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  int pulseWidth = pulseIn(2, HIGH);
  long distance = pulseWidth/29/2;
  analogWrite(10, distance);
  delay(100);
}
