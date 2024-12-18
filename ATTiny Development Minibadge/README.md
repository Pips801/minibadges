# ATtiny816 DEVBOARD
## Images
<img src="https://github.com/user-attachments/assets/08d73bf7-969f-488b-956e-efea55961474" height="200"><img src="https://github.com/user-attachments/assets/602e61fd-3275-40b5-b0be-b451f2613107" height="200"><img src="https://github.com/user-attachments/assets/3c6f5981-bbbd-4e7f-b78d-93d94c71777b" height="200"><img src="https://github.com/user-attachments/assets/4a3eb651-b174-4794-853f-94a5c92e95b5" height="200"><img src="https://github.com/user-attachments/assets/06d58bd1-e008-406e-b622-fba6eeb20f30" height="200"><img src="https://github.com/user-attachments/assets/dca33db4-9784-4bc0-88f5-30bcdb845505" height="200">
## Description
ATTiny-816 Minibadge Devboard with breakouts for USART, I2C, DAC, and SPI, as well as two LEDs. There is also support for two ADC (analog to digital conversion) inputs and two PTC (touch sense) pins. It is programmed using UPDI via pin 6 (PROG4).
## Assembly
Solder top and bottom pin rows. Solder wires directly to pin holes, or use your own pin headers or sockets.
## Setup and code
By default, the ATTiny Devboard will come with some default code flashed (which is in this repository) that will blink PIPS WAS HERE in morse code. To flash, you will need a cheapo $7 UPDI programmer. I use the [Adafruit UPDI friend](https://www.adafruit.com/product/5879). Download the MegaTinyCore library for Arduino and set it up, selecting the 816. Write your code, consulting the circuit diagram for specific pins. I recommend referencing the pins by their chip pinout name, rather than number. Example: `PIN_PB2` (for LEDs)

In the Arduino IDE, make the following changes
* Programmer: SerialUPDI - SLOW 57600 Baud
* Chip: ATtiny816
* Clock: 10Mhz Internal
You should then be able to do Sketch -> Upload Using Programmer 
