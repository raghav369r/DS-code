#include<stdio.h>
#include<stdlib.h>
struct player{
	int data;
	struct player *link;
};
typedef struct player node;
node *head=NULL;
int count();
void rotate(int n){
	node *curr,*old,*tmp=head;
	int coun=count();
	n%=coun;
	int in=coun-n,i=0;
	while(tmp->link!=NULL){
		i++;
		if(i==in){
			old=tmp;
			curr=tmp->link;
		}
		tmp=tmp->link;
	}
	tmp->link=head;
	old->link=NULL;
	head=curr;	
}
int count(){
	int c=0;
	node *tmp=head;
	while(tmp!=NULL){
		tmp=tmp->link;
		c++;
	}
	return c;
}
void insert(int num){
	node *ptr,*tmp=head,*old;
	ptr=(node*)malloc(sizeof(node));
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
		if(tmp->data<=num)
			tmp->link=ptr;
		else{
			ptr->link=old->link;
			old->link=ptr;
		}
	}
	printf("Count= %d\n",count());
}
int main(){
	int opt,num;
	while(1){
		printf("\n\n1..insert element\n2..display\n3..rotate list\n4..exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			insert(num);
			break;
		case 2:
			if(head==NULL) printf("No data!");
			node *tmp;
			for(tmp=head;tmp!=NULL;tmp=tmp->link)
				printf("%d -->",tmp->data);
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
