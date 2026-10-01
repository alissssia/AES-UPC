#include <Arduino.h>
#include <ESP32CAN.h>
#include <CAN_config.h>

/* the variable name CAN_cfg is fixed, do not change */
CAN_device_t CAN_cfg;

// counter value
uint8_t counter = 1;


void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAN TX");
    /* set CAN pins and baudrate */
    CAN_cfg.speed=CAN_SPEED_100KBPS;
    CAN_cfg.tx_pin_id = GPIO_NUM_21;
    CAN_cfg.rx_pin_id = GPIO_NUM_22;
    //initialize CAN Module
    ESP32Can.CANInit();
}

void sendMessageOne() {
  CAN_frame_t counter_value_frame;
  counter_value_frame.FIR.B.FF = CAN_frame_std;
  counter_value_frame.FIR.B.RTR = CAN_no_RTR;
  counter_value_frame.MsgID = 1;
  counter_value_frame.FIR.B.DLC = 1;
  counter_value_frame.data.u8[0] = counter;

  int ret_code = ESP32Can.CANWriteFrame(&counter_value_frame);
  printf("Transmitting CAN counter value frame. Return code: ");
  printf("%d\n",ret_code);
}

void sendMessageTwo() {
  CAN_frame_t all0_frame;
  all0_frame.FIR.B.FF = CAN_frame_std;
  all0_frame.FIR.B.RTR = CAN_no_RTR;
  all0_frame.MsgID = 2;
  all0_frame.FIR.B.DLC = 6;
  all0_frame.data.u8[0] = 0;
  all0_frame.data.u8[1] = 0;
  all0_frame.data.u8[2] = 0;
  all0_frame.data.u8[3] = 0;
  all0_frame.data.u8[4] = 0;
  all0_frame.data.u8[5] = 0;

  int ret_code = ESP32Can.CANWriteFrame(&all0_frame);
  printf("Transmitting CAN all 0s frame. Return code: ");
  printf("%d\n",ret_code);
}

void sendMessageThree() {
  CAN_frame_t nothing_frame;
  nothing_frame.FIR.B.FF = CAN_frame_std;
  nothing_frame.FIR.B.RTR = CAN_RTR;
  nothing_frame.MsgID = 3;
  nothing_frame.FIR.B.DLC = 4;

  int ret_code = ESP32Can.CANWriteFrame(&nothing_frame);
  printf("Transmitting CAN nothing frame. Return code: ");
  printf("%d\n",ret_code);
}

void loop() {
  
 
  
  /*CAN_frame_t tx_frame;
  tx_frame.FIR.B.FF = CAN_frame_std;
  tx_frame.FIR.B.RTR = CAN_no_RTR;
  tx_frame.MsgID = 1;
  tx_frame.FIR.B.DLC = 8;
  tx_frame.data.u8[0] = 'F';
  tx_frame.data.u8[1] = 'r';
  tx_frame.data.u8[2] = 'a';
  tx_frame.data.u8[3] = 'm';
  tx_frame.data.u8[4] = 'e';
  tx_frame.data.u8[5] = '_';
  tx_frame.data.u8[6] = '_';
  tx_frame.data.u8[7] = '1';

  int ret_code = ESP32Can.CANWriteFrame(&tx_frame);
  printf("Transmitting CAN frame. Return code: ");
  printf("%d\n",ret_code);*/


  switch (counter % 3) {
    case 0:
      sendMessageThree();
      break;
    case 1:
      sendMessageOne();
      break;
    case 2:
      sendMessageTwo();
      break;
    default:
      break;
  }
  
  delay(2000);
  counter++;

}
