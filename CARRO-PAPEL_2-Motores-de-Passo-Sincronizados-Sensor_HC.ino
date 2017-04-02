#include <Stepper.h>
#include <Ultrasonic.h>

// Este projeto sincroniza dois motores de passo 28BYJ-48
// que funciona junto com um driver ULN2003A
// e usa um sensor ultrasônico HC-SR04 montado à frente do carro
// se o objeto estiver próximo, o carro se afasta
// se o objeto estiver um pouco menos próximo, o carro o segue
// se estiver longe ou perto demais o carro fica parado



//criando objeto ultrasonic e definindo as portas digitais 
//do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);

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

long microsec = 0;
float distanciaCM = 0;
// int stepCount = 0;  

void setup() {
  Serial.begin(9600);
   //Determina a velocidade inicial do motor 
 // myStepper.setSpeed(100);
}

void loop() { 
  microsec = ultrasonic.timing();  //Lendo o sensor
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 

  delay(1);
  
 // map it to a range from 0 to 255:
 int motorSpeed = map(distanciaCM, 0, 1023, 255, 0);
 

 if (distanciaCM > 0) {

   if (distanciaCM < 10)  {
      myStepper.setSpeed(80);    
      myStepper.step(1); 
          
        
     myStepper2.setSpeed(80);    
      myStepper2.step(1); 
           
      delay(1);
   
 
   
     
      }
      
 if (distanciaCM > 10)  {
      myStepper.setSpeed(80);    
      myStepper.step(-1); 
           myStepper2.setSpeed(80);    
      myStepper2.step(-1); 
            //steps depois que sai (delay)
      delay(1);
   
   
     
      }
   
   
    if (distanciaCM > 50)  {
      myStepper.setSpeed(000);    
      myStepper.step(0); 
     myStepper2.setSpeed(00);    
      myStepper2.step(0); 
            //steps depois que sai (delay)
      delay(1000);
 
   
     
      }
      
      
      
   }  
  }









