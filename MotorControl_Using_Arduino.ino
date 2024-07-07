int speedL = 10;int IN1 = 9;
int IN2 = 8;int IN3 = 7;
int IN4 = 6;int speedR = 10;
char reading;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  for(int i=0;i<=10;i++)
  {
    pinMode(i,OUTPUT);
  }

}
void forword()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedR,128);
  analogWrite(speedL,128);
 
  
}
void backword()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(speedR,128);
  analogWrite(speedL,128);
 
  
}
void left()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedL,0);
  analogWrite(speedR,128);
 
  
}
void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(speedR,128);
  analogWrite(speedL,0);
 
  
}
void stopp()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(speedR,0);
  analogWrite(speedL,0);
 
  
}

void loop()
{
  if(Serial.available()>0)
  {
    reading =Serial.read();
    switch(reading)
    {
      case 'F' :  forword();break;
      case 'B' :  backword();break;
      case 'R' :  right();break;
      case 'L' :  left();break;
      case 'S' :  stopp();break;
      
    
    }
  
  }
 
  
}