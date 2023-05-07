//定义针脚
#define key1 23
#define key2 19
#define key3 18
#define key4 4  //按键
#define LED2 27
#define LED3 2
#define LED4 12
#define LED5 13  //LED
//按键中断函数
void INTfunc1()
{
   digitalWrite(LED2,!digitalRead(LED2));
}
void INTfunc2()
{
   digitalWrite(LED3,!digitalRead(LED3));
}
void INTfunc3()
{
   digitalWrite(LED4,!digitalRead(LED4));
}
void INTfunc4()
{
   digitalWrite(LED5,!digitalRead(LED5));
}
void setup() {
  //LED
  pinMode(LED2,OUTPUT);
  digitalWrite(LED2,LOW);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED3,LOW);
  pinMode(LED4,OUTPUT);
  digitalWrite(LED4,LOW);
  pinMode(LED5,OUTPUT);
  digitalWrite(LED5,LOW);
    //KEY
  pinMode(key1 ,INPUT_PULLUP);
  pinMode(key2 ,INPUT_PULLUP);
  pinMode(key3 ,INPUT_PULLUP);
  pinMode(key4 ,INPUT_PULLUP);
  attachInterrupt(key1,INTfunc1,RISING);
  attachInterrupt(key2,INTfunc2,RISING);
  attachInterrupt(key3,INTfunc3,RISING);
  attachInterrupt(key4,INTfunc4,RISING);
}

void loop() {
  
}
