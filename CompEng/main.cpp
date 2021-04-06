#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include "Decoder.h"
#include "DataMemory.h"



int main()
{
	int clock_counter = 0;
	std::string filename = "Text.txt";
	InstructionMemory IM;
	DataMemory DM;
	ProgramCounter PC;
	Decoder D;

	std::cout << "hello";

	IM.read_instructions(filename);
	IM.print_instructions();


	//FETCH
	//std::string  IR = IM.get_instruction(PC.get_address());
	//clock_counter++;

	//DECODE
	//D.decode(IR);

}