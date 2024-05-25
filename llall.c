#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player{
	char name[20];
	struct player *link;
};
typedef struct player node;
node *head=NULL;
void insertatlast(char *nam){
	node *ptr=malloc(sizeof(node));
	strcpy(ptr->name,nam);
	ptr->link=NULL;       
	if(head==NULL){
		head=ptr;
	}
	else{
		node *tmp=head;
		while(tmp->link!=NULL)
			tmp=tmp->link;
		tmp->link=ptr;
	}
}
void insertatfirst(char *nam){
	node *ptr=malloc(sizeof(node));
	strcpy(ptr->name,nam);
	ptr->link=NULL;       
	if(head==NULL){
		head=ptr;
	}
	else{
		//node *tmp=head;
		/*while(tmp->link!=NULL)
			tmp=tmp->link;*/
		//tmp->link=ptr;
		ptr->link=head;
		head=ptr;
	}
}
void delete(char n[]){
	node *tmp2=head,*tmp1=head;
	while(tmp2!=NULL){
		if(strcmp(tmp2->name,n)==0){
			tmp1->link=tmp2->link;
			if(tmp2==head) head=head->link;
			free(tmp2);
			break;
		}
		tmp1=tmp2;
		tmp2=tmp2->link;
	}
}
void addbyindex(int in,char val[]){
	node *ptr=malloc(sizeof(node));
	strcpy(ptr->name,val);
	int i=0,l=0;
	node *tmp2=head,*tmp1=head,*tmp=head;
	if(in!=0){
		while(tmp->link!=NULL){
			l++;
			tmp=tmp->link;
		}
	}	
	printf("\nLength= %d\n",l);
	if(in==l+1){
		tmp->link=ptr;
		ptr->link=NULL;
	}
	else if(in==0){
		if(head==NULL){
			head=ptr;
			ptr->link=NULL;
		}
	else{
		ptr->link=head;
		head=ptr;
	}
	}
	else{
		while(tmp2!=NULL){
			if(i==in){
				ptr->link=tmp1->link;
				tmp1->link=ptr;
				if(tmp2==head) head=head->link;
				break;
			}
			tmp1=tmp2;
			tmp2=tmp2->link;
			i++;
		}
	}
}
void delbyindex(int in){
	node *tmp2=head,*tmp1=head;
	int i=0;
	while(tmp2!=NULL){
		if(i==in){
			tmp1->link=tmp2->link;
			if(tmp2==head) head=head->link;
			free(tmp2);
			break;
		}
		tmp1=tmp2;
		tmp2=tmp2->link;
		i++;
	}
}
int main(){
	int opt;
	char name[20];
	while(1){
		printf("\n\n1..insert element at last\n2..insert element at first\n3..add element by index\n4..delete by element\n5..delete by index\n6..print\n7..exit\n\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			printf("Enter name to insert: ");
			scanf("%s",name);
			insertatlast(name);
			break;
		case 2:
			printf("Enter name to insert: ");
			scanf("%s",name);
			insertatfirst(name);
			break;
		case 3:
			printf("Enter name to add: ");
			scanf("%s",name);
			int in;
			printf("Enter index to add the name: ");
			scanf("%d",&in);
			addbyindex(in,name);
			break;
		case 4:
			printf("Enter name to remove: ");
			char na[20];
			scanf("%s",na);
			delete(na);
			break;
		case 5:
			printf("Enter index to delete: ");
			int index;
			scanf("%d",&index);
			delbyindex(index);
			break;
		case 6:
			if(head==NULL) printf("No data!");
			node *tmp;
			for(tmp=head;tmp!=NULL;tmp=tmp->link)
				printf("%s -->",tmp->name);
			printf("\n");
			break;
		case 7:
			exit(0);
		default: printf("U Entered Invalid Choice!/n");
		}
	}
}
