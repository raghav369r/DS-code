#include<stdio.h>
#include<stdlib.h>
int top=-1,stack[100];
void push(int ele){
	stack[++top]=ele;
}
int pop(){
	return stack[top--];
}
int evaluate(char *ex){
	int val1,val2,val;
	for(int i=0;ex[i]!='\0';i++){
		if(ex[i]>=97 && ex[i]<=122 || ex[i]>=65 && ex[i]<=90){
			printf("enter the value of %c: ",ex[i]);
			scanf("%d",&val1);
			push(val1);
		}
		else{
			val1=pop();
			val2=pop();
			switch(ex[i]){
				case '+':
					val=val2+val1;
					break;
				case '-':
					val=val2-val1;
					break;
				case '*':
					val=val2*val1;
					break;
				case '/':
					val=val2/val1;
					break;
				case '%':
					val=val2%val1;
					break;
				default:
					printf("SMT WENT WRONG!!");
					exit(0);
			}
			push(val);
		}
	}
	printf("\nsum= %d",(1+2)*3-(4-5)*(6+7));
	return stack[top];
}
int main(){
	char postfix[100];
	printf("Enter postfix expression: ");
	scanf("%s",postfix);
	printf("\nsum= %d",evaluate(postfix));
}
