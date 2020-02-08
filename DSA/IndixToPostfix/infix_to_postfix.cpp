/*Implement stack for expression conversion (infix to postfix)*/

#include<iostream>

int ICP(char *a);

int main(){
	char infix[30],buffer[30];
	std::cin>>infix;
	int icp;
	char stack[30];
	int buff,i,stack_top;
	for(stack_top = 0,buff = 0,i = 0; infix[i] != '\0'; i++){
		icp = ICP(&(infix[i]));
		if(icp == -1){
			buffer[buff++] = infix[i];
		}
		else {
			if(icp>ICP(stack[stack_top - 1]))
			stack[stack_top++] = infix[i];
		}
		std::cout<<icp<<std::endl;
	}
	std::cout<<buffer;
	return 0;
}

int ICP(char *a){
	char incoming = *a;
	switch(incoming){
			case '^':
				return 0;
			case '*':
			case '/':
			case '%':
				return 1;
			case '+':
			case '-':
				return 3;
			default:
				return -1;
	}
}
