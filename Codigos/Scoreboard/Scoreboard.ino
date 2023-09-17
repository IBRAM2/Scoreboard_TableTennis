//*********Marcador Ping pong Profesional****************
//Creditos:
//Iván Ibrahim Fernández Morales
//Luis Roberto Villa Salas
//Hector Varela Santos

#include <MD_MAX72xx.h>
#include <SPI.h>
#include "numeros.h"  // Librería pa dibujar los numeros en la matriz

//Define pines SPI
#define MOSI 11
#define SCK 13
#define SS 8
#define BUZZ_ACT 7
//Numero de matrices
#define NUM_MAT 10

//Instancia objeto
MD_MAX72XX mxObj = MD_MAX72XX(MD_MAX72XX::GENERIC_HW, SS, NUM_MAT);

//Mapea matrices a utilizar
int colMat_1[2][2] = {{5,1},{4,0}};
int colMat_2[2][2] = {{7,3},{6,2}};
int colMat_3[2] = {8,9};

//Mapeo de servicios
uint8_t S_Singles[4] = {1,2,1,2};
uint8_t S_Doubles1[4] = {1,4,3,2};
uint8_t S_Doubles2[4] = {2,3,4,1};
uint8_t S_Doubles3[4] = {3,2,1,4};
uint8_t S_Doubles4[4] = {4,1,2,3};
uint8_t Serve[4];

//Mapeo de botones
uint8_t B_SD = 2;
uint8_t B_OPT = 3;
uint8_t B_SL = 4;
uint8_t B_SV = 5;

//Inicializa contadores
uint8_t contL = 0;
uint8_t contV = 0;
uint8_t contSetL = 0;
uint8_t contSetV = 0;
uint8_t contS = 0;
uint8_t cont_pos = 0;
uint8_t suma = 0;

//Variable de cambio de servicio
bool Doubles;

//Inicializa variables de singles o dobles
//Doubles = 0;

//Setup
//*****************************************************************************
void setup() {
  //Inicializa objeto
  mxObj.begin();

  //Inicializa pines de entrada (Botones)
  //Botón de opciones
  pinMode(B_OPT, INPUT);
  //Botón marcador local
  pinMode(B_SL, INPUT);
  //Botón marcador visitante
  pinMode(B_SV, INPUT);
  
  //Pin de activación de victoria (Buzzer)
  pinMode(BUZZ_ACT, OUTPUT);
  digitalWrite(BUZZ_ACT, LOW);

  //Lee entrada digital de selección de sobles o singles
  Doubles = digitalRead(B_SD);

  //Define si es singles o dobles
  if(Doubles)
    for(uint8_t i = 0; i < 4; i++)
      Serve[i] = S_Doubles1[i];
  else
    for(uint8_t i = 0; i < 4; i++)
      Serve[i] = S_Singles[i];

  //Inciliza numeros en el marcador
  Numero(contL, colMat_1, mxObj);
  Numero(contV, colMat_2, mxObj);
  //Inicializa Sacador
  Servicio(Serve[contS], mxObj);
  //Inicializa Sets
  Sets(contSetL, colMat_3, 0, mxObj);
  Sets(contSetV, colMat_3, 1, mxObj);
}

//Ciclo plrincipal
//*****************************************************************************
void loop() 
{

  //Cambia posición de sacardor si el partido aún no empieza
  if(contL+contV == 0 && digitalRead(B_OPT))
    {
    cambiaServicio(Serve, &contS);
    delay(500);
    }

  //Punto de jugador local
  if(digitalRead(B_SL))
  { 
    subeLocal(&contL);
    suma = contL+contV;
    asignaServicio(Serve, &contS, suma);
    if(contL >= 11 && contL-2 >= contV)
    {
      Victoria(1, &contL, &contV, &contS, Serve);
      subeSet(&contSetL, 0);
    }
    delay(500);
  }

  //Punto de jugador visitante
  if(digitalRead(B_SV))
  {
    subeVisita(&contV);
    suma = contL+contV;
    asignaServicio(Serve, &contS, suma);
    if(contV >= 11 && contV-2 >= contL)
    {
      Victoria(2, &contL, &contV, &contS, Serve);
      subeSet(&contSetV, 1);
    }
    delay(500);
  }
}

//Funciones
//*****************************************************************************

//Función para subir marcador de jugador local
//---------------------------------------------------------------
void subeLocal(uint8_t *contL)
{
  *contL = *contL+1;
  Numero(*contL, colMat_1, mxObj);
}

//Función para subir marcador de jugador visitante
//---------------------------------------------------------------
void subeVisita(uint8_t *contV)
{
  *contV = *contV+1;
  Numero(*contV, colMat_2, mxObj);
}

//Función para subir set
//---------------------------------------------------------------
void subeSet(uint8_t *cont, uint8_t player)
{
  *cont = *cont+1;
  Sets(*cont, colMat_3, player, mxObj);
}

//Función para conocer sacador
//---------------------------------------------------------------
void asignaServicio(uint8_t Serve[4], uint8_t *contS, uint8_t suma)
{
  if(suma <=20)
  {
    if(suma%2 == 0)
    {
      LimpiaServ(Serve[*contS], mxObj);
      *contS = *contS+1;
      if(*contS > 3)
        *contS = 0;
      Servicio(Serve[*contS], mxObj);
    }
    else
      Servicio(Serve[*contS], mxObj);
  }
  else
  {
    LimpiaServ(Serve[*contS], mxObj);
    *contS = *contS+1;
    if(*contS > 3)
      *contS = 0;
    Servicio(Serve[*contS], mxObj);
  }
}
//Función de victoria
//---------------------------------------------------------------
void Victoria(uint8_t team, uint8_t *contL, uint8_t *contV, uint8_t *contS, uint8_t Serve[4])
{
  digitalWrite(BUZZ_ACT, HIGH);
  delay(300);
  digitalWrite(BUZZ_ACT, LOW);
  delay(5000);
  *contL = 0;
  *contV = 0;
  *contS = 0;
  Numero(*contL, colMat_1, mxObj);
  Numero(*contV, colMat_2, mxObj);
  Servicio(Serve[*contS], mxObj);
}

//Función de cambio de sacador manual
//---------------------------------------------------------------
void cambiaServicio(uint8_t Serve[4], uint8_t *contS)
{ 
  LimpiaServ(Serve[*contS], mxObj);
  
  if(Doubles)
  {
    cont_pos = cont_pos+1;
    if(cont_pos > 3)
      cont_pos = 0;
    cambiaMapeo(cont_pos);
    *contS = 0;
    Servicio(Serve[*contS], mxObj);
  }
  else
  {
    *contS = *contS+1;
    if(*contS > 3)
      *contS = 0;
    Servicio(Serve[*contS], mxObj);
  }
}

//Función de cambio de mapeo de dobles
//---------------------------------------------------------------
void cambiaMapeo(uint8_t cambio)
{
  switch(cambio)
  {
    case 0:
      for(uint8_t i = 0; i < 4; i++)
        Serve[i] = S_Doubles1[i];
    break;

    case 1:
      for(uint8_t i = 0; i < 4; i++)
        Serve[i] = S_Doubles2[i];
    break;

    case 2:
      for(uint8_t i = 0; i < 4; i++)
        Serve[i] = S_Doubles3[i];
    break;

    case 3:
      for(uint8_t i = 0; i < 4; i++)
        Serve[i] = S_Doubles4[i];
    break;
  }
}
