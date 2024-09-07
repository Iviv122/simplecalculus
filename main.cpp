#include <cstdlib>
#include <cstdio>

int getDigit(char digit){
	return digit-'0';
}

int getArg(char* arg, int size){
	
	int answer =0;
	
	for(int i=0;i<size;i++){

	answer += getDigit(arg[size-i-1])+answer*10; 

	}
	return answer;
}

float solveProblem(int operations, char* operators,int argc, int* args){

	float answer=args[0];

	int i=0;
	int j=1;
	
	while(i<operations){
	if(operators[i] == '+'){
	answer+=args[j];
	j++;	
	}else{
	answer-=args[j];
	j++;
	}
	
	i++;	
	}

	return answer;

}


int main(void){


	char* operators = (char*)malloc(1*sizeof(char));
	int operations =0;

	int* args = (int*)malloc(1*sizeof(int));
	char* arg = (char*)malloc(1*sizeof(char));
	int argc = 0;

	int i =0;
	int j =0;
	char c;
	
	printf("Write your problem (+- and ints only) \n");
	while((c=getchar()) != '\n'){

	if(c >= '0' && c <= '9'){
		arg[j] = c;
		j++;
		arg = (char*) realloc(arg, (j+1)*sizeof(char));	
	}
	
	if(c == '+' || c == '-' ) {
		args[argc] = getArg(arg, j);
		argc++;
		j=0;
		args = (int*)realloc(args,(argc+1)*sizeof(int));

		operators[operations] = c;
		operations++;
		operators= (char*)realloc(operators,operations*sizeof(char));
	}

	i++;
	}

	if (j > 0) {
        args[argc] = getArg(arg, j);
        argc++;
    	}
	
	printf("%f\n", solveProblem(operations,operators, argc,args));

	free(operators);
	free(args);
	free(arg);

	return 0;
}
