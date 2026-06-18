
```c
#include <xc.h>

void main(void) {

    TRISC = 0x80;   // RC7 (RX) input, RC6 (TX) output
    TXSTA = 0x24;   // TX enable, BRGH = 1 (high speed)
    RCSTA = 0x90;   // Serial port enable, continuous receive enable
    SPBRG = 129;    // Baud rate 9600 for 20 MHz clock

    char *message = "HELLO";
    char i = 0;

    while (message[i] != '\0') {
        TXREG = message[i];        // Load character into TX register
        while (TXIF == 0);         // Wait for transmit interrupt flag
        TXIF = 0;                  // Clear flag (done automatically in hardware)
        i++;
    }

    while (1);  // Infinite loop to keep MCU running
}
```

