#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT meraklimuhendis(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <virtuabotixRTC.h>
virtuabotixRTC saat(6,7,8);//clock,data,rst 
int esik_degeri=400;
int gaz_sensor = A0;
int buzzer = 13;
int alev_Sensor = 10;
int deger;
int deger_gaz;
void setup() {
  saat.setDS1302Time(00,33,15,1,23,8,2021);
  lcd.begin();
  meraklimuhendis.begin();
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(alev_Sensor,INPUT);
  pinMode(gaz_sensor,INPUT);
}

void loop() {
  float h = meraklimuhendis.readHumidity();
  float t = meraklimuhendis.readTemperature();
  float f = meraklimuhendis.readTemperature(true);
  saat.updateTime();
  deger = digitalRead(alev_Sensor);
  deger_gaz = analogRead(gaz_sensor);
  if (deger == HIGH)
  {
      digitalWrite(buzzer,LOW);
      Serial.println("Alev YOK.");
  }
  else{
    Serial.println("Alev Algılandı.");
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Alev  Tespit");
    lcd.setCursor(5,1);
    lcd.print("Edildi");
    delay(3000);
  }
  if (deger_gaz > esik_degeri){
    Serial.println("Oda hava kalitesi:DÜŞÜK");
    Serial.println(deger);
    Serial.println("");
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Zehirli  Gaz");
    lcd.setCursor(4,1);
    lcd.print("Algilandi");
    delay(3000); 
  }
  else
  {
    Serial.println("Oda hava kalitesi:yüksek");
    Serial.println(deger);
    Serial.println("");
    digitalWrite(buzzer,LOW);
    delay(1000);
  }

  
  int i;
  for(i=0; i<17; i++)
  {
  lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(saat.hours);
    lcd.print(":");
    lcd.print(saat.minutes);
    lcd.print("/");
    lcd.print(saat.dayofmonth);
    lcd.print("/");
    lcd.print(saat.month);
    lcd.print("/");
    lcd.print(saat.year);
    
    lcd.setCursor(i,1);
    lcd.print("Nem:");
    lcd.print(h);
    lcd.print("/");
    lcd.print("Sicaklik:");
    lcd.print(t);
    delay(1000);
    lcd.clear();
  }
  
}
