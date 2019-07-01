#ifndef __NCP5623C_H
#define __NCP5623C_H

#ifdef __cplusplus
extern "C" {
#endif

#define NCP5623C_REG_SHUTDOWN   ((uint8_t)0x00)
#define NCP5623C_REG_CURRENT    ((uint8_t)0x20)
#define NCP5623C_REG_PWM1       ((uint8_t)0x40)
#define NCP5623C_REG_PWM2       ((uint8_t)0x60)
#define NCP5623C_REG_PWM3       ((uint8_t)0x80)
#define NCP5623C_REG_UPWARD     ((uint8_t)0xA0)
#define NCP5623C_REG_DOWNWARD   ((uint8_t)0xC0)
#define NCP5623C_REG_GRAD       ((uint8_t)0xE0)

#ifdef __cplusplus
}
#endif

#endif /* __NCP5623C_H */
