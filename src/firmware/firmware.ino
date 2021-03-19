//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#include <Stepper.h>
const int stepsScale = 2400;
Stepper stepper = Stepper(stepsScale, 18,19,22,23);
int noSteps=1;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  String str = SerialBT.readString();
  if (str == "go") {
    stepper1.step(4.4 * stepsScale / noSteps);
    delay(500);
  }
  else {
    noSteps = (str.substring(0, str.length() - 1)).toInt();
  }
  stepper.step(stepsScale/noSteps);
}
