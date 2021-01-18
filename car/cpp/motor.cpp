///////// motor moving 
#include <wiringPi.h>
#include <softPwm.h>

void setup() {
    if (wiringPiSetup() == -1)
        exit(1);
    pinMode(L_M1, OUTPUT);
    pinMode(L_M2, OUTPUT);
    pinMode(R_M1, OUTPUT);
    pinMode(R_M2, OUTPUT);
    pinMode(L_ENA, OUTPUT);
    pinMode(R_ENB, OUTPUT);
    softPwmCreate(L_ENA, 0, 255);
    softPwmCreate(R_ENB, 0, 255);

}
void forward(int time) {
    digitalWrite(L_M1, 1);
    digitalWrite(L_M2, 0);
    softPwmWrite(L_ENA, 200);


    digitalWrite(R_M1, 1);
    digitalWrite(R_M2, 0);
    softPwmWrite(R_ENB, 200);
    delay(time);



}

void back(int time) {
    digitalWrite(L_M1, 0);
    digitalWrite(L_M2, 1);
    softPwmWrite(L_ENA, 200);


    digitalWrite(R_M1, 0);
    digitalWrite(R_M2, 1);
    softPwmWrite(R_ENB, 200);
    delay(time);


}
void right(int time) {
    digitalWrite(L_M1, 1);
    digitalWrite(L_M2, 0);
    softPwmWrite(L_ENA, 200);


    digitalWrite(R_M1, 1);
    digitalWrite(R_M2, 0);
    softPwmWrite(R_ENB, 100);
    delay(time);
}

void left(int time) {
    digitalWrite(L_M1, 1);
    digitalWrite(L_M2, 0);
    softPwmWrite(L_ENA, 100);


    digitalWrite(R_M1, 1);
    digitalWrite(R_M2, 0);
    softPwmWrite(R_ENB, 200);
    delay(time);


}

void stop(int time) {
    digitalWrite(L_M1, 1);
    digitalWrite(L_M2, 1);
    //softPwmWrite(L_ENA,0);


    digitalWrite(R_M1, 1);
    digitalWrite(R_M2, 1);
    //softPwmWrite(R_ENB,0);
    delay(time);
