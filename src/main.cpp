#include <Arduino.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include "Nextion.h"

#define CHECKED true
#define NOT_CHECKED false
#define OFF LOW
#define ON HIGH

/*Page 0*/
const int P_24 = 24;
const int P_25 = 25;
const int P_26 = 26;
const int P_27 = 27;
const int P_28 = 28;
const int P_29 = 29;
const int P_39 = 39;
const int P_30 = 30;

/*Page 1*/
const int P_31 = 31;
const int P_32 = 32;
const int P_33 = 33;
const int P_34 = 34;
const int P_35 = 35;
const int P_36 = 36;
const int P_23 = 23;
const int P_22 = 22;

/*Page 1 - Status Checkbox*/
bool statusP31 = NOT_CHECKED;
bool statusP32 = NOT_CHECKED;
bool statusP33 = NOT_CHECKED;
bool statusP34 = NOT_CHECKED;
bool statusP35 = NOT_CHECKED;
bool statusP36 = NOT_CHECKED;
bool statusP23 = NOT_CHECKED;
bool statusP22 = NOT_CHECKED;

/*Page 0*/
NexButton buttonP24 = NexButton(0, 2, "buttonP24");
NexButton buttonP25 = NexButton(0, 3, "buttonP25");
NexButton buttonP26 = NexButton(0, 4, "buttonP26");
NexButton buttonP27 = NexButton(0, 5, "buttonP27");
NexButton buttonP28 = NexButton(0, 6, "buttonP28");
NexButton buttonP29 = NexButton(0, 7, "buttonP29");
NexButton buttonP39 = NexButton(0, 8, "buttonP39");
NexButton buttonP30 = NexButton(0, 9, "buttonP30");

/*Page 1*/
NexCheckbox checkboxP31 = NexCheckbox(1, 2, "cP31");
NexCheckbox checkboxP32 = NexCheckbox(1, 4, "cP32");
NexCheckbox checkboxP33 = NexCheckbox(1, 5, "cP33");
NexCheckbox checkboxP34 = NexCheckbox(1, 3, "cP34");
NexCheckbox checkboxP35 = NexCheckbox(1, 9, "cP35");
NexCheckbox checkboxP36 = NexCheckbox(1, 10, "cP36");
NexCheckbox checkboxP23 = NexCheckbox(1, 11, "cP23");
NexCheckbox checkboxP22 = NexCheckbox(1, 12, "cP22");

NexTouch *nex_listen_list[] = {
  /*Page 0*/
  &buttonP24,
  &buttonP25,
  &buttonP26,
  &buttonP27,
  &buttonP28,
  &buttonP29,
  &buttonP39,
  &buttonP30,
  /*Page 1*/
  &checkboxP31,
  &checkboxP32,
  &checkboxP33,
  &checkboxP34,
  &checkboxP35,
  &checkboxP36,
  &checkboxP23,
  &checkboxP22,
  NULL
};

/*Page 0*/
void buttonP24PopCallback(void *ptr) {
  digitalWrite(P_24, LOW);
}

void buttonP24PushCallback(void *ptr) {
  digitalWrite(P_24, HIGH);
}

void buttonP25PopCallback(void *ptr) {
  digitalWrite(P_25, LOW);
}

void buttonP25PushCallback(void *ptr) {
  digitalWrite(P_25, HIGH);
}

void buttonP26PopCallback(void *ptr) {
  digitalWrite(P_26, LOW);
}

void buttonP26PushCallback(void *ptr) {
  digitalWrite(P_26, HIGH);
}

void buttonP27PopCallback(void *ptr) {
  digitalWrite(P_27, LOW);
}

void buttonP27PushCallback(void *ptr) {
  digitalWrite(P_27, HIGH);
}

void buttonP28PopCallback(void *ptr) {
  digitalWrite(P_28, LOW);
}

void buttonP28PushCallback(void *ptr) {
  digitalWrite(P_28, HIGH);
}

void buttonP29PopCallback(void *ptr) {
  digitalWrite(P_29, LOW);
}

void buttonP29PushCallback(void *ptr) {
  digitalWrite(P_29, HIGH);
}

void buttonP39PopCallback(void *ptr) {
  digitalWrite(P_39, LOW);
}

void buttonP39PushCallback(void *ptr) {
  digitalWrite(P_39, HIGH);
}

void buttonP30PopCallback(void *ptr) {
  digitalWrite(P_30, LOW);
}

