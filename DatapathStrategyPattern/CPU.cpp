#include "CPU.h"

void CPU::run()
{

	instruction = components.instr_mem.instruction_array[PC];

	//find opcode
	opcode = (instruction & 0xFC000000);	//0b11111100000000000000000000000000
	opcode >>= 26;
	
	if (opcode == 0)
		context.setType(R);
	
		
		
		
		
	context.run(opcode, instruction, &components);

	//if (opcode == 0)
	//	is_rtype_ = true;
	//else if (opcode == 0x02 || opcode == 0x03)
	//	is_jtype_ = true;
	//else					// Assuming we're dealing with valid instructions this should suffice.
	//	is_itype_ = true;	// Otherwise I would have to include a condition here as an "else if" 
	//						// instead of "else".

}