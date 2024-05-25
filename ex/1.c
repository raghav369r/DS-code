#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct player * link;
};
typedef struct player node;
node *head=NULL;
void insertatend(int n){
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->jno=n;
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
void display(){
	node *tmp2;
	tmp2=head;
	while(tmp2!=NULL){
		printf("%d-->",tmp2->jno);
		tmp2=tmp2->link;
	}
	printf("\n");
}
node *reverse(node *head1){
	node *revhead;
	if(head1==NULL || head1->link==NULL) return head1;
	revhead=reverse(head1->link);
	head1->link->link=head1;
	head->link=NULL;
	return revhead;
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert at last\n2)reverse\n3)print\n4)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:
				head=reverse(head);
				
			case 3:
				display();
				break;
			case 4: 
				exit(0);		
		}
	}
}
