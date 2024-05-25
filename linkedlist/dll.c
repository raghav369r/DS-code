#include<stdio.h>
#include<stdlib.h>
struct dll{
	struct dll *prev;
	int data;
	struct dll *next;
};
typedef struct dll node;
node *head=NULL;
int count(){
	node *tmp=head;
	int len=0;
	while(tmp!=NULL){
		len++;
		tmp=tmp->next;
	}
	return len;
}
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
void insertbysort(int num){
	node *ptr,*tmp=head;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	ptr->prev=NULL;
	ptr->next=NULL;
	if(head==NULL) head=ptr;
	else if(head->data>=num){
		head->prev=ptr;
		ptr->next=head;
		head=ptr;	
	}
	else{
		for(;tmp->data<num && tmp->next!=NULL;tmp=tmp->next);
		if(tmp->next==NULL && tmp->data<num){
			tmp->next=ptr;
			ptr->prev=tmp;
			
		}
		else{
			ptr->next=tmp;
			ptr->prev=tmp->prev;
			(tmp->prev)->next=ptr;
			tmp->prev=ptr;
		}
	}
}
void insertatbegin(int num){
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	ptr->prev=NULL;
	ptr->next=NULL;
	if(head==NULL) head=ptr;
	else{
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
	}
}
void insertatindex(int num,int index){
	if(index>count()||index<0) printf("Index out of range!\n");
	else{
		node *ptr,*tmp=head;
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->next=NULL;
		ptr->prev=NULL;
		if(index==0){
			if(head!=NULL) head->prev=ptr;
			ptr->next=head;
			head=ptr;
		}
		else{
			for(int i=0;i<index-1;tmp=tmp->next,i++);
			if(tmp->next==NULL){
				ptr->prev=tmp;
				tmp->next=ptr;
			}
			else{
				(tmp->next)->prev=ptr;
				ptr->prev=tmp; 
				ptr->next=tmp->next;
				tmp->next=ptr;
			}
				
		}
	}	
}
void deleteindex(int ind){
	if(ind>=count()||ind<0) printf("Index out of range!\n");
	else{
		node *tmp=head;
		if(ind==0){
			if(tmp->next==NULL) head=NULL;
			else{
				head=head->next;
				head->prev=NULL;
			}
			free(tmp);
		}
		else{
			int i=0;
			for(tmp=head;i!=ind && tmp!=NULL;tmp=tmp->next,i++);
			if(i==ind && tmp->next==NULL)
				(tmp->prev)->next=NULL;
			else{
				(tmp->next)->prev=tmp->prev;
				(tmp->prev)->next=tmp->next;
			}
		free(tmp);
		}
	}
}
/*void deleteele(int ele){
	node*tmp=head;
	if(head->data==ele){
		if(tmp->next==NULL) head=NULL;
		else{
			head=head->next;
			head->prev=NULL;
		}
		free(tmp);
	}
	else{
		for(tmp=head;tmp->data!=ele && tmp->next!=NULL;tmp=tmp->next);
		if(tmp->data!=ele) printf("Element is not there in the list");
		else{
			if(tmp->next==NULL){
				(tmp->prev)->next=NULL;
				free(tmp);
		}
			else{
				(tmp->next)->prev=tmp->prev;
				(tmp->prev)->next=tmp->next;
				free(tmp);
			}
		}
	}
}*/
void deleteele(int num){
	node *curr=head,*old;
	while(curr!=NULL && curr->data!=num){
		old=curr;
		curr=curr->next;
	}
	if(curr==NULL){
		printf("Element not found to delete!!");
		return;
	}
	if(head==curr){
		head=curr->next;
		if(curr->next!=NULL)
			curr->next->prev=NULL;
	}
	else{
		old->next=curr->next;
		if(curr->next!=NULL)
			curr->next->prev=old;
	}
	free(curr);
	if(head!=NULL) display();
}
void delall(){
	node *tmp=head;
	while(tmp!=NULL)
		tmp=tmp->next;
	head=tmp->prev;
	while(head!=NULL){
		tmp=head;
		head=head->prev;
		//free(tmp);
	}
	
}
void reverse(){
	node *tmp=head,*ptr;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	head=tmp;
	while(tmp!=NULL){
		ptr=tmp->prev;
		tmp->prev=tmp->next;
		tmp->next=ptr;
		tmp=tmp->next;
	}
}
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..insert element at begining\n3..insert element by index\n4..display\n5..delete element by element\n6..delete by index\n7..insert element in ascending order\n8..delete all elements\n9..reverse\n10..exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertatend(num);
			break;
		case 2:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertatbegin(num);
			break;
		case 3:
			printf("enter element to add: ");
			scanf("%d",&num);
			printf("Enter index: ");
			scanf("%d",&index);
			insertatindex(num,index);
			break;
		case 4:
				display();
				break;
		case 5:
			printf("Enter element to delete: ");
			scanf("%d",&num);
			deleteele(num);
			break;
		case 6: 
			printf("Enter index to delete: ");
			scanf("%d",&index);
			deleteindex(index);
			break;
		case 7:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertbysort(num);
			break;
		case 8:
			delall();
			break;
		case 9:
			reverse();
			break;
		case 10:
			exit(0);
		}
	}
}
