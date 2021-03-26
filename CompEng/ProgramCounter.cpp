#include "ProgramCounter.h"

int ProgramCounter::get_address()
{
	return address;
}

void ProgramCounter::increment_address()
{
	address += 4;
}