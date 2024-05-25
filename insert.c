#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player{
	char name[20];
	struct player *link;
};
typedef struct player node;
node *head=NULL;
void insert(char *nam){
	node *ptr=malloc(sizeof(node));
	strcpy(ptr->name,nam);
	ptr->link=NULL;       
	if(head==NULL){
		head=ptr;
	}
	else{
		node *tmp=head;
		while(tmp->link!=NULL)
		{	printf("\ntmp= %u\n",tmp);
			printf("tmp->link= %u\n",tmp->link);
		
			tmp=tmp->link;
		}
		tmp->link=ptr;
	}
}
int main(){
	int opt;
	char name[20];
	while(1){
		printf("Enter your choice..\n1..insert\n2..print\n3..exit\n");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter name to insert: ");
			scanf("%s",name);
			insert(name);
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
