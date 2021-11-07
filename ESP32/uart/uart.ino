#include <arduino.h>


bool ser_finished = false ;

char rec_data = 0;
unsigned int trns_rec_h = 1;
unsigned int trns_rec_l = 1;
unsigned int trns_rec = 1;
String rec_datas = "";

unsigned int i;
hw_timer_t *timer1 = NULL;
struct Timer_set
{

} timer1_pap;

void timer_init()
{
  timer1 = timerBegin(1, 80, true); //div 80 ??1MHZ
  timerAttachInterrupt(timer1, timer1Interrupt, true);
  timerAlarmWrite(timer1, 100, true); // 100 times - >0.1ms
  timerAlarmEnable(timer1);
}



void setup() {
  Serial2.begin(19200);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  timer_init();
}

void loop() {


  //   digitalWrite(13,!digitalRead(13));
  //   delayMicroseconds(1500);
  while (Serial2.available() > 0)
  {
    rec_data = char(Serial2.read());

    if ((rec_data == '\n') || (rec_data == '\r'))
    {
      if (ser_finished)   //???????????????????????
        break;
      trns_rec = rec_datas.toInt();
      trns_rec_h = (0XFF00 & trns_rec) >> 8;
      trns_rec_l = 0X00ff & trns_rec;
      //   Serial2.println(rec_datas);
      delay(1);
      Serial2.write(trns_rec_h);
      Serial2.write(trns_rec_l);
      Serial2.write('\n');
      Serial2.println(trns_rec);
      rec_data = 0;
      rec_datas = "";
      //  trns_rec_h=trns_rec_l=0;
      digitalWrite(2, !digitalRead(2));
      ser_finished = true;
    }
    else
    {
      ser_finished = false;
      rec_datas += (char)rec_data;
    }

  }
  delay(10);
  timerAlarmWrite(timer1, 500000 / trns_rec, true);

}


void timer1Interrupt()
{
  //   if(++i>=500)    // n*t =1/F -> n=1/trns_res*(10^-4s/2)
  {
    i = 0;
    digitalWrite(2, !digitalRead(2));
    digitalWrite(13, !digitalRead(13));
  }


}
