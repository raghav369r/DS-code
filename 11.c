#include<stdio.h>
#include<stdlib.h>
struct player{
	int jno;
	struct palyer *link;
};
typedef struct player node;
node *head=NULL;
void insert(int n){
	node *ptr=malloc(sizeof(node));
	ptr->jno=n;
	ptr->link=NULL;
	if(head==NULL) head=ptr;
	else{
		node *tmp=head;
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;
	}
}
int main(){
	int opt,num;
	while(1){
		printf("Enter ur choice:\n1..insert\n2..print\n..3..exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				insert(num);
				break;
			case 2:
				if(head==NULL) printf("no data!");
				else{
					node *tmp=head;
					while(tmp!=NULL){
						printf("%d-->",tmp->jno);
						tmp=tmp->link;
					}
				}
				break;
			case 3:
				exit(0);
			
		}
	}
	
}
