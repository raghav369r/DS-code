#include<stdio.h>
#include<stdlib.h>
struct sll{
	int data;
	struct sll *link;
};
typedef struct sll node;
node *head=NULL;
node *tail=NULL;
void add(int ele){
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
void del(){
	node *tmp=head;
	head=head->link;
	free(tmp);
}
int mid(){
	if(head==NULL)
		return -1;
	int len=0,i=0,ind;
	node *tmp=head;
	for(;tmp!=NULL;len++,tmp=tmp->link);
	//printf("len= %d\n",len);
	ind=len/2;
	for(tmp=head;i<ind;i++,tmp=tmp->link);
	printf("mid: %d\n",tmp->data);
		
}
int main(){
	int opt,ele;
	while(1){
		printf("1..add\t2..del\t3..display\t4..mid\t5..exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter element to add: ");
				scanf("%d",&ele);
				add(ele);
				break;
			case 2:
				del();
				break;
			case 3:
				for(node *tmp=head;tmp!=NULL;tmp=tmp->link)
					printf("%d - ",tmp->data);
				printf("\n");
				break;
			case 4:
				mid();
				break;
			case 5:
				return 1;
		}
	}
}
