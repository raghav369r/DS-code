#include<stdio.h>
struct node{
	int  data;
	struct node *link;
	
};
int main(){
	struct node p1,p2,p3,*ptr;
	p1.data=10;
	p2.data=20;
	p3.data=30;
	p1.link=&p2;
	p2.link=&p3;
	p3.link=NULL;
	ptr=&p1;
	while(ptr!=NULL){
		printf("%d--->",ptr->data);
		ptr=ptr->link;
	}
	printf("\nAfter adding: \n");
	struct node p4;
	p4.data=40;
	p2.link=&p4;
	p4.link=&p3;
	ptr=&p1;
	while(ptr!=NULL){
		printf("%d--->",ptr->data);
		ptr=ptr->link;
	}
}
