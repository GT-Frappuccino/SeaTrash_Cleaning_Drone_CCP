#include <NewPing.h>

 

// trigger and echo pins for each sensor

#define SONAR1 2

#define SONAR2 3

#define SONAR3 4

#define SONAR4 5

#define SONAR5 6

#define SONAR6 7

#define MAX_DISTANCE 30 // maximum distance for sensors

#define NUM_SONAR 6 // number of sonar sensors

#define PING_INTERVAL 33 // Milliseconds // 3개의 경우 100ms

unsigned long pingTimer[NUM_SONAR]; // When each pings.
unsigned int cm[NUM_SONAR]; // Store ping distances.
uint8_t currentSensor = 0;  


NewPing sonar[NUM_SONAR] = { // array of sonar sensor objects

  NewPing(SONAR1, SONAR1, MAX_DISTANCE),

  NewPing(SONAR2, SONAR2, MAX_DISTANCE),

  NewPing(SONAR3, SONAR3, MAX_DISTANCE),
  NewPing(SONAR4, SONAR4, MAX_DISTANCE),
  NewPing(SONAR5, SONAR5, MAX_DISTANCE),
  NewPing(SONAR6, SONAR6, MAX_DISTANCE),
 
};

 

int distance[NUM_SONAR]; // array stores distances for each

                         // sensor in cm

 void echoCheck() { // If ping echo, set distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
  //Serial.println(cm[currentSensor]);

}

void oneSensorCycle() { 
  for (uint8_t i = 0; i < NUM_SONAR; i++) {
    Serial.print(cm[i]);
    Serial.print("cm ");
    //Serial.write(9);
  }
  Serial.println();
}

void setup() {
 
Serial.begin(9600);
  pingTimer[0] = millis() + 75; // First ping start in ms.
  for (uint8_t i = 1; i < NUM_SONAR; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}
 // Serial.begin(9600);



 

void loop() {
  for (uint8_t i = 0; i < NUM_SONAR; i++) {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * NUM_SONAR;
      if (i == 0 && currentSensor == NUM_SONAR - 1)
          oneSensorCycle(); 
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      cm[currentSensor] = 0;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
}
  // 필요한 코드 추가 가능 부분

  /*

  delay(600);

  updateSonar(); // update the distance array

  // print all distances

  Serial.print(" a: ");
  if ( distance[0] > 30)
    Serial.print("inf");
  else 
    Serial.print(distance[0]);

 

  Serial.print("   b: ");
  if ( distance[1] > 30)
    Serial.print("inf");
  else 
    Serial.print(distance[1]);

  Serial.print("   c: ");
  if ( distance[2] > 30)
    Serial.print("inf");
  else 
    Serial.print(distance[2]);

   Serial.print("   d: ");
  if ( distance[3] > 30)
    Serial.print("inf");
  else 
    Serial.print(distance[3]);

   Serial.print("   e: ");
  if ( distance[4] > 30)
    Serial.print("inf");
  else 
    Serial.print(distance[4]);

   Serial.print("   f: ");
  if ( distance[5] > 30)
    Serial.println("inf");
  else 
    Serial.println(distance[5]); 
}

 

// takes a new reading from each sensor and updates the

// distance array

void updateSonar() {

  for (int i = 0; i < NUM_SONAR; i++) {

    distance[i] = sonar[i].ping_cm(); // update distance

    // sonar sensors return 0 if no obstacle is detected

    // change distance to max value if no obstacle is detected

    if (distance[i] == 0)

     // distance[i] = MAX_DISTANCE;
      distance[i] = 1234;

  }

}*/


