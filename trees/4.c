//bfs in bst and searching a value
#include<stdio.h>
#include<stdlib.h>
struct bst {
	struct bst *left;
	int data;
	struct bst *right;
};

typedef struct bst Node ;
Node *root = NULL;
Node *find_min(Node *);
Node *queue[50];
int rear=-1,front=-1,t=0,l=0,i=0;
void preorder( Node *root)
{
	if ( root == NULL)
	return;
	printf(" %d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder( Node *root)
{
	if ( root == NULL)
	return;
	
	inorder(root->left);
	printf(" %d ", root->data);
	inorder(root->right);


}
Node * delete(Node *root,int num)
{
 Node *temp;
 if(root==NULL)
 {
  printf("empty nodes");
  return NULL;
 }
 else if(num<root->data)
   root->left=delete(root->left,num);
 else if(num>root->data)
   root->right=delete(root->right,num);
 else if(root->left!=NULL && root->right!=NULL)
 {

  	//temp=find_max(root->left);
        temp=find_min(root->right);
        root->data=temp->data;//common
  	//root->right=delete(root->right,temp->data);
  	root->left=delete(root->left,temp->data);
 }
 else
 {
   temp=root;
   if(root->left==NULL)
     root=root->right;
   else if(root->right==NULL)
     root=root->left;
   free(temp);
  }
  return root;
} 
Node *find_min(Node *root)
{
 if(root==NULL)
    return NULL;
 else if(root->left==NULL)
    return root;
 else
   return(find_min(root->left));
}
/*
Node *find_max(Node *root)
{
 if(root==NULL)
    return NULL;
 else if(root->right==NULL)
    return root;
 else
   return(find_max(root->right));
}
*/
 Node * insert( Node *root, int num )
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
void bfs()
{
  if(root==NULL)
     printf("no nodes");
  else
  {
     Node *temp;
     while(rear!=-1 && front!=rear)
     {
      temp=queue[++front];
      t++;
      printf("%d->",temp->data);
      if(temp->left!=NULL)
        queue[++rear]=temp->left;
      if(temp->right!=NULL)
        queue[++rear]=temp->right;
      if(temp->left==NULL && temp->right==NULL)
        l++;
     }
    }
}
int search(Node *root,int val)
{
   if(root==NULL)
        return -1;
   else if(root->data==val)
        return 1;
   else if(val>root->data)
        search(root->right,val);
   else
         search(root->left,val);
}
int height(Node *root)
{
  if(root==NULL)
    return -1;
  int left_height=height(root->left)+1;
  int right_height=height(root->right)+1;
  return(max(left_height,right_height));
}
int max(int a,int b)
{
 if(a>b)
   return a;
 else
   return b;
}
void main()
{
	int opt,num,flag=-1,key,h;
	Node *temp;
	while(1)
	{
		printf(" \nEnter 1.. Insert 2.. Delete 3.. Preorder 4.. Inorder ...5.dfs...6...min...7..search...8..total nodes..9..height..10..Exit=");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1: // insert
				printf(" Enter a number to insert \n");
				scanf("%d", &num);
				root = insert(root, num);
			
				break;
			case 2 : // Delete
			        printf(" Enter a number to delete\n");
				scanf("%d", &num); 
   				root = delete(root, num);
				break;
				
			case 3: // Preorder
				preorder(root);
				break;
		
			case 4 :  // Inorder
				inorder(root);
				break;
			case 5:
			        queue[++rear]=root;
			        bfs();
			        break;
			case 6:
			      temp=find_min(root);
			      printf("minimum value =%d",temp->data);
			      break;
			case 7:
			     printf("enter key value");
			     scanf("%d",&key);
			     flag=search(root,key); 
			     if(flag==-1)
			       printf("\n%d not present",key);
			     else
			        printf("\n%d present",key);
			      break;
			case 8:
			     printf("total no of nodes=%d\n",t);
			     i=t-l;
	                     printf("total no of internal nodes=i=%d and leaves=%d",i,l);
			     break;
			case 9:
			      h=height(root);
			      printf("\nheight of tree=%d",h);
			      break;
			case 10:  exit(0);
		
		
		
		}
	
	
	
	}





}
