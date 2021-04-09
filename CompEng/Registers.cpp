#include "Registers.h"

int Registers::read_data(int address)
{
    return reg[address];
}

void Registers::set_data(int address, int data)
{
    reg[address] = data;
}
