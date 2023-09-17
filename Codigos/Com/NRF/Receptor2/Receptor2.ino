// Incluir librerías
// RadioHead ASK
// SPI
#include <RH_ASK.h>
#include <SPI.h> 

// Indicar tamaño del mensaje que se va a recibir
const byte tamMsg = 1;

// Crear un objeto de la clase ASK
RH_ASK askRx(2000, 10, 12, 11);
 
void setup()
{
    // Iniciar monitor serie
    Serial.begin(9600);
    // Inicializar objeto ASK
    askRx.init();
}
 
void loop()
{
    // Tamaño esperado del mensaje
    uint8_t msg[tamMsg];
    uint8_t msgLen = sizeof(msg);
    // Comprobar si el mensaje recibido tiene el tamaño adecuado
    if (askRx.recv(msg, &msgLen))
    {
      // Mostrar mensaje por el monitor serie
      Serial.print("Mensaje recibido: ");
      Serial.println((char*)msg);         
    }
}
