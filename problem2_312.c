#include <stdio.h>
#include <stdbool.h>

static int functionCount;





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
	bool sum5 = SUM(i15, i25,carryOut4);
	bool carryOut5 = CarryOut(i15, i25, carryOut4);
	output[2] = sum5;

	bool i16 = input1[1];
	bool i26 = input2[1];
	bool sum6 = SUM(i16, i26, carryOut5);
	bool carryOut6 = CarryOut(i16, i26, carryOut5);
	output[1] = sum6;

	bool i17 = input1[0];
	bool i27 = input2[0];
	bool sum7 = Sum(i17, i27, carryOut6);
	output[0] = sum7;

	return output;
}

bool* negate(bool* output, bool input[8]){
	
	neg[0] = NOT(input[0]);
	neg[1] = NOT(input[1]);
	neg[2] = NOT(input[2]);
	neg[3] = NOT(input[3]);
	neg[4] = NOT(input[4]);
	neg[5] = NOT(input[5]);
	neg[6] = NOT(input[6]);
	neg[7] = NOT(input[7]);
	
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
	
	return zeroOutput(subu(input1, input2));
}

bool lessthan(bool input1[8], bool input2[8]){
	// return 0 if false
	bool x = AND(AND(AND(NOT(input1[7]),input2[7]),AND(NOT(input1[6]),input2[6])),(AND(AND(NOT(input1[5]),input2[5])),AND(NOT(input1[4],input2[4]))));
	bool y = AND(AND(AND(NOT(input1[3]),input2[3]),AND(NOT(input1[2]),input2[2])),(AND(AND(NOT(input1[1]),input2[1])),AND(NOT(input1[0],input2[0]))));
	return AND(x,y); // if it comes out incorrect check OR(x,y)
}
bool greaterthan(bool input1[8], bool input2[8]){
	bool x = AND(AND(AND(input1[7],NOT(input2[7])),AND(input1[6],NOT(input2[6]))),(AND(AND(input1[5],NOT(input2[5]))),AND(input1[4],NOT(input2[4]))));
	bool y = AND(AND(AND(input1[3],NOT(input2[3])),AND(input1[2],NOT(input2[2]))),(AND(AND(input1[1],NOT(input2[1]))),AND(input1[0],NOT(input2[0]))));
	return  AND(x,y);
}

bool* equal(bool* output, bool input1[8],bool input2[8]){
	subu(input1, input2); //returns 00000000 if equal
}
bool* lessthan(bool input1[8], bool input2[8]){
	// returns 0000 00000
	return zeroPlusOutput( lessthan(bool input1[8], bool input2[8]))
}
bool* greaterthan(bool input1[8], bool input2[8]){
	// returns 0000 00000
	return zeroPlusOutput( greaterthan(bool input1[8], bool input2[8]));
}
bool* and(bool* output, bool input1[8], bool input2[8]){

	output[7] = AND(input1[7],input2[7]);
	output[6] = AND(input1[6],input2[6]);
	output[5] = AND(input1[5],input2[5]);
	output[4] = AND(input1[4],input2[4]);
	output[3] = AND(input1[3],input2[3]);
	output[2] = AND(input1[2],input2[2]);
	output[1] = AND(input1[1],input2[1]);
	output[0] = AND(input1[0],input2[0]);

}
bool* or(bool* output, bool input1[8], bool input2[8]){

	output[7] = OR(input1[7],input2[7]);
	output[6] = OR(input1[6],input2[6]);
	output[5] = OR(input1[5],input2[5]);
	output[4] = OR(input1[4],input2[4]);
	output[3] = OR(input1[3],input2[3]);
	output[2] = OR(input1[2],input2[2]);
	output[1] = OR(input1[1],input2[1]);
	output[0] = OR(input1[0],input2[0]);

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

int main(){
	bool test1[8] = {1, 1, 1, 1, 0, 0, 0, 1};  
	bool test2[8] = {1, 0, 0, 1, 1, 1, 1, 0};
	bool output[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	//mux(test1, test2);
	//printValue(addu(output, test1, test2));
	//printValue(negate(output, test2));
	//printValue(subu(output, test1, test2));
	//printValue(equal(test1, test2));
	//printValueInDecimal(test1);
	return 0; 
}