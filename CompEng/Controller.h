#pragma once
struct Controller
{
	bool RegDst;
	bool Branch;
	bool MemRead;
	bool MemWrite;
	bool MemToReg;
	bool ALUSrc;
	bool RegWrite;
	bool Jump;
	int ALUOp;

	Controller() : Branch(0), MemRead(0), MemWrite(0), MemToReg(0), ALUSrc(0), RegWrite(0), ALUOp(0), Jump(0), RegDst(0) {}
};

