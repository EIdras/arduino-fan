// constants won't change. They're used here to set pin numbers:
const byte buttonPPin = 11;     // the number of the plusbutton pin
const byte buttonMPin = 10;     // the number of the minusbutton pin
const byte buttonSPin = 12;     // the number of the stopbutton pin
//const byte red_led = 4;        // the number of the red LED pin
//const byte yellow_led = 3;     // the number of the yellow LED pin
//const byte green_led = 2;      // the number of the green LED pin
const byte fanPin =  13;       // the number of the FAN pin
const byte B = 9;
const byte A = 8;
const byte F = 7;
const byte G = 6;
const byte DP = 5;
const byte C = 4;
const byte D = 3;
const byte E = 2;

// variables will change:
byte bPState = 0;         // variable for reading the plusbutton status
byte bMState = 0;         // variable for reading the minusbutton status
byte bSState = 0;         // variable for reading the stopbutton status
byte pwm = 0;           // variable for stocking the PWM value

void setup() {
  // initialize the FAN pin as an output:
  pinMode(fanPin, OUTPUT);
  // initialize the plus, minus and stop buttons pins as input:
  pinMode(buttonPPin, INPUT);
  pinMode(buttonMPin, INPUT);
  pinMode(buttonSPin, INPUT);
  //  pinMode(red_led, OUTPUT);
  //  pinMode(yellow_led, OUTPUT);
  //  pinMode(green_led, OUTPUT);
  Serial.begin(9600);
  reset7();
}

void loop() {
  // read the state of the pushbutton value:
  bPState = digitalRead(buttonPPin);
  bMState = digitalRead(buttonMPin);
  bSState = digitalRead(buttonSPin);

  analogWrite(fanPin, pwm);    // define FAN speed based on the PWM variable

  // FAN-CONTROL PART //
  // check if the plusbutton is pressed. If it is, adding 51 (= +20% speed) to the pwm variable
  if (bPState == HIGH) {
    Serial.println("+");
    if (pwm > 153) {
      pwm = 255;
      delay(50);
    }
    else {
      pwm = pwm + 51;
      delay(50);
    }
  }

  // check if the minusbutton is pressed. If it is, substracting 51 (= -20% speed) to the pwm variable
  if (bMState == HIGH) {
    Serial.println("-");
    if (pwm < 51) {
      pwm = 0;
      delay(50);
    }
    else {
      pwm = pwm - 51;
      delay(50);
    }
  }

  // check if the stopbutton is pressed. If it is, checking the pwm variable value
  if (bSState == HIGH) {
    Serial.println("STOP");
    if (pwm < 255) {            // if fan is not full speed already, set it to full speed
      pwm = 255;
      delay(50);
    }
    else {                      // if fan is full speed, set speed to 0
      pwm = 0;
      delay(50);
    }
  }

  // 7-SEGMENT CONTROL PART //
  switch (pwm) {
    case 0:
      reset7();
      digitalWrite(A, HIGH);//0
      digitalWrite(F, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 51:
      reset7();
      digitalWrite(A, HIGH);//0
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 102:
      reset7();
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 153:
      reset7();
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 204:
      reset7();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 255:
      reset7();
      digitalWrite(DP, HIGH);
      break;
  }
  delay(200);
}

void reset7()
{
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
}
