#include<stdio.h>
#include<stdlib.h>
struct player{
	int data;
	struct player * next;
};
typedef struct player node;
node *head=NULL;
void insertatend(int n){
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=n;
	ptr->next=NULL;
	if(head==NULL) head=ptr;
	else{
		node *tmp;
		tmp=head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		tmp->next=ptr;
	}
}
void display(){
	node *tmp2;
	tmp2=head;
	while(tmp2!=NULL){
		printf("%d-->",tmp2->data);
		tmp2=tmp2->next;
	}
	printf("\n");
}
int i;
void dis(node *tmp,int n){
	if(tmp!=NULL){
		dis(tmp->next,n);
		if(i==n)
			//return tmp->data;
			printf("%d-->",tmp->data);
	}
}
/*void swap(){
	
	node *tmp=head,*ptr,*next;
	head=head->next;
	while(tmp!=NULL && tmp->next!=NULL){
		next=tmp->next;
		ptr=next->next;
		next->next=tmp;
		tmp->next=ptr;
		tmp=tmp->next;
	}
}*/
void swap(){
	node *tmp=head,*prev,*next;
	head=head->next;
	int i=0;
	while(tmp->next!=NULL){
		next=tmp->next;
		if(i%2==0){
			if(tmp->next->next==NULL)
				tmp->next=NULL;
			else
				tmp->next=tmp->next->next->next;
		}
		else{
			tmp->next=prev;
		}
		prev=tmp;
		tmp=next;
		i++;
	}
	//next=tmp->next;
	tmp->next=prev;
//prev->next=tmp;
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert to 1\n2)dis\n3)display\n4)Swap\n5)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
		i++;
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:
				i=0;
				printf("Enter num to return element: ");
				scanf("%d",&num);
				dis(head,num);
				//printf("-->%d",dis(head,num));
				break;
			case 3:
				display();
				break;
			case 4:
				swap();
				break;
			case 5:
				exit(0);
				
		}
	}
}
