//add element by index
#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct palyer *link;
};
typedef struct player node;
node *head=NULL;
void insert(int num,int index){
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->jno=num;
	node *tmp,*tmp1,*tmp2;
	tmp1=tmp2=tmp=head;
	if(head==0 && index==0){
		
	}
}
int main(){
	int num,ind,opt;
	while(1){
		printf("Enter your choice..\n1..insert by index\n2..print\n3..exit\n");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter numder to insert: ");
			scanf("%d",&num);
			printf("Enter index: ");
			scanf("%d",&ind);
			insert(num,ind);
			break;
		case 2:
			if(head==NULL) printf("No data!");
			node *tmp;
			for(tmp=head;tmp!=NULL;tmp=tmp->link)
				printf("%s -->",tmp->name);
			printf("\n");
			break;
		case 3:
			exit(0);
		default: printf("Enter valid choice!/n");
		}
	}
}









































/*void addbyindex(int val,int in){
	node *ptr=malloc(sizeof(node));
	ptr->jno=val;
	int i=0,l=0;
	node *tmp2=head,*tmp1=head,*tmp=head;
	while(tmp->link!=NULL){
		l++;
		tmp=tmp->link;
	}
	printf("\nLength= %d\n",l);
	if(in==l+1){
		tmp->link=ptr;
		ptr->link=NULL;
	}
	else{
		while(tmp2!=NULL){
			if(i==in){
				ptr->link=tmp1->link;
				tmp1->link=ptr;
				//if(tmp2==head) head=head->link;
				break;
			}
			tmp1=tmp2;
			tmp2=tmp2->link;
			i++;
		}
	}
}
int main(){
	int opt,num;
	node p1,p2,p3,p4,*tmp;
	head=&p1;
	p1.jno=1;
	p2.jno=2;
	p3.jno=3;
	p4.jno=4;
	p1.link=&p2;
	p2.link=&p3;
	p3.link=&p4;
	p4.link=NULL;
	tmp=head;
	while(tmp!=NULL){
		printf("%d-->",tmp->jno);
		tmp=tmp->link;
	}
	printf("\nAfter addbyindex function: \n");
	addbyindex(20,4);
	tmp=head;
	while(tmp!=NULL){
		printf("%d-->",tmp->jno);
		tmp=tmp->link;
	}
}*/

