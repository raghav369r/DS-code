#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head1 = NULL,*head2 = NULL, *head3=NULL;
//node* merge(node,node);
void insert1(int num1)
{
	node *ptr1;
	ptr1 = (node *)malloc(sizeof(node));
	ptr1->data = num1;
	ptr1->next = NULL;
	if(head1==NULL) head1 = ptr1;
	else
	{
		node *temp1 = head1;
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = ptr1;
	}
}

void insert2(int num2)
{
	node *ptr2;
	ptr2 = (node *)malloc(sizeof(node));
	ptr2->data = num2;
	ptr2->next = NULL;
	if(head2==NULL) head2 = ptr2;
	else
	{
		node *temp2 = head2;
		while(temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = ptr2;
	}
}

void merge()
{
	
	/*if(temp1==NULL)
	{
		temp1 = temp2;
		return temp1;
	}
	else if(temp2 == NULL)
	{
		return head3;
	}
	else if(temp1!=NULL && temp2 != NULL)
	{
		temp1->next = temp2;
		merge(temp1->next,temp2);
	}
	else
		return;
	}*/
	node *temp1 = head1,*temp2 = head2,*temp;
	head3 = head1;
	while(temp1->next != NULL && temp2!= NULL)
	{
		/*temp2->next = temp1->next;
		temp1->next = temp2;
		temp1 = temp1->next;
		temp2 = temp2->next;
*/
		temp = temp2->next;
		temp2->next = temp1->next;
		temp1->next=temp2;
		
		temp2=temp;
		temp1 = temp1->next->next;
	}
	if(temp1->next==NULL)
	{
		temp1->next = temp2;
	}
}
void display()
{
	int opt1;
	node *temp1 = head1,*temp2 = head2,*temp = head3;
	printf("Enter your option\n1..display first list\n2..display second list \n3..display merged list\n");
	scanf("%d",&opt1);
	switch(opt1)
	{
		case 1:
			while(temp1)
			{
				printf("%d-->\n",temp1->data);
				temp1 = temp1->next;
			}
			break;
		case 2:
			while(temp2)
			{
				printf("%d-->\n",temp2->data);
				temp2 = temp2->next;
			}
			break;
		case 3:
			while(temp)
			{
				printf("%d-->\n",temp->data);
				temp = temp->next;
			}
			break;
	}
}
int loopex(){
	node *ptr1,*ptr2;
	int i,j;
	for(ptr1=head1,i=0;ptr1!=NULL;ptr1=ptr1->next,i++){
		if(ptr1==ptr1->next)
			return 0;
		for(ptr2=head1,j=0;j<i;ptr2=ptr2->next,j++)
			if(ptr1==ptr2)
				return 0;
	}
	return 1;
}
void main()
{
	int opt,num1,num2;
	while(1)
	{
		printf("Enter your option\n1..insert first list\n2..insert second list\n3..mergelist\n4..display\n5..detect loop\n6..exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				//insertion
				printf("Enter first list: ");
				scanf("%d",&num1);
				insert1(num1);
				break;
			case 2:
				//inserting second number
				printf("Enter second list: ");
				scanf("%d",&num2);
				insert2(num2);
				break;
			case 3:
				//merge list
				merge();
				break;
			case 4:
				display();
				break;
			case 5:
				if(loopex()) printf("yes there is a loop");
				else printf("no there is no loop");
				break;
			case 6:
				exit(0);
		}
	}
}
