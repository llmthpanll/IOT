int potpin = A0;
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);
  int mapval = map(val, 0, 1023, 0, 100);
  Serial.println(String(val) + ":" + String(mapval));
  delay(100);
}
