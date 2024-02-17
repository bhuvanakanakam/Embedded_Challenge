const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int thresholdDistance = 5;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  long duration1, duration2;
  long distance1, distance2;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  if (distance1 < thresholdDistance && distance2 > thresholdDistance) {
    count++;
    Serial.print("Person entered. Count: ");
    Serial.println(count);
    delay(1000); 
  }
  
  if (distance1 > thresholdDistance && distance2 < thresholdDistance) {
    count--;
    Serial.print("Person exited. Count: ");
    Serial.println(count);
    delay(1000);
  }

  delay(100); 
}
