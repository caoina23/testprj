bool led=true;
void setup() {
    Serial2.begin(19200);
    touchAttachInterrupt(4,TSR,240);
    touchAttachInterrupt(27,TSR,240);
    pinMode(2,OUTPUT);
}

void loop() {
    
}

void TSR()
{
    led!=led;
    digitalWrite(2,led);
}