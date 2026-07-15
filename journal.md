# Soldering the PCB

_Time Spent: 1.5h_

I started with the USB connectors because they were the toughest to solder because of the tiny pins. For the Micro USB Type B, I used a normal soldering iron and it worked all right since the pins are bigger than from the USB C. That's why I used a hot air gun with solder paste for this one and had to fix a few bridging pins and because I already have some experience soldering the USB-C connector from another project, it worked a little faster this time.

After that, I tried soldering the Esp32 C3 Mini 1 module with a heat gun and solder paste which I re-did multiple times because I was never sure that all pins are really connected to their pads. This was definitely one of the difficult parts on the PCB.

Then, I made my way over to the smaller components.

Starting with the BMP280 sensor which was difficult to solder. The chip itself is so tiny, I couldn't see if the pins were connected. The AHT20 and MAX30102 went a little better since they're bigger. All the other components also didn't hold me back a lot, for the LEDs, I just had to check polarity and solder them in the right way. Since I couldn't unsolder the gas sensor from its module, I just plugged it in like that and it should work the same because all the pins are still correct. At the end, I supplied the board with power and measured the capacitors and checked the LEDs and everything worked!

<img src="https://github.com/F45c/esp32-IoT/blob/c4b29bcfaed27663d53e99ef803f32e0583bb4c3/images/pcb_assembled1.png" width=50% />
