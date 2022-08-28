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

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int blackFrequency = 0;

// Stores the red. green and blue colors
long redColor = 0;
long greenColor = 1;
long blueColor = 2;
long blackColor = 3;

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

  // Setting the sensorOut as an input
  pinMode(outputL, INPUT);
  pinMode(outputR, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Begins serial communication
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  int color_foundL = colorDetector(outputL);
  int color_foundR = colorDetector(outputR);

  if (color_foundL == color_foundR &&  color_foundR == 3) {
    driveForward(color_foundL);// drive straight
  }
  else if (color_foundL != color_foundR) {
    int priority = max(color_foundL, color_foundR);
    if (priority == color_foundL ) {
      driveLeft(); // turn left if priority == color_foundL
    }
    else{
      driveRight(); // turn right if priority == color_foundR
    }
  }
}



///////////////////////////////////////////////////////


int colorDetector(int sensorOut) {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  redColor = map(redFrequency, 70, 120, 255, 0);

  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  greenColor = map(greenFrequency, 100, 199, 255, 0);

  // Printing the GREEN (G) value
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(100);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  blueColor = map(blueFrequency, 38, 84, 255, 0);

  // Printing the BLUE (B) value
  Serial.print(" B = ");
  Serial.print(blueColor);
  delay(100);

  ////////////////////////////////////////////

  // Setting black (Blk) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  blackFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  blackColor = map(blackFrequency, 0, 38, 255, 0);

  // Printing the BLUE (B) value
  Serial.print(" Blk = ");
  Serial.print(blackColor);
  delay(100);



  // Checks the current detected color and prints
  // a message in the serial monitor
  if (redColor > greenColor && redColor > blueColor) {
    Serial.println(" - RED detected!");
    int detectedColor = 0;
    return detectedColor;
  }
  if (greenColor > redColor && greenColor > blueColor) {
    Serial.println(" - GREEN detected!");
    int detectedColor = 1;
    return detectedColor;
  }
  if (blueColor > redColor && blueColor > greenColor) {
    Serial.println(" - BLUE detected!");
    int detectedColor = 2;
    return detectedColor;
  }
  if (redColor < redColor && blueColor < greenColor) {
    Serial.println(" - BLACK detected!");
    int detectedColor = 3;
    return detectedColor;
  }

}
///////////////////////////////////////////////////////
int driveForward(int detectedColor) {
  if (detectedColor == 3) {
    // Forward - 1s
    analogWrite(ENA1, 140);
    analogWrite(ENA2, 100);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

  }
}

int driveLeft(){
    analogWrite(ENA1, 160); // left
    analogWrite(ENA2, 100);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

int driveRight(){
    analogWrite(ENA1, 140); // left
    analogWrite(ENA2, 120); // right
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}
