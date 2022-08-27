int red, blu, grn;

typedef enum {
  BLACK = 0,
  RED,
  GREEN,
  BLUE
} color_t;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


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