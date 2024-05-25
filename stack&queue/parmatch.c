#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1,i;
char stack[20];
void push(char ele){
	top++;
	stack[top]=ele;
}
char pop(){
	if(top==-1) return('\0');
	top--;
	return(stack[top+1]);
}
int isvalid(){
	char str[20];
	printf("Enter string: ");
	scanf("%s",str);
	if(strlen(str)%2!=0) return 0;
	else{
		for(i=0;str[i]!='\0';i++){
			if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
				push(str[i]);
			}
			else{
				char x=pop();
				if(x=='{' && str[i]!='}')
					return 0;
				else if(x=='[' && str[i]!=']')
					return 0;
				else if(x=='(' && str[i]!=')')
					return 0;
			}
		}
		if(top==-1) return 1;
		return 0;
	}
}
int main(){
	int opt=1;
	while(opt){
		if(isvalid()) printf("it is valid expression");
		else printf("not valid expression");
		printf("\n0..EXIT\n1..Check expression\nchoice: ");
		scanf("%d",&opt);
	}
}
