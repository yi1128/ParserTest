#include <stdint.h>

#pragma once
/* Define */
/* ROBOT SETTING STATUS */
#define JOINT_PARAMETER_SET 		0
#define JOINT_TRAJECTORY_SET 		1
#define CARTESIAN_PARAMETER_SET 	2
#define CARTESIAN_TRAJECTORY_SET 	3
#define JOINT_TARGET_SET 			4
#define CARTESIAN_TARGET_SET 		5
#define SERVER_SYSTEM_DAYA 			6
#define NONE 						7

/* COMMUNICATION STATUS */
#define REGISTRATION 				0
#define REGISTRATION_COMPLETE		1
#define SERVO_ON					2
#define SERVO_ON_COMPLETE			3
#define TUNING_STATE 				4
#define TUNING_STATE_COMPLETE		5
#define HOMING 						6
#define HOMING_COMPLETE 			7
#define FREE_STATE					8

/* CONTROL MODE */
#define NONE_MODE					0
#define GRAVITY_MODE 				1
#define JOINT_MODE 					2
#define CARTESIAN_MODE 				3
#define GRAVITY_WITH_JOINT_MODE		4
#define GRAVITY_WITH_CARTESIAN_MODE 5
/* End Define */

#define JOINT_AXIS 4
#define CARTESIAN_AXIS 3

/* Structure */
/* COMMUNICATION STRUCTURE */
#pragma pack(push,1)
typedef struct MsgState
{
	uint8_t packetType[2];
	uint16_t commState;
	uint16_t payloadSize;
	uint8_t controlMode;
};

typedef struct AxisServerData
{
	float actualMotorPosition[JOINT_AXIS];
	float actualMotorVelocity[JOINT_AXIS];
	float actualLinkPosition[JOINT_AXIS];
	float actualLinkVelocity[JOINT_AXIS];
	float actualCurrent[JOINT_AXIS];
	float targetPosition[JOINT_AXIS];
	float targetCurrent[JOINT_AXIS];
	int32_t modeOfOperation[JOINT_AXIS];
	int32_t statusword[JOINT_AXIS];
}Axis;

typedef struct ServerSystemData
{
	int32_t cnt;
	int32_t logCnt;
	int32_t gravityMode;
	int32_t targetReached;
	// Cartesian Position Info;
	float cartesianTargetPose[CARTESIAN_AXIS];
	float cartesianCurrentPose[CARTESIAN_AXIS];
	// Cartesian Trajectory Info
	float targetTrajectoryTime[CARTESIAN_AXIS];
	float targetTrajectoryAcc[CARTESIAN_AXIS];
	// Module Data (Motor Driver)
	Axis moduleData;
};

typedef struct JointParameterSettingStruct
{
	float jointPositionPgain[JOINT_AXIS];
	float jointPositionIgain[JOINT_AXIS];
	float jointPositionDgain[JOINT_AXIS];

	float jointTorquePgain[JOINT_AXIS];
	float jointTorqueIgain[JOINT_AXIS];
	float jointTorqueDgain[JOINT_AXIS];

	float jointConstantEfficiency[JOINT_AXIS];
	float jointConstantTorque[JOINT_AXIS];
	float jointConstantSpring[JOINT_AXIS];

	float jointGravityGain[JOINT_AXIS];
	float jointCurrentGain[JOINT_AXIS];
	float jointFrictionGain[JOINT_AXIS];
};

typedef struct JointTrajectorySetStruct
{
	float JointTrajecotryTime[JOINT_AXIS];
	float JointTrajectoryAcc[JOINT_AXIS];
};

typedef struct CartesianParameterSettingStruct
{
	float cartesianPositionPgain[CARTESIAN_AXIS];
	float cartesianPositionIgain[CARTESIAN_AXIS];
	float cartesianPositionDgain[CARTESIAN_AXIS];
};

typedef struct CartesianTrajectorySetStruct
{
	float cartesianTrajectoryTime[CARTESIAN_AXIS];
	float cartesianTrajectoryAcc[CARTESIAN_AXIS];
};

typedef struct JointTargetStruct
{
	float jointTarget[JOINT_AXIS];
};

typedef struct CartesianTargetStruct
{
	float pX;
	float pY;
	float pZ;
	float rX;
	float rY;
	float rZ;
};
#pragma pack(pop)
/* End Structure */
