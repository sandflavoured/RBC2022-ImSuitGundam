// Constants:
// motor pin allocation
const int ENA1 = 3;
const int motor1pin1 = 7;
const int motor1pin2 = 8;
const int ENA2 = 5; 
const int motor2pin1 = 2;
const int motor2pin2 = 4;

// sensor inputs
const int S0 = 2;
const int S1 = 3;   
const int S2 = 4;
const int S3 = 5;
const int outputL = 6;
const int outputR = 7;

typedef enum {
  WHITE = 0,
  BLACK,
  RED,
  GREEN
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
  

}

void loop() {
  // put your main code here, to run repeatedly:

  colorL = color_sens(LEFT);
  colorR = color_sens(RIGHT);



  drive(fwd, turn);
}


void drive(fwd_sp, turn_sp) {

}


// outputs:
// 0: BLACK
// 1: RED
// 2: GREEN
// 3: BLUE
void color_sens(dir_t dir) {

  // get RGB
  red = read_red(dir);
  blu = read_blu(dir);
  grn = read_grn(dir);

  // print values for debug
  serial.println(dir == RIGHT ? "RIGHT" : "LEFT");
  

  if () return BLACK;
  else if () return WHITE;
  else if () return GREEN;
  else if () return RED;

}

int read_red(dir_t dir){
  // switch color filter to red -- S2 LOW, S3 LOW

  switch (dir)
  {
  case LEFT:
    digitalWrite(S2, LOW);
    int Lcol = digitalRead(outputL);
    return Lcol;
    break;
  
  case RIGHT:
    digitalWrite(S3, LOW);
    int Rcol = digitalRead(outputR);
    return Rcol;
    break;
  
  default:
    serial.println("Error! Invalid direction")
    break;
  }
}

int read_blu(dir_t dir){
  // switch color filter to blue -- S2 LOW, S3 HIGH

  switch (dir)
  {
  case LEFT:
    digitalWrite(S2, LOW);
    int Lcol = digitalRead(outputL);
    return Lcol;
    break;
  
  case RIGHT:
    digitalWrite(S3, HIGH);
    int Rcol = digitalRead(outputR);
    return Rcol;
    break;
  
  default:
    serial.println("Error! Invalid direction")
    break;
  }
}

int read_grn(dir_t dir){
  // switch color filter to green -- S2 HIGH, S3 HIGH
  
  switch (dir)
  {
  case LEFT:
    digitalWrite(S2, HIGH);
    int Lcol = digitalRead(outputL);
    return Lcol;
    break;
  
  case RIGHT:
    digitalWrite(S3, HIGH);
    int Rcol = digitalRead(outputR);
    return Rcol;
    break;
  
  default:
    serial.println("Error! Invalid direction")
    break;
  }
}


// Documentation
  // Right = Out1
  // Left = Out2
  //     ENA -  IN1 - IN2 - Function
  //1.    H      H     H    L
  //2.    H      H     L    H (Clockwise)
  //3.    H      L     H    H (Counter Clockwise)
  //4.    H      L     L    L   
void motor_control(int sp1, rot_t dir1, int sp2, rot_t dir2) { 
  analogWrite(ENA1, sp1);
  analogWrite(ENA2, sp2);

  if (dir1 == FORWARD){
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  }
  else if (dir1 == BACKWARD){
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  }

  if (dir2 == FORWARD){
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  }
  else if (dir2 == BACKWARD){
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
  }
  delay(10);
}