#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
SoftwareSerial server(2,3);

const int led1 = 8;
const int led2 = 9;
long int data;

void setup() {
  Serial.begin(9600);
  server.begin(9600);
  motor1.setSpeed(255);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  motor1.run(RELEASE);
}

void loop() {

  if(server.available() > 0){
    data = server.parseInt();
    Serial.println(data);

    switch(data){
      case 50:
        digitalWrite(led1, LOW);
        break;
      case 51:
        digitalWrite(led1, HIGH);
        break;
      case 20:
        digitalWrite(led2, LOW);
        break;
      case 21:
        digitalWrite(led2, HIGH);
        break;
      case 40:
        motor1.run(RELEASE);
        break;
      case 41:
        motor1.run(FORWARD);
        break;
      default:
        break;
    }
  }
}
