# Command Engine Example
This is the example project on how to use the commands engine (terminal) with PIC32.

## Setting up
You need a MCU with at least 14K bytes flash for this project without optimization. You can lower this down to 6.5K by removing the default commands clear, and help.

###Software
Clone this project and in the same folder clone the https://github.com/phaetto/Commands repository.
Then compile with MPLAB X.
Add 2 tsp. of awesomeness and you are good to go.

###Hardware
You will need a FTDI USB to UART cable to test on hardware.
The default connection parameters are (defined in user.h/user.c):
* Baud rate: 9600, data bits: 8, stop bit: 1, parity: none, flow: none
* UART2 pins are used

When you connect, you should see a prompt by pressing enter ('$>' by default).
Press 'help' to see the services, commands and applications available.

Go to commands.c to add your own commands or customize the existing ones.

The software is provided under The MIT License.
