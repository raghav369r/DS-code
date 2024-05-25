#include<stdio.h>
#include<stdlib.h>
struct node{
	int data,priority;
	struct node *next;
};
typedef struct node node;
node *start=NULL;
int enqueue(int ele,int pri){
	node *ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->priority=pri;
	ptr->next=NULL;
	if(start==NULL){
		start=ptr;
	}
	else if(start->priority<pri){
		ptr->next=start;
		start=ptr;
	}
	else{
		node *tmp=start,*old;
		while(tmp->priority>=pri && tmp->next!=NULL){
			old=tmp;
			tmp=tmp->next;
		}
		if(tmp->priority>=pri) tmp->next=ptr;
		else{
			old->next=ptr;
			ptr->next=tmp;
		}
	}
}
int dequeue(){
	if(start==NULL){
		printf("UnderFlow!!");
		return (int *)NULL;
	}
	node *tmp=start;
	start = start->next;
	int d=tmp->data;
	int pri=tmp->priority;
	free(tmp);
	printf("%d of priotity %d deleted!!",d,pri);
	return d;
}
void display(){
	for(node *tmp=start;tmp!=NULL;tmp=tmp->next)
		printf("data: %d - pri: %d\n",tmp->data,tmp->priority);
}
int main(){
	int opt,ele,pri;
	while(1){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter data and its priority: ");
				scanf("%d%d",&ele,&pri);
				enqueue(ele,pri);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
		}
	}
	
}
