//库函数
#include <Wire.h>  
#include <Adafruit_SSD1306.h> 
//函数声明
void ammonia();
//定义针脚
#define scl 22
#define sda 21  //OLED
#define ammoniaA0 25
#define ammoniaD0 26 //氨气传感器
//新建iic对象以及显示屏对象
TwoWire I2Cone = TwoWire(0);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &I2Cone);

void setup() {
  Serial.begin(9600);
  I2Cone.begin(sda, scl, 400000); 
  //初始化显示屏
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //清屏
  display.clearDisplay();
  //设置字体大小
  display.setTextSize(2);
  display.setTextColor(INVERSE); 
}

void loop() {
  ammonia();
}

void ammonia()//气体传感器
{
  delay(1000);
  float A0 = analogRead(ammoniaA0);
  A0=A0/4095*5;
  display.clearDisplay();
  display.setTextColor(WHITE);//开像素点发光
  display.setCursor(25,21);
  display.print(A0);
  display.display();

}