void setup() {
  pintMode(0, INPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}


void loop() {

  for( int i = 8; i < 13; i++){
     digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(1000);              // wait for a second
     digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
  }
  
}
