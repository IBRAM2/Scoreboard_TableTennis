//*********Control inalámbrico del marcador de PingPong Profesional****************
//Creditos:
//Iván Ibrahim Fernández Morales

// Incluye librerías
#include <RH_ASK.h>
#include <SPI.h> 
#include <avr/sleep.h>

// Crear un objeto de la clase ASK
RH_ASK askTx;

//Variables
//-----------------------------------------------------------------------------------
//Bandera auxiliar de botón (inicializar en false)
bool ban = false;
//Numero de botón
const uint8_t Boton = 8;
//Pin de interrupción del Botón - 0 == INT0 *** 1 == INT1
int push_button_inter = 0;

//Setup
//***************************************************************************** 
void setup()
{
    // Inicializar objeto
    askTx.init();
    //Inicializa pin de botón
    pinMode(Boton, INPUT);
    //Interrupción del botón
    attachInterrupt(push_button_inter, send_message_ban, HIGH);
}

//Ciclo plrincipal
//***************************************************************************** 
void loop()
{
  if(ban == true)
  {
    if(bool estadoBoton = digitalRead(Boton))
    {
      delay(500);
      //Manda mensaje de bajar puntaje de equipo/jugador 1
      if(bool estadoBoton = digitalRead(Boton))
      {
        // Mensaje a enviar
        const char *msg = "b";
        // Envió información
        askTx.send((uint8_t *)msg, strlen(msg));
        askTx.waitPacketSent();
        delay(1000);
        ban = false;
      }
      else
      //Manda mensaje de subir puntaje de equipo/jugador 2
      {
        // Mensaje a enviar
        const char *msg = "a";
        // Envió información
        askTx.send((uint8_t *)msg, strlen(msg));
        askTx.waitPacketSent();
        ban = false;
      }
    }
  }
  delay(10);
  sleep();
}

//Funciones
//*****************************************************************************

//Interrupción de activación de bandera mensaje
//-----------------------------------------------------------------------------------
void send_message_ban() 
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