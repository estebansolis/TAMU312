#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "basic_functions.h"
#include <iostream>
#include <stdexcept>

using namespace std; 


bool registry[16][8];
bool instructionMemory[256][8];
bool dataMemory[16][8];
bool PC[8];
bool IR[32];
bool four[8] = {0,0,1,0,0,0,0,0};
bool eight[8] = {0,0,0,1,0,0,0,0};


// setting everything to 0 

void initialize()
{
	int i, j;
	
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 8; j++)
		{	
			registry[i][j] = 0;
			dataMemory[i][j] = 0;
		}
		
		if(i < 8)
		{
			PC[i] = 0;
		}
	}
	
	for(i = 0; i < 32; i++)
	{
		IR[i] = 0;
	}
	
	for(i = 0; i < 256; i++)
	{
		for(j = 0; j < 8; j++)
		{
			instructionMemory[i][j] = 0;
		}
	}
}
	

bool* getRegistryValue(bool* output, bool registerNum[8])
{                                               
	output[0] = registry[ValueInDecimal(registerNum)][0];
	output[1] = registry[ValueInDecimal(registerNum)][1];
	output[2] = registry[ValueInDecimal(registerNum)][2];
	output[3] = registry[ValueInDecimal(registerNum)][3];
	output[4] = registry[ValueInDecimal(registerNum)][4];
	output[5] = registry[ValueInDecimal(registerNum)][5];
	output[6] = registry[ValueInDecimal(registerNum)][6];
	output[7] = registry[ValueInDecimal(registerNum)][7];
}
	
void setRegistryValue(bool registerNum[8], bool value[8])
{
	registry[ValueInDecimal(registerNum)][0] =  value[0];
    registry[ValueInDecimal(registerNum)][1] =  value[1];
    registry[ValueInDecimal(registerNum)][2] =  value[2];
    registry[ValueInDecimal(registerNum)][3] =  value[3];
    registry[ValueInDecimal(registerNum)][4] =  value[4];
    registry[ValueInDecimal(registerNum)][5] =  value[5];
	registry[ValueInDecimal(registerNum)][6] =  value[6];
    registry[ValueInDecimal(registerNum)][7] =  value[7];
}
	
	

int toDecimal(bool registerNum[8])
{
	return ValueInDecimal(registerNum); 
}

void incrementPC()
{
	add(PC, PC, four);
}	
	

void addPC(bool addressOffset[8])
{
	throw(if(add(PC,PC, addressOffset)%4 == 1))("Not Divisible by 4"));
	add(PC,PC, addressOffset);
}
	


void instructionFetch()
{
	IR[0]  =  instructionMemory[ValueInDecimal(PC)][0];
	IR[1]  =  instructionMemory[ValueInDecimal(PC)][1];
	IR[2]  =  instructionMemory[ValueInDecimal(PC)][2];
	IR[3]  =  instructionMemory[ValueInDecimal(PC)][3];
	IR[4]  =  instructionMemory[ValueInDecimal(PC)][4];
	IR[5]  =  instructionMemory[ValueInDecimal(PC)][5];
	IR[6]  =  instructionMemory[ValueInDecimal(PC)][6];
	IR[7]  =  instructionMemory[ValueInDecimal(PC)][7];
	
	addPC(eight); 
	
	IR[8]  =  instructionMemory[ValueInDecimal(PC)][0];
	IR[9]  =  instructionMemory[ValueInDecimal(PC)][1];
	IR[10] =  instructionMemory[ValueInDecimal(PC)][2];
	IR[11] =  instructionMemory[ValueInDecimal(PC)][3];
	IR[12] =  instructionMemory[ValueInDecimal(PC)][4];
	IR[13] =  instructionMemory[ValueInDecimal(PC)][5];
	IR[14] =  instructionMemory[ValueInDecimal(PC)][6];
	IR[15] =  instructionMemory[ValueInDecimal(PC)][7];
	
	addPC(eight); 
	
	IR[16] =  instructionMemory[ValueInDecimal(PC)][0];
	IR[17] =  instructionMemory[ValueInDecimal(PC)][1];
	IR[18] =  instructionMemory[ValueInDecimal(PC)][2];
	IR[19] =  instructionMemory[ValueInDecimal(PC)][3];
	IR[20] =  instructionMemory[ValueInDecimal(PC)][4];
	IR[21] =  instructionMemory[ValueInDecimal(PC)][5];
	IR[22] =  instructionMemory[ValueInDecimal(PC)][6];
	IR[23] =  instructionMemory[ValueInDecimal(PC)][7];
	
	addPC(eight); 
	
	IR[24] =  instructionMemory[ValueInDecimal(PC)][0];
	IR[25] =  instructionMemory[ValueInDecimal(PC)][1];
	IR[26] =  instructionMemory[ValueInDecimal(PC)][2];
	IR[27] =  instructionMemory[ValueInDecimal(PC)][3];
	IR[28] =  instructionMemory[ValueInDecimal(PC)][4];
	IR[29] =  instructionMemory[ValueInDecimal(PC)][5];
	IR[30] =  instructionMemory[ValueInDecimal(PC)][6];
	IR[31] =  instructionMemory[ValueInDecimal(PC)][7];
}

