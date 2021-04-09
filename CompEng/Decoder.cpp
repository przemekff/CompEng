#include "Decoder.h"

void Decoder::decode(std::string  input)
{
	instruction = input;
	opcode = instruction.substr(0, 6);
}


int Decoder::get_opcode()
{
	return stoi(instruction.substr(0, 6), nullptr, 2);
}

int Decoder::get_rs()
{
	return stoi(instruction.substr(6, 5),nullptr,2);
}

int Decoder::get_rt()
{
	return stoi(instruction.substr(11, 5),nullptr,2);
}
int Decoder::get_rd()
{
	return stoi(instruction.substr(16, 5),nullptr,2);
}
int Decoder::get_shamt()
{
	return stoi(instruction.substr(21, 5),nullptr,2);
}
int Decoder::get_funct()
{
	return stoi(instruction.substr(26, 6),nullptr,2);
}
int Decoder::get_imm()
{
	return stoi(instruction.substr(16, 16),nullptr,2);
}
int Decoder::get_jump()
{
	return stoi(instruction.substr(6, 26),nullptr, 2);
}


