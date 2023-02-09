int PUL=7;
int DIR=6;
int ENA=5;

int PUL_M=12;
int DIR_M=11;
int ENA_M=10;

int SPEED = 170;

int current_location = 0;


void setup() 
{
  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  pinMode(PUL_M, OUTPUT);
  pinMode(DIR_M, OUTPUT);
  pinMode(ENA_M, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)  // 문자들어오면 실행
  {
    String inputStr = Serial.readStringUntil('\n');
   

   if(inputStr.equals("plastic"))
   {
      Serial.end();
     
      move_basket(0);
           
      Serial.begin(9600);
      
      Serial.println("O");
    }
    
   if(inputStr.equals("paper"))
   {
      Serial.end();
      
      move_basket(6600);
      
      Serial.begin(9600);
      
      Serial.println("O");

    } 


    if(inputStr.equals("can"))
   {
      Serial.end();
      
      
      move_basket(14000);
      
      
      Serial.begin(9600);
      
      Serial.println("O");
      
    } 

    if(inputStr.equals("battery"))
   {
      Serial.end();
      
      move_basket(20500);
      
      Serial.begin(9600);
      
      Serial.println("O");
      
    } 

    if(inputStr.equals("test"))
   {
       push_trash();
   } 

 
 }
}


void push_trash() // 쓰레기 미는 동작
{
      for(int i=0; i<30000; i++) //i 크기가 너무 커지면 모터가 멈추지 않는현상 발생함. 코드가 길어 지더라도 3만 단위로 끊어야 할듯
      {
        digitalWrite(DIR_M,LOW);
        digitalWrite(ENA_M,HIGH);
        digitalWrite(PUL_M,HIGH);
        delayMicroseconds(100);
        digitalWrite(PUL_M,LOW);
        delayMicroseconds(100);
      }

      for(int i=0; i<4500; i++) 
      {
        digitalWrite(DIR_M,LOW);
        digitalWrite(ENA_M,HIGH);
        digitalWrite(PUL_M,HIGH);
        delayMicroseconds(100);
        digitalWrite(PUL_M,LOW);
        delayMicroseconds(100);
      }



      for(int i=0; i<30000; i++) //복귀
      {
        digitalWrite(DIR_M,HIGH);
        digitalWrite(ENA_M,HIGH);
        digitalWrite(PUL_M,HIGH);
        delayMicroseconds(100);
        digitalWrite(PUL_M,LOW);
        delayMicroseconds(100);
      }

      for(int i=0; i<4500; i++) 
      {
        digitalWrite(DIR_M,HIGH);
        digitalWrite(ENA_M,HIGH);
        digitalWrite(PUL_M,HIGH);
        delayMicroseconds(100);
        digitalWrite(PUL_M,LOW);
        delayMicroseconds(100);
      }
}

 void move_basket(int location) // 레일이 지정된 위치까지 이동하는 동작
{
  
  
  
    for(int i=0; i<location; i++) // 이동거리 (21900이 레일 길이), DIR LOW일 경우 아래로 이동한다
      {
        digitalWrite(DIR,LOW);
        digitalWrite(ENA,HIGH);
        digitalWrite(PUL,HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(PUL,LOW);
        delayMicroseconds(SPEED);    
      }
      
      
      push_trash();
      
      
      
    for(int i=0; i<location; i++) // 이동거리 (21900이 레일 길이), DIR LOW일 경우 아래로 이동한다
      {
        digitalWrite(DIR,HIGH);
        digitalWrite(ENA,HIGH);
        digitalWrite(PUL,HIGH);
        delayMicroseconds(SPEED);
        digitalWrite(PUL,LOW);
        delayMicroseconds(SPEED);   
      }
 

  
}
