#include <DHT.h>
#include <Servo.h>


#define DHTPIN 2
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
Servo myservo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
myservo.attach(9);
dht.begin();
myservo.write(0); 
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
float h = dht.readHumidity();
float t = dht.readTemperature(true);
if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
    return;
}
Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *F ");


if(t<68)
{
  if(h<=55)
  {
    myservo.write(35);
  }
  else if(h>55)
  {
    myservo.write(70);
  }
}
if(t>=68&&t<77)
{
  if(h<=40)
  {
    myservo.write(70);
  }
  else
  {
    myservo.write(105);
  }
}
if(t>=77)
{
   if(h<=40)
  {
    myservo.write(105);
  }
  else
  {
    myservo.write(140);
  }
}
delay(1000);

}
