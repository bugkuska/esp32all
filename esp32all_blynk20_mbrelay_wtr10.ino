// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_FIRMWARE_VERSION        "0.2.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
// Uncomment your board, or configure a custom board in Settings.h
#define USE_WROVER_BOARD
//#define USE_TTGO_T7
#include "BlynkEdgent.h"
#include <SimpleTimer.h>
SimpleTimer timer;
//Modbus
#define RXD2            16
#define TXD2            17
HardwareSerial rs485(1);
#include "modbusRTU.h"

#define ledbb       23

//V1    mb_relay1
//V2    mb_relay2
//V3    mb_relay3
//V4    mb_relay4
//V5    mb_relay5
//V6    mb_relay6
//V7    mb_relay7
//V8    mb_relay8
//V9    mb_relay9
//V10   mb_relay10
//V11   mb_relay11
//V12   mb_relay12

//V20   wtr10e-temp
//V21   wtr10e-humi

#define Widget_btn_mbr1     V1
#define Widget_btn_mbr2     V2
#define Widget_btn_mbr3     V3
#define Widget_btn_mbr4     V4
#define Widget_btn_mbr5     V5
#define Widget_btn_mbr6     V6
#define Widget_btn_mbr7     V7
#define Widget_btn_mbr8     V8
#define Widget_btn_mbr9     V9
#define Widget_btn_mbr10    V10
#define Widget_btn_mbr11    V11
#define Widget_btn_mbr12    V12

//OLED Display
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
SSD1306Wire  display(0x3c, 21, 22);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  rs485.begin(9600, SERIAL_8N1, RXD2, TXD2);
 //delay(3000);
  //OLED
  display.init();
  display.display();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.display();
  
  pinMode(ledbb, OUTPUT);
  digitalWrite(ledbb, HIGH);
  
  BlynkEdgent.begin();

  timer.setInterval(30000L, wtr01);     
}

BLYNK_CONNECTED()
{
 Blynk.syncAll();
 if (Blynk.connected())
 {
    Serial.println("Blynk Connected");
    digitalWrite(ledbb,LOW);
    Serial.println("ledbb on");
 }
}

//================Loop Function=============//
void loop() {
  BlynkEdgent.run();
  timer.run();
}
//================Loop Function=============//

//================WTR10-E Sensor===========//
void wtr01()
{
  int id2 = 2;
  float temp2 = sht20ReadTemp_modbusRTU(id2);
  float humi2 = sht20ReadHumi_modbusRTU(id2);
 
  Serial.printf("Info: stemperature2 = %.1f\r\n",temp2);
  delay(1000);
  Serial.printf("Info:humidity2 = %.1f\r\n",humi2);
  delay(1000);
  Blynk.virtualWrite(V20,temp2);
  Blynk.virtualWrite(V21,humi2);
}
//================WTR10-E Sensor===========//

//============BUTTON ON/OFF mbr1===========//
BLYNK_WRITE(Widget_btn_mbr1){
      int valuembr1 = param.asInt();
      if(valuembr1 == 1){       
        relayControl_modbusRTU(1,1,1);        
      }
       else{                    
        relayControl_modbusRTU(1,1,0);   
     }
}  
//============BUTTON ON/OFF mbr1===========//

//============BUTTON ON/OFF mbr2===========//
BLYNK_WRITE(Widget_btn_mbr2){
      int valuembr2 = param.asInt();
      if(valuembr2 == 1){       
        relayControl_modbusRTU(1,2,1);        
      }
       else{                    
        relayControl_modbusRTU(1,2,0);   
     }
}  
//============BUTTON ON/OFF mbr2===========//

//============BUTTON ON/OFF mbr3===========//
BLYNK_WRITE(Widget_btn_mbr3){
      int valuembr3 = param.asInt();
      if(valuembr3 == 1){       
        relayControl_modbusRTU(1,3,1);        
      }
       else{                    
        relayControl_modbusRTU(1,3,0);   
     }
}  
//============BUTTON ON/OFF mbr3===========//

//============BUTTON ON/OFF mbr4===========//
BLYNK_WRITE(Widget_btn_mbr4){
      int valuembr4 = param.asInt();
      if(valuembr4 == 1){       
        relayControl_modbusRTU(1,4,1);        
      }
       else{                    
        relayControl_modbusRTU(1,4,0);   
     }
}  
//============BUTTON ON/OFF mbr4===========//

//============BUTTON ON/OFF mbr5===========//
BLYNK_WRITE(Widget_btn_mbr5){
      int valuembr5 = param.asInt();
      if(valuembr5 == 1){       
        relayControl_modbusRTU(1,5,1);        
      }
       else{                    
        relayControl_modbusRTU(1,5,0);   
     }
}  
//============BUTTON ON/OFF mbr5===========//

//============BUTTON ON/OFF mbr6===========//
BLYNK_WRITE(Widget_btn_mbr6){
      int valuembr6 = param.asInt();
      if(valuembr6 == 1){       
        relayControl_modbusRTU(1,6,1);        
      }
       else{                    
        relayControl_modbusRTU(1,6,0);   
     }
}  
//============BUTTON ON/OFF mbr6===========//

//============BUTTON ON/OFF mbr7===========//
BLYNK_WRITE(Widget_btn_mbr7){
      int valuembr7 = param.asInt();
      if(valuembr7 == 1){       
        relayControl_modbusRTU(1,7,1);        
      }
       else{                    
        relayControl_modbusRTU(1,7,0);   
     }
}  
//============BUTTON ON/OFF mbr7===========//

//============BUTTON ON/OFF mbr8===========//
BLYNK_WRITE(Widget_btn_mbr8){
      int valuembr8 = param.asInt();
      if(valuembr8 == 1){       
        relayControl_modbusRTU(1,8,1);        
      }
       else{                    
        relayControl_modbusRTU(1,8,0);   
     }
}  
//============BUTTON ON/OFF mbr8===========//

//============BUTTON ON/OFF mbr9===========//
BLYNK_WRITE(Widget_btn_mbr9){
      int valuembr9 = param.asInt();
      if(valuembr9 == 1){       
        relayControl_modbusRTU(1,9,1);        
      }
       else{                    
        relayControl_modbusRTU(1,9,0);   
     }
}  
//============BUTTON ON/OFF mbr9===========//

//============BUTTON ON/OFF mbr10===========//
BLYNK_WRITE(Widget_btn_mbr10){
      int valuembr10 = param.asInt();
      if(valuembr10 == 1){       
        relayControl_modbusRTU(1,10,1);        
      }
       else{                    
        relayControl_modbusRTU(1,10,0);   
     }
}  
//============BUTTON ON/OFF mbr10===========//

//============BUTTON ON/OFF mbr11===========//
BLYNK_WRITE(Widget_btn_mbr11){
      int valuembr11 = param.asInt();
      if(valuembr11 == 1){       
        relayControl_modbusRTU(1,11,1);        
      }
       else{                    
        relayControl_modbusRTU(1,11,0);   
     }
}  
//============BUTTON ON/OFF mbr11===========//

//============BUTTON ON/OFF mbr12===========//
BLYNK_WRITE(Widget_btn_mbr12){
      int valuembr12 = param.asInt();
      if(valuembr12 == 1){       
        relayControl_modbusRTU(1,12,1);        
      }
       else{                    
        relayControl_modbusRTU(1,12,0);   
     }
}  
//============BUTTON ON/OFF mbr12===========//
