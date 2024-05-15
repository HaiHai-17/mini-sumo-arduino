int duration, sm, tic, trigPin = 6, echoPin = 7, state = 0;

void forward() {
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}
void left() {
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
}
void right() {
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}
void stop() {
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}
void led_on() {
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}
void led_of() {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}
void plusUltra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  sm = duration / 58;
}

void setup() {
  // Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  led_on();
  delay(5000);
}

void loop() {
    plusUltra();
  // Serial.println(sm);
  if (sm > 1 && sm < 40) {
    tic ++;
  } else {
    tic = 0;
  }
  if (tic >= 2) {
    if (state == 0 && millis() > 5050) {
      right();
      delay(10);
    }
    forward();
    led_on();
    delay(300);
    state = 1;
  } else {
    left();
    led_of();
  }
}
