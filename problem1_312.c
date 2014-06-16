#include <stdio.h>
#include <stdbool.h>

static int functionCount;


bool XOR(bool a, bool b){
    return	OR(AND(a,NOT(b)),AND(NOT(a),b));
}

bool Mux(bool operation, bool output_if_true, bool output_if_false){
	return	OR(AND(operation, output_if_true), AND(NOT(operation), output_if_false));   
}

bool Sum(bool a, bool b){
	return XOR(a,b);
}

bool Sum(bool a, bool b, bool c){
	return XOR(XOR(a,b),c);
}

bool CarryOut(bool a, bool b, bool c){
	bool x = XOR(a,b);
	return OR(AND(c,x),AND(a,b));
}

bool Equal(bool a, bool b){
	return !XOR(a,b);
}


