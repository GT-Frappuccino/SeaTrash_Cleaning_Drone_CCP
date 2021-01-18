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
