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

| Designator | Footprint | Qty | Value | LCSC Part # |
|---|---|---|---|---|
| C1, C10, C12, C14, C15, C16, C17, C2, C4, C5, C6, C9 | 0603 | 12 | 100nF | |
| C11, C13 | 0603 | 2 | 1uF | |
| C3 | 0603 | 1 | 10uF | |
| C7 | 0603 | 1 | 2.2nF | |
| C8 | 0603 | 1 | 10nF | |
| D2, GAS-LED | 0603 | 2 | LED | |
| DS18B20 | TO-92_Inline | 1 | DS18B20 | |
| FEUER-LED | LED_D3.0mm | 1 | IR Sensor | |
| HC-SR501 | HC-SR501 | 1 | Motion Sensor | |
| J1 | AMPHENOL_GMSB0532112YEU | 1 | GMSB0532112YEU | |
| J8 | GCT_USB4215-03-A_REVA | 1 | USB4215-03-A_REVA | |
| LDR | R_LDR_5.1x4.3mm_P3.4mm_Vertical | 1 | LDR07 | |
| MAX30102 | Maxim_OLGA-14_3.3x5.6mm_P0.8mm | 1 | MAX30102 | |
| MPU-6050 | InvenSense_QFN-24_4x4mm_P0.5mm | 1 | MPU-6050 | |
| MQ-135 | MQ-6 | 1 | MQ-135 | |
| R1 | 0603 | 1 | 5kΩ | |
| R11 | 0603 | 1 | 33kΩ | |
| R12, R3, R7, R8 | 0603 | 4 | 10kΩ | |
| R13, R9 | 0603 | 2 | 100Ω | |
| R14, R15 | 0603 | 2 | 22Ω | |
| R4 | 0603 | 1 | 330Ω | |
| R5, R6 | 0603 | 2 | 2k–4.7kΩ | |
| RV1, RV2 | Potentiometer_Bourns_3296W_Vertical | 2 | 10k Pot | |
| U1 | ESP32-C3-MINI-1 | 1 | ESP32-C3-MINI-1 | |
| U10, U11 | SOIC127P600X265-8N | 2 | LM393 | |
| U2 | Aosong_DHT11_5.5x12.0_P2.54mm | 1 | DHT11 | |
| U4 | PSON100P300X300X110-6N | 1 | AHT20 | |
| U5 | Bosch_LGA-8_2x2.5mm_P0.65mm_ClockwisePinNumbering | 1 | BMP280 | |
| U8 | SOT95P255X145-3N | 1 | MCP1702T-3302E/CB | MCP1702T-3302E/CB |
