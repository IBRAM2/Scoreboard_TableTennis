#ifndef NUMEROS_H
#define NUMEROS_H
// #include <MD_MAX72xx.h>

//Prototipo de la función Numero
//Numero - Grupo de matrices - Objeto
void Numero(int n, int colMat[2][2], MD_MAX72XX &mxObj);

//Función para dibujar servicio
void Servicio(uint8_t player, MD_MAX72XX &mxObj);

//Función para limpiar servicio anterior
void LimpiaServ(uint8_t player, MD_MAX72XX &mxObj);

#endif