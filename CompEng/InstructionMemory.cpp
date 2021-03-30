#include "InstructionMemory.h"

unsigned __int32 InstructionMemory::get_instruction(int address)
{
	return memory[address];
}
