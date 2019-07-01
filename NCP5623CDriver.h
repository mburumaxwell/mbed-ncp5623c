#ifndef __NCP5623C_DRIVER_H
#define __NCP5623C_DRIVER_H
#include <mbed.h>

class NCP5623CDriver {
public:
    NCP5623CDriver(I2C *driver, int32_t addr = 0x72)
    {
        this->i2c_driver = driver;
        this->dev_addr = addr;
    }

    int32_t shutdown (void);
    int32_t set_brightness(uint8_t value);
    int32_t set_red(uint8_t value);
    int32_t set_green(uint8_t value);
    int32_t set_blue(uint8_t value);
    int32_t set_rgb(uint8_t red, uint8_t green, uint8_t blue);
    int32_t set_argb(uint32_t value);
    
private:
    I2C *i2c_driver;
    int32_t dev_addr;
    int32_t write_reg(uint8_t addr, uint8_t value);
};

#endif /* __NCP5623C_DRIVER_H */