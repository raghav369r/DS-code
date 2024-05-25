#include<stdio.h>
char stack[100],stack1[100],infix[20],pos[20];
int top=-1,top1=-1;
int prec(char c){
	if(c=='+' || c=='-') return 1;
	else return 2;
}
char *post(char *ex){
	//char infix[20];
	int i,j,in=0,len;
	for(len=0;ex[len]!='\0';len++);
	for(i=len-1;i>-1;i--){
		if(ex[i]>=65 && ex[i]<=90 || ex[i]>=97 && ex[i]<=122)
			stack[++top]=ex[i];
		else{
			if(in==len-1)
				infix[in++]=stack[top--];
			infix[in++]=ex[i];
			infix[in++]=stack[top--];
		}
		infix[in]='\0';
		//printf("infix= %s\n",infix);
	}
	printf("infix= %s\n",infix);
	in=0;
	printf("infix\t\t\tstack\t\t\tpostfix\n");
	for(i=0;i<len;i++){
		if(infix[i]>=65 && infix[i]<=90 || infix[i]>=97 && infix[i]<=122)
			pos[in++]=infix[i];
		else{
			if(top1==-1 || prec(infix[i])>prec(stack1[top1]))
				stack1[++top1]=infix[i];
			else{
				while(top1!=-1 && prec(stack1[top1])>=prec(infix[i]))
					pos[in++]=stack1[top1--];
				stack1[++top1]=infix[i];
			}
			stack1[top1+1]='\0';
		}
		printf("%c\t\t\t%s\t\t\t%s\n",infix[i],stack1,pos);
	}
	while(top1!=-1)
		pos[in++]=stack1[top1--];
	pos[in]='\0';
	return pos;
}
int main(){
	char *pre;
	printf("Enter prefix ex: ");
	scanf("%s",pre);
	printf("%s\n\n",pre);
	//pre="++A*BCD";
	char *postfix=post(pre);
	printf("post fix= %s",postfix);
}
