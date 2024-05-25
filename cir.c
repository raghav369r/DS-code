#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct player *link;
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
	p1.link=&p2;
	p2.link=&p3;
	p3.link=&p4;
	p4.link=&p1;
	tmp=head;
	do{
		printf("%d-->",tmp->jno);
		tmp=tmp->link;
	}
	while(tmp!=head);
}
