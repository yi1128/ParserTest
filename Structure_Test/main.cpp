#include "ethernet_structure.h"
#include "ethernet_parser.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct nStruct
{
	float* c;
	float* d;
};

typedef struct DataGether
{
	int *a;
	float* b;
	nStruct* nSt;
};

typedef struct Gether
{
	int* a;
	int* b;
	float* c;
};


extern struct MsgState* MsgStateSend;
extern struct MsgState* MsgStateRecv;

extern struct ServerSystemData* ServerData;

extern struct JointParameterSettingStruct* jParamSet;
extern struct JointParameterSettingStruct* jParamGet;

extern struct JointTrajectorySetStruct* jTrajSet;
extern struct JointTrajectorySetStruct* jTrajGet;

extern struct CartesianParameterSettingStruct* cParamSet;
extern struct CartesianParameterSettingStruct* cParamGet;

extern struct CartesianTrajectorySetStruct* cTrajSet;
extern struct CartesianTrajectorySetStruct* cTrajGet;

extern struct JointTargetStruct* jTarget;
extern struct JointTargetStruct* jTargetGet;

extern struct CartesianTargetStruct* cTarget;
extern struct CartesianTargetStruct* cTargetGet;

int main()
{

#if 0
	DataGether* gether = new DataGether;

	//gether->a = 3;
	gether->b = (float *)calloc(4, sizeof(float));
	if (gether->b == NULL)
	{
		return -1;
	}

	gether->b[0] = 0.0f;
	gether->b[1] = 1.1f;
	gether->b[2] = 2.3456f;
	gether->b[3] = 3.456789f;

	gether->nSt = (nStruct*)calloc(1, sizeof(nStruct));
	if (gether->nSt == NULL)
	{
		return -1;
	}
	gether->nSt->c = (float*)calloc(4, sizeof(float));
	if (gether->nSt->c == NULL)
	{
		return -1;
	}
	gether->nSt->d = (float*)calloc(4, sizeof(float));
	if (gether->nSt->d == NULL)
	{
		return -1;
	}
	gether->nSt->c[0] = 3.124f;
	gether->nSt->c[1] = 3.124f;
	gether->nSt->c[2] = 3.124f;
	gether->nSt->c[3] = 3.124f;

	gether->nSt->d[0] = 4.5124f;
	gether->nSt->d[1] = 4.5124f;
	gether->nSt->d[2] = 4.5124f;
	gether->nSt->d[3] = 4.5124f;


	printf_s("%d %f %f %f %f\n", gether->a, gether->b[0], gether->b[1], gether->b[2], gether->b[3]);
	printf_s("%f %f %f %f\n", gether->nSt->c[0], gether->nSt->c[1], gether->nSt->c[2], gether->nSt->c[3]);
	printf_s("%f %f %f %f\n", gether->nSt->d[0], gether->nSt->d[1], gether->nSt->d[2], gether->nSt->d[3]);

	printf_s("\n\n\n %d %d\n", sizeof(gether), sizeof(nStruct)*4);
	printf_s("\n\n %d %d\n", sizeof(Gether), sizeof(nStruct));

	int8_t* w = (int8_t*)calloc(8,sizeof(int8_t));
	if (w == NULL)
	{
		printf_s("w data NULL\n");
	}
	
	int8_t* total = (int8_t*)calloc(12, sizeof(int8_t));
	int8_t* a = (int8_t*)calloc(4, sizeof(int8_t));
	int8_t* b = (int8_t*)calloc(8, sizeof(int8_t));
	
	for (int i = 0; i < 4; i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < 8; i++)
	{
		b[i] = i + 4;
	}
	memcpy(total, a, _msize(a));
	for (int i = 0; i < _msize(total); i++) {
		printf_s("%d ", total[i]);
	}
	
	printf("\n\n\n");
	memcpy(total + _msize(a), b, _msize(b));
	for (int i = 0; i < _msize(total); i++) {
		printf_s("%d ", total[i]);
	}
	printf("\n\n\n");
	//free(a);
	//free(b);
	
	printf("total size : %d\n", _msize(total));
	//printf("buffOut size : %d\n", _msize(_buffOut));
	
	/*
	DataGethering2(a, b, _buffOut);
	for (int i = 0; i < _msize(_buffOut); i++) {
		printf_s("%d ", _buffOut[i]);
	}
	*/
	printf_s("a = ");
	for (int i = 0; i < _msize(a); i++) {
		printf_s("%d ", a[i]);
	}
	printf("\n\n\n");

	printf_s("b = ");
	for (int i = 0; i < _msize(b); i++) {
		printf_s("%d ", b[i]);
	}
	printf("\n\n\n");
	printf_s("total = ");
	for (int i = 0; i < _msize(total); i++) {
		printf_s("%d ", total[i]);
	}
	printf("\n\n\n");

	int8_t* _buffOut = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering3(a, b, total, _buffOut);
	printf("buffOut : ");
	for (int i = 0; i < _msize(_buffOut); i++) {
		printf_s("%d ", _buffOut[i]);
	}
	printf("\n\n\n");

	int8_t* _buffOut1 = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering4(a, b, total, _buffOut, _buffOut1);
	printf("buffOut1 : ");
	for (int i = 0; i < _msize(_buffOut1); i++) {
		printf_s("%d ", _buffOut1[i]);
	}
	printf("\n\n\n");
	
	int8_t* _buffOut2 = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering5(a, b, total, _buffOut, _buffOut1, _buffOut2);
	printf("buffOut2 : ");
	for (int i = 0; i < _msize(_buffOut2); i++) {
		printf_s("%d ", _buffOut2[i]);
	}
	printf("\n\n\n");
	
	int8_t* _buffOut3 = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering6(a, b, total, _buffOut, _buffOut1, _buffOut2, _buffOut3);
	printf("buffOut3 : ");
	for (int i = 0; i < _msize(_buffOut3); i++) {
		printf_s("%d ", _buffOut3[i]);
	}
	printf("\n\n\n");
	
	int8_t* _buffOut4 = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering7(a, b, total, _buffOut, _buffOut1, _buffOut2, _buffOut3, _buffOut4);
	printf("buffOut4 : ");
	for (int i = 0; i < _msize(_buffOut4); i++) {
		printf_s("%d ", _buffOut4[i]);
	}
	printf("\n\n\n");

	int8_t* _buffOut5 = (int8_t*)calloc(1, sizeof(int8_t));
	DataGethering8(a, b, total, _buffOut, _buffOut1, _buffOut2, _buffOut3, _buffOut4, _buffOut5);
	printf("buffOut5 : ");
	for (int i = 0; i < _msize(_buffOut5); i++) {
		printf_s("%d ", _buffOut5[i]);
	}
	printf("\n\n\n");
#endif

#if 0
	MsgStateSend = (MsgState*)malloc(sizeof(MsgState));
	MsgStateInit(MsgStateSend);
	printf_s("%d\n", _msize(MsgStateSend));
	printf_s("%d\n", MsgStateSize);

	ServerData = (ServerSystemData*)malloc(sizeof(ServerSystemData));
	ServerSystemDataInit(ServerData);
	printf_s("%d\n", _msize(ServerData));
	printf_s("%d\n", ServerSystemDataSize);

	jParamSet = (JointParameterSettingStruct*)malloc(sizeof(JointParameterSettingStruct));
	JointParameterSettingStructInit(jParamSet);
	printf_s("%d\n", _msize(jParamSet));
	printf_s("%d\n", JointParamSetStructSize);

	jTrajSet = (JointTrajectorySetStruct*)malloc(sizeof(JointTrajectorySetStruct));
	JointTrajectorySetStructInit(jTrajSet);
	printf_s("%d\n", _msize(jTrajSet));
	printf_s("%d\n", JointTrajSetStructSize);

	cParamSet = (CartesianParameterSettingStruct*)malloc(sizeof(CartesianParameterSettingStruct));
	CartesianParameterSettingStructInit(cParamSet);
	printf_s("%d\n", _msize(cParamSet));
	printf_s("%d\n", CartesianParamSetStructSize);

	cTrajSet = (CartesianTrajectorySetStruct*)malloc(sizeof(CartesianTrajectorySetStruct));
	CartesianTrajectorySetStructInit(cTrajSet);
	printf_s("%d\n", _msize(cTrajSet));
	printf_s("%d\n", CartesianTrajSetStructSize);

	jTargetSet = (JointTargetStruct*)malloc(sizeof(JointTargetStruct));
	JointTargetStructInit(jTargetSet);
	printf_s("%d\n", _msize(jTargetSet));
	printf_s("%d\n", JointTargetStructSize);

	cTargetSet = (CartesianTargetStruct*)malloc(sizeof(CartesianParameterSettingStruct));
	CartesianTargetStructInit(cTargetSet);
	printf_s("%d\n", _msize(cTargetSet));
	printf_s("%d\n", CartesianTargetStructSize);
#endif

#if 0
	EtherNetStructure_Init();

	printf_s("%d\n", MsgStateSize);
	printf_s("%d\n", ServerSystemDataSize);
	printf_s("%d\n", JointParamSetStructSize);
	printf_s("%d\n", JointTrajSetStructSize);
	printf_s("%d\n", CartesianParamSetStructSize);
	printf_s("%d\n", CartesianTrajSetStructSize);
	printf_s("%d\n", JointTargetStructSize);
	printf_s("%d\n", CartesianTargetStructSize);
	
	MsgStateSend->packetType[0] = 3;
	MsgStateSend->packetType[1] = 0;
	MsgStateSend->controlMode = 45;
	MsgStateSend->commState = 12;
	MsgStateSend->payloadSize = 155;

	int8_t *inBuff = (int8_t*)malloc(sizeof(int8_t));
	if (!MsgStateToBuffer(MsgStateSend, inBuff)) {
		printf("Convert Fail!!\n");
	}
	if (!DataDivideMsgState(inBuff, MsgStateRecv)) {
		printf("Divide Fail!!!\n");
	}
	printf_s("\n\n");
	printf_s("%d\n", _msize(MsgStateRecv));
	printf_s("%d\n", MsgStateRecv->packetType[0]);
	printf_s("%d\n", MsgStateRecv->packetType[1]);
	printf_s("%d\n", MsgStateRecv->controlMode);
	printf_s("%d\n", MsgStateRecv->commState);
	printf_s("%d\n", MsgStateRecv->payloadSize);

	//printf_s("binaray : %d\n", MsgStateSend->packetType[0]);

	jParamSet->jointTorquePgain[0] = 1.11;
	jParamSet->jointTorquePgain[1] = 2.22;
	jParamSet->jointTorquePgain[2] = 3.33;
	jParamSet->jointTorquePgain[3] = 4.44;

	jParamSet->jointTorqueIgain[0] = 5.55;
	jParamSet->jointTorqueIgain[1] = 6.66;
	jParamSet->jointTorqueIgain[2] = 7.77;
	jParamSet->jointTorqueIgain[3] = 8.88;

	jParamSet->jointTorqueDgain[0] = 9.99;
	jParamSet->jointTorqueDgain[1] = 10.111;
	jParamSet->jointTorqueDgain[2] = 11.111;
	jParamSet->jointTorqueDgain[3] = 12.222;

	jParamSet->jointPositionPgain[0] = 13.33;
	jParamSet->jointPositionPgain[1] = 14.44;
	jParamSet->jointPositionPgain[2] = 15.55;
	jParamSet->jointPositionPgain[3] = 16.6666;

	jParamSet->jointPositionIgain[0] = 17.777;
	jParamSet->jointPositionIgain[1] = 18.888;
	jParamSet->jointPositionIgain[2] = 19.999;
	jParamSet->jointPositionIgain[3] = 20.222;

	jParamSet->jointPositionDgain[0] = 21.111;
	jParamSet->jointPositionDgain[1] = 22.222;
	jParamSet->jointPositionDgain[2] = 23.3333;
	jParamSet->jointPositionDgain[3] = 24.4444;
	
	jParamSet->jointGravityGain[0] = 25.5555;
	jParamSet->jointGravityGain[1] = 26.6666;
	jParamSet->jointGravityGain[2] = 27.7777;
	jParamSet->jointGravityGain[3] = 28.8888;

	jParamSet->jointFrictionGain[0] = 29.9999;
	jParamSet->jointFrictionGain[1] = 30.1111;
	jParamSet->jointFrictionGain[2] = 31.1111;
	jParamSet->jointFrictionGain[3] = 32.22222;

	jParamSet->jointCurrentGain[0] = 33.33333;
	jParamSet->jointCurrentGain[1] = 34.44444;
	jParamSet->jointCurrentGain[2] = 35.555;
	jParamSet->jointCurrentGain[3] = 36.6666;

	jParamSet->jointConstantTorque[0] = 37.7777;
	jParamSet->jointConstantTorque[1] = 38.8888;
	jParamSet->jointConstantTorque[2] = 39.99999;
	jParamSet->jointConstantTorque[3] = 40.0141;
	
	jParamSet->jointConstantSpring[0] = 41.1111;
	jParamSet->jointConstantSpring[1] = 42.2222;
	jParamSet->jointConstantSpring[2] = 43.3333;
	jParamSet->jointConstantSpring[3] = 44.4444;

	jParamSet->jointConstantEfficiency[0] = 45.5555;
	jParamSet->jointConstantEfficiency[1] = 46.6666;
	jParamSet->jointConstantEfficiency[2] = 47.777;
	jParamSet->jointConstantEfficiency[3] = 48.8;

	printf("\n\n JointParam Set : \n");
	for (int i = 0; i < 4; i++)
	{
		printf_s("%f\n", jParamSet->jointTorquePgain[i]);
		printf_s("%f\n", jParamSet->jointTorqueIgain[i]);
		printf_s("%f\n", jParamSet->jointTorqueDgain[i]);
		printf_s("%f\n", jParamSet->jointPositionPgain[i]);
		printf_s("%f\n", jParamSet->jointPositionIgain[i]);
		printf_s("%f\n", jParamSet->jointPositionDgain[i]);
		printf_s("%f\n", jParamSet->jointGravityGain[i]);
		printf_s("%f\n", jParamSet->jointFrictionGain[i]);
		printf_s("%f\n", jParamSet->jointCurrentGain[i]);
		printf_s("%f\n", jParamSet->jointConstantTorque[i]);
		printf_s("%f\n", jParamSet->jointConstantSpring[i]);
		printf_s("%f\n", jParamSet->jointConstantEfficiency[i]);

	}
	
	int8_t* inBuff2 = (int8_t*)calloc(1,sizeof(int8_t));
	if (!JointParameterSettingStructToBuffer(jParamSet, inBuff2)) {
		printf("Convert Fail!!\n");
	}

	int8_t* combinedBuff = (int8_t*)calloc(1,sizeof(int8_t));
	if (!DataGethering2(inBuff, inBuff2, combinedBuff)) {
		printf("Data Gethering Fail!!!\n");
	}

	if (!DataDivideJointParamSettingStruct(combinedBuff, MsgStateSend ,jParamGet)) {
		printf("Divide Fail Joint Param Setting!!!\n");
	}


	printf("\n\n JointParam Get : \n");
	for (int i = 0; i < 4; i++)
	{
		printf_s("%f\n", jParamGet->jointTorquePgain[i]);
		printf_s("%f\n", jParamGet->jointTorqueIgain[i]);
		printf_s("%f\n", jParamGet->jointTorqueDgain[i]);
		printf_s("%f\n", jParamGet->jointPositionPgain[i]);
		printf_s("%f\n", jParamGet->jointPositionIgain[i]);
		printf_s("%f\n", jParamGet->jointPositionDgain[i]);
		printf_s("%f\n", jParamGet->jointGravityGain[i]);
		printf_s("%f\n", jParamGet->jointFrictionGain[i]);
		printf_s("%f\n", jParamGet->jointCurrentGain[i]);
		printf_s("%f\n", jParamGet->jointConstantTorque[i]);
		printf_s("%f\n", jParamGet->jointConstantSpring[i]);
		printf_s("%f\n", jParamGet->jointConstantEfficiency[i]);
	}
	
	jTrajSet->JointTrajecotryTime[0] = 200.11;
	jTrajSet->JointTrajecotryTime[1] = 321.11;
	jTrajSet->JointTrajecotryTime[2] = 4631.11;
	jTrajSet->JointTrajecotryTime[3] = 567.11;

	jTrajSet->JointTrajectoryAcc[0] = 3123.156;
	jTrajSet->JointTrajectoryAcc[1] = 76345.156;
	jTrajSet->JointTrajectoryAcc[2] = 364523.156;
	jTrajSet->JointTrajectoryAcc[3] = 234123.156;

	printf_s("\n\n\n");
	printf_s("Joint Trajectory : \n");
	int8_t* inBuff3 = (int8_t*)malloc(sizeof(int8_t));
	if (!JointTrajectorySetStructToBuffer(jTrajSet, inBuff3)) {
		printf("Convert Fail!!\n");
	}
	printf_s("\n\n\%d\n\n", _msize(inBuff3));
	int8_t* combinedBuff2 = (int8_t*)malloc(sizeof(int8_t));
	if (!DataGethering3(inBuff, inBuff2, inBuff3, combinedBuff2)) {
		printf("Data Gethering Fail!!!\n");
	}
	printf_s("\n\n\%d\n\n", _msize(inBuff)+_msize(inBuff2)+_msize(inBuff3));
	if (!DataDivideJointTrajectorySetStruct(combinedBuff2, MsgStateSend, jTrajGet)) {
		printf("Divide Fail Joint Param Setting!!!\n");
	}
	/*
	for (;;)
	{
		for (int i = 0; i < 4; i++)
		{
			printf_s("%f\n", jTrajGet->JointTrajecotryTime[i]);
			printf_s("%f\n", jTrajGet->JointTrajectoryAcc[i]);
		}
	}
	*/
	

#endif
#if 1
	int8_t* inBuff;
	int8_t* inBuff2;
	int8_t* inBuff3;
	int8_t* Buffer;

	EtherNetStructure_Init();
	
	for (;;)
	{
		printf_s("Convert To Buffer\n");
		inBuff = (int8_t*)malloc(sizeof(int8_t));
		MsgStateToBuffer(MsgStateSend, inBuff);
		//printf_s("%d\n", _msize(inBuff));
		inBuff2 = (int8_t*)malloc(sizeof(int8_t));
		printf_s("%d\n", JointTrajectorySetStructToBuffer(jTrajSet, inBuff2));
		//printf_s("%d\n", _msize(inBuff3));
		inBuff3 = (int8_t*)malloc(sizeof(int8_t));
		printf_s("%d\n", JointParameterSettingStructToBuffer(jParamSet, inBuff3));
		//printf_s("%d\n", JointParamSetStructSize);
		//printf_s("%d\n", _msize(inBuff2));
		printf_s("Data Gethering\n");

		//printf_s("%d %d %d\n", _msize(inBuff), _msize(inBuff2), _msize(inBuff3));
		Buffer = (int8_t*)malloc(sizeof(int8_t));
		printf_s("%d\n",DataGethering3(inBuff, inBuff2, inBuff3, Buffer));
		printf_s("Complete!!\n");
		//printf_s("%d\n", _msize(Buffer));
		
		free(inBuff);
		free(inBuff2);
		free(inBuff3);
		free(Buffer);
	}
	
#endif
	return 0;
}