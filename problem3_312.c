/*
Create variables for each of the following:
Let 16 (00010000)= ADDU
Let 17 (00010001)= SUBU
Let 2 (00000010)= NEG
Let 3 (00000011)= EQ
Let 4 (00000100)= LT
Let 5 (00000101)= GT
Let 6 (00000110)= AND
Let 7 (00000111)= OR
Let 8 (00001000)= SLL
Let 9 (00001001)= SRL
*/



bool* alu(bool instruction[8], bool input1[8], bool input2[8]){
bool* output; 
bool* add_result = addu(output, input1, input2); 
bool* sub_result = subu(output, input1, input2);
bool* neg_result = negate(output, input1);
bool* equal_result = equal(input1, input2);
bool* LT_result = lessthan(input1,input2);
bool* GT_result = greaterthan(input1, input2);
bool* AND_result = and(output, input1, input2);
bool* OR_result = or(output, input1,input2);
bool* SLL_result = shiftLeft(output, input1);
bool* SRL result = shiftRight(output, input1); 

}


bool* 8mux()
bool xADDU[8]  = {0, 0, 0, 1, 0, 0, 0, 0}; 
bool xSUBU[8] = {0, 0, 0, 1, 0, 0, 0, 1};
bool xNEG[8] = {0, 0,0, 0, 0, 0, 1, 0};
bool xEQ[8] = {0, 0, 0, 0, 0, 0, 1, 1};
bool xLT[8] = {0, 0, 0, 0, 0, 1, 0, 0};
bool xGT[8] = {0, 0, 0, 0, 0, 1, 0, 1};
bool xAND[8] = {0, 0, 0, 0, 0, 1, 1, 0};
bool xOR[8] = {0, 0, 0, 0, 0, 1, 1, 1};
bool xSLL[8] = {0, 0, 0, 0, 1, 0, 0, 0}; 
bool xSRl[8] = {0, 0, 0, 0, 1, 0, 0, 1};




e.g. assuming 1-bit control, choosing from add or sub:

bool* add_result = add(temp_buffer, a, b);
bool* sub_result = sub(temp_buffer, a, b);
return mutemp_buffer, control_bit, add_result, sub_result);

what you really need to do here is to extend mux() to mux2(), mux3(), mux4() etc which have 2, 3, or 4 control bits. this can be done like:

// mux2: control bits: ctrl1, ctrl2; inputs: a, b, c, d
return or(and(not(ctrl1), not(ctrl2), a),
          and(ctrl1, not(ctrl2), b),
          and(not(ctrl1), ctrl2, c),
          and(ctrl1, ctrl2, d));

same idea to make mux3, mux4, etc.