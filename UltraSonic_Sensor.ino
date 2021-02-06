int trigPin = 6;
int echoPin = 7;
const int led_red = 2;
const int led_blue = 3;

long duration, cm, inches;
void setup() {
  
  Serial.begin (9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if (cm >= 75){
    digitalWrite(led_blue, LOW);
    delay(50);
    digitalWrite(led_red, HIGH);
  }
  else {
    digitalWrite(led_red, LOW);
    delay(50);
    digitalWrite(led_blue, HIGH);
  }
  
  delay(250);
}
  