void parseInstructionInIR(bool* name, bool* reg_out,bool* reg_in1, bool* reg_in2, bool* imm16)
{
	name[0]    =  IR[0];
	name[1]    =  IR[1];
	name[2]    =  IR[2];
	name[3]    =  IR[3];
	name[4]    =  IR[4];
	name[5]    =  IR[5];
	name[6]    =  IR[6];
	name[7]    =  IR[7];
	
	reg_out[0] =  IR[8];
	reg_out[1] =  IR[9];
	reg_out[2] =  IR[10];
	reg_out[3] =  IR[11];
	reg_out[4] =  IR[12];
	reg_out[5] =  IR[13];
	reg_out[6] =  IR[14];
	reg_out[7] =  IR[15];
	
	reg_in1[0] =  IR[16];
	reg_in1[1] =  IR[17];
	reg_in1[2] =  IR[18];
	reg_in1[3] =  IR[19];
	reg_in1[4] =  IR[20];
	reg_in1[5] =  IR[21];
	reg_in1[6] =  IR[22];
	reg_in1[7] =  IR[23];
	
	reg_in2[0] =  IR[24];
	reg_in2[1] =  IR[25];
	reg_in2[2] =  IR[26];
	reg_in2[3] =  IR[27];
	reg_in2[4] =  IR[28];
	reg_in2[5] =  IR[29];
	reg_in2[6] =  IR[30];
	reg_in2[7] =  IR[31];
}
	
	


void initializeInstructionMemory(ifstream& fp)
{
	fp("file.txt");
	if(file.is_open())
	{
		string instructions[8];
		for(int i = 0; i < 8; i++){
			file >> instruction[i];
		}
	}	
}

bool* getInstructionValue(bool* output, const std::string& instructionName)
{
	return output;
}


void mem(bool registerNum[8], bool memlocation[16], bool read, bool write)
{
	if(read == write)
	{
		throw(runtime_error("MEM error: read == write"));
	}
	else if(read)
	{
		lw(registerNum, memlocation);
	}
	else 
	{
		sw(registerNum, memlocation);
	}
}
		
void lw(bool registerNum[8], bool memlocation[16])
{
	readMem(registerNum, memlocation);
}

void sw(bool registerNum[8], bool memlocation[16])
{
	writeMem(registerNum, memlocation);
}


void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write)
{
	if(read)
	{
		readMem(value, memlocation);
	}
	else
	{
		writeMem(value, memlocation);
	}
}

void readMem(bool value[8], bool memlocation[16])
{
	registry[ValueInDecimal(value)][0] = memlocation[0];
	registry[ValueInDecimal(value)][1] = memlocation[1];
	registry[ValueInDecimal(value)][2] = memlocation[2];
	registry[ValueInDecimal(value)][3] = memlocation[3];
	registry[ValueInDecimal(value)][4] = memlocation[4];
	registry[ValueInDecimal(value)][5] = memlocation[5];
	registry[ValueInDecimal(value)][6] = memlocation[6];
	registry[ValueInDecimal(value)][7] = memlocation[7];
}

void writeMem(bool value[8], bool memlocation[16])
{
	memlocation[0] = registry[ValueInDecimal(value)][0];
	memlocation[1] = registry[ValueInDecimal(value)][1];
	memlocation[2] = registry[ValueInDecimal(value)][2];
	memlocation[3] = registry[ValueInDecimal(value)][3];
	memlocation[4] = registry[ValueInDecimal(value)][4];
	memlocation[5] = registry[ValueInDecimal(value)][5];
	memlocation[6] = registry[ValueInDecimal(value)][6];
	memlocation[7] = registry[ValueInDecimal(value)][7];
}