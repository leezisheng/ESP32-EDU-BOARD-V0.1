//库函数
#include <DHT.h>
#include <Wire.h>  
#include <Adafruit_SSD1306.h> 
#include"BluetoothSerial.h"
//蓝牙初始化
BluetoothSerial SerialBT;
//函数声明
void humiture();
//定义针脚
#define DHTPIN 4  //温湿度传感器
#define scl 22
#define sda 21  //OLED
//定义类型，DHT11或者其它
#define DHTTYPE DHT11
//进行初始设置 
DHT dht(DHTPIN, DHTTYPE);
//新建iic对象以及显示屏对象
TwoWire I2Cone = TwoWire(0);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &I2Cone);
//字模
//中文：温  (存储点阵变量，用函数display.drawBitmap()调用即可)
static const unsigned char PROGMEM str_1[] =
{
  0x00,0x00,0x23,0xF8,0x12,0x08,0x12,0x08,0x83,0xF8,0x42,0x08,0x42,0x08,0x13,0xF8,
  0x10,0x00,0x27,0xFC,0xE4,0xA4,0x24,0xA4,0x24,0xA4,0x24,0xA4,0x2F,0xFE,0x00,0x00
};
//中文：度  (存储点阵变量，用函数display.drawBitmap()调用即可)
static const unsigned char PROGMEM str_2[] =
{
  0x01,0x00,0x00,0x80,0x3F,0xFE,0x22,0x20,0x22,0x20,0x3F,0xFC,0x22,0x20,0x22,0x20,
  0x23,0xE0,0x20,0x00,0x2F,0xF0,0x24,0x10,0x42,0x20,0x41,0xC0,0x86,0x30,0x38,0x0E

};
//中文：湿  (存储点阵变量，用函数display.drawBitmap()调用即可)
static const unsigned char PROGMEM str_3[] =
{
  0x00,0x00,0x27,0xF8,0x14,0x08,0x14,0x08,0x87,0xF8,0x44,0x08,0x44,0x08,0x17,0xF8,
  0x11,0x20,0x21,0x20,0xE9,0x24,0x25,0x28,0x23,0x30,0x21,0x20,0x2F,0xFE,0x00,0x00
};
void setup() {
  Serial.begin(9600);
  dht.begin(); //DHT开始工作
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
  humiture();
}
void humiture()//温湿度传感显示
{
  // 两次检测之间，要等几秒钟，这个传感器有点慢。
  delay(2000);
  // 读温度或湿度要用250毫秒
  float h = dht.readHumidity();//读湿度
  float t = dht.readTemperature();//读温度，默认为摄氏度
  Serial.print("Humidity: ");//湿度
  Serial.println(h);
  Serial.print("Temperature: ");//温度
  Serial.print(t);
  Serial.println(" ℃ ");
  display.clearDisplay();
  display.setTextColor(WHITE);//开像素点发光
  display.drawBitmap(2,1,str_1,16,16,SSD1306_WHITE);
  display.drawBitmap(21,1,str_2,16,16,SSD1306_WHITE);
  display.setCursor(40,6);
  display.print(":");
  display.drawBitmap(2,20,str_3,16,16,SSD1306_WHITE);
  display.drawBitmap(21,20,str_2,16,16,SSD1306_WHITE);
  display.setCursor(40,25);
  display.print(":");
  display.setCursor(50,2);
  display.print(t);
  display.setCursor(50,21);
  display.print(h);
  display.display();
}