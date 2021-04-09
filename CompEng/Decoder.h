#pragma once

#include <string>
#include <iostream>

class Decoder
{

public:
	void decode(std::string  input);
	int get_opcode();
	int get_rs();
	int get_rt();
	int get_rd();
	int get_shamt();
	int get_funct();
	int get_imm();
	int get_jump();


private:
	std::string instruction;
	std::string opcode;


};

