#include "InstructionMemory.h"


std::string  InstructionMemory::get_instruction(int address)
{
	return memory[address];
}

void InstructionMemory::read_instructions(const std::string& filename)
{
	int i = 0;
	std::fstream f(filename.c_str());
	std::string s;
	while (std::getline(f, s))
	{
		memory[i] = s;
		i++;
	}
	while (i < 256)
	{
		memory[i] = "";
		i++;
	}
}

void InstructionMemory::print_instructions()
{

		std::cout << memory[0]<<std::endl;
}


