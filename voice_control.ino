int motorLeft1=8;
int motorLeft2=9;
int motorRight1=10;
int motorRight2=11;

String command="";

void setup() 
{
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorRight2,OUTPUT);

  Serial.begin(9600);

  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorLeft2,LOW);
  digitalWrite(motorRight1,LOW);
  digitalWrite(motorRight2,LOW);

  delay(100);
}

void loop() 
{
  if(Serial.available()>0)
  {
    command=Serial.readString();
    
    if(command.equals("move forward"))
    {
     digitalWrite(motorLeft1,HIGH);
     digitalWrite(motorLeft2,LOW);
     digitalWrite(motorRight1,HIGH);
     digitalWrite(motorRight2,LOW);
     
    }
    if(command.equals("stop"))
    {
     digitalWrite(motorLeft1,LOW);
     digitalWrite(motorLeft2,LOW);
     digitalWrite(motorRight1,LOW);
     digitalWrite(motorRight2,LOW);
    }
    
    if(command.equals("turn left"))
    {
     digitalWrite(motorLeft1,LOW);
     digitalWrite(motorLeft2,HIGH);
     digitalWrite(motorRight1,HIGH);
     digitalWrite(motorRight2,LOW);
    }
    
    if(command.equals("turn right"))
    {
     digitalWrite(motorLeft1,HIGH);
     digitalWrite(motorLeft2,LOW);
     digitalWrite(motorRight1,LOW);
     digitalWrite(motorRight2,HIGH);
    }
  }
  command="";
}
