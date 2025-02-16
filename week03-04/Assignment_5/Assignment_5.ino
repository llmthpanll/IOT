int RGBPin[] = {3, 5, 6};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RGBPin[0], OUTPUT);
  pinMode(RGBPin[1], OUTPUT);
  pinMode(RGBPin[2], OUTPUT);
}

void setRGB(int r, int g, int b, int time){
  analogWrite(RGBPin[0], r);
  analogWrite(RGBPin[1], g);
  analogWrite(RGBPin[2], b);
  delay(time);
}

void loop() {
 setRGB(0, 255, 255, 1000);
 setRGB(255, 0, 255, 1000);
 setRGB(255, 255, 0, 1000);
 setRGB(0, 0, 255, 1000);
 setRGB(255, 0, 0, 1000);
 setRGB(0, 255, 0, 1000);
}