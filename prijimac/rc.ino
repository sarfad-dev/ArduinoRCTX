//prijimac
#include <RCSwitch.h>

RCSwitch prijimac = RCSwitch();

void setup() {

  Serial.begin(9600);
  prijimac.setProtocol(2);
  prijimac.enableReceive(0);
}

void loop() {
  if (prijimac.available()) {
    int velikost = prijimac.getReceivedValue();
    if (velikost == 0) {

    } else {
      Serial.print(prijimac.getReceivedValue()) / 10;
      Serial.print(" ");
      Serial.print(prijimac.getReceivedBitlength());
      Serial.println();
      prijimac.resetAvailable();
  }
}
}
