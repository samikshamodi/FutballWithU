#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);
int nice=10;
void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float data1;
  float data2;
  digitalWrite(12,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  data1 = analogRead(A0);
  digitalWrite(2,HIGH);
  data2 = analogRead(A1);
  int i=1;
  
  if(data1<150 || data2<150)
  { digitalWrite(12,LOW);
  //Serial.println(data);
  int x = BTSerial.println("10");
  int y = BTSerial.write("10");
  Serial.println(x);
  Serial.println(y);
  repeat:  
    digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
    delay(100);
    i++;
    if(i<20)
      goto repeat;
     }
 }
