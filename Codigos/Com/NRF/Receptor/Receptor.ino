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
  //Abrimos el canal de Lectura
  radio.openReadingPipe(0, 0xF0F0F0F0AA);
  radio.setAutoAck(false);
  // Nivel de transmisión
  radio.setPALevel(RF24_PA_MIN);
  //Datarate
  // radio.setDataRate(RF24_250KBPS);
  // empezamos a escuchar por el canal
  radio.startListening();
  radio.powerUp(); //Power up the radio
}

void loop() {
 if (radio.available() )
 {   
    char text[32] = "default";
     //Leemos los datos y los guardamos en la variable datos[]
     radio.read(&text,sizeof(text));
     Serial.println(text);
 }
 else
 {
     Serial.println("No hay datos de radio disponibles");
 }
 delay(1000);
}
