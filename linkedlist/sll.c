#include<stdio.h>
#include<stdlib.h>
struct player{
	int data;
	struct player * link;
};
typedef struct player node;
node *head=NULL;
void insertatend(int n){
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=n;
	ptr->link=NULL;
	if(head==NULL) head=ptr;
	else{
		node *tmp;
		tmp=head;
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;
	}
}
void insertsort(int num){
	node *ptr,*tmp=head,*old;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL) head=ptr;
	else if(head->data>=num){
		ptr->link=head;
		head=ptr;
	}
	else{
		while(tmp->data<=num && tmp->link!=NULL){
			old=tmp;
			tmp=tmp->link;
		}
		if(tmp->data<num) tmp->link=ptr;
		else {
			ptr->link=tmp;
			old->link=ptr;
		}
	}
	
}
void display(){
	node *tmp2;
	tmp2=head;
	while(tmp2!=NULL){
		printf("%d-->",tmp2->data);
		tmp2=tmp2->link;
	}
	printf("\n");
}
void deletefromlist(int num){
	node *curr=head,*old;
	while(curr!=NULL && curr->data!=num){
		old=curr;
		curr=curr->link;
	}
	if(curr==NULL){
		printf("Element not found to delete!!\n");
		return;
	}
	if(curr==head) head=curr->link;
	else old->link=curr->link;
	free(curr);
	printf("The element %d is deleated\n",num);
	if(head!=NULL) display();
}
void insertatfirst(int num){
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	if(head==NULL){
		head=ptr;
		ptr->link=NULL;
	}
	else{
		ptr->link=head;
		head=ptr;
	}
}
int count(){
	node *tmp=head;
	int len=0;
	while(tmp!=NULL){
		len++;
		tmp=tmp->link;
	}
	return len;
}
void insertatindex(int num,int index){
	node *ptr,*tmp=head;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	if(index>count()) printf("Index out of range\nElement not added\n");
	else{
		if(index==0){
			ptr->link=head;
			head=ptr;
		}	
		else{	
		for(int i=0;i<index-1;tmp=tmp->link,i++);
		ptr->link=tmp->link;
		tmp->link=ptr;
		}	
	}
}
void reverse(){
node *curr=head,*old,*cu=head,*ol;
	while(cu!=NULL){
		cu=curr->link;
		ol=curr;
		if(curr==head) curr->link=NULL;
		else {
			curr->link=old;
		}
		old=ol;
		curr=cu;
	}
	head=old;
}
/*
	node *prev=NULL,*curr=head,*next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
*/
void insertafterele(int ele,int num){
	node *ptr,*curr=head;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	while(curr->data!=ele && curr!=NULL)
		curr=curr->link;
	ptr->link=curr->link;
	curr->link=ptr;
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert at last\n2)delete\n3)print\n4)insert at first\n5)insert at a node\n6)count no of nodes\n7)reverse\n8)insert after a element\n9)insert in acsending order\n10)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:{
				if(head==NULL) printf("no element to delete freom list\n");
				else{
					printf("Elements present in the list are:\n");
					display();
					printf("Enter element to delete: ");
					scanf("%d",&num_d);
					deletefromlist(num_d);
					}
				break;
				}
			case 3:
				if(head==NULL) printf("no data!");
				else{
					display();
				}
				break;
			case 4:
				printf("Enter element to add: ");
				scanf("%d",&num);
				insertatfirst(num);
				break;
			case 5:
				printf("enter element to add: ");
				scanf("%d",&num);
				printf("afrer which index we have to add: ");
				scanf("%d",&index);
				insertatindex(num,index);
				break;
			case 6:{
				int cou=count();
				printf("no of nodes= %d",cou);
				break;
				}
			case 7:
				reverse();
				break;
			case 8:
				printf("After which element u have to add: ");
				int ele;
				scanf("%d",&ele);
				printf("Enetr element to add: ");
				scanf("%d",&num);
				insertafterele(ele,num);
				break;
			case 9:
				printf("enter element to add: ");
				scanf("%d",&num);
				insertsort(num);
				break;
			case 10:
				exit(0);
				
		}
	}
}
