const byte buttonPPin = 11;     // the number of the plusbutton pin
const byte buttonMPin = 10;     // the number of the minusbutton pin
const byte buttonSPin = 12;     // the number of the stopbutton pin

byte bPState = 0;         // variable for reading the plusbutton status
byte bMState = 0;         // variable for reading the minusbutton status
byte bSState = 0;         // variable for reading the stopbutton status
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPPin, INPUT);
  pinMode(buttonMPin, INPUT);
  pinMode(buttonSPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  bPState = digitalRead(buttonPPin);
  bMState = digitalRead(buttonMPin);
  bSState = digitalRead(buttonSPin);

  if (bPState == HIGH) {
    Serial.println("+");
  }

  // check if the minusbutton is pressed. If it is, substracting 51 (= -20% speed) to the pwm variable
  if (bMState == HIGH) {
    Serial.println("-");
  }

  // check if the stopbutton is pressed. If it is, checking the pwm variable value
  if (bSState == HIGH) {
    Serial.println("STOP");
  }
delay(200);
}
