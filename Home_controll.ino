*/Smart home controll with app developed by shourove Sharma Contact: 01777152541


#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial btdevice;
String btdata = "null";
const int leda = 12;
const int ledb = 13;
const int ledc = 14;
const int ledd = 27;
const int ac = 15;
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

int pwm = 0;


void setup() {
  pinMode (leda, OUTPUT);
  pinMode (ledb, OUTPUT);
  pinMode (ledc, OUTPUT);
  pinMode (ledd, OUTPUT);
  digitalWrite (leda, HIGH);
  digitalWrite (ledb, HIGH);
  digitalWrite (ledc, HIGH);
  digitalWrite (ledd, HIGH);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ac, ledChannel);
  btdevice.begin("IOT Squad");
}

void loop() {
if (btdevice.available()) {
  btdata= btdevice.read();
  }
  delay(100);
  controll();
}




int controll(){
  if(btdata == "LIGHT ON"){
    digitalWrite (leda, LOW);
  }
  else if(btdata == "LIGHT OFF"){
    digitalWrite (leda, HIGH);
  }
  else if(btdata == "WIFI ON"){
    digitalWrite (ledb, LOW);
  }
  else if(btdata == "WIFI OFF"){
     digitalWrite (ledb, HIGH);
  }
  else if(btdata == "TV ON"){
     digitalWrite (ledc, LOW);
  }
  else if(btdata == "TV OFF"){
     digitalWrite (ledc, HIGH);
  }
  else if(btdata == "AIR ON"){
     digitalWrite (ledd, LOW);
  }
  else if(btdata == "AIR OFF"){
      digitalWrite (ledd, LOW);
  }

//AC Speed Controll

  if(btdata == "FAN OFF" || btdata == "FAN OFFFAN OFF"){
    pwm=0;
  }
  else if(btdata == "ONE"){
    pwm=25;
  }
  else if(btdata == "TWO"){
    pwm=50;
  }
  else if(btdata == "THREE"){
    pwm=75;
  }
  else if(btdata == "FOUR"){
    pwm=100;
  }
  else if(btdata == "FIVE"){
    pwm=125;
  }
  else if(btdata == "SIX"){
    pwm=150;
  }
  else if(btdata == "SEVEN"){
    pwm=175;
  }
  else if(btdata == "EIGHT"){
    pwm=200;
  }
  else if(btdata == "NINE"){
    pwm=225;
  }
  else if(btdata == "TEN"){
    pwm=250;
  }
ledcWrite(ledChannel, pwm);
}