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
void deldup(){
	node *tmp1,*old,*tmp2;
	for(tmp1=head;tmp1!=NULL;tmp1=tmp1->next){
		for(tmp2=head;tmp2!=NULL;old=tmp2,tmp2=tmp2->next){
			if(tmp1!=tmp2 && tmp1->data==tmp2->data){
					old->next=tmp2->next;
					free(tmp2);
					tmp2=old;
			}
		}
	}
}
/*
//in acending order
void deldup(){
	node *tmp=head;
	while(tmp!=NULL&&tmp->next!=NULL){
		if((tmp->data)==(tmp->next)->data){
			tmp->next=(tmp->next)->next;
		}
		tmp=tmp->next;
	}
}*/
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..delete duplicate\n3..display\n4..exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertatend(num);
			break;
		case 2:
			deldup();
			break;
		case 3:
			if(head==NULL) printf("no data!");
			else{
				display(2);
			}
			break;
		case 4:
			exit(0);
		}
	}
		
}
