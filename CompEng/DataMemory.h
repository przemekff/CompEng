#pragma once

#include <string>

const int MEMORY_SIZE = 256;

class DataMemory
{
public:
	int  get_data(int address);
	void set_data(int address, int data);

private:
	int  memory[MEMORY_SIZE];
};

