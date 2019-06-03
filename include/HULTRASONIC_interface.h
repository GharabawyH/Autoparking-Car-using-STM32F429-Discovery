#ifndef _HULTRASONIC_interface_h
#define _HULTRASONIC_interface_h

#define TRIGGER   
#define ECHO

void HULTRASONIC1_voidInitialize(void);
void HULTRASONIC1_SendTrigger(void);
void HULTRASONIC2_SendTrigger(void);
void HULTRASONIC3_SendTrigger(void);
void HULTRASONIC4_SendTrigger(void);
void HULTRASONIC5_SendTrigger(void);

f64 HULTRASONIC_CalculateDistance(void);

#endif
