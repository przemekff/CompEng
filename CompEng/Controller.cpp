#include "Controller.h"

void Controller::reset_signals()
{
	Branch = 0;
	RegDst = 0;
	MemRead = 0;
	MemWrite = 0;
	MemToReg = 0;
	ALUSrc = 0;
	RegWrite = 0;
}
