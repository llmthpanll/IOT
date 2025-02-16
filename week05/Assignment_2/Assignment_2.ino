void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(2);
  if(val == LOW){ //ถ้ากด SW จะ LOW
    Serial.println("LOW");
    digitalWrite(13, HIGH);
  } else { //ถ้ากด SW จะ HIGH
    Serial.println("HIGH");
    digitalWrite(13, LOW);
  }
  delay(100);
}
