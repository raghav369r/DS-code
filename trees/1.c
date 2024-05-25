#include<stdio.h>
#include<stdlib.h>
struct bst {
	struct bst *left;
	int data;
	struct bst *right;
};

typedef struct bst Node ;
Node *root = NULL;
void preorder( Node *root)
{
	if ( root == NULL)
	  return;
	printf(" %d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
Node *insert(Node *root,int num)
{

	if (root == NULL)
	{
		root = (Node *) malloc ( sizeof(Node));
		root->data = num;
		root->left = NULL;
		root->right = NULL;
	
	
	}
	else
	{
		if ( num < root->data)
			root->left = insert( root->left , num);
		else 
			root->right = insert ( root->right, num);
	
	}
	return root;
}
int totalnodes(Node *root)
{
 if(root==NULL)
    return 0;
 else
    return totalnodes(root->left)+totalnodes(root->right)+1;
}
int total_internal_nodes(Node *root)
{
 if(root==NULL)
    return 0;
 if(root->left==NULL && root->right==NULL)
    return 0;
 else
    return total_internal_nodes(root->left)+total_internal_nodes(root->right)+1;
}
int external(Node *root)
{
 if(root==NULL)
    return 0;
 else if(root->left==NULL && root->right==NULL)
    return 1;
 else
    return external(root->left)+external(root->right);
}
void mirror(Node *root)
{
  Node *ptr;
  if(root!=NULL)
  {
    mirror(root->left);
    mirror(root->right);
    ptr=root->left;
    root->left=root->right;
    root->right=ptr;
   }
}
void main()
{
	int opt,num,h,t;
	Node *temp;
	while(1)
	{
		printf("\nEnter 1.. Insert ..2.. Preorder ..3  total nodes..4..total internal nodes..5.external..6..mirror image..7..delete tree..8..Exit=");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1: // insert
				printf(" Enter a number to insert \n");
				scanf("%d", &num);
				root = insert(root, num);
			
				break;
