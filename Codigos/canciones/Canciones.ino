//Librerías
//-----------------------------------------------------------------------------------
#include "math.h"
#include "canciones.h"
#include <avr/sleep.h>

//Variables
//-----------------------------------------------------------------------------------
int numero;            //Inicializa número aleatorio
bool ban = false;      //bandera auxiliar de push button (inicializar en false)
int pin_inter = 0;     //Pin de interrupción del push button - 0 == INT0 *** 1 == INT1

//Setup
//-----------------------------------------------------------------------------------
void setup() {
  randomSeed(analogRead(0));
  attachInterrupt(pin_inter, canciones_inter_ban, HIGH);
}

//Loop principal
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
void loop() 
{
  //Si ban es verdadero toca una canción 
  if(ban == true)
  { 
    numero = random(10);
    play(numero);
      
    ban = false;
  }

  //Entra en modo sleep
  delay(10);
  sleep();
}

//Interrupción de activación de bandera mensaje
//-----------------------------------------------------------------------------------
void canciones_inter_ban() 
{
  sleep_disable();
  ban = true;
}

//Función Sleep
//-----------------------------------------------------------------------------------
void sleep() 
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Modo extremo de sleep
  sleep_enable();        // Habilita modo sleep
  sleep_cpu();   // CPU detenida
}

