
/* Don't Blink
 * Simple game for the Arduino
 * 
 * 
 */

int current = 0;
boolean but_press = LOW;
int inter = 1000;
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
    digitalWrite(8+ i,LOW);
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

      switch(inter){
          case inter > 700:{
            inter -= 100;
            break;
          }
          case inter > 500:{
            inter -= 50;
            break;
          }
          case inter > 300:{
            inter -= 25;
            break;
          }
          case inter > 10:{
            inter -= 1
            break;
          } 
        }
      Serial.print("Score: ");
      Serial.println(inter);
      
      }
      else {
      
      Serial.println("GAME OVER");
      Serial.print("Final Score: ");
      Serial.println(inter);

      for (int i = 0: i < 6; i++){
        digitalWrite(8 + current, LOW);
        delay(150);
        digitalWrite(8 + current, HIGH);
      }

      
     digitalWrite(8, HIGH);
     switch(inter)
     {
      case inter < 800:{
        digitalWrite(9,HIGH);
        delay(250);
        break;
      }
      case inter < 600:{
        digitalWrite(10,HIGH);
        delay(250);
        break;
      }
      case inter < 250:{
        digitalWrite(11, HIGH);
        delay(250);
      }
      case inter < 100:{
        digitalWrite(12, HIGH);
        delay(250);
      }
     }
    delay(2000);
    setup_game();
    }
  }

 but_press = digitalRead(0);
  
}


