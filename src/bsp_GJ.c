#include "bsp_GJ.h"

static struct board_s board ={0};

board_t BoardCreate(void){

    Chip_SCU_PinMuxSet(LED_R_PORT, LED_R_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_R_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, true);

    Chip_SCU_PinMuxSet(LED_G_PORT, LED_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_G_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, true);

    Chip_SCU_PinMuxSet(LED_B_PORT, LED_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_B_FUNC);

    board.Led_azul=DigitalOutput_Create(LED_B_GPIO, LED_B_BIT);



    Chip_SCU_PinMuxSet(LED_1_PORT, LED_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_1_FUNC);
    
    board.Led_amarillo=DigitalOutput_Create(LED_1_GPIO, LED_1_BIT);     //cambio?



    Chip_SCU_PinMuxSet(LED_2_PORT, LED_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_2_FUNC);

    board.Led_rojo=DigitalOutput_Create(LED_2_GPIO, LED_2_BIT);    //cambio?



    Chip_SCU_PinMuxSet(LED_3_PORT, LED_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_3_FUNC);

    board.Led_verde=DigitalOutput_Create(LED_3_GPIO,LED_3_BIT);

//******
    Chip_SCU_PinMuxSet(TEC_1_PORT, TEC_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_1_FUNC);
    board.boton_prueba=DigitalInput_Create(TEC_1_GPIO,1,TEC_1_BIT);                                 //1-> Logica invertida, 0 lo contrario, consultar y ver los otros 3 casos



    Chip_SCU_PinMuxSet(TEC_2_PORT, TEC_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_2_FUNC);
    board.boton_cambiar=DigitalInput_Create(TEC_2_GPIO,1, TEC_2_BIT);



    Chip_SCU_PinMuxSet(TEC_3_PORT, TEC_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_3_FUNC);
    board.boton_prender=DigitalInput_Create(TEC_3_GPIO,1, TEC_3_BIT);



    Chip_SCU_PinMuxSet(TEC_4_PORT, TEC_4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_4_FUNC);
    board.boton_apagar=DigitalInput_Create(TEC_4_GPIO,1,TEC_4_BIT);







    return &board;
}