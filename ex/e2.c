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
}/*
void swap(){
	head=head->next;
	node *tmp=head,*ptr,*next;
	
	while(tmp!=NULL && tmp->next!=NULL){
		next=tmp->next;
		ptr=next->next;
		next->next=tmp;
		tmp->next=ptr;
		tmp=tmp->next;
	}
}*//*
void swap(){
	node *curr=head,*prev=head,*tmp;
	if(head->next!=NULL) head=head->next;
	while(prev->next!=NULL){
		curr=curr->next;
		tmp=curr->next;
		curr->next=prev;
		prev->next=tmp;
		prev=tmp;
		curr=tmp;
	}
}*//*
void swap(node *head1){
	node *curr=head->next,*prev=head,*tmp,*tmp2=NULL;
	if(head1->next!=NULL) head=head1->next;
	while(prev->next!=NULL){
		curr=prev->next;
		if(tmp2!=NULL)
			tmp2->next=curr;
		tmp=curr->next;
		curr->next=prev;
		prev->next=tmp;
		tmp2=prev;
		prev=tmp;
		if(prev==NULL) break;
	}
}*/
node* swap(node *root){
	if(root==NULL || root->next==NULL)
		return root;
	node *curr=root->next->next,
	*prev=root;
	root=root->next;
	root->next=prev;
	while(curr!=NULL && curr->next!=NULL){
		prev->next=curr->next;
		prev=curr;
		node *next=curr->next->next;
		curr->next->next=curr;
		curr=next;
	}
	prev->next=curr;
	return root;
	
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert to 1\n2)swap\n3)display\n4)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:
				head=swap(head);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				
		}
	}
}
