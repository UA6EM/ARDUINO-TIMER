// Пример использования Таймера 1 (шестнадцатибитный) (с) UA6EM 
// на основе заимствований на arduino.ru у DIMAX и ЕвгенийП
#include "lgtx8p.h"

enum Prescalers {
  PRESCALER_1 = 1,
  PRESCALER_8 = 2,
  PRESCALER_64 = 3,
  PRESCALER_256 = 4,
  PRESCALER_1024 = 5
};

void setup() {
  pinMode(13,OUTPUT);
  uint8_t prescaler = PRESCALER_1024;
  uint16_t topValue = 30000;
  pinMode(9, OUTPUT);
  TCCR1A = 0x40;              //  Инвертирование пина 9 по сравнению
  TCCR1B = 0x08 | prescaler;  // Установить СТС режим и делитель частоты
  OCR1A = topValue;           //  установить TOP равным topValue
}

void loop() {
  digitalWrite(13,digitalRead(9));
  }
