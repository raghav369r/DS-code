#include<stdio.h>
#include<stdlib.h>
struct stackll{
	int data;
	struct stackll *link;
};
typedef struct stackll node;
node *top=NULL;
void push(){
	int num;
	printf("Enter no to add: ");
	scanf("%d",&num);
	node *ptr=(node *)malloc(sizeof(node));
	ptr->data=num;
	ptr->link=NULL;
	node *tmp=top;
	if(top==NULL)
		top=ptr;
	else{
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;	
	}
}
void pop(){
	if(top==NULL) printf("stack is empty!");
	else{
		node *tmp=top;
		printf("%d is deleted",top->data);
		top=top->link;
		free(tmp);
	}
}
int main(){
	int opt;
	while(1){
		printf("\n1.push\n2.pop\n3.display\n4.exit\nEnter ur choice: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				if(top==NULL) printf("stack is empty!\n");
				else for(node *tmp=top;tmp!=NULL;tmp=tmp->link) printf("%d-->",tmp->data);
				break;
			case 4:
				exit(0);
		}
	}
	
}
