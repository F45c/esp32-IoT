# Esp32-IoT-Sensors

An Esp32 packed with sensors for IoT use. It uses the Esp32-C3-Mini-1 module that includes an antenna and it receives data from lots of sensors like heart rate, temperature, flame detector and much more.

#### These are the Sensors:

> DHT11
> - Temperature & Humidity
> 
> BMP280
> - Barometer & Air Pressure
> 
> AHT20
> - Temperature & Air Humidity
> 
> MQ-135
> - Air Quality & Gas detection
> 
> MPU-6050
> - Accelerometer & Gyro
> 
> HC-SR501
> - Motion Sensor
> 
> DS18B20
> - Temperature
> 
> MAX30102
> - Heart Rate & Oxigen Saturation
> 
> IR Flame Detector
> 
> Light Dependent Resistor

### Finished Build
I finished the PCB assembly. Since I'm a beginner, I was struggling a lot with the tiny solder joints. The most annoying parts to solder were definitely the BMP280 and the USB-C connector because the pins are so tiny and are easily bridged. Soldering the LEDs failed a few times because I would test them before for polarity check and while picking the up with the tweezers, they would move and I accidentally soldered them wrong a few times.

Originally, I would have unsoldered the MQ-135 gas sensor and solder it to my pcb, but I wasn't able to because of how to module is designed so I stuck the pins that are sticking out of the bottom of the board into my pcb and it fits.

I spaced everything tightly in the design and now that I built it, I find it hard to fully reach the Heart Rate sensor (2nd image bottom right), but since the Motion sensor is unpluggable, you can still use it.

<img src="https://github.com/F45c/esp32-IoT/blob/c4b29bcfaed27663d53e99ef803f32e0583bb4c3/images/pcb_assembled1.png" width=40%>

<img src="https://github.com/F45c/esp32-IoT/blob/c4b29bcfaed27663d53e99ef803f32e0583bb4c3/images/pcb_assembled2.png" width=40%>

![Here you can find the Demo Video](https://github.com/F45c/esp32-IoT/blob/1337bfd01edbffe72ce3f5e00ffe7f1ed57a7687/demo_video.mp4)

## Why am I making this?

I'm building this sensor board for a presentation of mine about Internet of Things.
This will help me demonstrate the practical application of Esp32 Chips, low energy sensors and Telemetry using different Protocols like MQTT. The many different sensors will come in handy when the crowd can try their newly learned skills on programming this device. That's why I designed it very openly and you can clearly see how all the components are connected (when you unplug the motion sensor from the pin sockets)

## Design

I carefully checked that every sensor is in the right place and its functionality won't be blocked by other components (e.g. LDR, IR LED, ...). If you don't like the huge motion detector in the center, you can just unplug it because it's connected via Pin Sockets.

There are two trimmer for controlling the sensitivity of the gas sensor and flame detector respectively.

![3D Model of PCB](https://github.com/F45c/esp32-IoT/blob/fbed3bfc5218fe83a78dfc8c5ae1e6ccfdde8883/images/3d_pcb.png)

### PCB

The important points to mention in the PCB Design are the two Ground Planes which fill up all unused space on the front and back layers. Though, the space below the esp32's pcb antenna needs to be copper-free allowing the antenna to work without being blocked / the signal reflected.

![PCB Design](https://github.com/F45c/esp32-IoT/blob/fbed3bfc5218fe83a78dfc8c5ae1e6ccfdde8883/images/pcb.png)

### Schematic

![Schematic Design](https://github.com/F45c/esp32-IoT/blob/fbed3bfc5218fe83a78dfc8c5ae1e6ccfdde8883/images/schematic.png)

### BOM
|Name|Purpose|Quantity|Total Cost (USD)|Link|Distributor|
|----|------|---|------|------------|-----------|
|PCB|PCB board|1|5.5||JLCPCB|
|HC-SR501|Motion sensor|1|4.05|https://www.amazon.com/-/de/dp/B09LVJ4DZX|Amazon|
|MQ-135|Gas Sensor|1|4.99|https://www.amazon.com/dp/B0GSRWSLB1|Amazon|

Everything else is in the PCBA BOM
