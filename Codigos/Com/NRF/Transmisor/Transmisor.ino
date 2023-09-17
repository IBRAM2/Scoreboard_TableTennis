#include <SPI.h>
#include <RF24.h>

RF24 radio(10,9);

// const byte identificacion[6] = "00001";

void setup()
{
  //inicializamos el puerto serie
  Serial.begin(9600); 

  //inicializamos el NRF24L01 
  radio.begin();

  radio.setChannel(0x55);
 
  //Abrimos un canal de escritura
  radio.openWritingPipe(0xF0F0F0F0AA);
  // Nivel de transmisión
  radio.setPALevel(RF24_PA_MIN);
  // //Datarate
  // radio.setDataRate(RF24_250KBPS);
  //Deja de escuchar
  radio.stopListening();
  radio.powerUp(); //Power up the radio
}

void loop()
{
  const char mensaje[] = "Hola que tal";
  //enviamos los datos
 bool ok = radio.write(&mensaje, sizeof(mensaje));
  //reportamos por el puerto serial los datos enviados 
  if(ok)
     Serial.print("Datos enviados:\n"); 
  else
     Serial.println("no se ha podido enviar");
  delay(1000);
}