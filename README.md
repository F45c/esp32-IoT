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

![3D Model of PCB](https://github.com/F45c/esp32-IoT/blob/5c1764f8c9ce926280e4762f08e09c0a4af0f980/images/3d_pcb.png)

### PCB

The important points to mention in the PCB Design are the two Ground Planes which fill up all unused space on the front and back layers. Though, the space below the esp32's pcb antenna needs to be copper-free allowing the antenna to work without being blocked / the signal reflected.

![PCB Design](https://github.com/F45c/esp32-IoT/blob/5c1764f8c9ce926280e4762f08e09c0a4af0f980/images/pcb.png)

### Schematic

![Schematic Design](https://github.com/F45c/esp32-IoT/blob/5c1764f8c9ce926280e4762f08e09c0a4af0f980/images/schematic.png)


