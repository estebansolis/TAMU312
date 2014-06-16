// Overflow
// for add 
/* When two signed 2's complement numbers are added, overflow is detected if:

both operands are positive and the result is negative, or

both operands are negative and the result is positive. */

// When two unsigned numbers are added, overflow occurrs if there is a carry out of the leftmost bit.

bool Overflow(bool input1[8], bool input2[8]){
	bool x = AND(AND(NOT(input1[0]),NOT(input[0])),SUM(input1[0],input2[0])));
	bool y = AND(AND(input1[0], input2[0]),NOT(SUM(input1[0],input2[0])));

	bool i10 = input1[7];
	bool i20 = input2[7];
	bool carryOut0 = CarryOut(i10, i20,0);
	
	bool i11 = input1[6];
	bool i21 = input2[6];
	
	bool carryOut1 = CarryOut(i11, i21, carryOut0);
	
	bool i12 = input1[5];
	bool i22 = input2[5];
	bool carryOut2 = CarryOut(i12, i22, carryOut1);

	bool i13 = input1[4];
	bool i23 = input2[4];
	bool carryOut3 = CarryOut(i13, i23, carryOut2);

	bool i14 = input1[3];
	bool i24 = input2[3];
	bool carryOut4 = CarryOut(i14, i24, carryOut3);

	bool i15 = input1[2];
	bool i25 = input2[2];
	bool carryOut5 = CarryOut(i15, i25, carryOut4);

	bool i16 = input1[1];
	bool i26 = input2[1];
	bool sum6 = SUM(i16, i26, carryOut5);
	bool carryOut6 = CarryOut(i16, i26, carryOut5);
	output[1] = sum6;

	bool i17 = input1[0];
	bool i27 = input2[0];
	bool carryOut7 = CarryOut(i17, i27, carryOut6);

	return OR(OR(x,y),carryOut7);
}
 

bool* add(bool* output, bool input1[8], bool input2[8]){
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

	bool overflow1 = overflow(input1, input2);

	// havent figured out how to call the exception overflow

}
	return output;

}
bool* sub(bool* output, bool input1[8], bool input2[8]){
bool* input3 = negate(output, input2);
	output = add(output, input1, input3);
	bool overflow1 = overflow(input1, input3);

	return output;
}	