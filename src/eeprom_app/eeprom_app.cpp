
// REF:
// https://blog.hirnschall.net/esp8266-eeprom/

#include "eeprom_app.h"

/* /////////////////////////////////////////////////////////////////
    Application functions

    These functions are the ones that the main code will use
    Extend and modify only these functions

*/ /////////////////////////////////////////////////////////////////

uint16_t EepromApp::getMaxHumidity(){
  return _readUint16(_max_humidity_addr);
}
void     EepromApp::setMaxHumidity(uint16_t val){
  _writeVal(_max_humidity_addr, val);
}
uint16_t EepromApp::getMinHumidity(){
  return _readUint16(_min_humidity_addr);
}
void     EepromApp::setMinHumidity(uint16_t val){
  _writeVal(_min_humidity_addr, val);
}

void EepromApp::_setAddresses() {
  _max_humidity_addr = 0;
  _min_humidity_addr = 2;
}

/* /////////////////////////////////////////////////////////////////
    Constructors
*/ /////////////////////////////////////////////////////////////////

EepromApp::EepromApp(uint16_t mem_size) {
  _mem_size = mem_size;
  EEPROM.begin(_mem_size);

  _setAddresses();
}

EepromApp::EepromApp() {
  _mem_size = 256;
  EEPROM.begin(_mem_size);

  _setAddresses();
}

/* /////////////////////////////////////////////////////////////////
    Internal functions
*/ /////////////////////////////////////////////////////////////////

void EepromApp::_writeVal(uint16_t addr, uint8_t val){
  if (_readUint8(addr) != val){
    EEPROM.put(addr, val);
    EEPROM.commit();
  }
}
void EepromApp::_writeVal(uint16_t addr, uint16_t val){
  if (_readUint16(addr) != val){
    EEPROM.put(addr, val);
    EEPROM.commit();
  }
}
void EepromApp::_writeVal(uint16_t addr, uint32_t val){
  if (_readUint32(addr) != val){
    EEPROM.put(addr, val);
    EEPROM.commit();
  }
}
void EepromApp::_writeVal(uint16_t addr, uint64_t val){
  if (_readUint64(addr) != val){
    EEPROM.put(addr, val);
    EEPROM.commit();
  }
}

uint8_t  EepromApp::_readUint8(uint16_t address){
  uint8_t val = 0;
  EEPROM.get(address, val);
  return val;
}
uint16_t EepromApp::_readUint16(uint16_t address){
  uint16_t val = 0;
  EEPROM.get(address, val);
  return val;
}
uint32_t EepromApp::_readUint32(uint16_t address){
  uint32_t val = 0;
  EEPROM.get(address, val);
  return val;
}
uint64_t EepromApp::_readUint64(uint16_t address){
  uint64_t val = 0;
  EEPROM.get(address, val);
  return val;
}
