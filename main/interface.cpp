#include "interface.h"

LedInterface::LedInterface(byte pin) {
  this->pin = pin;
  init();
}

void LedInterface::init() {
  pinMode(pin, OUTPUT);
  off();
}

void LedInterface::on() {
  digitalWrite(pin, HIGH);
}

void LedInterface::off() {
  digitalWrite(pin, LOW);
}

String LedInterface::handleTrainerMessage(){
  String res = "OK";
  return res;
}

String LedInterface::callTrainer(){
  String id = "";
  Serial.begin(115200);
	UniqueIDdump(Serial);
	for (size_t i = 0; i < UniqueIDsize; i++)
	{
		if (UniqueID[i] < 0x10)
			id = id + "0";
		id = id + String(UniqueID[i], HEX);
		id = id + " ";
	}
  return id + " need help!";
}