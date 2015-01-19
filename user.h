
#include "system.h"

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

#define	GetPeripheralClock()		(SYS_FREQ/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(SYS_FREQ)

#define UART_CMD_MODULE_ID              UART2
#define DESIRED_CMD_BAUDRATE            (9600)

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

void InitApp(void);         /* I/O and Peripheral Initialization */

void WriteString(const char *string);
void PutCharacter(const char character);
