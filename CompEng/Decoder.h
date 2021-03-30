#pragma once

#include <string>

class Decoder
{

public:
	void decode(unsigned __int32 input);
	int get_rs();
	int get_rt();
	int get_rd();
	int get_shamt();
	int get_funct();
	int get_imm();
	int get_address();

private:
	std::string instruction;
	std::string opcode; 

};

