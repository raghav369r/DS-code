#include<stdio.h>
#include<stdlib.h>
struct player{
	int data;
	struct player * link;
};
typedef struct player node;
node *head1=NULL,*head2=NULL,*head3=NULL;
void insertatend1(int n){
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=n;
	ptr->link=NULL;
	if(head1==NULL) head1=ptr;
	else{
		node *tmp;
		tmp=head1;
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;
	}
}
void insertatend2(int n){
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=n;
	ptr->link=NULL;
	if(head2==NULL) head2=ptr;
	else{
		node *tmp;
		tmp=head2;
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;
	}
}
void display(){
	node *tmp;
	tmp=head1;
	printf("\n=====================1st====================\n");
	if(head1==NULL) printf("no elements!");
	else{
		for(tmp=head1;tmp!=NULL;tmp=tmp->link)
		printf("%d-->",tmp->data);	
	}
	printf("\n=====================2nd====================\n");
	if(head2==NULL) printf("no elements!");
	else{
		for(tmp=head2;tmp!=NULL;tmp=tmp->link)
		printf("%d-->",tmp->data);	
	}
	printf("\n=====================3rd====================\n");
	if(head3==NULL) printf("no elements!");
	else{
		for(tmp=head3;tmp!=NULL;tmp=tmp->link)
		printf("%d-->",tmp->data);	
	}
}
void merge(){
	node *list1=head1,*list2=head2,*list22;
	head3=head1;
	while(list1->link!=NULL && list2!=NULL){
		list22=list2->link;
		list2->link=list1->link;
		list1->link=list2;
		list2=list22;
		list1=list1->link->link;
	}
	if(list1->link==NULL) list1->link=list2;
}
int loopex(){
	node *ptr1,*ptr2;
	int i,j;
	for(ptr1=head1,i=0;ptr1!=NULL;ptr1=ptr1->link,i++){
		if(ptr1==ptr1->link)
			return 1;
		for(ptr2=head1,j=0;j<i;ptr2=ptr2->link,j++)
			if(ptr1==ptr2)
				return 1;
	}
	return 0;
}
int main(){
	int opt,num,num_d,index;
	while(1){
		printf("\n1)insert to 1\n2)insert to 2\n3)display\n4)swap\n5)exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend1(num);
				break;
			case 2:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insertatend2(num);
				break;
			case 3:
				display();
				break;
			case 4:
				merge();
				break;
			case 5:
				exit(0);
			case 6:
				if(loopex()) printf("yes there is a loop");
				else printf("no there is no loop");
				break;
				
		}
	}
}
