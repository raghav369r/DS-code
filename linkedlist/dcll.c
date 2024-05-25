#include<stdio.h>
#include<stdlib.h>
struct dcll{
	struct dcll *prev;
	int data;
	struct dcll *next;
};
typedef struct dcll node;
node *head=NULL,*tail=NULL;
void display(int n){
	node *tmp2;
	tmp2=head;
	int i=0;
	do{
		printf("%d-->",tmp2->data);
		tmp2=tmp2->next;
		if(tmp2==head)printf(" %d\n",i++);
	}
	while(i<n);
	i=0;
	tmp2=tail;
	do{
		printf("%d-->",tmp2->data);
		tmp2=tmp2->prev;
		if(tmp2==tail)printf(" %d\n",i++);
	}
	while(i<n);
	printf("\n");
}
void insertatend(int num){
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	if(head==NULL){
		head=ptr;
		tail=ptr;
		head->prev=head;
		head->next=head;
	}
	else{
		tail->next=ptr;
		ptr->prev=tail;
		tail=ptr;
		tail->next=head;
		head->prev=ptr;
	}
}
void deleteele(int ele){
	node *tmp=head,*old;
	if(tmp->data==ele){
		if(head==tail) head=tail=NULL;
		else{		
			head=head->next;
			head->prev=tail;
			tail->next=head;
		}
	}
	else{
		while(tmp->data!=ele){
			old=tmp;
			tmp=tmp->next;
		}
		if(tmp==tail){
			old->next=head;
			tail=old;
			head->prev=tail;
		}
		else{
			old->next=tmp->next;
			tmp->next->prev=old;
		}
	}
	free(tmp);
}
void insertatbegin(int num){
	node *ptr,*temp=head;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	if(head==NULL){
		head=tail=ptr;
		ptr->next=head;
		ptr->prev=head;
	}
	else{
		ptr->prev=tail;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		tail->next=head;	
	}
}
void insertatindex(int num,int index){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	if(index==0){
		if(head==NULL){
			head=tail=ptr;
			head->prev=head->next=head;
		}
		else{
			head->prev=ptr;
			ptr->prev=tail;
			ptr->next=head;
			tail->next=ptr;
			head=ptr;
		}
	}
	else{
		node *tmp=head;
		for(int i=0;i<index-1;tmp=tmp->next,i++);
		/*if(tmp==head){
			printf("index out of range!!\n");
			return;
		}*/
		if(tmp==tail){
			ptr->prev=tmp;
			tmp->next=ptr;
			tail=ptr;
			tail->next=head;
		}
		else{
			(tmp->next)->prev=ptr;
			ptr->prev=tmp; 
			ptr->next=tmp->next;
			tmp->next=ptr;
		}
	}	
}
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..insert element at begining\n3..display\n4..delete element by element\n5..insert by index\n6..exit\nEnter your choice: ");
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
			if(head==NULL) printf("no data!");
			else{
				display(2);
			}
			break;
		case 4:
			printf("Enter num to delete: ");
			scanf("%d",&num);
			deleteele(num);
			break;
		case 5:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			printf("Enter index to insert: ");
			scanf("%d",&index);
			insertatindex(num,index);
			break;
		case 6:
			exit(0);
		}
	}		
}
