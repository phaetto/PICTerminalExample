/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#include "../Commands/commands.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void InitApp(void)
{
    // Configure UART modules
    UARTConfigure(UART_CMD_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART_CMD_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART_CMD_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART_CMD_MODULE_ID, GetPeripheralClock(), DESIRED_CMD_BAUDRATE);
    UARTEnable(UART_CMD_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // Configure UART Interrupts
    INTEnable(INT_SOURCE_UART_RX(UART_CMD_MODULE_ID), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART_CMD_MODULE_ID), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART_CMD_MODULE_ID), INT_SUB_PRIORITY_LEVEL_0);
}

void WriteString(const char *string)
{
    while(*string != '\0')
    {
        while(!UARTTransmitterIsReady(UART_CMD_MODULE_ID));
        UARTSendDataByte(UART_CMD_MODULE_ID, *string);
        string++;
        while(!UARTTransmissionHasCompleted(UART_CMD_MODULE_ID));
    }
}

void PutCharacter(const char character)
{
    while(!UARTTransmitterIsReady(UART_CMD_MODULE_ID));
    UARTSendDataByte(UART_CMD_MODULE_ID, character);
    while(!UARTTransmissionHasCompleted(UART_CMD_MODULE_ID));
}
