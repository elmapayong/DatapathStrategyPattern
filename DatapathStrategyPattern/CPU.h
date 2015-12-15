#include "Datapath.h"
#include "Context.h"
#include "RType.h"
#include "IType.h"
#include "IType_lw.h"

#ifndef CPU_H
#define CPU_H

class CPU
{
public:
	void run();
private:
	int PC = 0;
	unsigned int instruction;
	unsigned int opcode;
	Datapath components;
	Context context;
	RType R;
	IType I;
	IType_lw I_lw;
};

#endif