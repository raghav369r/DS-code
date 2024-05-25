//delete N nodes after M nodes
#include<stdio.h>
#include<stdlib.h>
struct sll{
	int data;
	struct sll *link;
};
typedef struct sll node;
node *head=NULL;
node *tail=NULL;
void insert(){
	printf("Enter element to add: ");
	int ele;
	scanf("%d",&ele);
	node *ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->link=NULL;
	if(head==NULL)
		head=tail=ptr;
	else{
		tail->link=ptr;
		tail=ptr;
	}
}
void delMN(int m,int n){
	node *tmp=head,*tmp1,*tmp2,*old;
	int ind=m+n;
	int i=0;
	while(tmp!=NULL && i<m){
		i++;
		old=tmp;
		tmp=tmp->link;
	}
	printf("\ntmp= %d\n",tmp->data);
	if(tmp==NULL)
		printf("Not have enough nodes!!\n");
	else{
		tmp1=tmp;
		while(tmp1!=NULL && i<m+n){
			tmp2=tmp1->link;
			free(tmp1);
			tmp1=tmp2;
			i++;		
		}
		if(m==0) head=tmp1;
		else old->link=tmp1;
	}
}
int main(){
	int opt;
	while(1){
		printf("1..Add\t2..Del N After M\t3..Display\t4..exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				insert();
				break;
			case 2:
				printf("Enter M and N values: ");
				int m,n;
				scanf("%d%d",&m,&n);
				delMN(m,n);
				break;
			case 3:
				for(node *tmp=head;tmp!=NULL;tmp=tmp->link)
					printf("%d - ",tmp->data);
				break;
			case 4:
				return 1;
		}
	}	
}
