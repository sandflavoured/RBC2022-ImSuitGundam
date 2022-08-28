// Constants:
// int colorL, colorR;

bool offtrack;

int base = 130;
int redCal = 54;
int bluCal = 47;
int grnCal = 60;

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

color_t prevL, prevR;

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

color_t color_foundL, color_foundR, priority;

void loop() {
//  colorL = color_sens(LEFT);
//  colorR = color_sens(RIGHT);

    // put your main code here, to run repeatedly:
  color_foundL = color_sens(LEFT);
  color_foundR = color_sens(RIGHT);

  if (color_foundL == color_foundR &&  color_foundR == BLACK) {
    driveForward();// drive straight
    offtrack = false;
  }
  else if (color_foundL == color_foundR &&  color_foundR == WHITE) {
    offtrack = true;
    if (prevL == BLACK && prevR != BLACK) driveLeft();
    else driveRight();
  }
  else /*if (color_foundL != color_foundR)*/ {
    priority = max(color_foundL, color_foundR);
    if (priority == color_foundL ) {
      driveForward(); // turn left if priority == color_foundL
      offtrack = false;

    }
    else{
      driveForward(); // turn right if priority == color_foundR
      offtrack = false;

    }
  }

  if (offtrack == false){
    prevL = color_foundL;
    prevR = color_foundR;
  }

//  offtrack = false;

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
  Serial.print(grn);
  Serial.print(" ");
  Serial.println(blu);

  // if (red > -70 && red < -30 && grn > 180 && grn < 200 && blu < -80 && blu > -115) return GREEN;
  // else if (red > 260 && red < 300 && blu > -20 && blu < -15 && grn > 295 && grn < 315) return YELLOW;
  // else if (red > 170 && red < 180 && blu > -115 && blu < -80 && grn > 165 && grn < 185) return RED;
  // else if (red > 10 && red < 45 && blu > -70 && blu < -30 && grn > 190 && grn < 210) return BLACK;
  // else if (red > 220 && red < 260 && blu > 120 && blu < 165 && grn > 305 && grn < 312) return WHITE;

//  if (red > 150 && blu > 150 && grn > 150) return BLACK;
//  else if (red < 150 && blu < 150 && grn < 150) return WHITE;
//  else Serial.println("huh?????");

  if (grn > 390) return WHITE;
  else if (grn <= 390) return BLACK;


//  if (red > -70 && red < -30 && grn > 180 && grn < 200 && blu < -80 && blu > -115) Serial.println("green");
//  else if (red > 260 && red < 300 && blu > -20 && blu < -15 && grn > 295 && grn < 315) Serial.println("yellow");
//  else if (red > 170 && red < 180 && blu > -115 && blu < -80 && grn > 165 && grn < 185) Serial.println("red");
//  else if (red > 10 && red < 45 && blu > -70 && blu < -30 && grn > 190 && grn < 210) Serial.println("black");
//  else if (red > 220 && red < 260 && blu > 120 && blu < 165 && grn > 305 && grn < 312) Serial.println("white");

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
    col = map(col, base, redCal, 0,255);
    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    col = map(col, base, redCal, 0,255);
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
    col = map(col, base, bluCal, 0, 255);

    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    col = map(col, base, bluCal, 0, 255);
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
    col = map(col, base, grnCal, 0, 255);

    return col;
    //break;
  
  case RIGHT:
    col = pulseIn(outputR, LOW);
    col = map(col, base, grnCal, 0, 255);

    return col;
    //break;
  
  default:
    Serial.println("Error! Invalid direction");
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
  analogWrite(ENA2, sp2 + 40);

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

int left_sp = 120;
int right_sp = 120;

int driveForward() {
  Serial.println("GO FORWARD");
    analogWrite(ENA1, right_sp);
    analogWrite(ENA2, left_sp);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

//    delay(100);
//
//    analogWrite(ENA1, 0); // left
//    analogWrite(ENA2, 0); // right
//    
//    delay(100);
}

int driveLeft(){
  Serial.println("TURN LEFT");
    analogWrite(ENA1, right_sp * 1.5); // left
    analogWrite(ENA2, left_sp * 0.0);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

//    delay(100);
//
//    analogWrite(ENA1, 0); // left
//    analogWrite(ENA2, 0); // right
//    
//    delay(100);
}

int driveRight(){
  Serial.println("TURN RIGHT");
    analogWrite(ENA1, right_sp * 0.0); // left
    analogWrite(ENA2, left_sp * 1.5); // right
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

//    delay(100);
//
//    analogWrite(ENA1, 0); // left
//    analogWrite(ENA2, 0); // right
//    
//    delay(100);
}
