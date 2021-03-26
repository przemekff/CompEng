#include <iostream>
#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include "Decoder.h"


int main()
{
	int clock_counter = 0;
	InstructionMemory IM;
	ProgramCounter PC;
	Decoder D;

	//FETCH
	int IR = IM.get_instruction(PC.get_address());
	clock_counter++;

	//DECODE
	D.decode(IR);

}