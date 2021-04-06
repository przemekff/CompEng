#include "DataMemory.h"

unsigned __int32  DataMemory::get_data(int address)
{
	return memory[address];
}