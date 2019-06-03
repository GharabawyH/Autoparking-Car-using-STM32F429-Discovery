#ifndef _HMOTOR_interface_h
#define _HMOTOR_interface_h
#define HMOTOR_Forward  0
#define HMOTOR_Backward   1
#define HMOTOR_LEFT       2
#define HMOTOR_RIGHT      3
#define HMOTOR_LEFT_HALFSPEED 13000
#define HMOTOR_LEFT_FULLSPEED 14100
#define HMOTOR_RIGHT_HALFSPEED 15800
#define HMOTOR_RIGHT_FULLSPEED 18000
void HMOTOR_voidInitialize(void);
void HMOTOR_voidRotation(u8 Dir,u16 speed);
#endif
