/*
 *
 *    Created on : Dec 14, 2021
 *        Author : Chanil
 *
 */

#ifndef CAN_STRUCTURE_H
#define CAN_STRUCTURE_H

#include <stdint.h>

/* MOTOR STATUS WORD */
#define STATUS_READY_TO_SWITCH_ON			0
#define STATUS_SWITCHED_ON					1
#define STATUS_OPERATION_ENABLED			2
#define STATUS_FAULT						3
#define STATUS_VOLTAGE_ENABLED				4
#define STATUS_QUICK_STOP					5
#define STATUS_SWITCH_ON_DISABLED			6
#define STATUS_WARNING						7
#define STATUS_REMOTE						9
#define STATUS_OPERATING_MODE_SPECIFIC		10
#define STATUS_INTERNAL_LIMIT_ACTIVE		11
/* END MOTOR STATUS WORD */

/* MOTOR CONTROL WORD */
#define CONTROL_SWITCHED_ON					0
#define CONTROL_ENABLE_VOLTAGE				1
#define CONTROL_QUICK_STOP					2
#define CONTROL_ENABLE_OPERATION			3
/* END MOTOR CONTROL WORD */

/* MODE OF OPERATION */
#define CURRENT_MODE						1
#define POSITION_MODE						2
#define VELOCITY_MODE						3
#define HOMING_MODE							4
/* END MODE OF OPERATION */

typedef struct
{
	int32_t digitalInput;
	int32_t AnalogInput;
	uint8_t statusword;
	int8_t modoeOfOperation;
	int32_t actualPosition;
	int32_t actualVelocity;
	int16_t actualCurrent;
	int32_t absolutActualPosition;
	int16_t actualIMUroll;
	int16_t actualIMUpitch;
	int16_t actualIMUyaw;
	int16_t actualIMUpx;
	int16_t actualIMUpy;
	int16_t actualIMUpz;
}MotorDriverInput;

typedef struct
{
	int32_t digitalOutput;
	int32_t analogOutput;
	int16_t controlword;
	int32_t targetPosition;
	int32_t targetVelocity;
	int16_t targetCurrent;
}MotorDriverOutput;
#endif /* CAN_STRUCTURE_H */