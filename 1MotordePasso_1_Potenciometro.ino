#include <Stepper.h>

// este código precisa da biblioteca Stepper que vem com o Arduino
// e pode ser encontrada no menu Sketch > Include Library > Contributed Libraries

// este código é uma colagem de uma série de fontes da internet 
// e pode ser copiado e modificado conforme a sua necessidade


int val = 0;    // Define uma variável pra armazenar o valor do potênciometro


int potpin = 0; // Define o pino do Arduino que o potenciômetro está conectado




const int stepsPerRevolution = 200;   


 // Define as entradas digitais do Arduino onde os fios do driver ULN2003A
 // estarão conectadas: 1N1 -> 5, 1N3 -> 6, 1N2 -> 7 e 1N4 -> 8
Stepper myStepper = Stepper(stepsPerRevolution, 5, 6, 7, 8); 
 




void setup() {
  Serial.begin(9600);
  //Determina a velocidade inicial do motor
  myStepper.setSpeed(60);

}


void loop() {
  val = analogRead(potpin);            // Lê o valor do potenciômetro, entre 0 e 1023

  val = map(val, 0, 1023, 0, 179);     // mapeia o valor lido em apenas 180 posições


  delay(1);


  // com o valor entre os limites estabelecidos no código, 
  // o motor funciona pra uma direção, para outra ou não funciona


  if (val > 50 && val < 90)  {

    myStepper.step(1);

    //steps depois que sai (delay)
    delay(1);



  }


  if (val <= 50 && val > 10)  {

    myStepper.step(-1);


    //steps depois que sai (delay)
    delay(1);

  }


  if (val >= 85 && val <= 15)  {

    myStepper.step(0);



    //steps depois que sai (delay)
    delay(1);



  }



}





