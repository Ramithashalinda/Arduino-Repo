

#include <BeeLineSensorPro.h> 
#define M1 4
#define M1pwm 5
#define M2 7
#define M2pwm 6

BeeLineSensorPro sensor = BeeLineSensorPro((unsigned char[]) {
  A0, A1, A2, A3, A4, A5, A6, A7
}, LINE_BLACK);


#define MOT_RIGHT 1
#define MOT_LEFT 0
 

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  
  pinMode(M1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M2, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  char cSen_Status = 0b00000000;

  cSen_Status = cRead_Sensor();

  if((cSen_Status == 0b00001100) || (cSen_Status == 0b00000100) || (cSen_Status == 0b00001000)|| (cSen_Status == 0b00011100)|| (cSen_Status == 0b00011110)) //Forward
  {
    vMotor_Control(MOT_RIGHT, 80);
    vMotor_Control(MOT_LEFT, 80);
  }
  else if((cSen_Status == 0b00000001) || (cSen_Status == 0b00000011)  || (cSen_Status == 0b00000010) || (cSen_Status == 0b00000110)||(cSen_Status == 0b00001110) || (cSen_Status == 0b00000100)||(cSen_Status == 0b00001111)|| (cSen_Status == 0b00011111)|| (cSen_Status == 0b00000111))
  {
    vMotor_Control(MOT_RIGHT, 0);
    vMotor_Control(MOT_LEFT, 80);
  }

  else if((cSen_Status == 0b00100000) || (cSen_Status == 0b00110000) ||(cSen_Status == 0b00010000) ||(cSen_Status == 0b00111100)|| (cSen_Status == 0b00111110)|| (cSen_Status == 0b00111000)|| (cSen_Status == 0b00011000) || (cSen_Status == 0b00011100) || (cSen_Status == 0b00001000))
  {
    vMotor_Control(MOT_RIGHT, 80);
    vMotor_Control(MOT_LEFT, 0);
  }

  
  else 
  {
    vMotor_Control(MOT_RIGHT, 0);
    vMotor_Control(MOT_LEFT, 0);    
  }

  
  Serial.println((short)cSen_Status);
}

char cRead_Sensor(void) //stop
{
  short sSen_Pin[6] = {A0,A1,A2, A3,A4,A5};
  char cStatus = 0b00000000;

  for(short i=0; i<6; i++)
  {
    cStatus = cStatus | (digitalRead(sSen_Pin[i]) << i);
  }

  return cStatus;
}

void vMotor_Control(short sWhich_Mot, short sSpeed)
{
  if(sWhich_Mot == MOT_RIGHT)
  {
    if(sSpeed < 0) //reverse
    {
      sSpeed = abs(sSpeed);
      analogWrite(M1, sSpeed);
      digitalWrite(M1, LOW);
    }
    else
    {
      digitalWrite(M1, LOW);
      analogWrite(M1, sSpeed);
    }
  }
  else
  {
    if(sSpeed < 0) //reverse
    {
      sSpeed = abs(sSpeed);
      analogWrite(M2, sSpeed);
      digitalWrite(M2, LOW);
    }
    else
    {
      digitalWrite(M2, LOW);
      analogWrite(M2, sSpeed);
    }    
  }
}
