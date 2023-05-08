#ifndef DIGITAL_H
#define DIGITAL_H             //Buscar referencia del digital de los videos (hueco clases 11 y 12)

#include <stdint.h>

typedef struct DigitalInput *  DigitalInput_t;
typedef struct DigitalOutput * DigitalOutput_t;


DigitalInput_t DigitalInput_Create(uint8_t port, uint8_t pin, bool inverted);  //eror uint_8


bool DigitalInput_GetState(DigitalInput_t input);


bool DigitalInput_HasChange(DigitalInput_t input);


bool DigitalInput_HasActivate(DigitalInput_t input);


bool DigitalInput_HasDesactivate(DigitalInput_t input);


DigitalOutput_t DigitalOutput_Create(uint8_t port, uint8_t pin);


void DigitalOutput_Activate(DigitalOutput_t input);


void DigitalOutput_Desactivate(DigitalOutput_t input);


void DigitalOutput_Toggle(DigitalOutput_t input);


#endif