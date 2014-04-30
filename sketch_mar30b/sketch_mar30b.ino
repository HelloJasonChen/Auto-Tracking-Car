/*
Track Racing Car.

Data: 2014.4.22
*/

// These constants won't change.  They're used to give names
// to the pins used:
const int SERVO_PIN_1 = 12; // servoMotor1 controled by pin 12
const int SERVO_PIN_2 = 13; // servoMotor1 controled by pin 13

// Init whisker pin
const int WHISKER_PIN_1 = 5;
const int WHISKER_PIN_2 = 7;

// Init track sensor pin
const int TRACK_RIGHT_PIN = 2;
const int TRACK_LEFT_PIN = 3;

// Define the PWM
const int PWM1700 = 1700;
const int PWM1550 = 1550;
const int PWM1520 = 1520;
const int PWM1500 = 1500;
const int PWM1480 = 1480;
const int PWM1450 = 1450;
const int PWM1300 = 1300;

const int TURN_RIGHT = 1;
const int TURN_LEFT = 2;

byte byWhiskerRight;
byte byWhiskerLeft;

int iTrackRightVal;
int iTrackLeftVal;

int iKeepTurn = 0;
  
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Pin setup
  pinMode(SERVO_PIN_1,OUTPUT); // sets the SERVO_PIN_1 as output
  pinMode(SERVO_PIN_2,OUTPUT); // sets the SERVO_PIN_2 as output
  
  pinMode(WHISKER_PIN_1,INPUT); // set the WHISKER_PIN_1 as input
  pinMode(WHISKER_PIN_2,INPUT); // set the WHISKER_PIN_2 as input
  
  pinMode(TRACK_RIGHT_PIN,INPUT);// set the TRACK_RIGHT_PIN as input
  pinMode(TRACK_LEFT_PIN,INPUT);// set the TRACK_LEFT_PIN as input
}

// the loop routine runs over and over again forever:
void loop() {
  //byWhiskerLeft = digitalRead(WHISKER_PIN_1);
  //byWhiskerRight = digitalRead(WHISKER_PIN_2);

  iTrackRightVal = digitalRead(TRACK_RIGHT_PIN);
  iTrackLeftVal = digitalRead(TRACK_LEFT_PIN);
  /*
  Serial.print("Tracking Right = ");
  Serial.println(iTrackRightVal);
  Serial.print("Tracking Left = ");
  Serial.println(iTrackLeftVal);
  */
  
  if ((iTrackRightVal == 0) && (iTrackLeftVal == 1)) { // right side out of line
    slowLeft(5);
    iKeepTurn = TURN_LEFT;
  } else if ((iTrackRightVal == 1) && (iTrackLeftVal == 0)) { // left side out of line
    slowRight(5);
    iKeepTurn = TURN_RIGHT;
  } else if ((iTrackRightVal == 1) && (iTrackLeftVal == 1)) { // in line
    fastForward(5); // fast forward
    iKeepTurn = 0;   
  } else if (iKeepTurn == TURN_RIGHT) {
    turnClockwise(5);
  } else if (iKeepTurn == TURN_LEFT) {
    turnCounterclockwise(5);
  } else {
    delay(100); // do not thing
  }
  
  //delay(1000);
  /*
  // Whisker
  if ((byWhiskerLeft == 0) && (byWhiskerRight == 0)) { //both left and right touch something
    backward(50); // backward about 10cm
    turnLeft(20); // turn left about 30 degree
  } else if (byWhiskerLeft == 0) { // left side touch
    backward(50); // backward about 10cm
    turnRight(20); // turn right about 30 degree
  } else if (byWhiskerRight == 0) { // right side touch
    backward(50); // backward about 10cm
    turnLeft(20); // turn left about 30 degree   
  } else { // no touch
    forward(5); // forward
  }
  */
}

// Fast Forward
void fastForward(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1300);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1700);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Slow Forward
void slowForward(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1480);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1520);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Slow Right
void slowRight(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1480);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    //delayMicroseconds(PWM1550);
    delayMicroseconds(PWM1700);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Slow Left
void slowLeft(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    //delayMicroseconds(PWM1450);
    delayMicroseconds(PWM1300);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1520);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Backward
void backward(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1700);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1300);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
  //delay(time);
}
  
// Trun Left
void turnLeft(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1300);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1300);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Trun Right
void turnRight(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1700);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1700);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}



// Stop
void stopMove(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1500);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1500);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Turn Clockwise
void turnClockwise(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1520);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1520);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}

// Turn Counter Clockwise
void turnCounterclockwise(int time) {
  for (int i = 0; i < time; i++) {
    digitalWrite(SERVO_PIN_1, HIGH);
    delayMicroseconds(PWM1480);
    digitalWrite(SERVO_PIN_1, LOW);
    delay(5);
    digitalWrite(SERVO_PIN_2, HIGH);
    delayMicroseconds(PWM1480);
    digitalWrite(SERVO_PIN_2, LOW);
    delay(5);
  }
}
