#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct player *prev;
	struct player *next;
};
typedef struct player node;
node *head;
int main(){
	node p1,p2,p3,p4,*tmp;
	head=&p1;
	p1.jno=1;
	p2.jno=2;
	p3.jno=3;
	p4.jno=4;
	p1.prev=&p4;
	p2.prev=&p1;
	p3.prev=&p2;
	p4.prev=&p3;
	p1.next=&p2;
	p2.next=&p3;
	p3.next=&p4;
	p4.next=&p1;
	tmp=head;
	printf("Using next\n");
	do{
		printf("%d-->",tmp->jno);
		tmp=tmp->next;
	}
	while(tmp!=head);
	tmp=head;
	printf("\nUsing prev\n");
	do{
		printf("%d-->",tmp->jno);
		tmp=tmp->prev;
	}
	while(tmp!=head);
}
