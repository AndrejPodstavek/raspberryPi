
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

#define TRUE 1

// first distance sensor
#define TRIG 5
#define ECHO 6

// second distance sensor
#define TRIG2 1
#define ECHO2 4

// third distance sensor
#define TRIG3 26
#define ECHO3 27

//forth distance sensor
#define TRIG4 28
#define ECHO4 29

int gate = 0;
int gate2 = 0;
int gate3 = 0;
int gate4 = 0;

long startTime = 0;
long travelTime = 0;

int distance = 0;

void setup() {

        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);

        pinMode(TRIG2, OUTPUT);
        pinMode(ECHO2, INPUT);
        //TRIG pin must start LOW
        digitalWrite(TRIG2, LOW);

        pinMode(TRIG3, OUTPUT);
        pinMode(ECHO3, INPUT);
        //TRIG pin must start LOW
        digitalWrite(TRIG3, LOW);

        pinMode(TRIG4, OUTPUT);
        pinMode(ECHO4, INPUT);
        //TRIG pin must start LOW
        digitalWrite(TRIG4, LOW);

        delay(30);
}

void getCM() {

        //first distance sensor
        while(gate == 0){
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);


        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
        //Wait for echo end
         startTime = micros();


        while(digitalRead(ECHO) == HIGH);
         travelTime = micros() - startTime;

        //Get distance in cm
         distance = travelTime / 58;

        printf("Distance: %dcm\n", distance);

        gate = 1;
        }

        //second distance sensor
        while(gate2 == 0){
        //Send trig pulse
        digitalWrite(TRIG2, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG2, LOW);


        //Wait for echo start
        while(digitalRead(ECHO2) == LOW);
        //Wait for echo end
         startTime = micros();


        while(digitalRead(ECHO2) == HIGH);
         travelTime = micros() - startTime;

        //Get distance in cm
         distance = travelTime / 58;

        printf("Distance2: %dcm\n", distance);
        gate2 = 1;
        }


        while(gate3 == 0){
        //Send trig pulse
        digitalWrite(TRIG3, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG3, LOW);


        //Wait for echo start
        while(digitalRead(ECHO3) == LOW);
        //Wait for echo end
         startTime = micros();


        while(digitalRead(ECHO3) == HIGH);
         travelTime = micros() - startTime;

        //Get distance in cm
         distance = travelTime / 58;

        printf("Distance3: %dcm\n", distance);
        gate3 = 1;
        }


        while(gate4 == 0){
        //Send trig pulse
        digitalWrite(TRIG4, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG4, LOW);


        //Wait for echo start
        while(digitalRead(ECHO4) == LOW);
        //Wait for echo end
         startTime = micros();


        while(digitalRead(ECHO4) == HIGH);
         travelTime = micros() - startTime;

        //Get distance in cm
         distance = travelTime / 58;

        printf("Distance4: %dcm\n", distance);
        gate4 = 1;
        }

        gate = 0;
        gate2 = 0;
        gate3 = 0;
        gate4 = 0;

}

void main(void) {
        setup();
        while(1){
        getCM();
          delay(1000);

        }

}
