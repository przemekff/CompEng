#include "DataMemory.h"

unsigned __int32 DataMemory::get_instruction(int address)
{
	return memory[address];
}