void buttonP30PushCallback(void *ptr) {
  digitalWrite(P_30, HIGH);
}

/*Page 1*/
void checkStatus(bool status, int PIN) {
  if(status == CHECKED) {
    digitalWrite(PIN, ON);
  } else {
    digitalWrite(PIN, OFF);
  }
}

void checkStatusAllCheckbox() {
  checkStatus(statusP31, P_31);
  checkStatus(statusP32, P_32);
  checkStatus(statusP33, P_33);
  checkStatus(statusP34, P_34);
  checkStatus(statusP35, P_35);
  checkStatus(statusP36, P_36);
  checkStatus(statusP23, P_23);
  checkStatus(statusP22, P_22);
}

void changeStatusAndExecute(bool * status, int PIN) {
  *status = !*status;
  if(*status) {
    digitalWrite(PIN, ON);
  }

  if(!*status) {
    digitalWrite(PIN, OFF);
  }
}

void checkboxP31PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP31, P_31);
}

void checkboxP32PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP32, P_32);
}

void checkboxP33PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP33, P_33);
}

void checkboxP34PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP34, P_34);
}

void checkboxP35PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP35, P_35);
}

void checkboxP36PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP36, P_36);
}

void checkboxP23PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP23, P_23);
}

void checkboxP22PopCallback(void *ptr) {
  changeStatusAndExecute(&statusP22, P_22);
}

void setup(void) {    
  Serial1.begin(9600);
  nexInit();

  /*Page 0*/
  buttonP24.attachPop(buttonP24PopCallback, &buttonP24);
  buttonP24.attachPush(buttonP24PushCallback, &buttonP24);

  buttonP25.attachPop(buttonP25PopCallback, &buttonP25);
  buttonP25.attachPush(buttonP25PushCallback, &buttonP25);

  buttonP26.attachPop(buttonP26PopCallback, &buttonP26);
  buttonP26.attachPush(buttonP26PushCallback, &buttonP26);

  buttonP27.attachPop(buttonP27PopCallback, &buttonP27);
  buttonP27.attachPush(buttonP27PushCallback, &buttonP27);

  buttonP28.attachPop(buttonP28PopCallback, &buttonP28);
  buttonP28.attachPush(buttonP28PushCallback, &buttonP28);

  buttonP29.attachPop(buttonP29PopCallback, &buttonP29);
  buttonP29.attachPush(buttonP29PushCallback, &buttonP29);

  buttonP39.attachPop(buttonP39PopCallback, &buttonP39);
  buttonP39.attachPush(buttonP39PushCallback, &buttonP39);

  buttonP30.attachPop(buttonP30PopCallback, &buttonP30);
  buttonP30.attachPush(buttonP30PushCallback, &buttonP30);

  /*Page 1*/
  checkboxP31.attachPop(checkboxP31PopCallback, &checkboxP31);
  checkboxP32.attachPop(checkboxP32PopCallback, &checkboxP32);
  checkboxP33.attachPop(checkboxP33PopCallback, &checkboxP33);
  checkboxP34.attachPop(checkboxP34PopCallback, &checkboxP34);
  checkboxP35.attachPop(checkboxP35PopCallback, &checkboxP35);
  checkboxP36.attachPop(checkboxP36PopCallback, &checkboxP36);
  checkboxP23.attachPop(checkboxP23PopCallback, &checkboxP23);
  checkboxP22.attachPop(checkboxP22PopCallback, &checkboxP22);

  /*Page 0*/
  pinMode(P_24, OUTPUT);
  pinMode(P_25, OUTPUT);
  pinMode(P_26, OUTPUT);
  pinMode(P_27, OUTPUT);
  pinMode(P_28, OUTPUT);
  pinMode(P_29, OUTPUT);
  pinMode(P_39, OUTPUT);
  pinMode(P_30, OUTPUT);

  /*Page 1*/
  pinMode(P_31, OUTPUT);
  pinMode(P_32, OUTPUT);
  pinMode(P_33, OUTPUT);
  pinMode(P_34, OUTPUT);
  pinMode(P_35, OUTPUT);
  pinMode(P_36, OUTPUT);
  pinMode(P_23, OUTPUT);
  pinMode(P_22, OUTPUT);
  checkStatusAllCheckbox();
  digitalWrite(P_23, ON);
  digitalWrite(P_22, ON);
}

void loop(void) {
  nexLoop(nex_listen_list);
}