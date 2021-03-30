#pragma once

const int MEMORY_SIZE = 1024;

class InstructionMemory
{
public:
	unsigned __int32 get_instruction(int address);

private:
	unsigned __int32 memory[MEMORY_SIZE];
};

