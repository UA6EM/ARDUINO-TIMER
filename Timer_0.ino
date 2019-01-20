// Пример использования Таймера 0 (восьмибитный) (с) UA6EM 
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
unsigned int counter = 0;

void setup() {
   pinMode(13, OUTPUT);
   
   uint8_t prescaler = PRESCALER_1024;
   uint8_t topValue = 255;
   pinMode(6, OUTPUT);
   TCCR0A = 0x42;              // Инвертирование пина 6 по сравнению и режим CTC то OCR0A
   TCCR0B = 0x00 | prescaler;  // Установить СТС режим и делитель частоты
   OCR0A = topValue;           // установить TOP равным topValue
}

void loop() {
  while(digitalRead(6)==LOW);
  counter++;
  if(counter==60000){
  digitalWrite(13,!digitalRead(13));
  counter = 0;}
}
