#include<stdio.h>
#include<stdlib.h>
struct dll{
	struct dll *prev;
	int data;
	struct dll *next;
};
typedef struct dll node;
node *head=NULL;
void display(){
	if(head==NULL) printf("No data!");
	else{	
		node *tmp,*pre;
		for(tmp=head;tmp!=NULL;pre=tmp,tmp=tmp->next)
			printf("%d -->",tmp->data);
		printf("\nFrom back\n");
		for(tmp=pre;tmp!=NULL;tmp=tmp->prev)
			printf("%d -->",tmp->data);
	}
}
void insertatend(int num){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	ptr->prev=NULL;
	ptr->next=NULL;
	if(head==NULL) head=ptr;
	else{
		node *tmp=head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=ptr;
		ptr->prev=tmp;
	}
}
void swap(){
	node *next,*curr=head;
	while(curr->next!=NULL){
		next=curr->next;
		if(curr==head){
			head=curr->next;
			curr->prev=curr->next;
			curr->next=curr->next->next;
			head->prev=NULL;
			head->next->prev=curr;
			head->next=curr;
		}
		else{
				
		}
	}
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert at last\n2)swap\n3)print\n4)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:
				swap();
				
			case 3:
				display();
				break;
			case 4: 
				exit(0);		
		}
	}
}
