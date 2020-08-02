//초음파 센서의 핀번호를 설정한다.
int echopin1 = 12;
int trigpin1 = 13;
int echopin2 = 10;
int trigpin2 = 11;
int echopin3 = 8;
int trigpin3 = 9;
int echopin4 = 6;
int trigpin4 = 7;
int echopin5 = 4;
int trigpin5 = 5;
int echopin6 = 2;
int trigpin6 = 3;
void setup() {
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(trigpin3, OUTPUT);
  pinMode(echopin3, INPUT);
  pinMode(trigpin4, OUTPUT);
  pinMode(echopin4, INPUT);
  pinMode(trigpin5, OUTPUT);
  pinMode(echopin5, INPUT);
  pinMode(trigpin6, OUTPUT);
  pinMode(echopin6, INPUT);
}

void loop() {

  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
    digitalWrite(trigpin1, LOW);
    digitalWrite(echopin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin1, HIGH);
    delayMicroseconds(10);
    unsigned long duration1 = pulseIn(echopin1, HIGH);
    
    digitalWrite(trigpin2, LOW);
    digitalWrite(trigpin2, LOW);
    digitalWrite(echopin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin2, HIGH);
    delayMicroseconds(10);
    unsigned long duration2= pulseIn(echopin2, HIGH);
    
    digitalWrite(trigpin3, LOW);
    digitalWrite(trigpin3, LOW);
    digitalWrite(echopin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin3, HIGH);
    delayMicroseconds(10);
    unsigned long duration3 = pulseIn(echopin3, HIGH); 
    
    digitalWrite(trigpin4, LOW);
    digitalWrite(trigpin4, LOW);
    digitalWrite(echopin4, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin4, HIGH);
    delayMicroseconds(10);
    unsigned long duration4= pulseIn(echopin4, HIGH);
    
    digitalWrite(trigpin5, LOW);
    digitalWrite(trigpin5, LOW);
    digitalWrite(echopin5, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin5, HIGH);
    delayMicroseconds(10);
    unsigned long duration5 = pulseIn(echopin5, HIGH); 

    
    digitalWrite(trigpin6, LOW);
    digitalWrite(trigpin6, LOW);
    digitalWrite(echopin6, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin6, HIGH);
    delayMicroseconds(10);
    unsigned long duration6= pulseIn(echopin6, HIGH);
    
  
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
     
    
    
    
    
    
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  float distance1 = ((float)(340 * duration1) / 10000) / 2;  
  float distance2 = ((float)(340 * duration2) / 10000) / 2;  
  float distance3 = ((float)(340 * duration3) / 10000) / 2;  
  float distance4 = ((float)(340 * duration4) / 10000) / 2;  
  float distance5 = ((float)(340 * duration5) / 10000) / 2;  
  float distance6 = ((float)(340 * duration6) / 10000) / 2;  
  Serial.print("1: ");
  if ( distance1 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance1);

 Serial.print("   2: ");
  if ( distance2 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance2);

 Serial.print("    3: ");
  if ( distance3 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance3);

 Serial.print("   4: ");
  if ( distance4 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance4);

     Serial.print("   5: ");
  if ( distance5 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance5);

 Serial.print("   6: ");
  if ( distance6 > 30)
    Serial.print("inf");
  else 
    Serial.print(distance6);

    
  
  Serial.println("cm");
  
  // 수정한 값을 출력
  delay(500);


  
}

 
