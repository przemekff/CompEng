#pragma once
class Registers
{
public:
	int read_data(int address);
	void set_data(int address, int data);
private:
	int reg[32];
};

