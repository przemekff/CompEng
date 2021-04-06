#include "Decoder.h"

void Decoder::decode(std::string  input)
{
	instruction = input;
	opcode = instruction.substr(0, 6);

	if (stoi(opcode) == 0)
	{
		R = 1;
		I = 0;
		J = 0;
	}
	else if (stoi(opcode) == 2 || stoi(opcode) == 3)
	{
		R = 0;
		I = 0;
		J = 0;
	}
	else
	{
		R = 0;
		I = 1;
		J = 0;
	}

}

int Decoder::get_rs()
{
	return stoi(instruction.substr(6, 5));
}

int Decoder::get_rt()
{
	return stoi(instruction.substr(11, 5));
}
int Decoder::get_rd()
{
	return stoi(instruction.substr(16, 5));
}
int Decoder::get_shamt()
{
	return stoi(instruction.substr(21, 5));
}
int Decoder::get_funct()
{
	return stoi(instruction.substr(26, 6));
}
int Decoder::get_imm()
{
	return stoi(instruction.substr(16, 16));
}
int Decoder::get_address()
{
	return stoi(instruction.substr(6, 26));
}
