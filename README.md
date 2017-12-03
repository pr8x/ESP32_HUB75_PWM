## P5 RGB Panel (64x32)

**Size:** 320x160mm = 51200mm² = 0,0512m²
<br>
**Voltage:** 5V  
**Max Wattage:** 800W/m² = 40,96W ~ 40W  
**Avg Wattage:** 500W/m² = 25,6W ~ 25W  
**Max Power:** 40 / 5 = 8A  
**Avg Power:** 25 / 5 = 5A

## Pinout

| RGB Matrix | Description                                                                         |
|------------|-------------------------------------------------------------------------------------|
| R1         | Red channel of upper LEDs                                                         |
| B1         | Blue channel of upper LEDs                                                        |
| R2         | Red channel of lower LEDs                                                         |
| B2         | Blue channel of lower LEDs                                                        |
| A          | Current row (bit1)                                                                |
| C          | Current row (bit3)                                                                |
| CLK        | Marks the arrival of each bit of data.                                            |
| OE         | Output Enable: Switches the LEDs off when transitioning from one row to the next. |

<br>

| RGB Matrix | Description                           |
|------------|---------------------------------------|
| G1         | Green channel of upper LEDs           |
| GND        | Ground                                |
| G2         | Green channel of lower LEDs           |
| GND        | Ground                                |
| B          | Current row (bit2)                    |
| D          | Current row (bit4)                    |
| LAT        | Latch: Marks the end of a row of data.|
| GND        | Ground                                |
