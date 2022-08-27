int red, blu, grn;

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


void setup() {
  // Motor controller set up:
  pinMode(ENA1, OUTPUT); 
  pinMode(motor1pin1, OUTPUT); 
  pinMode(motor1pin2, OUTPUT); 
  pinMode(ENA2, OUTPUT); 
  pinMode(motor2pin1, OUTPUT); 
  pinMode(motor2pin2, OUTPUT);

  // Colour sensor set up
  // Samin:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  color = color_sens();

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
  // switch color filter to red

  // read value
}

void read_blu(){
  // switch color filter to blue

  // read value
}

void read_grn(){
  // switch color filter to green

  // read value
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


// EX: 1
  // Forward - 1s
  analogWrite(ENA1, sp1);
  analogWrite(ENA2, sp2);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);   
}