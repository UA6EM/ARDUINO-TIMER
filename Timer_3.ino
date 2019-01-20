// Пример использования Таймера 3 (шестнадцатибитный)(с) UA6EM 
// на основе заимствований на arduino.ru у DIMAX и ЕвгенийП
#include "lgtx8p.h"

enum Prescalers {
   PRESCALER_STOP = 0,
   PRESCALER_1 = 1, 
   PRESCALER_8 = 2, 
   PRESCALER_64 = 3, 
   PRESCALER_256 = 4, 
   PRESCALER_1024 = 5
};

int dig = 256;
uint8_t r3ah; 
uint8_t r3al; 

void setup() {
   pinMode(13,OUTPUT);
   
  uint8_t prescaler = PRESCALER_1024;
  uint16_t topValue = 30000;
  if(topValue > dig){
  r3ah = topValue / dig;
  r3al = topValue % dig;
  }
  else{
  r3ah = 0x00;
  r3al = topValue;
  }
 //*(uint8_t*)0x33 = 0x2;  //  DDRF=1<<DDF1 // ПИН TXI
 //*(uint8_t*)0x33 = 0x4;  //  DDRF=1<<DDF2 // ПИН D2
 //*(uint8_t*)0x33 = 0x6;  //  DDRF=1<<DDF2,DDF1 // ПИН D2 + TXI DDRF = 1<<2 | 1<<1;

 DDRF = 1<<2 | 1<<1;   // Разрешаем вывод в порты D1 и D2 
 
 OCR3AH=r3ah;          // Важно, вначале необходимо загрузить верхний регистр!!!
 OCR3AL=r3al;          // затем нижний
                       // Нельзя как для Atmega328 -  OCR3A = topValue;
                       // TCCR3A=1<<COM3A0;     // ПИН TXI
                       // TCCR3A=1<<COM3B0;     // ПИН D2
 TCCR3A=1<<COM3A0 | 1<<COM3B0;  // ПИН D2 + TXI
 TCCR3B=1<<WGM32 | prescaler;   // Режим СТС WGM3[3:0]=4 или 12
}

void loop(){
  digitalWrite(13,!digitalRead(2)); // :-)))
  }     
