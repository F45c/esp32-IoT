#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <AHT20.h>
#include <DHT11.h>
#include <DallasTemperature.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "DevLab_MAX30102.h"
#include "heartRate.h"

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#define DS18B20 7

AHT20 aht20;
Adafruit_BMP280 bmp;
DHT11 dht11(6);
OneWire oneWire(DS18B20);
DallasTemperature sensors(&oneWire);
Adafruit_MPU6050 mpu;
DevLab_MAX30102 particleSensor;

const byte RATE_SIZE = 4;
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0;
float beatsPerMinute;
int beatAvg;

void setup() {
  unsigned status;
  status = bmp.begin();

  if (!status) Serial.println("BMP280 not connected correctly");

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);

  Wire.begin();
  if (aht20.begin() == false) Serial.println("AHT20 not connected correctly");

  sensors.begin();

  if (!mpu.begin()) Serial.println("MPU6050 not connected correctly");

  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);


  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) Serial.println("MAX30102 not connected correctly");

  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x0A);
  particleSensor.setPulseAmplitudeGreen(0);
}

void measureHeartRate() {
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute;
      rateSpot %= RATE_SIZE;

      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);

  if (irValue < 50000)
    Serial.print(" No finger?");

  Serial.println();
}

void loop() {
  Serial.println("BMP280");
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude(1013.25));
  Serial.println(" m");



  Serial.println("AHT20");
  Serial.print("T: ");
  Serial.print(aht20.getTemperature(), 2);
  Serial.print(" C\t H: ");
  Serial.print(aht20.getHumidity(), 2);
  Serial.println("% RH");


  int temperature = 0;
  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else Serial.println(DHT11::getErrorString(result));

  sensors.requestTemperatures();
  Serial.print("DS18B20: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" °C");

  Serial.print("LDR reading: ");
  Serial.println(analogRead(2));

  Serial.print("IR Flame Detector reading: ");
  Serial.println(analogRead(3));

  Serial.print("Gas Sensor reading: ");
  Serial.println(analogRead(5));


  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");


  Serial.print(" R[");
  Serial.print(particleSensor.getRed());
  Serial.print("] IR[");
  Serial.print(particleSensor.getIR());
  Serial.print("] G[");
  Serial.print(particleSensor.getGreen());
  Serial.println("]");


}
