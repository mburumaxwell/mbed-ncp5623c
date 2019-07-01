#include "ncp5623c_def.h"
#include "NCP5623CDriver.h"
#include "mbed_debug.h"

#define DEBUG_ERR_WRITE(res, reg)  debug_if(res, "NCP5623C write 0x%02X failed with result %ld\r\n", reg, res)
#define DEBUG_ERR_READ(res, reg)   debug_if(res, "NCP5623C read 0x%02X failed with result %ld\r\n", reg, res)

int32_t NCP5623CDriver::write_reg(uint8_t addr, uint8_t value)
{
    int ret = 0;

	// the first 3MSB are for the address, the last 5LSB are for the value
	char val = (addr & 0xE0) | (value & 0x1F);
    
    ret = i2c_driver->write(dev_addr, &val, 1);
    DEBUG_ERR_WRITE(ret, (addr & 0xE0));
    
	return ret;
}

int32_t NCP5623CDriver::shutdown (void) {
	return write_reg(NCP5623C_REG_SHUTDOWN, 0);
}

int32_t NCP5623CDriver::set_brightness (uint8_t value) {
	// ignore the value for now because it is function of current being consumed hence battery drain.
	
	return write_reg(NCP5623C_REG_CURRENT, 0x01); //0.92mA
}

int32_t NCP5623CDriver::set_red (uint8_t value) {
	return write_reg(NCP5623C_REG_PWM1, value);
}

int32_t NCP5623CDriver::set_green (uint8_t value) {
	return write_reg(NCP5623C_REG_PWM2, value);
}

int32_t NCP5623CDriver::set_blue (uint8_t value) {
	return write_reg(NCP5623C_REG_PWM3, value);
}

int32_t NCP5623CDriver::set_rgb (uint8_t red, uint8_t green, uint8_t blue) {
	int32_t ret;
	
	ret = set_red(red);
	if (ret == 0) {
		ret = set_green(green);
		if (ret == 0) {
			ret = set_blue(blue);
		}
	}
	
	return ret;
}

int32_t NCP5623CDriver::set_argb (uint32_t hex) {
	uint8_t brightness, red, green, blue;
	int32_t ret;
	
	brightness = (uint8_t)(hex >> 24);
	red = (uint8_t)(hex >> 16);
	green = (uint8_t)(hex >> 8);
	blue = (uint8_t)(hex);
	
	ret = set_brightness(brightness);
	if (ret == 0) {
		ret = set_rgb(red, green, blue);
	}
	
	return ret;
}