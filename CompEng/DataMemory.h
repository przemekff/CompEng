#pragma once

#include <string>

const int MEMORY_SIZE = 256;

class DataMemory
{
public:
	unsigned __int32  get_data(int address);

private:
	unsigned __int32  memory[MEMORY_SIZE];
};

