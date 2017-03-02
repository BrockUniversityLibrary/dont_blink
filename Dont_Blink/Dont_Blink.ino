
/* Don't Blink
 * Simple game for the Arduino
 * 
 * 
 */

int current = 0;
int but_press;
int interval = 500;
long last = millis();


//Basics
void setup() {
  pinMode(1, INPUT);
  digitalWrite(1, HIGH);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  Serial.begin(9600);
  setup_game();
  last = millis();
}


void setup_game(){
  current = 0;
  interval = 1000;
  Serial.println("New Game");
}

void increment(){

  for (int i = 0; i < 5; i++){
    digitalWrite(8 + i,LOW);
  }
  digitalWrite(8 + current,HIGH);
  current = (current + 1) % 5;
}


//HIGH is pressed

void loop() {

if ((millis() - last) > interval){


  last = millis();
  increment();


  if(digitalRead(1) == HIGH && but_press == HIGH)
  {
    if(current == 3){

      digitalWrite(8 + 3, LOW);
      delay(100);
      digitalWrite(8 + 3, HIGH);
      digitalWrite(8 + 3, LOW);
      delay(100);
      digitalWrite(8 + 3, HIGH);
      digitalWrite(8 + 3, LOW);
      delay(100);

     if (interval > 700)
     {
      interval = interval - 100;
     }
     else if (interval > 500)
     {
      interval = interval - 50;
     }
     else if(interval > 300){
            interval = interval - 25;
     }
     else if(interval > 100){
            interval = interval - 1;
     } 
     
      Serial.print("Score: ");
      Serial.println(interval);
      
     }  
     else     
     { 
      Serial.print("GAME OVER");
      Serial.print(" Final Score: ");
      Serial.println(interval);
      setup_game(); 
     }

    }
  }   
}

   /*   
    digitalWrite(8, HIGH);
    if( iterval < 800)
    {
        digitalWrite(9,HIGH);
        delay(250);
    }
    if (interval < 600)
    {
        digitalWrite(10,HIGH);
        delay(250);
    }
    if (interval < 250)
    {
        digitalWrite(11, HIGH);
        delay(250);
    }
    if (interval < 100)
    {
        digitalWrite(12, HIGH);
        delay(250);
    }
    }
    delay(2000);
    */



