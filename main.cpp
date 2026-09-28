#include <Arduino.h>
#include <ESP32CAN.h>
#include <CAN_config.h>

/* the variable name CAN_cfg is fixed, do not change */
CAN_device_t CAN_cfg;

int limit = 2000;


void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAN TX");
    /* set CAN pins and baudrate */
    CAN_cfg.speed=CAN_SPEED_100KBPS;
    CAN_cfg.tx_pin_id = GPIO_NUM_21;
    CAN_cfg.rx_pin_id = GPIO_NUM_22;
    pinMode(34, INPUT);
    //initialize CAN Module
    ESP32Can.CANInit();
}

void loop() {
  int temperature = analogRead(34);
  
  printf("%d\n", temperature);
  CAN_frame_t tx_frame;
  tx_frame.FIR.B.FF = CAN_frame_std;
  tx_frame.FIR.B.RTR = CAN_no_RTR;
  tx_frame.MsgID = 1;
  tx_frame.FIR.B.DLC = 1;
  
  if (temperature > limit) {
    tx_frame.MsgID = 1;
    tx_frame.FIR.B.DLC = 1;
    tx_frame.data.u8[0] = 1;
  }
  else {
    tx_frame.MsgID = 2;
    tx_frame.FIR.B.DLC = 1;
    tx_frame.data.u8[0] = 0;
  }

  int ret_code = ESP32Can.CANWriteFrame(&tx_frame);
  delay(2000);
}
