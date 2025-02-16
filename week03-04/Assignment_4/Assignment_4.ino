int ledPin = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(ledPin, 0);
  // delay(1000);
  // analogWrite(ledPin, 64);
  // delay(1000);
  for (int i = 0; i <= 256; i += 64){
    if (i == 256){
      i = 255;
    }
    Serial.println(i);
    analogWrite(ledPin, i);
    delay(1000);
  }
}