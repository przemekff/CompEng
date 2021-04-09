#include "DataMemory.h"

int  DataMemory::get_data(int address)
{
	return memory[address];
}

void DataMemory::set_data(int address, int data)
{
	memory[address] = data;
}
