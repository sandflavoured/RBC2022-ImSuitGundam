// Constants:
// Pin allocation
int ENA1 = 3;
int motor1pin1 = 7;
int motor1pin2 = 8;
int ENA2 = 5; 
int motor2pin1 = 2;
int motor2pin2 = 4;

typedef enum {
  BLACK = 0,
  RED,
  GREEN,
  BLUE
} color_t;

typedef enum {
  LEFT = 0;
  RIGHT
} dir_t;

typedef enum {
  FORWARD = 1,
  BACKWARD
} rot_t;


void setup() {
  // Motor controller set up:
  pinMode(ENA1, OUTPUT); 
  pinMode(motor1pin1, OUTPUT); 
  pinMode(motor1pin2, OUTPUT); 
  pinMode(ENA2, OUTPUT); 
  pinMode(motor2pin1, OUTPUT); 
  pinMode(motor2pin2, OUTPUT);

  // Colour sensor set up
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  // sensor inputs
  S0 = 2;
  S1 = 3;   
  S2 = 4;
  S3 = 5;
  outputL = 6;
  outputR = 7;

}

void loop() {
  // put your main code here, to run repeatedly:

  colorL = color_sens();



  drive(fwd, turn);
}


void drive(fwd_sp, turn_sp) {

}


// outputs:
// 0: BLACK
// 1: RED
// 2: GREEN
// 3: BLUE
void color_sens() {

  // get RGB
  red = read_red();
  blu = read_blu();
  grn = read_grn();

  if () return BLACK;
  else if () return RED;
  else if () return BLUE;
  else if () return GREEN;

}

void read_red(){
  // switch color filter to red -- S2 LOW, S3 LOW

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // read value
  int Lcol = digitalRead(outputL);
  int Rcol = digitalRead(outputR);

  return 
}

void read_blu(){
  // switch color filter to blue -- S2 LOW, S3 HIGH
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // read value
  int Lcol = digitalRead(outputL);
  int Rcol = digitalRead(outputR);
}

void read_grn(){
  // switch color filter to green -- S2 HIGH, S3 HIGH
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  
  // read value
  int Lcol = digitalRead(outputL);
  int Rcol = digitalRead(outputR);
}


// Documentation
  // Right = Out1
  // Left = Out2
  //     ENA -  IN1 - IN2 - Function
  //1.    H      H     H    L
  //2.    H      H     L    H (Clockwise)
  //3.    H      L     H    H (Counter Clockwise)
  //4.    H      L     L    L   
void motor_control(int sp1, dir1, sp2, dir2) { 
  analogWrite(ENA1, sp1);
  analogWrite(ENA2, sp2);

  // Forward
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);
}