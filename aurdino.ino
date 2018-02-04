int out_pin1 = 1;
int out_pin2 = 2;
int out_pin3 = 3;
int out_pin4 = 4;
void setup() {
  pinMode(out_pin1, OUTPUT);
  pinMode(out_pin2, OUTPUT);
  pinMode(out_pin3, OUTPUT);
  pinMode(out_pin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(out_pin4, 1);
  digitalWrite(out_pin4, 0);
  digitalWrite(out_pin1, random(0,2));
  digitalWrite(out_pin2, random(0,2));
  digitalWrite(out_pin3, random(0,2));
  delay(2000);
}