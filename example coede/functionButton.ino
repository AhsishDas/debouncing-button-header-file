#define firstButton 1
#define secondButton 2
#define resetButton 3
boolean status1=HIGH;
int i,j;
int sensor;
int flag=0;
int levelpressed[3];
int levelreleased[3];
int pressed[3]={1,1,1};
int buttonPressed( int buttonNo);


void setup()
{
  for(j=1;j<=3;j++)
  {
    pinMode(j,INPUT);
    digitalWrite(j,HIGH);
  }
  pinMode(4,INPUT);
  for(j=5;j<=7;j++)
  {
    pinMode(j,OUTPUT);
  }
}


void loop() 
{
  sensor = digitalRead(4);
  if(sensor==HIGH)
  {
    for(j=5;j<=7;j++)
    {
      digitalWrite(j,HIGH);
      flag=1;
    }
  }
  if(sensor==LOW & flag==1)
  {
    for(j=5;j<=7;j++)
    {
      digitalWrite(j,HIGH);
    }
  }
  if(buttonPressed(firstButton) & flag==0)
  {
    digitalWrite(5,status1);
    status1 = !status1;
  }
  if(buttonPressed(secondButton) & flag==0)
  {
    digitalWrite(6,status1);
    status1 = !status1;
  }
  if(buttonPressed(resetButton))
  {
    for(j=5;j<=7;j++)
    {
      digitalWrite(j,LOW);
      flag=0;
    }
  }
}

int buttonPressed(int buttonNo)
{
    if(buttonNo==1) i=0;
    if(buttonNo==2) i=1;
    if(buttonNo==3) i=2;
    if(digitalRead(buttonNo)==LOW)
    {
      levelpressed[i]++;
      levelreleased[i]=0;
      if(levelpressed[i]>100)
      {
        levelpressed[i]=0;
        if(pressed[i]==1)
        {
          pressed[i]=0;
          return 1;
        }
      }
    }
    else
    {
      levelreleased[i]++;
      levelpressed[i]=0;
      if(levelreleased[i]>100)
       {
        levelreleased[i]=0;
        pressed[i]=1;
       }
       return 0;
    }
}


