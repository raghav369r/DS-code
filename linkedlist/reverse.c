#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct palyer *link;
};
typedef struct player node;
node *head=NULL;
void insertatend(int num){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->jno=num;
	ptr->link=NULL;
	if(head==NULL) head=ptr;
	else{
		node *tmp=head;
		while(tmp->link!=NULL) tmp=tmp->link;
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
int main(){
	int opt,num;
	while(1){
		printf("\n1)insert at last\n2)reverse the list\n3)display\n4)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend(num);
				break;
			case 2:
				reverse();
				break;
			case 3:
				if(head==NULL) printf("no data!");
				else{
					display();
				}
				break;
			case 4: exit(0);
		}
	}
}
