#include "CPU.h"

void CPU::run()
{
	int type;
	//DELETE THIS
	components.setPC(10);

	instruction = components.instr_mem.instruction_array[components.PC];

	//find opcode
	opcode = (instruction & 0xFC000000);	//0b11111100000000000000000000000000
	opcode >>= 26;

	type = opcode >> 3;

	//R-format
	if (opcode == 0)
	{
		context.setType(R);
	}
	//I-format BEQ
	else if (opcode == 4)
		;
	//I-format ANDi, ORi, XORi, Addi, Subi
	else if (type == 1)
		context.setType(I);
	//I-format lw
	else if (type == 4)		//100
		context.setType(I_lw);
	//I-format sw
	else if (type == 5)		//101
		;
	//I-format JUMP
	else if (type == 0)
		;
	
	context.run(opcode, instruction, &components);

}