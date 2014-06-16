
extern int functionCount;

bool AND(bool a, bool b){
	return (a && b);
}
bool OR (bool a, bool b){
	return (a || b);

}
bool NOT(bool a) {
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

void printValueInDecimal(bool byte[8]);{
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

bool zeroOutput(bool input[8]){
	bool a = OR(0,input[0]);
	bool b = OR(a ,input[1]);
	bool c = OR(b,input[2]);
	bool d = or(c, input[3]);
	bool e = OR(d, input[4]);
	bool f = OR(e, input[5]);
	bool g = OR(f, input[6]);
	bool h = OR(g, input[7]);
	return h;
}

bool* zeroPlusOutput(bool input){
 	bool output[8];
	output[0] = OR(0, input);
	output[1] = OR(0, input);
	output[2] = OR(0, input);
	output[3] = OR(0, input);
	output[4] = OR(0, input);
	output[5] = OR(0, input);
	output[6] = OR(0, input);
	output[7] = OR(0, input);

	return output;
}