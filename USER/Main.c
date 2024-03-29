/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2019/10/15
 * Description        : Main program body.
 *******************************************************************************/
#include "debug.h"
#include "string.h"

/* Global define */

/*******************************************************************************
 * Function Name  : GPIO_Toggle_INIT
 * Description    : Initializes GPIOA.0
 * Input          : None
 * Return         : None
 *******************************************************************************/
void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************************************************
 * Function Name  : main
 * Description    : Main program.
 * Input          : None
 * Return         : None
 *******************************************************************************/
int main()
{
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x8005000);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    GPIO_Toggle_INIT();
    printf("Start @Chip_ID:%08x\r\n", DBGMCU->IDCODE);
    printf("GPIO Toggle TEST\r\n");

    while (1)
    {
        Delay_Ms(250);
        PAout(0) ^= (1 << 0);
    }
}
