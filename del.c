#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct player *link;
};
typedef struct player node;
node *head;
void delete(int num){
	node *tmp2=head,*tmp1=head;
	while(tmp2!=NULL){
		if(tmp2->jno==num){
			tmp1->link=tmp2->link;
			if(tmp2==head) head=head->link;
			//free(tmp2);
			break;
		}
		tmp1=tmp2;
		tmp2=tmp2->link;
	}
}
void reverse(){
	node *curr=head,*cu=head,*old,*ol;
	while(cu!=NULL){
		cu=curr->link;
		ol=curr;
		if(curr==head) curr->link=NULL;
		else curr->link=old;
		curr=cu;
		old=ol;
	}
	head=old;
}
void delbyindex(int in){
	node *tmp2=head,*tmp1=head;
	int i=0;
	while(tmp2!=NULL){
		if(i==in){
			tmp1->link=tmp2->link;
			if(tmp2==head) head=head->link;
			//free(tmp2);
			break;
		}
		tmp1=tmp2;
		tmp2=tmp2->link;
		i++;
	}
}
int loopex(){
	node *ptr1,*ptr2;
	int loop=0,i,j;
	for(ptr1=head,i=0;ptr1!=NULL;ptr1=ptr1->link,i++){
		if(ptr1==ptr1->link)
			return 1;
		for(ptr2=head,j=0;j<i;ptr2=ptr2->link,j++)
			if(ptr1==ptr2)
				return 1;
	}
	return 0;
}
/*int loopex1(){
	node *ptr1=head,*ptr2;
	int loop=0,i=0,j;
	while(ptr1!=NULL){
		ptr2=head;
		i++;
		j=0;
		while(j<i){
			j++;
			if(ptr1==ptr2){
				loop=1;
				break;
			}
			ptr2=ptr2->link;
		}
		if(loop==1) break;
		ptr1=ptr1->link;
	}
	return loop;
}*/
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
	p3.link=NULL;
	p4.link=&p1;
	tmp=head;
	
	/*while(tmp!=NULL){
		printf("%d-->",tmp->jno);
		tmp=tmp->link;
	}
	//printf("Enter index to delete: ");
	//scanf("%d",&num);
	//delbyindex(num);
	//reverse();
	printf("\nAfter reversing function: \n");
	tmp=head;
	while(tmp!=NULL){
		printf("%d-->",tmp->jno);
		tmp=tmp->link;
	}*/
	int loop=loopex();
		if(loop) printf("YES,There is a loop\n");
		else printf("NO,There is no loop\n");
}
