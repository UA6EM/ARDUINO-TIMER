// Пример использования Таймера 2 (восьмибитный)(с) UA6EM 
// на основе заимствований на arduino.ru у DIMAX и ЕвгенийП
#include "lgtx8p.h"

enum Prescalers {
   PRESCALER_STOP = 0,
   PRESCALER_1 = 1, 
   PRESCALER_8 = 2, 
   PRESCALER_32 = 3, 
   PRESCALER_64 = 4, 
   PRESCALER_128 = 5, 
   PRESCALER_256 = 6, 
   PRESCALER_1024 = 7  
};
unsigned int counter = 0;

void setup() {
   pinMode(13, OUTPUT);
   
   uint8_t prescaler = PRESCALER_128;
   uint8_t topValue = 255;
   pinMode(11, OUTPUT);
   TCCR2A = 0x42;              // Инвертирование пина 11 по сравнению и режим CTC то OCR2A
   TCCR2B = 0x00 | prescaler;  // Установить СТС режим и делитель частоты
   OCR2A = topValue;           // установить TOP равным topValue
  }
   
void loop() {
 while(digitalRead(11)==LOW);
  counter++;
  if(counter==60000){
  digitalWrite(13,!digitalRead(13));
  counter = 0;}
}
