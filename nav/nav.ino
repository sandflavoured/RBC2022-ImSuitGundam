void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  drive(fwd, turn);
}


void drive(fwd_sp, turn_sp) {

}



void motor_control(sp1, dir1, sp2, dir2) {
  // Red tap facing left
  // Right = Out1
  // Left = Out2
  //     ENA -  IN1 - IN2 - Function
  //1.    H      H     H    L
  //2.    H      H     L    H (Clockwise)
  //3.    H      L     H    H (Counter Clockwise)
  //4.    H      L     L    L   
//  analogWrite(ENA, 50);

//  digitalWrite(motor1pin1, HIGH);
//  digitalWrite(motor1pin2, HIGH);
//  delay(1000);

//  digitalWrite(motor1pin1, HIGH);
//  digitalWrite(motor1pin2, LOW);
//  delay(1000);  

//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, HIGH);
//  delay(1000);

//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, LOW);
//  delay(1000);


// EX: 1
  // Forward - 1s
  analogWrite(ENA1, 100);
  analogWrite(ENA2, 100);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);   
}