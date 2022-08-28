// Constants:
int colorL, colorR;


// motor pin allocation
const int ENA1 = 3;
const int motor1pin1 = 7;
const int motor1pin2 = 8;
const int ENA2 = 5; 
const int motor2pin1 = 2;
const int motor2pin2 = 4;

// sensor inputs
const int S0 = 11;
const int S1 = 13;   
const int S2 = 9;
const int S3 = 10;
const int outputL = 12;
const int outputR = 6;

typedef enum {
  WHITE = 0,
  BLACK,
  RED,
  YELLOW,
  GREEN
} color_t;

typedef enum {
  LEFT = 0,
  RIGHT
} dir_t;

typedef enum {
  FORWARD = 0,
  BACKWARD
} rot_t;


void setup() {
  Serial.begin(9600);
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
  colorL = color_sens(LEFT);
  colorR = color_sens(RIGHT);

  //drive(fwd, turn);
}


// void drive(fwd_sp, turn_sp) {

// }


// outputs:
// 0: BLACK
// 1: RED
// 2: GREEN
// 3: BLUE

color_t color_sens(dir_t dir) {

  // get RGB
  int red = read_red(dir);
  int blu = read_blu(dir);
  int grn = read_grn(dir);

  // print values for debug
  Serial.println(dir == RIGHT ? "RIGHT" : "LEFT");
  Serial.print(red);
  Serial.print(" ");
  Serial.print(blu);
  Serial.print(" ");
  Serial.println(grn);

  // if () return BLACK;
  // else if () return WHITE;
  // else if () return GREEN;
  // else if () return RED;

}

int read_red(dir_t dir){
  // switch color filter to red -- S2 LOW, S3 LOW
  int col;

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  switch (dir)
  {
  case LEFT:
    
    col = pulseIn(outputL, LOW);
    //col = map(col, )
    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    return col;
    //break;
  
  default:
    Serial.println("Error! Invalid direction");
    //break;
  }
}

int read_blu(dir_t dir){
  // switch color filter to blue -- S2 LOW, S3 HIGH
  int col;

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  switch (dir)
  {
  case LEFT:
    
    col = pulseIn(outputL, LOW);
    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    return col;
    //break;
  
  default:
    Serial.println("Error! Invalid direction");
    //break;
  }
}

//int 

  
int read_grn(dir_t dir){
  // switch color filter to green -- S2 HIGH, S3 HIGH
  int col;
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  switch (dir)
  {
  case LEFT:
    col = pulseIn(outputL, LOW);
    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    return col;
    //break;
  
  default:
    Serial.println("Error! Invalid direction");
    //break;
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
