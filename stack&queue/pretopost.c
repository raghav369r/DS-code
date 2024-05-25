#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;
int isope(char c){
	switch(c){
		case '+':
			return 1;
		case '%':
			return 1;
		case '/':
			return 1;
		case '*':
			return 1;
		case '-':
			return 1;
	}
	return 0;
}
void pretopost(char *ex){
	int len=strlen(ex),i,j=0;
	char post[20];
	for(i=0;i<len;i++){
		if(isope(ex[i]))
			stack[++top]=ex[i];
		else{
			 post[j++]=ex[i];
			 while(top!=-1 && stack[top]=='@'){
			 	top--;
			 	post[j++]=stack[top--];
			 }
			 stack[++top]='@';
		}
		post[j]='\0';
	}
	printf("post fix= %s",post);
}
int main(){
	char *pre;
	printf("enter prefix: ");
	scanf("%s",pre);
	
	pretopost(pre);
	//intf("== %s",post);
}
