int potPin = 3;
int potVal = 0;
int ledVal = 0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int redVal = 0;
int blueVal = 0;
int greenVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  if(potVal < 333){
    ledVal = (potVal * 3) / 4;

    greenVal = 0;
    redVal = ledVal;
    blueVal = 0;
  }
  else if (potVal < 666) {
    ledVal = ((potVal-333) * 3) / 4;

    redVal = 255 - ledVal;
    greenVal = ledVal;
    blueVal = 0;
  }
  else if (potVal < 1000) {
    ledVal = ((potVal-666) * 3) / 4;

    blueVal = ledVal;
    redVal = 0;
    greenVal = 255 - ledVal;
  }
  else {
    ledVal = 255;

    redVal = ledVal;
    greenVal = ledVal;
    blueVal = ledVal;
  }
 analogWrite(redPin, redVal);
 analogWrite(greenPin, greenVal);
 analogWrite(bluePin, blueVal);
  

}
