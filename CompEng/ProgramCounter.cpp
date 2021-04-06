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

void ProgramCounter::jump_address(int jump_address)
{
	address = jump_address;
}
