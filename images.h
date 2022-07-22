#define CLOUD_WIDTH 48
#define CLOUD_HEIGHT 48
#define SUN_WIDTH 48
#define SUN_HEIGHT 48

const unsigned char cloud_rain_icon [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x18, 0x04, 0x00, 0x00, 0x00, 0x3F, 0x7E, 0x1F, 0x00, 
  0x00, 0xC0, 0xFF, 0xFF, 0x33, 0x00, 0x00, 0xE0, 0xEF, 0x01, 0x31, 0x00, 
  0x00, 0xF0, 0x80, 0x03, 0x22, 0x00, 0x00, 0x78, 0x80, 0x7F, 0x60, 0x00, 
  0x00, 0x38, 0x00, 0xFF, 0xE0, 0x03, 0x00, 0x1C, 0x00, 0xC7, 0xE0, 0x03, 
  0x00, 0x1C, 0x00, 0x80, 0x21, 0x07, 0x00, 0x1C, 0x00, 0x80, 0x01, 0x06, 
  0x00, 0x1C, 0x00, 0x80, 0x0F, 0x06, 0x00, 0x1F, 0x00, 0x80, 0x1F, 0x06, 
  0x80, 0x3F, 0x00, 0x00, 0x18, 0x03, 0xC0, 0x3F, 0x00, 0x00, 0xB0, 0x03, 
  0xC0, 0x01, 0x00, 0x00, 0x70, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xF0, 0x01, 
  0xE0, 0x00, 0x00, 0x00, 0xE0, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x03, 
  0xE0, 0x00, 0x20, 0x00, 0x00, 0x03, 0xE0, 0x01, 0x31, 0x00, 0x80, 0x03, 
  0xC0, 0x83, 0x7F, 0x01, 0xEC, 0x03, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 
  0x00, 0xFE, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xE0, 0x00, 0xB0, 0x06, 0x00, 
  0x00, 0x00, 0x00, 0x30, 0x02, 0x00, 0x00, 0x06, 0x40, 0x10, 0x00, 0x00, 
  0x00, 0x06, 0x60, 0x00, 0x00, 0x00, 0x00, 0x07, 0x63, 0xC0, 0x00, 0x00, 
  0x00, 0x83, 0x23, 0x60, 0x00, 0x00, 0x00, 0x80, 0x01, 0x62, 0x00, 0x00, 
  0x00, 0x80, 0x00, 0x63, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 
  0x00, 0x06, 0x80, 0x11, 0x00, 0x00, 0x00, 0x07, 0x08, 0x18, 0x00, 0x00, 
  0x00, 0x03, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x62, 0x04, 0x0C, 0x00, 0x00, 
  0x00, 0x30, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x30, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x01, 0x02, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x07, 0x00, 0x00, 
  0x00, 0xC0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char sun_icon [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x04, 0x80, 0x01, 0x20, 0x00, 
  0x00, 0x0E, 0x80, 0x01, 0x70, 0x00, 0x00, 0x1C, 0x80, 0x01, 0x38, 0x00, 
  0x00, 0x38, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x70, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x60, 0xC0, 0x01, 0x06, 0x00, 0x00, 0x40, 0xF8, 0x1F, 0x02, 0x00, 
  0x00, 0x00, 0x7C, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x80, 0x03, 0xC0, 0x01, 0x00, 
  0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 
  0x00, 0xC0, 0x01, 0x80, 0x03, 0x00, 0xF0, 0xC7, 0x00, 0x00, 0xF3, 0x0F, 
  0xF0, 0xCF, 0x00, 0x00, 0xE3, 0x0F, 0x00, 0xC0, 0x01, 0x80, 0x03, 0x00, 
  0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 
  0x00, 0x80, 0x03, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 
  0x00, 0x00, 0x0E, 0x70, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3E, 0x00, 0x00, 
  0x00, 0x40, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x60, 0x80, 0x03, 0x07, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x38, 0x00, 0x00, 0x1C, 0x00, 
  0x00, 0x1C, 0x80, 0x01, 0x38, 0x00, 0x00, 0x0E, 0x80, 0x01, 0x70, 0x00, 
  0x00, 0x04, 0x80, 0x01, 0x20, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};