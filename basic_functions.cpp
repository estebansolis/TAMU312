#include "basic_functions.h"
#include <cstdio>
#include <iostream>

using namespace std;


int functionCount = 0;

bool lastBit(bool output, bool* input) {
	output = input[7];
	return output;
}

bool And(bool a, bool b){
	return (a && b);
}

bool Or (bool a, bool b){
	return (a || b);

}
bool Not(bool a) {
	return !a;
}

void printFunctionCount(){
	printf("%d\n", functionCount);
}
void print(bool a){
	printf("%d\n", a);
}

void resetFunctionCount(){
	functionCount = 0;
}

bool getValue(bool byte[8], int offset){
	// getValue gets the specific bit from "byte" at position "offset".
	bool x = byte[offset];
	return x;
}
void writeValue(bool* byte, int offset, bool value){
	//writeValue writes the bit given by "value" to position "offset" of "byte".
	byte[offset] = value;
}

void printValue(bool byte[8]){
	PRINT(byte[0]);
	PRINT(byte[1]);
	PRINT(byte[2]);
	PRINT(byte[3]);
	PRINT(byte[4]);
	PRINT(byte[5]);
	PRINT(byte[6]);
	PRINT(byte[7]);

}

void printValueInDecimal(bool byte[8]){
	// printValueInDecimal converts "byte" into a decimal number (assuming the number is signed, which means it can be positive or negative) and print it out.
	int i;
	int output=0;
	int power =1;
	output = output + byte[7]*power;
	power *= 2;	
	output = output + byte[6]*power;
	power *= 2;
	output = output + byte[5]*power;
	power *= 2;
	output = output + byte[4]*power;
	power *= 2;
	output = output + byte[3]*power;
	power *= 2;
	output = output + byte[2]*power;
	power *= 2;
	output = output + byte[1]*power;
	power *= 2;
	output = output + byte[0]*power;
	printf("%d\n", output);
}

int ValueInDecimal(bool byte[8]){
	int i;
	int output=0;
	int power =1;
	output = output + byte[7]*power;
	power *= 2;	
	output = output + byte[6]*power;
	power *= 2;
	output = output + byte[5]*power;
	power *= 2;
	output = output + byte[4]*power;
	power *= 2;
	output = output + byte[3]*power;
	power *= 2;
	output = output + byte[2]*power;
	power *= 2;
	output = output + byte[1]*power;
	power *= 2;
	output = output + byte[0]*power;

	return output; 
}

bool zeroOutput(bool input[8]){
	bool a = Or(0,input[0]);
	bool b = Or(a ,input[1]);
	bool c = Or(b,input[2]);
	bool d = Or(c, input[3]);
	bool e = Or(d, input[4]);
	bool f = Or(e, input[5]);
	bool g = Or(f, input[6]);
	bool h = Or(g, input[7]);
	return h;
}

bool* zeroPlusOutput(bool input){
 	bool output[8];
	output[0] = Or(0, input);
	output[1] = Or(0, input);
	output[2] = Or(0, input);
	output[3] = Or(0, input);
	output[4] = Or(0, input);
	output[5] = Or(0, input);
	output[6] = Or(0, input);
	output[7] = Or(0, input);

	return output;
}
