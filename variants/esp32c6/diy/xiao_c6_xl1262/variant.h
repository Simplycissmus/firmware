// Seeed XIAO ESP32-C6 + XL1262 (SX1262-class) LoRa module, hand-wired on the D0..D7 header:
//   D0=GPIO0 NSS, D1=GPIO1 SCK, D2=GPIO2 MOSI, D3=GPIO21 MISO, D4=GPIO22 RST, D5=GPIO23 BUSY, D6=GPIO16 DIO1,
//   D7=GPIO17 DIO3 (not used by the firmware). Same map as the raw-SPI bring-up sketch next to this repo.

// Headless, GPS-less node (fixed or app-set position only)
#define HAS_SCREEN 0
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// I2C on D8/D9 for the BMP388 — NEVER on the Arduino-core defaults GPIO22/23 (= LORA_RESET/BUSY: the boot-time
// Wire.begin() + scan would toggle the radio's reset/busy lines). Explicit I2C_SDA keeps Wire off those pins.
#define HAS_WIRE 1
#define I2C_NO_RESCAN
#define I2C_SDA 19 // D8 (owner: green wire = SCL on D9; if the sensor stays silent, swap the two wires at the sensor)
#define I2C_SCL 20 // D9

// Yellow user LED (active-low) and the BOOT button
#define LED_POWER 15
#define LED_STATE_ON 0
#define BUTTON_PIN 9

// LoRa: SX126x-class module of uncertain identity ("XL1262"). src/mesh/RadioInterface.cpp probes in this order:
// SX1262 (DIO3 TCXO 1.8 V) -> SX1262 (crystal) -> LLCC68 (crystal). A die reporting "SX1261" (SX1261/SX1262)
// gets the SX1262 driver with the full SF5-12 range; a die reporting "LLCC68" falls back to the LLCC68 driver.
#define USE_SX1262
#define USE_LLCC68
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL
#define LORA_SCK 1
#define LORA_MISO 21
#define LORA_MOSI 2
#define LORA_CS 0
#define LORA_RESET 22
#define SX126X_CS LORA_CS
#define SX126X_DIO1 16
#define SX126X_BUSY 23
#define SX126X_RESET LORA_RESET
#define SX126X_DIO2_AS_RF_SWITCH

// ESP32-C6 has only Serial0/Serial1; the SerialModule needs the second port
#define SERIAL_PRINT_PORT 1
