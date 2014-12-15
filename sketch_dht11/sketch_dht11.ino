#define DHT11_PIN 0 // Устанавливаем для работы 0 аналоговый порт

byte read_dht11_dat()

{
  byte i = 0;
  byte result=0;
  for(i=0; i< 8; i++)
  {
    while(!(PINC & _BV(DHT11_PIN)))
    {
    }; // Ждем, пока на 0 аналоговом порте не будет '1'
    delayMicroseconds(30);
    if(PINC & _BV(DHT11_PIN)) // Если после 30 мкс на 0 аналоговом порте до сих пор '1'
      result |=(1<<(7-i)); // Записываем результат
    while((PINC & _BV(DHT11_PIN))); // Ждем окончания '1'
  }
  return result;
}


void setup()
{
  DDRC |= _BV(DHT11_PIN); // Устанавливаем 0 аналоговый порт, как output
  PORTC |= _BV(DHT11_PIN); // Устанавливаем начальное значение порта в '1'
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop()
{
  byte dht11_dat[5];
  byte dht11_in;
  byte i;
  PORTC &= ~_BV(DHT11_PIN); 
  delay(18);
  PORTC |= _BV(DHT11_PIN);
  delayMicroseconds(1);
  DDRC &= ~_BV(DHT11_PIN); // Устанавливаем 0 аналоговый порт, как input 
  delayMicroseconds(40);
  dht11_in = PINC & _BV(DHT11_PIN); // считываем только 0 порт
  if(dht11_in)
  {
    Serial.println("dht11 start condition 1 not met"); // Ждем ответ от DHT:  LOW
    delay(1000);
    return;
  }
  delayMicroseconds(80);
  dht11_in = PINC & _BV(DHT11_PIN); //
  if(!dht11_in)
  {
    Serial.println("dht11 start condition 2 not met"); // Ждем второй ответ от DHT: HIGH
    return;
  }
  delayMicroseconds(80);// Готовимся к приему данных
  for (i=0; i<5; i++)
  { 
    dht11_dat[i] = read_dht11_dat();
  } // Получаем 40 бит данных
  DDRC |= _BV(DHT11_PIN); // Устанавливаем 0 аналоговый порт в положение output, после того, как все данные получены
  PORTC |= _BV(DHT11_PIN); // Устанавливаем значение этого порта в '1', после того, как все данные получены
  byte dht11_check_sum = dht11_dat[0]+dht11_dat[1]+dht11_dat[2]+dht11_dat[3];// Проверяем контрольную сумму
  if(dht11_dat[4]!= dht11_check_sum)
  {
    Serial.println("DHT11 checksum error");
  }
  Serial.print("Current humdity = ");
  Serial.print(dht11_dat[0], DEC);
  Serial.print(".");
  Serial.print(dht11_dat[1], DEC);
  Serial.print("% ");
  Serial.print("temperature = ");
  Serial.print(dht11_dat[2], DEC);
  Serial.print(".");
  Serial.print(dht11_dat[3], DEC);
  Serial.println("C ");
  delay(5000); // Время ожидания датчика
}
