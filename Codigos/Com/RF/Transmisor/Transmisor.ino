#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    // vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_tx_pin(2); //Pin 2 como salida para el RF 
}

void loop()
{
    const char *msg = "hello";

    // digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    // digitalWrite(13, false);
    //  Serial.println("hola");
    delay(200);
}