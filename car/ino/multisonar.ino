#include <Servo.h>
#include <NewPing.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

#define NUM_SONAR 2 // number of sonar sensors
#define MAX_DISTANCE 25 // Milliseconds // 3개의 경우 100ms
unsigned long pingTimer[NUM_SONAR]; // When each pings.
unsigned int cm[NUM_SONAR]; // Store ping distances.
uint8_t currentSensor = 0;




enum Sensor_Location {
  FORWARD=0, RIGHT    
};

int trig_forward = 13;   // 초음파센서 TRIG - D13
int echo_forward = 12;     // 초음파센서 ECHO - D12
int trig_right = 7;    // 초음파센서 TRIG - D7
int echo_right = 4;      // 초음파센서 ECHO - D4
float distance;       // 초음파 센서 거리값 변수
int servoPin = 2;     // 서보모터 연결 포트
int Motor_speed = 70; //모터 속도 PWM
Servo servo;
NewPing sonar[NUM_SONAR] = { // array of sonar sensor objects
//sonar(TrigPin, EchoPin, MaxDistance);

  NewPing(trig_forward, echo_forward, MAX_DISTANCE),

  NewPing(trig_right, echo_right, MAX_DISTANCE),

 
};

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
      digitalWrite(IN2, LOW);
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
      digitalWrite(IN4, LOW);  
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
  pinMode(trig_forward, OUTPUT); // 초음파 센서 초기화
  pinMode(echo_forward, INPUT);  // 초음파 센서 초기화
  pinMode(trig_right, OUTPUT); // 초음파 센서 초기화
  pinMode(echo_right, INPUT);  // 초음파 센서 초기화
  servo.attach(servoPin);   // 서보모터 연결 지정
  servo.write(90);          // 초기값으로 정면 응시
  delay(1000);

  Serial.begin(9600);
}
float getDistanceCM(int where) {   // 초음파 센서 거리 측정 함수(단위:cm)
  
  /*
  int echoPin, trigerPin;
  if (where == FORWARD){
      echoPin = echo_forward;
      trigerPin = trig_forward;
  }
  else if(where == RIGHT){
      echoPin = echo_right;
      trigerPin = trig_right;
  }
  
  digitalWrite(echoPin, LOW);
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW); 
  distance = pulseIn(echoPin, HIGH)  / 58;  //거리값 계산 후 저장
  return distance;
  */ 
  return sonar[where].ping_cm();
}
// 거리값 정확도를 위한 평균치 계산(1회 이상~ 10회 미만으로 조정 해보기)
float getStableDistanceCM(int where) {
  int CmSum = 0;
  for (int i = 0; i < 8; i++) {
    CmSum += getDistanceCM(where);  //예, 'sum = sum + cm' 과 동일
  }
  return CmSum / 8;
  
}
void loop() {

  int forward_dist = getDistanceCM(FORWARD); // 전방 초음파 센서
  int right_dist = getDistanceCM(RIGHT); // 전방 초음파 센서
  int short_dist = min(forward_dist, right_dist);
  String short_dir = "";
  if (short_dist == forward_dist)
    short_dir = "forward";
  else if(short_dist == right_dist)
    short_dir = "right";      
  
   if ( short_dist < 25 ) {   //초음파 센서에서 25cm이하로 장애물 감지
//      stop(); 
//      delay(300);      
//      servo.write(180); // 서보모터 좌회전 후 측정 거리값 변수에 저장      
//      delay(500);
//      int leftDistance = getStableDistanceCM();
//      delay(300);
//      servo.write(0); // 서보모터 우회전 후 측정 거리값 변수에 저장
//      delay(500);
//      int rightDistance = getStableDistanceCM();
//      delay(300);
//      servo.write(90);  // 서보모터 중앙으로 원위치
//      delay(500);
//      back();           // 0.5초간 후진 
//      delay(500);  
//      if (leftDistance > rightDistance) {
//        left();
//        } else {
//        right();
//      }
//      delay(500);
      Serial.print("right    ");
      Serial.println(right_dist);
      Serial.print("forward    ");
      Serial.println(forward_dist);
    } else {          // 장애물 감지가 안 될 경우 전진
    forward();
    }
}
