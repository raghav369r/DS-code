#include<stdio.h>
char infix[100],postfix[100],prefix[100];
char stack[100],stack1[100];
int top=-1,top1=-1;
void rev(char *ex){
	int len,i;
	for(len=0;ex[len]!='\0';len++);
	for(i=0;i<len/2;i++){
		char tmp=ex[i];
		ex[i]=ex[len-i-1];
		ex[len-i-1]=tmp;
	}
	printf("After rev: %s\n",prefix);
}
int preced(char c){
	if(c=='+'||c=='-') return 1;
	else return 2;
}
void infixtopostfix(char *infix){
	int len,j=0,i;
	for(len=0;infix[len]!='\0';len++);
	printf("i/p\t\t\tstack\t\t\toutput\n");
	for(i=0;i<len;i++){
		if((infix[i]<=90 && infix[i]>=65) || (infix[i]>=97 && infix[i]<=122))
			postfix[j++]=infix[i];
		else{
			if(top1==-1 || preced(stack1[top1])<preced(infix[i]))
				stack1[++top1]=infix[i];
			else{
				while(top1!=-1 && preced(stack[top1])>=preced(infix[i]))
		//		printf("\n")
					postfix[j++]=stack1[top1--];
				stack1[++top1]=infix[i];
			}
		}
		postfix[j]='\0';
			printf("%c\t\t\t%s\t\t\t%s\n",infix[i],stack1,postfix);
	}
	while(top1!=-1)
		postfix[j++]=stack1[top1--];
	postfix[j]='\0';
}
void prefixtopostfix(char *ex){
	rev(ex);
	printf("ex= %s\n",ex);
	int ind=0,len,j;
	for(len=0;ex[len]!='\0';len++);
	for(j=0;j<len;j++){
		if((ex[j]<=90 && ex[j]>=65)||(ex[j]>=97 && ex[j]<=122))
			stack[++top]=ex[j];
		else{
			if(ind==0)
				infix[ind++]=stack[top--];
			infix[ind++]=ex[j];
			infix[ind++]=stack[top--];
		}
	}
	printf("infix= %s\n",infix);
	infixtopostfix(infix);
	printf("the postfix expression is: %s",postfix);	
}
int main(){
	printf("Enter prefix: ");
	scanf("%s",prefix);
	prefixtopostfix(prefix);
}




