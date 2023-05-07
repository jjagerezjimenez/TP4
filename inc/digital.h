#ifndef DIGITAL_H
#define DIGITAL_H             //Buscar referencia del digital de los videos (hueco clases 11 y 12)


typedef struct DigitalInput *  DigitalInput_pt;
typedef struct DigitalOutput * DigitalOutput_pt;


DigitalInput_pt DigitalInput_Create(uint8_t port, uint8_t pin, bool inverted);  //eror uint_8


bool DigitalInput_GetState(DigitalInput_pt input);


bool DigitalInput_HasChange(DigitalInput_pt input);


bool DigitalInput_HasActivate(DigitalInput_pt input);


bool DigitalInput_HasDesactivate(DigitalInput_pt input);


DigitalOutput_pt DigitalOutput_Create(uint8_t port, uint8_t pin);


void DigitalOutput_Activate(DigitalOutput_pt input);


void DigitalOutput_Desactivate(DigitalOutput_pt input);


void DigitalOutput_Toggle(DigitalOutput_pt input);


#endif