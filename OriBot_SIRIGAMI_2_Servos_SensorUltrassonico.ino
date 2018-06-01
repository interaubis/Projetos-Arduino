#include <Servo.h> 
#include <Ultrasonic.h>


//criando objeto ultrasonic e definindo as portas digitais 
//do Trigger - 9- e Echo - 10
Ultrasonic ultrasonic(9,10);


long microsec = 0;
float distanciaCM = 0;

int val =0;



//criando os motores 
Servo myservo2; 


Servo myservo; 










void setup() {
  Serial.begin(9600);
  
 //pinos do arduino onde ligar os motores  
   myservo2.attach(6); 


    myservo.attach(7); 



}


void loop() {
  


  
    microsec = ultrasonic.timing();  //Lendo o sensor
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 
 


  delay(1);
  



  int val = map(distanciaCM, 0, 1023, 0, 179);



 
  if(distanciaCM >= 10 && distanciaCM <=70){
 
      myservo2.write(val*(random(10,20)));
          
  myservo.write(random(20,140)); 
  delay(100);
   myservo.write(random(10,180));  
     
    delay(100);
            Serial.println(distanciaCM); //Mostra no Serial Monitor o valor obtido da conversao do sensor
        Serial.println(val); //Mostra no Serial Monitor o valor obtido da conversao do sensor
              
          
  }
   
   
// se a distancia for maior do que 70
// e menor do que 10 cm ele não faz nada
 
   if(distanciaCM > 70 || distanciaCM < 10){
     
   
       
      myservo2.write(0);  
          
        myservo.write(180);  
          // sets the servo position according to the scaled value 
    delay(10);

    
           
  }
  



}



