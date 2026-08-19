// Waveshare ESP32-P4-WIFI6 with hand-wired LoRa on header pins 4-11, GNSS on 21/22, and I2C on 24/25.
// Avoid board-reserved SDIO, UART0, TF, audio, and strapping pins.

#define HAS_SCREEN 0

// GEP-M10-DI GNSS (u-blox M10050) on UART1: the P4 receives on 47, transmits on 48
#define HAS_GPS 1
#define GPS_RX_PIN 47
#define GPS_TX_PIN 48
#define GPS_BAUDRATE 115200

// GEP-M10-DI I2C: DPS310 baro/temp @0x76 (IST8310 mag @0x0E is not supported by the firmware)
#define I2C_SDA 46
#define I2C_SCL 33

// BOOT button
#define BUTTON_PIN 35

// LoRa: same SX1262-class module family as the XIAO C6 node (probe order SX1262/TCXO -> SX1262/XTAL -> LLCC68)
#define USE_SX1262
#define USE_LLCC68
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL
#define LORA_SCK 31
// The shared Pico W harness fixes MOSI on header pin 5 and MISO on pin 6;
// the P4 GPIO matrix follows that wiring.
#define LORA_MOSI 30 // header pin 5
#define LORA_MISO 29 // header pin 6
#define LORA_CS 28
#define LORA_RESET 50
#define SX126X_CS LORA_CS
#define SX126X_DIO1 5
#define SX126X_BUSY 49
#define SX126X_RESET LORA_RESET
#define SX126X_DIO2_AS_RF_SWITCH
