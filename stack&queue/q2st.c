#include<stdio.h>
int stack1[5],stack2[5];
int top1=-1,top2=-1;

void display();
void push1(int );
void push2(int );
int pop1();
int pop2();

int main(){
	int opt,ele;
	while(1){
		printf("1..ENQUEUE\t2..DEQUEUE\t3..Display\t4..Exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter ele to enqueue: ");
				scanf("%d",&ele);
				push1(ele);
				break;
			case 2:
				if(top1==-1 && top2==-1) printf("Queue Empty!\n");
				else if(top2==-1){
					while(top1!=0)
						push2(pop1());
					pop1();
				}
				else pop2();
				break;
			case 3:
				display();
				break;
			/*case *:
				if(top1!=-1) printf("top= %d\n",stack1[top1]);
				else printf("top= %d\n",stack2[0]);
				break;
			*/
			case 4:
				return 1;
				
		}
	}
}

void push2(int ele){
	stack2[++top2]=ele;
}

void push1(int num){
	if(top1==4) printf("Queue Full!\n");
	else stack1[++top1]=num;
}

int pop1(){
	return stack1[top1--];
}

int pop2(){
	return stack2[top2--];
}

void display(){
	if(top1==-1 && top2==-1){
		printf("Empty Queue!\n");
		return;
	}
	int i;
	for(i=top2;i>=0;i--) printf("%d - ",stack2[i]);
	for(i=0;i<=top1;i++) printf("%d - ",stack1[i]);
	printf("\n");
}
