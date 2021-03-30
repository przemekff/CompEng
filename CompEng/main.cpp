#include <iostream>
#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include "Decoder.h"
#include "DataMemory.h"



int main()
{
	int clock_counter = 0;
	InstructionMemory IM;
	DataMemory DM;
	ProgramCounter PC;
	Decoder D;


	//FETCH
	unsigned __int32 IR = IM.get_instruction(PC.get_address());
	clock_counter++;

	//DECODE
	D.decode(IR);

}