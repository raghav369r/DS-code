#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};
typedef struct bst node;
node *root=NULL;
void preorder(node *root){
	if(root!=NULL){
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->data);
	}
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}
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
node *max(node *root){
	if(root==NULL) return NULL;
	else if(root->right==NULL) return root;
	else max(root->right);
}
node *min(node *root){
	if(root==NULL) return NULL;
	else if(root->left==NULL){
		printf("/nmin= %d\n",root->data);
		return root;
	}
	else min(root->left);
}
node *delete(node *root,int num){
	node *tmp;//=root;
	//tmp->right=root->right;
	//tmp->left=root->left;
	if(root==NULL){
		printf("empty tree!!");
		return root;
	}
	else if(num>root->data)
		root->right=delete(root->right,num);
	else if(num<root->data)
		root->left=delete(root->left,num);
	else if(root->left!=NULL && root->right!=NULL){
		tmp=max(root->left);
		//tmp=min(root->right);
		root->data=tmp->data;
		root->left=delete(root->left,root->data);
		//root->right=delete(root->right,root->data);
	}
	else{
		tmp=root;
		if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
		//free(root);
		free(tmp);
		//tmp->right=root->right;
		//tmp->left=root->left;
	}
	//if(root==NULL) printf("\nNULL");
	//else printf("\n-->%d ",root->data);
	return root;
}
int totalnodes(node *root)
{
 if(root==NULL)
    return 0;
 else
    return totalnodes(root->left)+totalnodes(root->right)+1;
}
int main(){
	int num,opt;
	while(1){
		printf("1..add\n2..delete\n3..display(inoreder)\n4..display(preorder)\n5..display(postorder)\n6..exit\n7..no of nodes\nEnter ur chioce: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter num to add: ");
				scanf("%d",&num);
				root=add(root,num);
				break;
			case 2:
				printf("Enter num to delete: ");
				scanf("%d",&num);
				root=delete(root,num);
				//printf("\nroot of left= %d",root->left->data);
				break;
			case 3:
				inorder(root);
				printf("\n");
				break;
			case 4:
				preorder(root);
				printf("\n");
				break;
			case 5:
				postorder(root);
				printf("\n");
				break;
			case 6:
				return 1;
			case 7:
				printf("No Of Nodes= %d\n",totalnodes(root));
				break;
		}
	}
}
