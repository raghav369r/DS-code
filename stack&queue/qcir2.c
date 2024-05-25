#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear=-1,front=-1;
void enq(){
	if(rear<size && rear==front) rear=front=-1;
	if((rear==size-1 && front==-1) ||(rear>=size && rear%size==front%size))
		printf("No space to insert element!");
	else{
		int ele,n;
		printf("Enter element to insert: ");
		scanf("%d",&ele);
		rear++;
		n=(rear)%size;
		queue[n]=ele;	
	}
}
void deq(){
	if(rear==-1 || rear==front){
		printf("No elements to delete!");
		//rear=front=-1;
	}
	else{
		front++;
		int n=(front)%size;
		printf("\n%d id deleted\n",queue[n]);
	}
}
void display(){
	if(rear==-1 || rear==front) printf("No elements to display");
	else{
		int i;
		for(i=front+1;i!=rear;i++){
			printf("%d\n",queue[i%size]);
		}
		printf("%d\n",queue[i%size]);
	}
}
int main(){
	int opt;
	while(1){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enq();
				break;
			case 2:
				deq();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}	
}
