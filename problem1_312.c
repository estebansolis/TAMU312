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

/*
int main(){
	bool a = 0;
	bool b = 1;
	PRINT(AND(a,b));
	PRINT(OR(a,b));
	PRINT(XOR(a,b));
	PRINT(Equal(a,b));


	return 0; 
}
*/