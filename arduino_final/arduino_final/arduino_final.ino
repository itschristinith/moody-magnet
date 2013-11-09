// motor pins
int motorPin10 = 10;
int motorPin8 = 8;

// red LED to indicate when motorPins are high/low
int pin13=13; 

// yellow LEDs for inside
int pin5=5;
int pin4=4;
int pin3=3;
int pin2=2;

// variable to hold incoming byte from Python
int inByte = 0;

void setup() {
  pinMode(motorPin10, OUTPUT);
  pinMode(motorPin8, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin2, OUTPUT);

  // set yellow LEDs to high and red LED to low to start
  digitalWrite(pin5, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin13, LOW);

  Serial.begin(9600); 
}

void loop() {

  // 1 from python indicates negative sentiment. LEDs on, motorpins high
  if( inByte == '1' ) {
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin13,HIGH);

    digitalWrite(motorPin10, HIGH);
    digitalWrite(motorPin8, HIGH);
  }
  else if (inByte == '3') {
    // 3 from python indicates neutral sentiment. blinking LEDs, motorpins low
    digitalWrite(pin13, LOW);
    digitalWrite(motorPin10, LOW);
    digitalWrite(motorPin8, LOW);

    // make yellow LEDs blink
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    delay(1000);
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    delay(1000);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    delay(1000);
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    delay(1000);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    delay(1000);
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    delay(1000);

  }
  else {
    // 2 from python indicates positive sentiment. yellow LEDs back on and motorpins low
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin13, LOW);

    digitalWrite(motorPin10, LOW);
    digitalWrite(motorPin8, LOW);
  }

  // if there's a byte coming in, read the serial port
  if( Serial.available() > 0 ) {
    inByte = Serial.read(); 
  } 
}




