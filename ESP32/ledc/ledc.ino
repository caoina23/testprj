#define RUN 1
#define STOP 2
String ledon="open";
String ledoff="close";
int ledm=1;
void setup()
{
    pinMode(2,OUTPUT);
    ledcSetup(1,4882,14) ;
    ledcAttachPin(2,1);
    Serial2.begin(19200);
}

void loop()
{
    ledm=Catchseri(ledon);
    delay(100);
    ledm=Catchseri(ledoff);
    delay(100);
    myseri
    /*
    if(Catchseri(ledon))
    {
        ledm=RUN;
        ledcAttachPin(2,1);
    }
        
    if(Catchseri(ledoff))
    {
         ledm=STOP;
        ledcDetachPin(2);
    }
       
    switch (ledm)
    {
    case RUN:
        for (int i = 0; i < 4069; i+=5)
        {
            ledcWrite(1,i);
            delay(2);
        }
        for (int i = 4069; i >0; i-=5)
        {
            ledcWrite(1,i);
            delay(2);
        }
        break;
    case STOP:
        ledcDetachPin(2);
        digitalWrite(2,!digitalRead(2));
        break;
    default:
        break;
    }
*/
}

bool Catchseri(String compstr)
{
    String instr=compstr;
    String tempstr="";
    while (Serial2.available())
    {
        tempstr+=Serial2.read();
        delay(10);
    }
    if (tempstr==compstr)
    {
        Serial2.print("get your mess:");
        Serial2.println(tempstr);
        tempstr="";
        return true;
    }
    else
    {
        tempstr="";
    }

    return false;
    
    
}