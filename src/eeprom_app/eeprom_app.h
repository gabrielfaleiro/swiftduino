
#ifndef EEPROM_APP_H_
#define EEPROM_APP_H_

#include <Arduino.h>
#include <EEPROM.h>

class EepromApp{
public:
  // Constructor
  EepromApp(uint16_t mem_size);
  EepromApp();

  uint16_t getMaxHumidity();
  void     setMaxHumidity(uint16_t val);
  uint16_t getMinHumidity();
  void     setMinHumidity(uint16_t val);

private:
  uint16_t _mem_size; // bytes. Up to 4096

  uint16_t _max_humidity_addr;
  uint16_t _min_humidity_addr;

  void _setAddresses();

  void _writeVal(uint16_t addr, uint8_t val);
  void _writeVal(uint16_t addr, uint16_t val);
  void _writeVal(uint16_t addr, uint32_t val);
  void _writeVal(uint16_t addr, uint64_t val);

  uint8_t  _readUint8(uint16_t address);
  uint16_t _readUint16(uint16_t address);
  uint32_t _readUint32(uint16_t address);
  uint64_t _readUint64(uint16_t address);
};

#endif // EEPROM_APP_H_