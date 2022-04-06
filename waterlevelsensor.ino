#define sensorpower 13
#define sensorread A0
int blue = 2;
int green = 3;
int white = 4;
void setup() {
  pinMode(sensorpower,OUTPUT);
  digitalWrite(sensorpower,LOW);
  //pinMode(sensorread,INPUT);
  Serial.begin(9600);

}

void loop() {
  int level = readSensor();
  Serial.print("Sensor read : ");
  Serial.println(level);
  delay(1000);
 /* if(level <50)
  {
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(white,LOW);
  }
  else if(50<level<100)
  {
     digitalWrite(blue,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(white,LOW);
  }
  else
  {
     digitalWrite(blue,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(white,HIGH);
  }*/
 digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(white,LOW);
}
  int level=0;
int readSensor()
{
  digitalWrite(sensorpower,HIGH);
  delay(10);
  level = analogRead(sensorread);
  digitalWrite(sensorpower,LOW);
  return level;
}
