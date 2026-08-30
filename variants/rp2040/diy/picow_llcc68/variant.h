// Raspberry Pi Pico W + SX1262-class LoRa module + GEPRC GEP-M10-DI. Header pin -> GP (Pico numbering):
// 4=GP2 SCK, 5=GP3 MOSI, 6=GP4 MISO, 7=GP5 NSS, 8=GND, 9=GP6 RST, 10=GP7 BUSY, 11=GP8 DIO1, 21=GP16 GNSS RX<-TX,
// 22=GP17 GNSS TX->RX, 24=GP18 SDA, 25=GP19 SCL, 36=3V3. RP2040 fixed functions: SPI0 on GP2/3/4, UART0 on GP16/17,
// I2C1 on GP18/19 (hence Wire1).
#define ARDUINO_ARCH_AVR

#ifndef HAS_WIFI
#define HAS_WIFI 1
#endif
#define HAS_SCREEN 0

#define LED_POWER PIN_LED
#define EXT_NOTIFY_OUT 22

#define BATTERY_PIN 26
#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic (Pico VSYS divider R17/R18)
#define BATTERY_SENSE_RESOLUTION_BITS ADC_RESOLUTION

// GEP-M10-DI GNSS on UART0 (Serial1): Pico TX GP16 -> module RX, module TX -> Pico RX GP17
#define HAS_GPS 1
#define GPS_TX_PIN 16
#define GPS_RX_PIN 17
#define GPS_BAUDRATE 115200

// GEP-M10-DI I2C (DPS310 @0x76) on I2C1 = Wire1
#define I2C_SDA1 18
#define I2C_SCL1 19
// arduino-pico's default Wire (I2C0) pins are GP4/GP5 = our LoRa MISO/NSS; Wire.begin() there kills the radio (init -2).
// Park Wire on the free I2C0 pins GP20/21 (header 26/27).
#define I2C_SDA 20
#define I2C_SCL 21

// LoRa on SPI0 (no HW_SPI1_DEVICE): same SX1262-class module family as the other nodes
#define USE_SX1262
#define USE_LLCC68
#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS
#define LORA_SCK 2
#define LORA_MOSI 3
#define LORA_MISO 4
#define LORA_CS 5
#define LORA_DIO0 RADIOLIB_NC
#define LORA_RESET 6
#define LORA_DIO1 8 // IRQ
#define LORA_DIO2 7 // BUSY
#define LORA_DIO3 RADIOLIB_NC
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL
