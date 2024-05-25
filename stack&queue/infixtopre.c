#include<stdio.h>
#include<stdlib.h>
int top=-1;
char stack[100];
void push(char ele){
	stack[++top]=ele;
	stack[top+1]='\0';
}
int pop(){
	return stack[top--];
}
int preced(char op){
	if(op=='+' || op=='-') return 1;
	else if(op=='%' || op=='/' || op=='*') return 3;
	else return 0;
}
char* intopostfix(char *infix,char *postfix){
	int len,i,j=0;
	for(len=0;infix[len]!='\0';len++);
	for(i=0;i<len;i++){
		if(infix[i]>=97 && infix[i]<=122 || infix[i]>=65 && infix[i]<=90)
			postfix[j++]=infix[i];
		else if(infix[i]=='('||infix[i]=='{'||infix[i]=='[')
			push(infix[i]);
		else if(infix[i]==')'||infix[i]=='}'||infix[i]==']'){
			char open;
			open=(infix[i]=='}')?infix[i]-2:infix[i]-1;
			while(stack[top]!=open)
				postfix[j++]=pop();
			pop();	
		}
		else{
	if(preced(infix[i])>preced(stack[top])|| top==-1 || stack[top]=='(' || stack[top]=='[' ||stack[top]=='{')
			push(infix[i]);
			else{
				while(preced(stack[top])>=preced(infix[i]))
					postfix[j++]=pop();
				push(infix[i]);
			}
		}
		postfix[j]='\0';
	}
	while(top!=-1)
		postfix[j++]=pop();
	postfix[j]='\0';
	//printf("\ninfix expression: %s\npostfix Expression: %s",infix,postfix);
	return postfix;
}
char *reverse(char *infix){
	int len,i;
	char tmp;
	for(len=0;infix[len]!='\0';len++);
	for(i=0;i<len/2;i++){
			if(infix[i]=='(') infix[i]=')';
			else if(infix[i]==')') infix[i]='(';
			if(infix[len-1-i]=='(') infix[len-1-i]=')';
			else if(infix[len-1-i]==')') infix[len-1-i]='(';
			tmp=infix[i];
			infix[i]=infix[len-1-i];
			infix[len-i-1]=tmp;
	}
	if((len/2)%2==0 && infix[len/2]=='(') infix[len/2]=')';
	else if((len/2)%2==0 && infix[len/2]==')') infix[len/2]='(';
}
char* intoprefix(char *infix,char *prefix){
	reverse(infix);	//printf("reversed infix= %s\n",infix);
	intopostfix(infix,prefix);	 //printf("postfix after rev of infix= %s\n",prefix);
	reverse(prefix);	//printf("prefix after rev of postfix= %s\n",prefix);
	//return prefix;
}
int main(){
	char infix[100];
	char prefix[100];
	//char infix[100]="(a*b)-(c+(d/e-f)+g)*h";
	//char infix[100]="a+b-c/d*e-f+g";
	//char infix[100]="(A+B)*C-D";
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	printf("infix= %s\n",infix);
	intoprefix(infix,prefix);
	printf("prefix= %s",prefix);
}
