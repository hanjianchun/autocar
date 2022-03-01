#include <SoftwareSerial.h>

int LED = 6;

SoftwareSerial BT(10, 11); 

char val;

void setup() {                
  // 定义6为输出引脚
  pinMode(LED, OUTPUT);

  Serial.begin(9600); 
  Serial.println("BT is ready!");
  BT.begin(9600);
  
}

void loop() {
//    digitalWrite(LED, HIGH);   // 点亮LED
//    delay(100);               // 持续1秒
//    digitalWrite(LED, LOW);    // 熄灭LED
//    delay(200);               // 持续1秒

    if (Serial.available()) {
      val = Serial.read();
      if(val == '1'){
        digitalWrite(LED, HIGH);
      }
      BT.print(val);
    }    
     if(BT.available() > 0)
    {
      val = BT.read();
      if(val == '1'){
        digitalWrite(LED, HIGH);
      }
      if(val == '0'){
        digitalWrite(LED, LOW);
      }
      Serial.print(val);
    }
}
