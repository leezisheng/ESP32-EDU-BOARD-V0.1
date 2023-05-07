//库函数
#include <Wire.h>  
#include <Adafruit_SSD1306.h> 
//函数声明
void rockerXY();
//定义针脚
#define rockerX 36  //遥感X
#define rockerY 39  //遥感Y
#define scl 22
#define sda 21  //OLED
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
    rockerXY();
}


void rockerXY() //遥感
{
  float X = analogRead(rockerX);
  float Y = analogRead(rockerY);
  Serial.print("rockerX: ");//X
  Serial.println(X);
  Serial.print("rockerY ");//Y
  Serial.print(Y);
  display.clearDisplay();
  display.setTextColor(WHITE);//开像素点发光
  display.setCursor(2,3);
  display.print("X");
  display.setCursor(15,6);
  display.print(":");
  display.setCursor(2,22);
  display.print("Y");
  display.setCursor(15,25);
  display.print(":");
  display.setCursor(25,2);
  display.print(X);
  display.setCursor(25,21);
  display.print(Y);
  display.display();
  delay(100);
}