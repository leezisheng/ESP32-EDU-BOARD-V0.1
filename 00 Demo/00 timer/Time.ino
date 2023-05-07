#include <Arduino.h>
 
hw_timer_t *tim1 = NULL;
int tim1_IRQ_count = 0;
 
void tim1Interrupt()
{//中断服务函数
  Serial.println("haha");
  tim1_IRQ_count++;
  Serial.println(timerAlarmEnabled(tim1));
}
 
void setup()
{
  Serial.begin(115200);
  tim1 = timerBegin(0, 80, true);
  timerAttachInterrupt(tim1, tim1Interrupt, true);
  timerAlarmWrite(tim1, 100000ul, true);
  timerAlarmEnable(tim1);
}
 
void loop()
{
  if (tim1_IRQ_count > 10)
  {//相当于一秒触发一次
    Serial.println("定时器触发");
    tim1_IRQ_count = 0;
  }
}

