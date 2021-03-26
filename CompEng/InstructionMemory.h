#pragma once

const int MEMORY_SIZE = 1024;

class InstructionMemory
{
public:
	int get_instruction(int address);

private:
	int memory[1024];
};

