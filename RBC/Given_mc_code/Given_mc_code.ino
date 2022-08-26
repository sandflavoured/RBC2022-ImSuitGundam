typedef struct {
    int Trig;
    int Echo;
} ultrasonic_sensor;

typedef struct {
    int In1;
    int In2;
    int Enable;
} motor;

ultrasonic_sensor UltrasonicSensor = {};
motor MotorL = {};
motor MotorR = {};

void
setup() {
    Serial.begin(9600);
    
    //////////////////////////////////////
    // ULTRASONIC SENSOR
    //////////////////////////////////////
//  UltrasonicSensor.Trig = 12;
//  UltrasonicSensor.Echo = 13;
//    pinMode(UltrasonicSensor.Trig, ...);
//    pinMode(UltrasonicSensor.Echo, ...);
    
    //////////////////////////////////////
    // MOTORS
    //////////////////////////////////////
    MotorL.In1 = 2;
    MotorL.In2 = 4;
    MotorL.Enable = 5;
    pinMode(MotorL.In1, OUTPUT);
    pinMode(MotorL.In2, OUTPUT);
    pinMode(MotorL.Enable, OUTPUT);
    
    MotorR.In1 = 7;
    MotorR.In2 = 8;
    MotorR.Enable = 3;
    pinMode(MotorR.In1, OUTPUT);
    pinMode(MotorR.In2, OUTPUT);
    pinMode(MotorR.Enable, OUTPUT);
}

void
loop() {
    /*
    // Clears the trigPin
    digitalWrite(UltrasonicSensor.Trig, LOW);
    delayMicroseconds(2);
    
  // Sends a pulse
    digitalWrite(UltrasonicSensor.Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(UltrasonicSensor.Trig, LOW);
    
    // Reads the echoPin, returns the sound wave round trip time in microseconds
    float Duration = pulseIn(UltrasonicSensor.Echo, HIGH);
    
    // Calculates the distance based on the sound wave round trip time
    int Distance = Duration*0.034f/2;
    */
    
    // Drive forwards
    int MotorLSpeed = 110;
    int MotorRSpeed = 100;
    
//    // EX1:
//    // Forward
//    digitalWrite(MotorL.In1, HIGH);
//    digitalWrite(MotorL.In2, LOW);
//    analogWrite(MotorL.Enable, MotorLSpeed);
//    digitalWrite(MotorR.In1, HIGH);
//    digitalWrite(MotorR.In2, LOW);
//    analogWrite(MotorR.Enable, MotorRSpeed);
//    delay(1000);
//
//    // Right 90 degree
//    digitalWrite(MotorL.In1, HIGH);
//    digitalWrite(MotorL.In2, LOW);
//    analogWrite(MotorL.Enable, MotorLSpeed);
//    digitalWrite(MotorR.In1, LOW);
//    digitalWrite(MotorR.In2, LOW);
//    analogWrite(MotorR.Enable, MotorRSpeed);
//    delay(900);
//
//    // Forward
//    digitalWrite(MotorL.In1, HIGH);
//    digitalWrite(MotorL.In2, LOW);
//    analogWrite(MotorL.Enable, MotorLSpeed);
//    digitalWrite(MotorR.In1, HIGH);
//    digitalWrite(MotorR.In2, LOW);
//    analogWrite(MotorR.Enable, MotorRSpeed);
//    delay(1000);

    // EX2:
    // Backward
    digitalWrite(MotorL.In1, LOW);
    digitalWrite(MotorL.In2, HIGH);
    analogWrite(MotorL.Enable, MotorLSpeed);
    digitalWrite(MotorR.In1, LOW);
    digitalWrite(MotorR.In2, HIGH);
    analogWrite(MotorR.Enable, MotorRSpeed);
    delay(4000);

    // Right 90 degree
    digitalWrite(MotorL.In1, HIGH);
    digitalWrite(MotorL.In2, LOW);
    analogWrite(MotorL.Enable, MotorLSpeed);
    digitalWrite(MotorR.In1, LOW);
    digitalWrite(MotorR.In2, LOW);
    analogWrite(MotorR.Enable, MotorRSpeed);
    delay(1600);

    // Forward
    digitalWrite(MotorL.In1, HIGH);
    digitalWrite(MotorL.In2, LOW);
    analogWrite(MotorL.Enable, MotorLSpeed);
    digitalWrite(MotorR.In1, HIGH);
    digitalWrite(MotorR.In2, LOW);
    analogWrite(MotorR.Enable, MotorRSpeed);
    delay(4000);


}
