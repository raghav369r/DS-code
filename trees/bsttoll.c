#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};
typedef struct bst node;
struct sll{
	int data;
	struct sll *next;
};
typedef struct sll node1;
node1 *head=NULL;
node1 *tail=NULL;
node *root=NULL;
node *add(node *root,int num){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		root->data=num;
	}
	else if(num<root->data)
		root->left=add(root->left,num);
	else
		root->right=add(root->right,num);
	//printf("\n-->%d ",root->data);
	return root;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}
void insert(int ele){
	node1 *ptr=(node1*)malloc(sizeof(node1));
	ptr->data=ele;
	ptr->next=NULL;
	if(head==NULL)
		head=tail=ptr;
	else{
		tail->next=ptr;
		tail=ptr;
	}
}
void bsttosll(node *root){
	node *q[100],*tmp;
	int front,rear;
	front=rear=-1;
	q[++rear]=root;
	while(rear!=front){
		tmp=q[++front];
		if(tmp->left!=NULL) q[++rear]=tmp->left;
		if(tmp->right!=NULL) q[++rear]=tmp->right;
		insert(tmp->data);
	}
}
void display(){
	for(node1 *tmp=head;tmp!=NULL;tmp=tmp->next)
		printf("%d - ",tmp->data);
}
void inordersll(node *root){
	if(root!=NULL){
		inordersll(root->left);
		insert(root->data);
		inordersll(root->right);
	}
}
int main(){
	root=add(root,100);
	root=add(root,50);
	root=add(root,150);
	root=add(root,25);
	root=add(root,75);
	root=add(root,125);
	root=add(root,175);
	root=add(root,10);
	root=add(root,35);
	root=add(root,60);
	root=add(root,85);
	root=add(root,110);
	root=add(root,115);
	//inorder(root);
	bsttosll(root);
	display();
	head=NULL;
	printf("\nInorder\n");
	inordersll(root);
	display();
}
