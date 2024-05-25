#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data[10];
	struct node *left,*right;
};
typedef struct node node;
node *root=NULL;
int compare(char *a,char *b){
	int l1=strlen(a),l2=strlen(b),i,j;
	for(i=0;i<l1 && i<l2;i++){
		if(a[i]>b[i]) return -1;
		else if(a[i]<b[i]) return 1;
	}
	if(l1==l2) return 0;
	else if(l1<l2) return 1;
	else return -1;
}
node *insert(node *root,char *nam){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		//strcat(root->data,nam);
		strcpy(root->data,nam);
		//root->data=nam;
		root->left=root->right=NULL;
	}
	else{
		//int n=compare(nam,root->data);
		if(compare(nam,root->data)>0)
			root->left=insert(root->left,nam);
		else
			root->right=insert(root->right,nam);
	}
	return root;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%s -> ",root->data);
		inorder(root->right);
	}
}
node *min(node *root){
	if(root==NULL) return NULL;
	else if(root->left==NULL) return root;
	else
		min(root->left);
}
node *delete(node* root,char *name){
	if(root==NULL){
		printf("Element not found to delete!!");
		return NULL;
	}
	else{
		int n=compare(root->data,name);
		if(n<0)
			root->left=delete(root->left,name);
		else if(n>0)
			root->right=delete(root->right,name);
		else if(root->left!=NULL && root->right!=NULL){
			node *tmp=min(root->right);
			strcpy(root->data,tmp->data);
			root->right=delete(root->right,root->data);
		}
		else{
			node *tmp=root;
			if(root->right==NULL)
				root=root->left;
			else
				root=root->right;
			free(tmp);
		}
		
	}
	return root;
}
int main(){
	char *a="a",*b="z";
	printf("%d ",compare(a,b));
	int op;
	char *name;
	while(1){
		printf("1..insert\t2..delete\t3..print\t4..exit\nEnter ur choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter name to insert: ");
				scanf("%s",name);
				root=insert(root,name);
				break;
			case 3:
				//printf("Root: %s\n",root->data);
				inorder(root);
				printf("\n");
				break;
			case 2:
				printf("Enter name to delete: ");
				scanf("%s",name);
				root=delete(root,name);
				break;
			case 4:
				return 1;
		}
	}
}
