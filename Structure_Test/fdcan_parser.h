/*
 *
 *    Created on : Dec 14, 2021
 *        Author : Chanil
 *
 */

#ifndef CAN_PARSER_H
#define CAN_PARSER_H

#include "fdcan_structure.h"
#include "string.h"

void ConvertToInput(MotorDriverInput *_input,  uint8_t *_buffer)
{
	memcpy(_buffer, _input, sizeof(MotorDriverInput));
}

void ConverToOutput(MotorDriverOutput *_output, uint8_t *_buffer)
{
	memcpy(_buffer, _output, sizeof(MotorDriverOutput));
}

#endif /* CAN_STRUCTURE_H */