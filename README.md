# PIC18F4550 USART Serial Communication Example

## 💡 Overview

This project demonstrates using the USART (Universal Synchronous Asynchronous Receiver Transmitter) of the PIC18F4550 microcontroller to send a simple `"HELLO"` string to a virtual terminal via serial communication.

---

## 🛠️ Hardware Requirements

* Microcontroller: **PIC18F4550**
* USB-UART converter or virtual terminal (Proteus)
* Optional: PC terminal software (e.g., Tera Term, PuTTY)

### 🔌 Connections

* TX (Transmit) → Virtual terminal RXD
* Ground → Virtual terminal GND

---

## 🗺️ Circuit Diagram

*(Add your circuit diagram image here if available)*

---

## 💻 Software Requirements

* Compiler: **MPLAB XC8** (or compatible)
* Simulator: **Proteus Design Suite**
* Header file: `<xc.h>`

---

## ⚙️ How It Works

* USART is configured in **asynchronous mode** for serial transmission.
* Baud rate generator value (**SPBRG**) is set for **9600 baud** with **Fosc = 20 MHz** (value: `129`).
* Characters of the message `"HELLO"` are sent one by one via `TXREG`.
* The virtual terminal receives and displays the string.

---

## 🧑‍💻 Code

```c
#include <xc.h>

void main(void) {

    TRISC = 0x80;   // RC7 (RX) input, RC6 (TX) output
    TXSTA = 0x24;   // TX enable, BRGH = 1 (high speed)
    RCSTA = 0x90;   // Serial port enable, continuous receive enable
    SPBRG = 129;    // Baud rate 9600 for 20 MHz clock

    char msg[] = "HELLO";
    int i = 0;

    while(msg[i] != '\0') {
        while(!TXIF);   // Wait until transmit buffer is empty
        TXREG = msg[i];
        i++;
    }

    while(1);
}
```

---

## ⚖️ Baud Rate Calculation

The baud rate is calculated using:

```
Baud Rate = Fosc / (16 * (SPBRG + 1))
```

For:

* `Fosc = 20 MHz`
* `Baud = 9600`

```
SPBRG = (Fosc / (16 * Baud)) - 1
SPBRG = (20,000,000 / (16 * 9600)) - 1 ≈ 129
```

---

## 🪜 Steps to Build & Simulate

1. Write the code in **MPLAB IDE** and compile using XC8.
2. Generate and load the `.hex` file into **Proteus** simulation.
3. Connect **RC6 (TX)** pin to virtual terminal **RXD** in Proteus.
4. Start simulation; `"HELLO"` will be displayed on the virtual terminal.
5. *(Optional)* Connect to a real PC terminal using a USB-UART converter for hardware testing.

---

## ⚠️ Notes

* Baud rate configuration depends on crystal frequency. Adjust `SPBRG` if using a different clock.
* No receive functionality is implemented here; only transmission.
* RC6 (TX) must be set as output, RC7 (RX) as input.

---

## 📄 License

This project is shared for **educational purposes only**. Unauthorized reproduction or distribution is prohibited.

---

## 🙏 Acknowledgments

Designed and simulated using **Proteus** with a PIC18F4550 development setup.

---

## 📚 Resources

* PIC18F4550 Datasheet
* Proteus Design Suite
