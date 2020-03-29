int B = 9;
int A = 8;
int F = 7;
int G = 6;
int DP = 5;
int C = 4;
int D = 3;
int E = 2;

void setup()
{
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
}

void loop()
{
  digitalWrite(B, HIGH);//All
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  delay(1000);
  digitalWrite(DP, LOW);//9
  digitalWrite(E, LOW);
  delay(1000);
  digitalWrite(E, HIGH);//8
  delay(1000);
  digitalWrite(F, LOW);//7
  digitalWrite(G, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  delay(1000);
  digitalWrite(B, LOW);//6
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  delay(1000);
  digitalWrite(E, LOW);//5
  delay(1000);
  digitalWrite(B, HIGH);//4
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  delay(1000);
  digitalWrite(A, HIGH);//3
  digitalWrite(D, HIGH);
  digitalWrite(F, LOW);
  delay(1000);
  digitalWrite(F, LOW);//2
  digitalWrite(C, LOW);
  digitalWrite(E, HIGH);
  delay(1000);
  digitalWrite(A, LOW);//1
  digitalWrite(G, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  delay(1000);
  digitalWrite(A, HIGH);//0
  digitalWrite(F, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  delay(1000);
  digitalWrite(B, LOW);//.
  digitalWrite(A, LOW);
  digitalWrite(DP, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F,LOW);
  delay(1000);
}
