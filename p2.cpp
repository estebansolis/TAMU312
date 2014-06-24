#include "p1.h"
#include "p2.h"
#include "basic_functions.h"
#include <iostream>


bool* mux(bool* output, bool operation, bool input1[8], bool input2[8]){
	//bool Mux(bool operation, bool output_if_true, bool output_if_false); pr1
	output[0]= Mux(operation, input1[0], input2[0]);  
	output[1]= Mux(operation, input1[1], input2[1]);
	output[2]= Mux(operation, input1[2], input2[2]);
	output[3]= Mux(operation, input1[3], input2[3]);
	output[4]= Mux(operation, input1[4], input2[4]);
	output[5]= Mux(operation, input1[5], input2[5]);
	output[6]= Mux(operation, input1[6], input2[6]);
	output[7]= Mux(operation, input1[7], input2[7]);

	return output; 
}


bool* addu(bool* output, bool input1[8], bool input2[8]){
	bool i10 = input1[7];
	bool i20 = input2[7];
	bool sum0 = Sum(i10, i20);
	bool carryOut0 = CarryOut(i10, i20,0);
	output[7] = sum0;

	bool i11 = input1[6];
	bool i21 = input2[6];
	bool sum1 = Sum(i11, i21, carryOut0);
	bool carryOut1 = CarryOut(i11, i21, carryOut0);
	output[6] = sum1;

	bool i12 = input1[5];
	bool i22 = input2[5];
	bool sum2 = Sum(i12, i22,carryOut1);
	bool carryOut2 = CarryOut(i12, i22, carryOut1);
	output[5] = sum2;

	bool i13 = input1[4];
	bool i23 = input2[4];
	bool sum3 = Sum(i13, i23,carryOut2);
	bool carryOut3 = CarryOut(i13, i23, carryOut2);
	output[4] = sum3;

	bool i14 = input1[3];
	bool i24 = input2[3];
	bool sum4 = Sum(i14, i24, carryOut3);
	bool carryOut4 = CarryOut(i14, i24, carryOut3);
	output[3] = sum4;

	bool i15 = input1[2];
	bool i25 = input2[2];
	bool sum5 = Sum(i15, i25,carryOut4);
	bool carryOut5 = CarryOut(i15, i25, carryOut4);
	output[2] = sum5;

	bool i16 = input1[1];
	bool i26 = input2[1];
	bool sum6 = Sum(i16, i26, carryOut5);
	bool carryOut6 = CarryOut(i16, i26, carryOut5);
	output[1] = sum6;

	bool i17 = input1[0];
	bool i27 = input2[0];
	bool sum7 = Sum(i17, i27, carryOut6);
	output[0] = sum7;

	return output;
}

bool* negate(bool* output, bool input[8]){
  bool neg[8];
	
	neg[0] = Not(input[0]);
	neg[1] = Not(input[1]);
	neg[2] = Not(input[2]);
	neg[3] = Not(input[3]);
	neg[4] = Not(input[4]);
	neg[5] = Not(input[5]);
	neg[6] = Not(input[6]);
	neg[7] = Not(input[7]);
	
	bool oneplus[8] = {0,0,0,0,0,0,0,1};

	output = addu(output, oneplus, output);
	return output;
}



bool* subu(bool* output, bool input1[8], bool input2[8]){
	// a - b
	bool* input3 = negate(output, input2);
	output = addu(output, input1, input3);

	return output;

}

bool equal(bool input1[8], bool input2[8]){
	// negates one and adds them if return 0 it's equal
	
  bool subu_result[8];
	return zeroOutput(subu(subu_result, input1, input2));
}

bool lessthan(bool input1[8], bool input2[8]){
	// return 0 if false
	bool x = And(And(And(Not(input1[7]),input2[7]), And(Not(input1[6]),input2[6])), And(And(Not(input1[5]),input2[5]), And(Not(input1[4]),input2[4])));
	bool y = And(And(And(Not(input1[3]),input2[3]), And(Not(input1[2]),input2[2])), And(And(Not(input1[1]),input2[1]), And(Not(input1[0]),input2[0])));
	return And(x,y); // if it comes out incorrect check Or(x,y)
}
bool greaterthan(bool input1[8], bool input2[8]){
	bool x = And(And(And(input1[7],Not(input2[7])), And(input1[6],Not(input2[6]))), And(And(input1[5],Not(input2[5])), And(input1[4],Not(input2[4]))));
	bool y = And(And(And(input1[3],Not(input2[3])), And(input1[2],Not(input2[2]))), And(And(input1[1],Not(input2[1])), And(input1[0],Not(input2[0]))));
	return  And(x,y);
}

bool* equal(bool* output, bool input1[8],bool input2[8]){
	subu(output, input1, input2); //returns 00000000 if equal
}
bool* lessthan(bool* output, bool input1[8], bool input2[8]){
	// returns 0000 00000
	return zeroPlusOutput( lessthan(output, input1, input2));
}
bool* greaterthan(bool* output, bool input1[8], bool input2[8]){
	// returns 0000 00000
	return zeroPlusOutput( greaterthan(output, input1, input2));
}
bool* and8(bool* output, bool input1[8], bool input2[8]){

	output[7] = And(input1[7],input2[7]);
	output[6] = And(input1[6],input2[6]);
	output[5] = And(input1[5],input2[5]);
	output[4] = And(input1[4],input2[4]);
	output[3] = And(input1[3],input2[3]);
	output[2] = And(input1[2],input2[2]);
	output[1] = And(input1[1],input2[1]);
	output[0] = And(input1[0],input2[0]);

}
bool* or8(bool* output, bool input1[8], bool input2[8]){

	output[7] = Or(input1[7],input2[7]);
	output[6] = Or(input1[6],input2[6]);
	output[5] = Or(input1[5],input2[5]);
	output[4] = Or(input1[4],input2[4]);
	output[3] = Or(input1[3],input2[3]);
	output[2] = Or(input1[2],input2[2]);
	output[1] = Or(input1[1],input2[1]);
	output[0] = Or(input1[0],input2[0]);

}

 bool* shiftLeft(bool* output, bool input[8]){
  //(shift left all bits, equivalent to multiplication with 2)
  	int temp = input[7];
  	input[7] = input[6];
	input[6] = input[5];
	input[5] = input[4];
	input[4] = input[3];
	input[3] = input[2];
	input[2] = input[1];
	input[1] = input[0];
	input[0] = temp;
  	return output;

}

 bool* shiftRight(bool* output, bool input[8]){ //(shift right all bits including the sign bit)(shift in same value as MSB)

	bool temp = input[0];
	input[0] = input[1];
	input[1] = input[2];
	input[2] = input[3];
	input[3] = input[4];
	input[4] = input[5];
	input[5] = input[6];
	input[6] = input[7];
	input[7] = temp;
  	return input;
}

