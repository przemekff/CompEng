#pragma once

#include <string>

class ProgramCounter
{

public:
	int get_address();
	void increment_address();
	void branch_address(int offset);
	void set_address(int set_address);

private:
	int address;

};

