#include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1,stack[size];
void push(){
	if(top==size-1) printf("stack overflow!");
	else{
		int num;
		printf("Enter no to add: ");
		scanf("%d",&num);
		top++;
		stack[top]=num;
	}
}
void pop(){
	if(top==-1) printf("stack is empty!");
	else{
		printf("%d is deleted\n",stack[top]);
		top--;	
	}
}
int main(){
	int opt;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				if(top==-1) printf("stack is empty!\n");
				else for(int i=top;i>=0;i--) printf("%d-->",stack[i]);
				break;
			case 4:
				exit(0);
		}
	}
	
}
