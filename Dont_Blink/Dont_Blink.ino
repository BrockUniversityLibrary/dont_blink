
/* Don't Blink
 * Simple game for the Arduino
 * 
 * 
 */

current = 0;
but_press = LOW;
inter = 1000;
long last = millis();


//Basics
void setup() {
  pinMode(0, INPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}


setup_game(){
  current = 0;
  inter = 1000;
  Serial.println("New Game");

}

increment(){

  current = (current++) % 5;
  for (int i = 0; i < 5; i++)
    digitalWrite(i,LOW);
  digitalWrite(8 + current,HIGH)
}


void loop() {

if (millis() - last > inter){
  last = millis();

  increment();

  if(but_press = LOW && digitalRead(0) == HIGH){

    if(current == 3){
      digitalWrite(8 + 3, LOW);
      delay(100);
      digitalWrite(8 + 3, HIGH);

      switch(current){
          case current > 700:{
            current -= 100;
            break;
          }
          case current > 500:{
            current -= 50;
            break;
          }
          case current > 300:{
            current -= 25;
            break;
          }
          case current > 10:{
            current -= 1
            break;
          } 
        }
      }
    
    }
  }
  
}





/*

  for( int i = 8; i < 13; i++){
     digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(1000);              // wait for a second
     digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
  }
  
*/
