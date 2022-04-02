#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
int smoke = A0;
int greenLed = 12;
int redLED1 = 11;
int redLED2 = 13;
int buzzer1=10;
int buzzer2=9;
int sensorThres = 400; //consigne mq-2

dht DHT;

#define DHT11_PIN 2

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smoke, INPUT);
  

}

void loop() {
  int smokeSensor = analogRead(smoke); //déclaration et lecture capteur fumée
  int tempChauffe=26; //consigne temperature
  int chk = DHT.read11(DHT11_PIN); // lecture temperature et humidité
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  if(DHT.temperature>tempChauffe && smokeSensor > sensorThres){ //si fumée et temperature détecté
    lcd.setCursor(0,1);
    lcd.print("TOO HOT and SMOKE");
    digitalWrite(redLED1, HIGH);//LED rouge 1 ON
    digitalWrite(redLED2, HIGH); //LED rouge 2 ON
    digitalWrite(greenLed, LOW); // LED verte Off
    tone(buzzer1, 3000); //the buzzer sound frequency at 3000 Hz
    tone(buzzer2, 400); //the buzzer sound frequency at 400 Hz
    delay(5000);
    
  }
else if (smokeSensor > sensorThres) //si fumée détectée
{
  digitalWrite(redLED2, HIGH); //LED rouge 2 ON
  digitalWrite(redLED1, LOW); //LED rouge 1 Off
  digitalWrite(greenLed, LOW); // LED verte Off
  lcd.setCursor(0,1);
  lcd.print("SMOKE");
  tone(buzzer2, 400); //the buzzer sound frequency at 400 Hz
  delay(4000);  
}
else if (DHT.temperature>tempChauffe){ //si température élevée
  digitalWrite(redLED1, HIGH); //LED rouge 1 ON
  digitalWrite(redLED2, LOW); //LED rouge 2 Off
  digitalWrite(greenLed, LOW); // LED verte Off
  tone(buzzer1, 3000); //the buzzer sound frequency at 3000 Hz
  lcd.setCursor(0,1);
  lcd.print("TOO HOT ");
}
  else{ //sinon
    noTone(buzzer1); //buzzer off
    noTone(buzzer2); //buzzer off
    digitalWrite(redLED1, LOW); //LED rouge 1 Off
    digitalWrite(redLED2, LOW); //LED rouge 2 Off
    digitalWrite(greenLed, HIGH); // LED verte ON
    lcd.setCursor(0,1);
    lcd.print("                               "); 
     
  }
}
