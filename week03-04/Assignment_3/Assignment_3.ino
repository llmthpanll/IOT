int incomingByte = 0;
int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Type 'a' for blinky");
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    incomingByte = Serial.read();
    Serial.print("> ");
    Serial.write(incomingByte);
    Serial.println("");
    if (incomingByte == 'a'){
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
