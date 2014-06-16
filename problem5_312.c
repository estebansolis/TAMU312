

bool MULTU (bool* output, bool input1[8], bool input2[8]){
	bool* exput;

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);


	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);
							
		

	if(AND(input2,1)){
		output = output + input1;
	}
		shiftRight(exput,input2);
		shiftLeft(exput,input1);	
		return output;
}

bool DIVU (bool* output, bool input1[8], bool input2[8]){
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);
	shiftLeft(output,input1);

	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);



	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	
	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	
	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	
	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	
	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	
	shiftRight(output,input1);
	shiftLeft(output,output);
	input2 = sub(input2,input1);

	if(lessthan(input2,0)){
		input2 = input2 + input1;
	}
	else{
		output = output + 1;
	}

	shiftLeft(output,output);

	return output;


}