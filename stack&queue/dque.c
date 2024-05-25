#include<stdio.h>
#define size 5
int dq[size];
int front=-1;
int rear=-1;
int isfull(){
	if((front==-1 && rear==size-1) || (rear>=size && front%size==rear%size))
		return 1;
	return 0;
}
int isempty(){
	if((front==-1 && rear==-1) || front==rear)
		return 1;
	return 0;
}
int insertfront(int ele){
	if(front==rear) front=rear=-1;
	if(isfull()){
		printf("overflow!!\n");
		return 0;
	}
	if(front==-1){
		front=size-1;
		rear+=size;
	}
	dq[(front)%size]=ele;
	front --;
	return 1;
}
int insertrear(int ele){
	if(front==rear) front=rear=-1;
	if(isfull()){
		printf("overflow!!\n");
		return 0;
	}
	dq[(++rear)%size]=ele;
	return 1;
}
int delfront(){
	if(isempty()){
		printf("UnderFlow!!");
		return 0;
	}
	front++;
	return 1;
}
int delrear(){
	if(isempty()){
		printf("UnderFlow!!");
		return 0;
	}
	rear--;
	return 1;	
}
void display(){
	if(isempty()) printf("It's empty!!\n");
	else{
		int i;
		//for(i=0;i<size;i++) printf("%d - ",dq[i]);
		//printf("\n");
		/*for(i=front+1;i%size!=rear;i++){
			if(rear==-1 && i==size-1) break; 
			printf("%d -> ",dq[i%size]);
		}*/
		for(i=front+1;i<rear;i++)
			printf("%d -> ",dq[i%size]);
		printf("%d -> ",dq[i%size]);
	}
}
int main(){
	int opt,ele;
	while(1){
		printf("\n1.insert at front\n2.insert at rear\n3.delete at front\n4.delete at rear\n5.display\n6.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&ele);		
				insertfront(ele);
				//printf("front= %d\nrear= %d\n",front,rear);
				break;
			case 2:
				printf("Enter element to insert: ");
				scanf("%d",&ele);
				insertrear(ele);
				//printf("front= %d\nrear= %d\n",front,rear);
				break;
			case 3:
				delfront();
				//printf("front= %d\nrear= %d\n",front,rear);
				break;
			case 4:
				delrear();
				//printf("front= %d\nrear= %d\n",front,rear);
				break;
			
			case 5:
				display();
				//printf("front= %d\nrear= %d\n",front,rear);
				break;
			case 6:
				return 1;
		}
	}	
}
