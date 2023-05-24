//////////////  MATRICES LED //////////////
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "numeros.h"  // Librería pa dibujar los numeros en la matriz

//Defiine pines SPI
#define MOSI 11
#define SCK 13
#define SS 10
//Numero de matrices
#define NUM_MAT 8

//Instancia objeto
MD_MAX72XX mxObj = MD_MAX72XX(MD_MAX72XX::GENERIC_HW, SS, NUM_MAT);

//Mapea matrices a utilizar
int colMat_1[2][2] = {{5,1},{4,0}};
int colMat_2[2][2] = {{7,3},{6,2}};

void setup() {
  //Inicializa objeto
  mxObj.begin();
}

void loop() {
  
  for(int i=0; i<10; i++)
  {
    //Función para llamar un numero
    //Numero - Grupo de matrices - Objeto
    Numero(i, colMat_1, mxObj);
    delay(5000);
  }
}