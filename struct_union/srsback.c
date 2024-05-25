#include<stdio.h>
struct node{
	struct node *prev;
	int  data;
	struct node *next;
	
};
int main(){
	struct node p1,p2,p3,p4,*nex,*pre;
	p1.data=10;
	p2.data=20;
	p3.data=30;
	p4.data=40;
	p1.next=&p2;
	p2.next=&p3;
	p3.next=&p4;
	p4.next=NULL;
	p1.prev=NULL;
	p2.prev=&p1;
	p3.prev=&p2;
	p4.prev=&p3;
	nex=&p1;
	pre=&p4;
	while(nex!=NULL){
		printf("%d--->",nex->data);
		nex=nex->next;
	}
	printf("\n");
	while(pre!=NULL){
		printf("%d--->",pre->data);
		pre=pre->prev;
	}
}
