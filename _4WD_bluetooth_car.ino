const int enB = 9;
const int in3 = 7;
const int in4 = 8;
void setup()
{
  // set all the motor control pins to outputs
 
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop()
{
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  delay(5000);
  // now change motor directions
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(5000);
  // now turn off motors
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
