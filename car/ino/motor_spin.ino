#include <Servo.h>
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6
int trigerPin = 7;   // 초음파센서 TRIG - D13
int echoPin = 4;     // 초음파센서 ECHO - D12
float distance;       // 초음파 센서 거리값 변수
int Motor_speed = 120;//모터 속도 PWM

void forward() {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, Motor_speed);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, Motor_speed);
}
void back() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, Motor_speed);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, Motor_speed);
}
void left() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, Motor_speed);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, Motor_speed);
}
void right() {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, Motor_speed);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);  
      analogWrite(ENB, Motor_speed);
}
void stop() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
}

void setup() {
  //모터를 컨트롤하는 출력핀을 설정해줍니다..
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigerPin, OUTPUT); // 초음파 센서 초기화
  pinMode(echoPin, INPUT);  // 초음파 센서 초기화
  delay(1000);
}

float getDistanceCM() {   // 초음파 센서 거리 측정 함수(단위:cm)
  digitalWrite(echoPin, LOW);
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);  
  distance = pulseIn(echoPin, HIGH)  / 58;  //거리값 계산 후 저장
  return distance;
}
// 거리값 정확도를 위한 평균치 계산(1회 이상~ 10회 미만으로 조정 해보기)
float getStableDistanceCM() {
  int CmSum = 0;
  for (int i = 0; i < 8; i++) {
    CmSum += getDistanceCM();  //예, 'sum = sum + cm' 과 동일
  }
  return CmSum / 8;
}
void loop() {
   if ( getStableDistanceCM() < 25 ) {   //초음파 센서에서 25cm이하로 장애물 감지
    left();
    delay(350);//delay값으로 각도 조정 350-400 사이
    stop();
    delay(300);
}
 
