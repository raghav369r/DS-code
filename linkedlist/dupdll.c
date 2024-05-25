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
void deldup(){
	node *tmp1,*tmp2,*old;
	for(tmp1=head;tmp1!=NULL;tmp1=tmp1->next){
		for(tmp2=head;tmp2!=NULL;old=tmp2,tmp2=tmp2->next){
			if(tmp1!=tmp2 && tmp1->data==tmp2->data){
				tmp2->prev->next=tmp2->next;
				tmp2->next->prev=tmp2->prev;
				free(tmp2);
				tmp2=old;
			}
		}
	}
	
}
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..print data\n3..delete duplicate\n4..exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertatend(num);
			break;
		case 2:
			display();
			break;
		case 3:
			deldup();
			break;
		case 4:
			exit(0);
		}
	}
}
