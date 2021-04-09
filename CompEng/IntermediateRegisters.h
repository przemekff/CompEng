#pragma once
#include <string>

struct IFID
{
	int address;
	std::string instruction ;
	IFID() : address(0), instruction("") {};

};

struct IDEX
{
	int address;
	int rd1;
	int rd2;
	int imm;
	int wb;
	IDEX() :address(0), rd1(0), rd2(0), imm(0), wb(0) {};

};

struct EXMEM
{
	int address;
	int result;
	int wb;
	int wd;
	bool zero;
	EXMEM() : address(0), result(0), wb(0), wd(0), zero(0) {};

};

struct MEMWB
{
	int rd = 0;
	int wb = 0;
	int result = 0;
	MEMWB() : rd(0), wb(0), result(0) {};
};

