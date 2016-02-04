//Written by Ray Tann and Ishaan Parikh and Ibrahim Hashme and Gurpreet Singh

#define SENSOR_DIFFERENCE 200
#include <Servo.h>


// Servo stuff
Servo myservo;
int pos = 0;
int servoPin = 13;

// Buzzer pin
int ledPin = 8;

// Button info
int initSensorValue[5] = {0};
int sensorValue[5] = {0};  //Sensors are counted from left to right
int sensorPin[5];
int i = 0;
int diff = 0;

// Dynamic vars
int buttonsHit[4];
int currStep = 0;
int password[4] = {0,2,1,2};


void setup() {
  myservo.attach(servoPin);
  myservo.write(90);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  sensorPin[0] = A0;
  sensorPin[1] = A1;
  sensorPin[2] = A2;
  sensorPin[3] = A3;
  sensorPin[4] = A4;
  for (int i = 0; i < 5; i++) {
    initSensorValue[i] = analogRead(sensorPin[i]);
  }
}

void loop() {
  
  for (i = 0; i < 5; i++){
    sensorValue[i] = analogRead(sensorPin[i]);
    
  }
 // Checking for button presses
  for (i = 0; i < 5; i++){
    diff = initSensorValue[i] - sensorValue[i];
    if (diff > SENSOR_DIFFERENCE){
     Serial.println("pressed");
      digitalWrite(ledPin, HIGH);
     
      pressed(i);
      break;
    }else{
      digitalWrite(ledPin, LOW);
    }
  }
}
  // Sends the index of the pressed button to update the buttonsHit array
  void pressed(int k){
    // Makes sure we aren't hitting the first button
    if (currStep != 0){
      // Makes sure it isn't the button being held down
       if (k != buttonsHit[currStep - 1]){
        Serial.println(k);
        // Setting the next part in the choice array
        buttonsHit[currStep] = k;
        currStep = currStep + 1;
        // After we have picked four buttons, run the checker
        if (currStep == 4){
          checkIfCorrect();
        }
      }
      // If we are at the first button
    } else {
      Serial.println(k);
       buttonsHit[currStep] = k;
       currStep = currStep + 1;
    }
  }

    void checkIfCorrect(){
     Serial.println("Checking");
     for (int ind = 0; ind < 4; ind ++) {
       if (buttonsHit[ind] == password[ind]){
        if (ind == 3){
            Serial.println("correct!");
            digitalWrite(12, HIGH);
            opener();
          }
        } else {
          Serial.println("incorrect :(");
          reseter(1000);
        } 
       }
    }

    // reset if someone gets it right or wrong
    void reseter(int time){
        currStep = 0;
        buttonsHit[0] = 0;
        buttonsHit[1] = 0;
        buttonsHit[2] = 0;
        buttonsHit[3] = 0;
        delay(time);
    }

    void opener(){
      myservo.write(179);
      delay(10000);
      myservo.write(0);
      delay(6000);
      myservo.write(90);
      reseter(1000);
    }
   

    
