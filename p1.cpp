#include "p1.h"
#include "basic_functions.h"
#include <iostream>


bool XOR(bool a, bool b){
    return	Or(And(a,Not(b)),And(Not(a),b));
}

bool Mux(bool operation, bool output_if_true, bool output_if_false){
	return	Or(And(operation, output_if_true), And(Not(operation), output_if_false));   
}

bool Sum(bool a, bool b){
	return XOR(a,b);
}

bool Sum(bool a, bool b, bool c){
	return XOR(XOR(a,b),c);
}

bool CarryOut(bool a, bool b, bool c){
	bool x = XOR(a,b);
	return Or(And(c,x),And(a,b));
}

bool Equal(bool a, bool b){
	return !XOR(a,b);
}


