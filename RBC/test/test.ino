/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

int base = 130;
int red = 54;
int blu = 47;
int grn = 60;

// TCS230 or TCS3200 pins wiring to Arduino
//#define S0 11
//#define S1 13
//#define S2 9
//#define S3 10
//#define sensorOut 12

#define S0 11
#define S1 13
#define S2 9
#define S3 10
#define sensorOut 6

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

// Stores the red. green and blue colors
long redColor = 0;
long greenColor = 0;
long blueColor = 0;

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
}

void loop() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
   redColor = map(redFrequency, base, red, 0,255);
//  redColor = map(redFrequency, XX, XX, 255,0);
  
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.println(redFrequency);
  Serial.println(redColor);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
   greenColor = map(greenFrequency, base, grn, 0, 255);
  //greenColor = map(greenFrequency, XX, XX, 255, 0);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.println(greenFrequency);
  Serial.println(greenColor);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
   blueColor = map(blueFrequency, base, blu, 0, 255);
  //blueColor = map(blueFrequency, XX, XX, 255, 0);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  Serial.println(blueColor);
  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > greenColor && redColor > blueColor){
      Serial.println(" - RED detected!");
  }
  if(greenColor > redColor && greenColor > blueColor){
    Serial.println(" - GREEN detected!");
  }
  if(blueColor > redColor && blueColor > greenColor){
    Serial.println(" - BLUE detected!");
  }
}
