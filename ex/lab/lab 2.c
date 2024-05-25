#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *link;
	int data; 
};
typedef struct node node;
node *head=NULL,*tail=NULL;
void display(){
	for(node *tmp=head;tmp!=NULL;tmp=tmp->link)
		printf("%d->",tmp->data);
	printf("\n");
}
void insert(int n){
	node *head1=NULL,*tail1=NULL;
	while(n!=0){
		node *ptr=(node *)malloc(sizeof(node));
		ptr->link=NULL;
		ptr->data=n%10;
		if(head1==NULL) head1=tail1=ptr;
		else{
			ptr->link=head1;
			head1=ptr;
		}
		n=n/10;
	}
	if(tail==NULL) tail=tail1;
	else{
		tail->link=head1;
		tail=tail1;
	}
	if(head==NULL) head=head1;
}
int main(){
	insert(432);
	display();
	insert(854);
	display();
}
