# 开发板介绍

​	开发板以ESP32 WROOM最小系统板为核心，板载5V降压稳压模块和供电指示电路、RS485通信模块、摇杆模块、OLED显示模块、气体传感器接口、DTH11温湿度传感器模块、18650电池盒、蜂鸣器驱动电路和按键及LED驱动电路组成。

​	实物图如下所示：

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/0.jpg)

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/1.jpg)

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/2.jpg)

​	相关原理图如下：

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/schematic.png)

​	相关PCB的3D模型图如下：

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/3.png)

![image](https://github.com/leezisheng/ESP32-EDU-BOARD-V0.1/blob/master/Pic/4.png)

# 文件夹介绍

​	00 Demo：

  	相关软件例程，包括
​		00 timer：定时器实验例程
​		01 ammonia：ESP32 ADC外设数据读取，计算气体传感器浓度例程
​		02 Bluetooth：ESP32蓝牙外设使用实验
​		03 humiture：ESP32读取DTH11温湿度传感器数据实验
​		04 key：ESP32 GPIO口外部中断实验
​		05 rockerXY：ESP32 读取遥感位置实验
​	01 Hardware：

​		相关开发板的原理图和PCB图，及其工程文件

​	02 Video：

​		相关资料关注公众号：工训A座413，或者B站视频号：工训A413实验室

​		软件相关课程：
​			00 esp32制作循迹小车导论课
​			https://www.bilibili.com/video/BV1X8411h7uW/?spm_id_from=333.999.0.0
​			01 esp32第一课，用arduion安装esp32开发环境
​			https://www.bilibili.com/video/BV1Wd4y1r7pR/?spm_id_from=333.999.0.0
​			02 ESP32第二课之GPIO的输入输出
​			https://www.bilibili.com/video/BV1J84y1y7jj/?spm_id_from=333.999.0.0
​			03 ESP32第三课之外部中断
​			https://www.bilibili.com/video/BV1424y127jU/?spm_id_from=333.999.0.0

​		硬件相关课程：
​			00 纳新培训（硬件篇）第一课：立创EDA基本使用
​			https://www.bilibili.com/video/BV16P4y1X7go/?spm_id_from=333.999.0.0
​			01 纳新培训（硬件篇）第二课：稳压电源电路
​			https://www.bilibili.com/video/BV1iP411u7g7/?spm_id_from=333.999.0.0
​			02  纳新培训（硬件篇）第三课：双H桥电机驱动电路
​			https://www.bilibili.com/video/BV1iP411u7g7/?spm_id_from=333.999.0.0
