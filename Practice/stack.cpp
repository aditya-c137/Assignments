#include<iostream>
using namespace std;

int priority(char a){
	switch (a){
		case '(':
			return 6;
		case '^':
			return 5;
		case '*':
		case '/':
			return 4;
		case '+':
		case '-':
			return 3;
		case ')':
			return 2;
		default:
			return 1;
	}
}

void push(char *a,char b){
	char* temp = a;
	for(int i=0;*temp != '\0';i++){
		temp++;
	}
	*(temp) = b;
}

int length(char *a){
	char *temp = a;
	int i;
	for(i=0;*temp != '\0';i++){
		temp++;
	}
	return i-1;
}

char top_of_the_stack(char *a){
	char *temp = a;
	for(int i=0;*temp != '\0';i++){
		temp++;
	}
	return *(temp-1);
}

char pop(char *a){
	char *temp = a;
	char poped;
	for(int i=0;*temp != '\0';i++){
		temp++;
	}
	poped = *(temp-1);
	*(temp-1) = '\0';
	return poped;
}

void infix_to_postfix(char a[]){
	char stack[50];
	int prio = 0;
	char x;
	for(int i = 0; i < 50; i++)
		{stack[i] = '\0';}
	for(int i = 0; i < 50; i++){
		if(a[i]==';'){
			for(int i = length(stack); i >= 0 ; i--)
				cout<<stack[i];
			break;
		}
		prio = priority(a[i]);
		switch(prio){
			case 1:
				cout<<a[i];
				break;
			case 3:
				if(stack[0]!='\0'){
					while((prio <= priority(top_of_the_stack(stack))) && (top_of_the_stack(stack) != '(')){
						cout<< pop(stack);
					}
				}
				push(stack,a[i]);
				break;
			case 4:
				if(stack[0]!='\0'){
					while((prio <= priority(top_of_the_stack(stack))) && (top_of_the_stack(stack) != '(')){
						cout<< pop(stack);
					}
				}
				push(stack,a[i]);
				break;
			case 5:
				push(stack,a[i]);
				break;
			case 6:
				push(stack,a[i]);
				break;
			case 2:
				while(top_of_the_stack(stack)!='('){
					cout<<pop(stack);
				}
				pop(stack);
		}
	}
}

int main(){
	char a[50];
	cout<<"enter expression: ";
	cin>>a;
	cout<<endl;
	infix_to_postfix(a);
	return 0;
}
