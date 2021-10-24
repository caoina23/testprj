
void setup() {
  // put your setup code here, to run once:
  pinMode(31, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(31, 0);
  delay(1000);
  digitalWrite(31, 1);
  delay(1000);
  Serial.println("aBCD");
}
