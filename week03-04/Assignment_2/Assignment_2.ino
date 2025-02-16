// C++ code
//
int led_green = 9;
int led_red = 3;
void setup() {
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  delay(1000);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  delay(1000);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, HIGH);
  delay(1000);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  delay(1000);
}