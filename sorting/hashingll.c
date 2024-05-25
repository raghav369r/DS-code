#include<stdio.h>
#include<stdlib.h>
struct node1{
	int data;
	struct node1 *next;
};
typedef struct node1 node;
int addhash(node*[],int);
void display(node*[]);
int delete(node*[],int);
float search(node*[],int);
int main(){
	int i,len,op,ele;
	node *arr[10];
	for(i=0;i<10;i++) arr[i]=NULL;	
	while(1){
		printf("\n1..add\n2..search\n3..delete\n4..display\n5..exit\nEnter ur choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter element add: ");
				scanf("%d",&ele);
				addhash(arr,ele);
				break;
			case 2:
				printf("Enter element search: ");
				scanf("%d",&ele);
				float j=search(arr,ele);
				if(j>0) printf("Element found at: %.1f\n",j);
				else printf("Element not found!!\n");
				break;
			case 3:
				printf("Enter element delete: ");
				scanf("%d",&ele);
				if(delete(arr,ele)) printf("Element deleted successfully\n");
				else printf("Element not found to delete!!\n");
				break;
			case 4:
				display(arr);
				break;
			case 5:
				return 1;
		}
	}
}
int addhash(node *arr[],int ele){
	int key=ele%10;
	node *ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->next=NULL;
	if(arr[key]==NULL) arr[key]=ptr;
	else{
		node *tmp=arr[key];
		for(;tmp->next!=NULL;tmp=tmp->next);
		tmp->next=ptr;
	}
}
float search(node *arr[],int ele){
	int key=ele%10,i;
	node *tmp=arr[key];
	for(int i=0;tmp!=NULL;tmp=tmp->next,i++){
		if(tmp->data==ele) return (float)key+0.1*i; 
	}
	return -1;
}
void display(node *arr[]){
	int i;
	node *tmp;
	for(i=0;i<10;i++){
		for(tmp=arr[i];tmp!=NULL;tmp=tmp->next){
			printf("%d-->",tmp->data);
			if(tmp->next==NULL) printf("\n");
		}
	}
}
int delete(node *arr[],int ele){
	int key=ele%10;
	node *tmp=arr[key],*old;
	if(tmp==NULL) return 0;
	if(tmp->data==ele){
		arr[key]=tmp->next;
		free(tmp);
		return 1;
	}
	while(tmp!=NULL){
		if(tmp->data==ele){
			old->next=tmp->next;
			free(tmp);
			return 1;
		}
		old=tmp;
		tmp=tmp->next;
	}
	return 0;
}

