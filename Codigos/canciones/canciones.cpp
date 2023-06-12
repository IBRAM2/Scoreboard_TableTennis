#include "canciones.h"
#include <Arduino.h>

// Frecuencias
#define A2 110
#define As2 116.54
#define B2 123.47
#define G3 196
#define Gs3 207.65
#define A3 220
#define As3 233.08
#define B3 246.94
#define C4 261.63
#define Cs4 277.18
#define D4 293.66
#define Ds4 311.13
#define E4 329.63
#define F4 349.23
#define Fs4 369.99
#define G4 392.00
#define Gs4 415.30
#define A4 440.00
#define As4 466.16
#define B4 493.88
#define C5 523.25
#define Cs5 554.37
#define D5 587.33
#define Ds5 622.25
#define E5 659.25
#define F5 698.46
#define Fs5 739.99
#define G5 783.99
#define Gs5 830.61
#define A5 880.00
#define As5 932.33
#define B5 987.77
#define C6 1046.50

const double starfox[][2] = {
  {D4, 0.5},{D5, 0.5},{C5, 2},{B4, 0.3},{A4, 0.33},{B4, 0.34},{0, 0.33},{G4, 0.67},{G5, 3},{Fs5, 0.33},{Fs5, 0.33},{Fs5, 0.34},{G5, 0.5},{G4, 0.5}
};

const double mario[][2] = {
  {G3, .33},{C4, .33},{E4, .34},{G4, .33},{C5, .33},{E5, .34},{G5, 1},{E5, .5},{37, .5},{Gs3, .33},{C4, .33},{Ds4, .34},{Gs4, .33},{C5, .33},{Ds5, .34},{Gs5, 1},{Ds5, .5},{37, .5},{As3, .33},{D4, .33},{F4, .34},{As4, .33},{D5, .33},{F5, .34},{As5, 1},{As5, .33},{As5, .33},{As5, .34},{C6, 4}
};

const double kirby[][2] = {
  {C5, .5},{D5, .5},{E5, .5},{Fs5, .5},{E5, .5},{Fs5, .5},{G5, 1},{D5, .5},{B4, 1},{D5, .5},{C5, 1},{B4, .5},{A4, 1},{B4, .5},{G4, 1.5},{G5, 1.5}
};

const double finalfantasy[][2] = {
  {C5, 1/3},{C5, 1/3},{C5, 1/3},{C5, 1},{Gs4, 1},{As4, 1},{C5, 1/3},{0, 1/3},{As4, 1/3},{C5, 3}
};

const double fallguys[][2] = {
  {Fs4, 1/2},{E4, 1/2},{Fs4, 1/2},{A4, 1},{Fs4, 1/2},{A4, 1/2},{B4, 1},{A4, 1/2},{B4, 1/2},{E5, 1},{Cs5, 1/2},{E5, 1},{Fs5, 1}
};

const double zelda[][2] = {
  {D4, 1/3},{D4, 1/3},{D4, 1/3},{G4, 3},{G4, 1/4},{A4, 1/4},{B4, 1/4},{C5, 1/4},{D5, 3},{C5, 1/4},{D5, 1/4},{E5, 1/4},{F5, 1/4},{G5, 3}
};

const double smash[][2] = {
  {D4, 4/5},{E4, 4/5},{F4, 9/10},{D4, 1/2},{F4, 1/2},{C5, 1/2},{B4, 4/5},{A4, 4/5},{B4, 2/5},{G4, 2}
};

const double yoshi[][2] = {
  {G5, 2},{A5, 1/2},{G5, 1/2},{A5, 1},{G5, 2},{F5, 1/2},{E5, 1/2},{F5, 1},{E5, 2},{D5, 1/2},{C5, 1/2},{D5, 1},{C5, 2}
};

const double metroid[][2] = {
  {F4, 1/2},{As3, 1/2},{C4, 1/2},{D4, 1/2},{E4, 1/2},{C4, 1/2},{G3, 1/2},{C4, 1/2},{F4, 1/2},{D4, 1/2},{As3, 1/2},{G3, 1/2},{A3, 2}
};

const double fireemblem[][2] = {
  {C4, 2},{F4, 1},{A4, 1},{C5, 2},{As4, 1},{A4, 1},{D5, 2},{E5, 2/3},{F5, 2/3},{G5, 2/3},{C5, 3}
};

