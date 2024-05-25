#include<stdio.h>
#include<stdlib.h>
struct dll{
	struct dll *prev;
	int data;
	struct dll *next;
};
typedef struct dll node;
node *head=NULL;
int count();
void rotate(int n){
	node *curr,*old,*tmp=head;
	int coun=count();
	n%=coun;
	int in=coun-n,i=0;
	while(tmp->next!=NULL){
		i++;
		if(i==in){
			old=tmp;
			curr=tmp->next;
		}
		tmp=tmp->next;
	}
	head->prev=tmp;
	tmp->next=head;
	old->next=NULL;
	head=curr;
	head->prev=NULL;	
}
int count(){
	node *tmp=head;
	int len=0;
	while(tmp!=NULL){
		len++;
		tmp=tmp->next;
	}
	return len;
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
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..display\n3..rotate\n4..exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insertatend(num);
			break;
		case 2:
			if(head==NULL) printf("No data!");
			else{	
				node *tmp,*pre;
				for(tmp=head;tmp!=NULL;pre=tmp,tmp=tmp->next)
					printf("%d -->",tmp->data);
				printf("\nFrom back\n");
				for(tmp=pre;tmp!=NULL;tmp=tmp->prev)
					printf("%d -->",tmp->data);
			}
				break;
			
		case 3:
			printf("Enter num to rotate: ");
			scanf("%d",&num);
			rotate(num);
			break;
		case 4:	
			exit(0);
		}
	}
}
