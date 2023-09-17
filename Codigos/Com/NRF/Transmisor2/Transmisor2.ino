// Incluir librerías
// RadioHead ASK
// SPI
#include <RH_ASK.h>
#include <SPI.h> 
 
// Crear un objeto de la clase ASK
RH_ASK askTx;

//Numero de pin
const uint8_t boton = 9;
 
void setup()
{
    // Inicializar objeto
    askTx.init();
    //Inicializa pin de botón
    pinMode(boton, INPUT);
}
 
void loop()
{
  if(bool estadoPulsador = digitalRead(boton))
  {
    delay(500);
    if(bool estadoPulsador = digitalRead(boton))
    {
      // Mensaje a enviar
      const char *msg = "b";
      // Envió información
      askTx.send((uint8_t *)msg, strlen(msg));
      // Esperar a que sea enviado el paquete
      askTx.waitPacketSent();
      delay(1000);
    }
    else
    {
      // Mensaje a enviar
      const char *msg = "a";
      // Envió información
      askTx.send((uint8_t *)msg, strlen(msg));
      // Esperar a que sea enviado el paquete
      askTx.waitPacketSent();
    }
  }
}