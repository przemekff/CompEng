#include "ProgramCounter.h"

int ProgramCounter::get_address()
{
	return address;
}

void ProgramCounter::increment_address()
{
	address += 1;
}

void ProgramCounter::branch_address(int offset)
{
	address += offset;
}

void ProgramCounter::set_address(int set_address)
{
	address = set_address;
}
