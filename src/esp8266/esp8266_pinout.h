
// PINOUT
// https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

#ifndef ESP8266_PINOUT_H_
#define ESP8266_PINOUT_H_

#define PIN_GPIO_0   (0)
#define PIN_GPIO_1   (1)
#define PIN_GPIO_2   (2)
#define PIN_GPIO_3   (3)
#define PIN_GPIO_4   (4)
#define PIN_GPIO_5   (5)
#define PIN_GPIO_12  (12)
#define PIN_GPIO_13  (13)
#define PIN_GPIO_14  (14)
#define PIN_GPIO_15  (15)
#define PIN_GPIO_16  (16)

static const uint8_t D0    = PIN_GPIO_16;
static const uint8_t D1    = PIN_GPIO_5;
static const uint8_t D2    = PIN_GPIO_4;
static const uint8_t D3    = PIN_GPIO_0;
static const uint8_t D4    = PIN_GPIO_2;
static const uint8_t D5    = PIN_GPIO_14;
static const uint8_t D6    = PIN_GPIO_12;
static const uint8_t D7    = PIN_GPIO_13;
static const uint8_t D8    = PIN_GPIO_15;
static const uint8_t RX    = PIN_GPIO_3;
static const uint8_t TX    = PIN_GPIO_1;

#endif // ESP8266_PINOUT_H_