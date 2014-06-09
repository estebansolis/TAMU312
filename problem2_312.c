#include <stdio.h>
#include <stdbool.h>

static int functionCount;

void printFunctionCount(){
	printf("%d\n", functionCount);
}

void PRINT(bool a){
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
//-----------------------------------------------------------------------------------------------------------

bool AND(bool a, bool b){
	return (a && b);
}
bool OR (bool a, bool b){
	return (a || b);
}
bool NOT(bool a) {
	return !a;
}
bool XOR(bool a, bool b){
    return(OR(AND(a,NOT(b)),AND(NOT(a),b)));
}
bool Mux(bool operation, bool output_if_true, bool output_if_false){
	return(OR(AND(operation, output_if_true), AND(NOT(operation), output_if_false)));   
}
bool Sum(bool a, bool b){
	return (XOR(a,b));
}	
bool CarryOut(bool a, bool b, bool c){
	return (Sum(Sum(a,b),c));
}
bool Equal(bool a, bool b){
	return !Sum(a,b);
}

//----------------------------------------------------------------------------------------------------------


bool* mux(bool* output, bool operation, bool input1[8], bool input2[8]){
	
	output[0]= Mux(operation,input1[0], input2[0]);  // mux from problem 1 
	output[1]= Mux(operation,input1[1], input2[1]);
	output[2]= Mux(operation,input1[2], input2[2]);
	output[3]= Mux(operation,input1[3], input2[3]);
	output[4]= Mux(operation,input1[4], input2[4]);
	output[5]= Mux(operation,input1[5], input2[5]);
	output[6]= Mux(operation,input1[6], input2[6]);
	output[7]= Mux(operation,input1[7], input2[7]);

	return output; 
}


bool* addu(bool* output, bool input1[8], bool input2[8]){
	bool i10    = input1[7];
	bool i20 = input2[7];
	bool sum0 = Sum(i10, i20);
	bool carryOut0 = CarryOut (i10, i20,0);
	output[7] = sum0;

	bool i11 = input1[6];
	bool i21 = input2[6];
	bool sum1 = Sum(i11, i21);
	bool carryOut1 = CarryOut(i11, i21, carryOut0);
	output[6] = sum1;

	bool i12 = input1[5];
	bool i22 = input2[5];
	bool sum2 = Sum(i12, i22);
	bool carryOut2 = CarryOut(i12, i22, carryOut1);
	output[5] = sum2;

	bool i13 = input1[4];
	bool i23 = input2[4];
	bool sum3 = Sum(i13, i23);
	bool carryOut3 = CarryOut(i13, i23, carryOut2);
	output[4] = sum3;

	bool i14 = input1[3];
	bool i24 = input2[3];
	bool sum4 = Sum(i14, i24);
	bool carryOut4 = CarryOut(i14, i24, carryOut3);
	output[3] = sum4;

	bool i15 = input1[2];
	bool i25 = input2[2];
	bool sum5 = Sum(i15, i25);
	bool carryOut5 = CarryOut(i15, i25, carryOut4);
	output[2] = sum5;

	bool i16 = input1[1];
	bool i26 = input2[1];
	bool sum6 = Sum(i16, i26);
	bool carryOut6 = CarryOut(i16, i26, carryOut5);
	output[1] = sum6;

	bool i17 = input1[0];
	bool i27 = input2[0];
	bool sum7 = Sum(i17, i27);
	//bool carryOut7 = CarryOut(i17, i27, carryOut6);
	output[0] = sum7;

	return output;
}

bool* negate(bool* output, bool input[8]){
	
	output[0] = NOT(input[0]);
	output[1] = NOT(input[1]);
	output[2] = NOT(input[2]);
	output[3] = NOT(input[3]);
	output[4] = NOT(input[4]);
	output[5] = NOT(input[5]);
	output[6] = NOT(input[6]);
	output[7] = NOT(input[7]);

	return output;
}

/*

bool* subu(bool* output, bool input1[8], bool input2[8]){
	// a - b

	bool* input3 = negate(output, input2);
	output = addu(output, input1, input3);

	return output;

}

bool* equal(bool input1[8], bool input2[8]){
	// negates one and adds them if return 0 it's equal
	return subu(input1, input2);
}
*/
bool lessthan(bool input1[8], bool input2[8]){

}

bool greaterthan(bool input1[8], bool input2[8]){

}
int main(){
	bool test1[8] = {1, 1, 1, 1, 0, 0, 0, 1};  
	bool test2[8] = {1, 0, 0, 1, 1, 1, 1, 0};
	bool output[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	//mux(test1, test2);
	//printValue(addu(output, test1, test2));
	//printValue(negate(output, test2));
	//printValue(subu(output, test1, test2));
	//printValue(equal(test1, test2));
	printValueInDecimal(test1);
	return 0; 
}