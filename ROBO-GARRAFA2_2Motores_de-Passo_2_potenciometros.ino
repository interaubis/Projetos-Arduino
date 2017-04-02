#include <Stepper.h>

// Este código controla dois motores de passo
// 28BYJ-48
// que funcionam junto com o driver ULN2003A
// cada motor é controlado indepente a partir
// de dois potênciômetros


int val = 0;    // variable to store the value of analog digital conversion


int potpin = 0; // Define o pino do Arduino que o potenciômetro está conectado

int val2 = 0;    // variable to store the value of analog digital conversion


int potpin2 = 1; // Define o pino do Arduino que o potenciômetro está conectado



const int stepsPerRevolution = 360; 

 // os fios do driver ULN2003A devem ser ligados no arduino
 // assim: IN1 ligado no 8
 // IN2 ligado no 10
 // IN3 ligado no 9
 // IN4 ligado no 11
 Stepper myStepper = Stepper(stepsPerRevolution, 8,9,10,11);            

// os fios do driver ULN2003A do segundo motor devem ser ligados no arduino
 // assim: IN1 ligado no 2
 // IN2 ligado no 4
 // IN3 ligado no 3
 // IN4 ligado no 5
Stepper myStepper2 = Stepper(stepsPerRevolution, 2,3,4,5);            





void setup() {
  Serial.begin(9600);
   //Determina a velocidade inicial do motor 
// myStepper.setSpeed(100);
}


void loop() { 
 val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 


val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023) 
 
  val2 = map(val2, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 

  delay(1);
  
 
 // set the motor speed:
   
  
   if (val >= 70)  {
      myStepper.setSpeed(80);    
      myStepper.step(1); 
      
        //steps depois que sai (delay)
      delay(1);

   
     
      }
     
      
       if (val <= 40)  {
        myStepper.setSpeed(80);    
      myStepper.step(-1); 
     
        //steps depois que sai (delay)
      delay(1);
     
      }

        if (val < 10)  {
        myStepper.setSpeed(0);    
      myStepper.step(0); 
        
        //steps depois que sai (delay)
      delay(1);
     
      }
      
   if (val2 >= 70)  {
      myStepper.setSpeed(80);    
     
        myStepper2.step(1);    
        //steps depois que sai (delay)
      delay(1);

   
     
      }
     
      
       if (val2 <= 40)  {
        myStepper.setSpeed(80);    
     
        myStepper2.step(-1);    
        //steps depois que sai (delay)
      delay(1);
     
      }

        if (val2 < 10)  {
        myStepper.setSpeed(0);    
    
        myStepper2.step(0);    
        //steps depois que sai (delay)
      delay(1);
     
      }
      
 
   }  