const double duckhunt[][2] = {
  {E4, 1/4},{E4, 1/4},{G4, 1/4},{0, 1/4},{E4, 1/4},{0, 1/4},{G4, 1/4},{0, 1/4},{F4, 1/4},{F4, 1/4},{A4, 1/4},{0, 1/4},{F4, 1/4},{0, 1/4},{A4, 1/4},{0, 1/4},{E4, 1/4},{E4, 1/4},{G4, 1/4},{0, 1/4},{E4, 1/4},{0, 1/4},{G4, 1/4},{0, 1/4},{G4, 1/4},{F4, 1/4},{E4, 1/4},{D4, 1/4},{C4, 1/4},{B3, 1/4},{A3, 1/4},{0, 1/4},{B3, 1/4},{C4, 1/4},{D4, 1/4},{E4, 1/4},{F4, 1/4},{G4, 1/4},{A4, 1/4},{B4, 1/4},{C5, 1/2}
};

const double kingkrool[][2] = {
  {F5, 1/2},{E5, 1/2},{D5, 1/2},{C5, 1/2},{D5, 1/2},{E5, 1/2},{F5, 1/2},{E5, 1/2},{D5, 1/2},{E5, 1/2},{F5, 1/2},{0, 1/2},{A5, 1/2},{0, 1/2},{F5, 1},{As5, 1/2},{B5, 1/2},{C6, 4}
};

const double dragonquest[][2] = {
  {A4, 1/2},{B4, 1/2},{C5, 1/2},{F5, 2},{E5, 2},{C5, 3}
};

const double BPM[13] = {
  150,150,260,120,170,150,150,150,120,150,120,230,120
};

void play(int numero){
  Serial.begin(115200);
  // randomSeed(analogRead(0));
  // int numero = random(13);
  Serial.println(numero);

  int arrSize = 0;
  switch(numero){
    case 0:
      arrSize = sizeof(starfox) / sizeof(starfox[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[0] * starfox[thisNote][1];tone(9, starfox[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 1:
      arrSize = sizeof(mario) / sizeof(mario[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[1] * mario[thisNote][1];tone(9, mario[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 2:
      arrSize = sizeof(kirby) / sizeof(kirby[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[2] * kirby[thisNote][1];tone(9, kirby[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 3:
      arrSize = sizeof(finalfantasy) / sizeof(finalfantasy[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[3] * finalfantasy[thisNote][1];tone(9, finalfantasy[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 4:
      arrSize = sizeof(fallguys) / sizeof(fallguys[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[4] * fallguys[thisNote][1];tone(9, fallguys[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 5:
      arrSize = sizeof(zelda) / sizeof(zelda[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[5] * zelda[thisNote][1];tone(9, zelda[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 6:
    //   arrSize = sizeof(smash) / sizeof(smash[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[6] * smash[thisNote][1];tone(9, smash[thisNote][0], noteDuration);double pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 7:
      arrSize = sizeof(yoshi) / sizeof(yoshi[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[7] * yoshi[thisNote][1];tone(9, yoshi[thisNote][0], noteDuration);double pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 8:
      arrSize = sizeof(metroid) / sizeof(metroid[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[8] * metroid[thisNote][1];tone(9, metroid[thisNote][0], noteDuration);double pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 9:
      arrSize = sizeof(fireemblem) / sizeof(fireemblem[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[9] * fireemblem[thisNote][1];tone(9, fireemblem[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    case 10:
    //   arrSize = sizeof(duckhunt) / sizeof(duckhunt[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[10] * duckhunt[thisNote][1];tone(9, duckhunt[thisNote][0], noteDuration);double pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);Serial.println("Duracion: ");Serial.println(noteDuration);}
      break;
    case 11:
    //   arrSize = sizeof(kingkrool) / sizeof(kingkrool[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[11] * kingkrool[thisNote][1];tone(9, kingkrool[thisNote][0], noteDuration);double pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);Serial.println("Duracion: ");Serial.println(noteDuration);}
      break;
    case 12:
      arrSize = sizeof(dragonquest) / sizeof(dragonquest[0]);for(int thisNote = 0; thisNote < arrSize; thisNote++){double noteDuration = 60000 / BPM[12] * dragonquest[thisNote][1];tone(9, mario[thisNote][0], noteDuration);int pauseBetweenNotes = noteDuration * 1.05;delay(pauseBetweenNotes);noTone(8);}
      break;
    default:
      break;
  };
}