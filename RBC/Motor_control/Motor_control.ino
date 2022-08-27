int ENA1 = 3;
int motor1pin1 = 7;
int motor1pin2 = 8;
int ENA2 = 5; 
int motor2pin1 = 2;
int motor2pin2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA1, OUTPUT); 
  pinMode(motor1pin1, OUTPUT); 
  pinMode(motor1pin2, OUTPUT); 
  pinMode(ENA2, OUTPUT); 
  pinMode(motor2pin1, OUTPUT); 
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
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
  analogWrite(ENA1, 255);
  analogWrite(ENA2, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);   
}
