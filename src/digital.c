#include <stdbool.h>
#include <stdio.h>			// controlar
#include <stdint.h>
#include "digital.h"

#define INSTANCES 4		//ver 4

struct DigitalInput {
    uint8_t port;
    uint8_t pin;
    bool    inverted;
    bool    last_state;
    bool    ocupado;
};

struct DigitalOutput {
    uint8_t port;
    uint8_t pin;
    bool    ocupado;
};


static struct DigitalInput  Input[INSTANCES]  = {0};
static struct DigitalOutput Output[INSTANCES] = {0};


DigitalInput_t DigitalInput_Create(uint8_t port, uint8_t pin, bool inverted) {
    uint8_t posicion = 0;

    for (int i = 0; (i < INSTANCES) & (posicion == 0); i++) {

        if (Input[i].ocupado == false)
            posicion = i;
    }
    DigitalInput_t input = &Input[posicion];
    input->port           = port;
    input->pin            = pin;
    input->inverted       = inverted;
    input->ocupado        = true;

    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, port, pin, false);

    return input;
}


bool DigitalInput_GetState(DigitalInput_t input) {

    if (input->inverted == 0)

        return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, input->port, input->pin);
    else
        return !(Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, input->port, input->pin));		//el profesor formulo esto distinto, controlar
}


bool DigitalInput_HasChange(DigitalInput_t input) {

    bool current_state = DigitalInput_GetState(input);
    bool resultado;

    if (current_state != input->last_state)
        resultado = true;
    else
        resultado = false;
    input->last_state = current_state;
    return resultado;
}


bool DigitalInput_HasActivate(DigitalInput_t input) {

    bool current_state = DigitalInput_GetState(input);
    bool resultado;

    if ((0 == input->last_state) & (1 == current_state))
        resultado = true;
    else
        resultado = false;
    input->last_state = current_state;
    return resultado;
}


bool DigitalInput_HasDesactivate(DigitalInput_t input) {

    bool current_state = DigitalInput_GetState(input);
    bool resultado;

    if ((1 == input->last_state) & (0 == current_state))
        resultado = true;
    else
        resultado = false;
    input->last_state = current_state;
    return resultado;
}



//Salidas // Ver


DigitalOutput_t DigitalOutput_Create(uint8_t port, uint8_t pin) {

    uint8_t posicion = 0;

    for (int i = 0; (i < INSTANCES) & (posicion == 0); i++) {

        if (Output[i].ocupado == false)
            posicion = i;
    }

    DigitalOutput_t output = &Output[posicion];
    output->port            = port;
    output->pin             = pin;
    output->ocupado         = true;

    Chip_GPIO_SetPinState(LPC_GPIO_PORT, port, pin, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, port, pin, true);

    return output;
}


void DigitalOutput_Activate(DigitalOutput_t output) {		//output?
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->port, output->pin, true);
}


void DigitalOutput_Desactivate(DigitalOutput_t output) {
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->port, output->pin, false);
}


void DigitalOutput_Toggle(DigitalOutput_t output) {
    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->port, output->pin);
}