# RGB LED MATRIX P5 (64x32)

## Specs

**Size:** 320x160mm = 51200mm² = 0,0512m²
<br>
**Voltage:** 5V  
**Max Wattage:** 800W/m² = 40,96W ~ 40W  
**Avg Wattage:** 500W/m² = 25,6W ~ 25W  
**Max Power:** 40 / 5 = 8A  
**Avg Power:** 25 / 5 = 5A

## Pins

| RGB Matrix | ESP8266 | Description                                                                         |
|------------|---------|-------------------------------------------------------------------------------------|
| <span style="color:lightgreen">R1</span>         | D3      | Red channel of upper LEDs                                                         |
| <span style="color:yellow">B1</span>         | D5      | Blue channel of upper LEDs                                                        |
| <span style="color:orange">R2</span>         | D6      | Red channel of lower LEDs                                                         |
| <span style="color:red">B2</span>         | D8      | Blue channel of lower LEDs                                                        |
| <span style="color:brown">A</span>          | -      | Current row (bit1)                                                                           |
| <span style="color:black">C</span>          | -       | Current row (bit3)                                                                               |
| <span style="color:white">CLK</span>       | D0      | Marks the arrival of each bit of data.                                            |
| <span style="color:grey">OE</span>         | -      | Output Enable: Switches the LEDs off when transitioning from one row to the next. |

<br>

| RGB Matrix | ESP8266 | Description                           |
|------------|---------|---------------------------------------|
| <span style="color:orange">G1</span>         | D4      | Green channel of upper LEDs           |
| <span style="color:red">GND</span>        | GND     | Ground                                |
| <span style="color:brown">G2</span>         | D7      | Green channel of lower LEDs           |
| <span style="color:black">GND</span>        | GND     | Ground                                |
| <span style="color:white">B</span>          | -      | Current row (bit2)                                  |
| <span style="color:grey">D</span>          | -       | Current row (bit4)                                  |
| <span style="color:purple">LAT</span>        | -      | Latch: Marks the end of a row of data. |
| <span style="color:darkblue">GND</span>        | GND     | Ground                                |

## A,B,C,D,LAT
 Since the ESP8266 only has a limited amount of GPIO pins we need to use a shift register or I2C IO extender.

# SN74HC595 (Shift Register)

## Pins

<img src="sn74hc595 2.PNG"/>

| SN74HC595 | ESP8266 | Description               |
|-----------|---------|---------------------------|
| SER       | D1      | Data pin                  |
| RCLK      | D2      | Controls transfer of data |
| SRCLK     | GPIO9   | Clock                     |
| OE        | GND     | Output Enable             |

Note: Use `board_flash_mode = dio` option for platformIO.  
**GPIO9 may not be available as GPIO pin your board. In this case use the I2C IO extender.**

## Shift Pins

| SN74HC595 | RGB MATRIX |
|-----------|---------|
| QB        | A       |
| QC        | B       |
| QD        | C       |
| QE        | D       |
| QF        | LAT     |