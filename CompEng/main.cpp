#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include "Decoder.h"
#include "DataMemory.h"
#include "IntermediateRegisters.h"
#include "Registers.h"
#include "Controller.h"



int main()
{
	InstructionMemory IM;
	DataMemory DM;
	ProgramCounter PC;
	Decoder D;
	Registers R;
	Controller C;

	IFID IF_ID;
	IDEX ID_EX;
	EXMEM EX_MEM;
	MEMWB MEM_WB;


	int clock_counter = 0;
	std::string filename = "Text.txt";



	IM.read_instructions(filename);
	IM.print_instructions();

	PC.set_address(0);
	
	//set registers 
	for (int i = 0; i < 31; i++)
	{
		R.set_data(i, 0);
	}

	//set data memory
	for (int i = 0; i < 255; i++)
	{
		DM.set_data(i, 0);
	}

	while (IM.get_instruction(PC.get_address()) != "")
	{

		//reset control signals
		C.ALUOp = 0;
		C.ALUSrc = 0;
		C.Branch = 0;
		C.Jump = 0;
		C.MemRead = 0;
		C.MemToReg = 0;
		C.MemWrite = 0;
		C.RegDst = 0;
		C.RegWrite = 0;


		//FETCH
		IF_ID.instruction = IM.get_instruction(PC.get_address());
		PC.increment_address();
		IF_ID.address = PC.get_address();


		//DECODE
		D.decode(IF_ID.instruction);
		switch (D.get_opcode())
		{
		case 0: //R_TYPE
			C.ALUSrc = 1;
			if (D.get_funct() == 32) //ADD
			{
				C.RegDst = 1;
				C.RegWrite = 1;
				C.ALUOp = 0;
				std::cout << "ADD" << std::endl;
			}
			if (D.get_funct() == 34) //SUB
			{
				C.RegDst = 1;
				C.RegWrite = 1;
				C.ALUOp = 1;
				std::cout << "SUB" << std::endl;

			}
			break;

		case 2: //J
			C.RegDst = 0;
			C.RegWrite = 0;
			C.Jump = 1;
			C.ALUOp = 0;
			C.ALUSrc = 0;
			std::cout << "JUMP" << std::endl;
			break;

		case 4: //BEQ
			C.RegDst = 0;
			C.RegWrite = 0;
			C.ALUSrc = 1;
			C.Branch = 1;
			C.ALUOp = 1;
			C.MemRead = 0;
			C.MemToReg = 0;
			std::cout << "BEQ" << std::endl;
			break;

		case 8: //ADDI
			C.RegDst = 0;
			C.RegWrite = 1;
			C.ALUSrc = 0;
			C.ALUOp = 0;
			std::cout << "ADDI" << std::endl;
			break;

		case 35: //LW
			C.RegDst = 0;
			C.RegWrite = 1;
			C.ALUSrc = 0;
			C.ALUOp = 0;
			C.MemRead = 1;
			C.MemToReg = 1;
			std::cout << "LW" << std::endl;
			break;

		case 43: //SW
			C.RegDst = 0;
			C.ALUSrc = 0;
			C.ALUOp = 1;
			C.MemWrite = 1;
			std::cout << "SW" << std::endl;
			break;

		default:
			std::cout << "Unknown opcode";
			break;

		}


		//update the ID_EX register values
		ID_EX.address = IF_ID.address;
		std::cout << "Address:" << ID_EX.address << std::endl;
		ID_EX.rd1 = R.read_data(D.get_rs());
		std::cout << "Rd1:" << ID_EX.rd1 << std::endl;
		ID_EX.rd2 = R.read_data(D.get_rt());
		std::cout << "Rd2:" << ID_EX.rd2 << std::endl;
		ID_EX.imm = D.get_imm();
		std::cout << "Imm:" << ID_EX.imm << std::endl;

		if (C.RegDst == 0)
		{
			ID_EX.wb = D.get_rt();
			std::cout << "Wb:" << ID_EX.wb << std::endl;

		}
		else
		{

			ID_EX.wb = D.get_rd();
			std::cout << "Wb:" << ID_EX.wb << std::endl;

		}

		if (C.Jump == 1)
		{
			ID_EX.imm = D.get_jump();
		}


		//EXECUTE
		EX_MEM.wb = ID_EX.wb;
		EX_MEM.address = ID_EX.address;
		EX_MEM.wd = ID_EX.rd2;

		if (C.ALUSrc)
		{
			switch (C.ALUOp)
			{
			case 0:
				EX_MEM.result = ID_EX.rd1 + ID_EX.rd2;
				break;
			case 1:
				EX_MEM.result = ID_EX.rd1 - ID_EX.rd2;
				break;
			}
		}
		else
		{
			switch (C.ALUOp)
			{
			case 0:
				EX_MEM.result = ID_EX.rd1 + ID_EX.imm;
				break;
			case 1:
				EX_MEM.result = ID_EX.rd1 - ID_EX.imm;
				break;
			}
		}
		std::cout << EX_MEM.result;
		if (EX_MEM.result == 0)
		{
			EX_MEM.zero = 1;
		}
		else
		{
			EX_MEM.zero = 0;
		}

		if ((C.Branch && EX_MEM.zero) || C.Jump)
		{
			EX_MEM.address = ID_EX.address + ID_EX.imm  ;
			if (EX_MEM.address >= 256)
				EX_MEM.address = EX_MEM.address - 256;
			std::cout << "The new address is " << EX_MEM.address << std::endl;
		}

		PC.set_address(EX_MEM.address);


		//MEMORY ACCESS
		MEM_WB.result = EX_MEM.result;
		MEM_WB.wb = EX_MEM.wb;
		if (C.MemRead || C.MemWrite)
		{

			if (C.MemRead)
			{
				MEM_WB.rd = DM.get_data(EX_MEM.result);
				std::cout << "The value " << MEM_WB.rd << "read from address" << EX_MEM.result << std::endl;

			}

			if (C.MemWrite)
			{
				DM.set_data(EX_MEM.result, EX_MEM.wd);
				std::cout << "The value " << EX_MEM.wd << "saved to address" << EX_MEM.result << std::endl;
			}
		}

		//WRITE BACK
		if (C.RegWrite)
		{
			if (C.MemToReg)
			{
				R.set_data(MEM_WB.wb, MEM_WB.rd);
				std::cout << "The data " << MEM_WB.rd << " written back at register" << MEM_WB.wb << std::endl;
				std::cout << "Register" << MEM_WB.wb << "contains " << R.read_data(MEM_WB.wb)<<std::endl;
			}

			else
			{
				R.set_data(MEM_WB.wb, MEM_WB.result);
				std::cout << "The data " << MEM_WB.result << " written back at register" << MEM_WB.wb << std::endl;
				std::cout << "Register" << MEM_WB.wb << "contains " << R.read_data(MEM_WB.wb)<<std::endl;
			}
		}

		std::cout << std::endl;
	}

}