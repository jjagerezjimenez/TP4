#ifndef BSP_H
#define BSP_H

#include "digital.h"

typedef struct board_s {

    DigitalOutput_t Led_azul;
    DigitalOutput_t Led_rojo;
    DigitalOutput_t Led_amarillo;
    DigitalOutput_t Led_verde;

    DigitalInput_t  boton_prueba;
    DigitalInput_t  boton_cambiar;
    DigitalInput_t  boton_prender;
    DigitalInput_t  boton_apagar;

} const * const board_pt;


board_pt BoardptCreate(void);

#endif