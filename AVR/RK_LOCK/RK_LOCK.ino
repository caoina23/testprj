#include <arduino.h>




char a;
String b1 = " ", b2 =" ";
int l[] ={};
bool recode =false;
int j =0;
int rec_data;
String rec_datas="";

unsigned char code_local = ' ';

int ReadCode()
{
  DDRC = 0;
  PORTC = 0;

  code_local = PINC ;

}




void setup() {

  //init code IO


  Serial.begin(19200);
  Serial.println("start");
  pinMode(11,OUTPUT);
  digitalWrite(11,1);

}

void loop() 
{
  // put your main code here, to run repeatedly:


    while(Serial.available()>0)
    {
      rec_data = Serial.read();
      if(rec_data == 0x55)
      {
        j=0;
        recode=true; 
    //    Serial.println("get 55");
      }
      if (recode == true)  
      {
          if(rec_data != 0xAA)
          {
            l[j++] =  rec_data;
          }
          else 
          {
      //      Serial.println("get AA");
            l[j] = rec_data;
            for(int k=0;k<j;k++)
            {
              rec_datas += char(l[k]);
            }
    //          Serial.println(j);
              Serial.print(rec_datas);
              rec_datas = "";
            recode = false;
            j=0; 
            
          }
      }
    }
}
