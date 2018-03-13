// agradecimentos ao site do laboratorio de garagem
// de onde tirei dicas pra resolver problemas nesse código

#include <Servo.h> 



int trigPin = 9;    //Trig - green Jumper
int echoPin = 10;    //Echo - yellow Jumper
long duration, cm, inches;

long value=0;
int x;

int val =0;




Servo myservo2; 


Servo myservo; 










void setup() {
  Serial.begin(9600);
  
  
   myservo2.attach(6); 


    myservo.attach(7); 

 //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

}


void loop() {
  
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(50);

x=map(value,0,1023,30,100);


// se a distancia for menor do que 10 cm
// ele não faz nada

   if(cm > 0 || cm < 10 ){ 
 
  
    myservo.write(80);  
    
        myservo2.write(80); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits for the servo to reach the position 


 
   }

 // se a distancia for maior do que 30 cm
// ele não faz nada

  if(cm > 30){ 
 
  
    myservo.write(80);  
    
        myservo2.write(80); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits for the servo to reach the position 


 
   } 
   
  // se a distancia for menor do que 20
  // e maior do que 10 ele joga as duas
  // pernas pra frente e vai se empurrando
  // pra trás
 
  if(cm > 10 && cm < 20){ 
 
  
    myservo.write(150);  
    
        myservo2.write(30); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(250);                       // waits for the servo to reach the position 


  myservo.write(110);  
    
        myservo2.write(70); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(250);  
  
  
  
  }

 // se a distancia for maior do que 20 e menor do que
  // 30 cm, ele anda pra frente, cada perna da um
  // passo por vez, alternadas

       
     if(cm > 20 && cm < 30){ 
 
    myservo.write(110);  
    
        myservo2.write(100); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(250);                       // waits for the servo to reach the position 
 

  myservo.write(85);  
    
        myservo2.write(80); 
 
 // tell servo to go to position in variable 'val' 
                 // tell servo to go to position in variable 'pos' 
    delay(250); 
  }


  

}
 
  







