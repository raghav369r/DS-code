#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear=-1,front=-1;
void enqueue(){
	if(rear==size-1)printf("No space to enqueue");
	else{
		int ele;
		printf("Enter element to insert: ");
		scanf("%d",&ele);
		rear++;
		queue[rear]=ele;
		
	}
}
void dequeue(){
	if(rear==-1 || rear==front)printf("no elements to delete");
	else{
		front++;
		printf("\n%d id deleted\n",queue[front]);
	}
}
void display(){
	if(rear==-1 || front==rear) printf("No elements to display");
	else{
		int i;
		for(i=front+1;i<=rear;i++) printf("%d\n",queue[i]);
	}
}
int main(){
	int opt;
	while(1){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	
}
