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
}

void InstructionMemory::print_instructions()
{
	for (int i = 0; i < 256; i++)
	{
		std::cout << memory[i]<<std::endl;
	}
}

void InstructionMemory::convert_to_MC()
{
	for(int i =0; i)
}
