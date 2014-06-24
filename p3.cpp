#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "basic_functions.h"
#include <iostream>

bool* alu(bool instruction[8], bool input1[8], bool input2[8]) {
	//and instruction with each condition, or solutions
	bool* alu0 = new bool[8];
	bool* alu1 = new bool[8];
	bool* alu2 = new bool[8];
	bool* alu3 = new bool[8];
	bool* alu4 = new bool[8];
	bool* alu5 = new bool[8];
	bool* alu6 = new bool[8];
	bool* alu7 = new bool[8];
	bool* alu8 = new bool[8];
	bool* alu9 = new bool[8];
	bool* alu10 = new bool[8];
	bool* alu11 = new bool[8];
	bool* alu12 = new bool[8];
	bool* alu13 = new bool[8];
	bool* alu16 = new bool[8];
	bool* alu17 = new bool[8];
	bool* output = new bool[8];

	alu0 = and8(alu0, instruction, add(output, input1, input2));
	alu1 = and8(alu1, instruction, sub(output, input1, input2));
	alu2 = and8(alu2, instruction, negate(&output, input1));
	alu3 = and8(alu3, instruction, equal(output, input1, input2));
	alu4 = and8(alu4, instruction, lessthan(output, input1, input2));
	alu5 = and8(alu5, instruction, greaterthan(output, input1, input2));
	alu6 = and8(alu6, instruction, and8(output, input1, input2));
	alu7 = and8(alu7, instruction, or8(output, input1, input2));
	alu8 = and8(alu8, instruction, shiftLeft(output, input1));
	alu9 = and8(alu9, instruction, shiftRight(output, input1));
	alu10 = and8(alu10, instruction, multu(output, input1, input2));
	alu11 = and8(alu11, instruction, mult(output, input1, input2));
	alu12 = and8(alu12, instruction, divu(output, input1, input2));
	alu13 = and8(alu13, instruction, div(output, input1, input2));
	alu16 = and8(alu16, instruction, addu(output, input1, input2));
	alu17 = and8(alu17, instruction, subu(output, input1, input2));

	//Or everything together for the answer
	output = or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, or8(output, 
		or8(output, alu0, alu1), alu2), alu3), alu4), alu5), alu6), alu7), alu8), alu9), alu10), alu11), alu12), alu13), alu16), alu17);
	return output;
}

