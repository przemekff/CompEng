#pragma once

#include <iostream>
#include <string>
#include <fstream>


class InstructionMemory
{
public:
	std::string get_instruction(int address);
	void read_instructions(const std::string& filename);
	void print_instructions();

private:
	std::string  memory[256];
};

