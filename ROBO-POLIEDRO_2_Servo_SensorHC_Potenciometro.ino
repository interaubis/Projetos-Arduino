  #include <Servo.h> 
#include <Ultrasonic.h>


// Este código controla dois motores servo
// um deles é controlado pelo sensor ultrasônico HC-SR04
// o outro é controlado por um potenciômetro


//criando objeto ultrasonic e definindo as portas digitais 
//do Trigger - 10- e Echo - 11
Ultrasonic ultrasonic(10,11);


long microsec = 0;
float distanciaCM = 0;


int val = 0;    // variable to store the value of analog digital conversion


int potpin = 0; // Define o pino do Arduino que o potenciômetro está conectado




Servo myservo; 

Servo myservo2;  // create servo object to control a servo 


void setup() {
  Serial.begin(9600);
  
  
 

    myservo.attach(6); 

  myservo2.attach(5); 

}


void loop() {
  

 val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 


  
    microsec = ultrasonic.timing();  //Lendo o sensor
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 
 


  delay(1);
  
 // map it to a range from 0 to 255:


  int motorSpeed = map(distanciaCM, 0, 1023, 0, 179);


   if (val > 10)  {
 myservo2.write(val); 
   
      // sets the servo position according to the scaled value 
    delay(1);
            Serial.println(val); //Mostra no Serial Monitor o valor obtido do potenciômetro

    

   
   }
 
 
  if(distanciaCM <= 15){
 
     
          
  myservo.write(0); 
   
      // sets the servo position according to the scaled value 
    delay(1);
            Serial.println(distanciaCM); //Mostra no Serial Monitor o valor obtido do potenciômetro

              
          
  }
   
 
   if(distanciaCM > 15){
     
   
                 
        myservo.write(distanciaCM);  
          // sets the servo position according to the scaled value 
    delay(1);

    
           
  }
  

   
  if(distanciaCM > 150){ 
   
   
        myservo.write(90);  
        
    Serial.println(distanciaCM); //Mostra no Serial Monitor o valor obtido do potenciômetro
  }
}




