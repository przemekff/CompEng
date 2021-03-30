#include "Decoder.h"

void Decoder::decode(unsigned __int32 input)
{
	instruction = std::to_string(input);
	opcode = instruction.substr(0, 6);
}

int Decoder::get_rs()
{
	return stoi(opcode.substr(6, 5));
}

int Decoder::get_rt()
{
	return stoi(opcode.substr(11, 5));
}
int Decoder::get_rd()
{
	return stoi(opcode.substr(16, 5));
}
int Decoder::get_shamt()
{
	return stoi(opcode.substr(21, 5));
}
int Decoder::get_funct()
{
	return stoi(opcode.substr(26, 6));
}
int Decoder::get_address()
{
	return stoi(opcode.substr(6, 26));
}
