#include<stdio.h>
#include<stdlib.h>
struct cll{
	int data;
	struct cll *next;
};
typedef struct cll node;
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
	while(i<2);
	/*while(tmp2->next!=head){
		printf("%d-->",tmp2->data);
		tmp2=tmp2->next;
	}
	printf("%d-->",tmp2->data);*/
	printf("\n");
}
void insertatend(int num){
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	if(head==NULL){
		head=ptr;
		tail=ptr;
		head->next=head;
	}
	else{
		tail->next=ptr;
		ptr->next=head;
		tail=ptr;
	}
}
void deleteele(int ele){
	node *tmp=head,*old;
	if(tmp->data==ele){
		if(head==tail) head=tail=NULL;
		else{
			head=head->next;
			tail->next=head;
		}
	}
	else{
		tmp=head->next;
		while(tmp!=head && tmp->data!=ele){
			old=tmp;
			tmp=tmp->next;
		}
		if(tmp->data!=ele){
			printf("Element not found in the list!!");
			return;
		}
		if(tmp==tail){
			old->next=head;
			tail=old;		
		}
		else{
			old->next=tmp->next;
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
	}
	else{
		ptr->next=head;
		head=ptr;
		tail->next=ptr;	
	}
}
void insertatindex(int num,int index){
	node *ptr,*tmp=head;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	if(index==0){
		if(head==NULL){
			head=tail=ptr;
			ptr->next=head;
		}
		else{
			ptr->next=head;
			head=ptr;
			tail->next=ptr;
		}
	}	
	else{	
		for(int i=0;i<index-1;tmp=tmp->next,i++);
		ptr->next=tmp->next;
		tmp->next=ptr;
		if(tmp==tail){
			tail=ptr;
			tail->next=head;
		}	
	}
}
int main(){
	int opt,num,index;
	while(1){
		printf("\n\n1..insert element at end\n2..insert element at begining\n3..insert by index\n4..display\n5..delete element by element\n6..exit\nEnter your choice: ");
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
		case 4:
			if(head==NULL) printf("no data!");
			else{
				display(2);
			}
			break;
		case 3:
			printf("Enter num to insert: ");
			scanf("%d",&num);
			printf("Enter index to insert: ");
			scanf("%d",&index);
			insertatindex(num,index);
			break;
		case 5:
			printf("Enter num to delete: ");
			scanf("%d",&num);
			deleteele(num);
			break;
		case 6:
			exit(0);
		}
	}
		
}
