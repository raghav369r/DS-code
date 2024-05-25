#include<stdio.h>
#include<stdlib.h>
struct player{
	int data;
	struct player *link;
};
typedef struct player node;
node *head=NULL;
void insertbyindex(int num,int index){
	node *tmp=head,*ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	ptr->link=NULL;
	if(index==0){
		ptr->link=head;
		head=ptr;
	}
	else{
		for(int i=0;i<index-1;i++,tmp=tmp->link);
		ptr->link=tmp->link;
		tmp->link=ptr;
	}
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
}
int loopex(){
	node *ptr1,*ptr2;
	int loop=0,i,j;
	for(ptr1=head,i=0;ptr1!=NULL;ptr1=ptr1->link,i++){
		if(ptr1==ptr1->link){
			loop=1;
			break;
		}	
		for(ptr2=head,j=0;j<i;ptr2=ptr2->link,j++){
			if(ptr1==ptr2){
				loop=1;
				break;
			}
		}
		if(loop==1) break;
	}
	return loop;
}
int main(){
	int opt,num;
	while(1){
		printf("\n\n1..insert element\n2..display\n3..loop existance\n4..insert by index\n5..exit\nEnter your choice: ");
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
		
		case 3:{
			int loop=loopex();
			if(loop) printf("YES,There is a loop");
			else printf("NO,There is no loop");
			break;
		}
		case 4: 
			printf("Enter element to add: ");
			scanf("%d",&num);
			int index;
			printf("Enter index to add: ");
			scanf("%d",&index);
			insertbyindex(num,index);
			break;	
		case 5:
			exit(0);
		}
	}
}
