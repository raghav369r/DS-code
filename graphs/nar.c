#include<stdio.h>
int queue[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},queue1[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},n=5,k=-1,s,vertices[5]={0,1,2,3,4};
int rear=-1,front=-1;
int color[5]={10,10,10,10,10};
int predecessor[5]={0,0,0,0,0},input[5][5]={{0,1,0,1,0},{1,0,1,1,0},{0,1,0,0,1},{1,1,0,0,1},{0,0,1,1,0}};
void adjacent_nodes(int input1[5][5],int msource,int c)
{
	k=-1;
	int j=0;
	for(j=0;j<c;j++)
	{
		if(input1[msource][j]!=0)
			queue1[++k]=j;	
	}
}/*
void enqueue(int o)
{
		rear++;
		queue[rear]=o;
}
int dequeue()
{
		front++;
		return queue[front];
}*/
void dfs(int u)
{
	printf("in dfs");
	color[u]=20;
	adjacent_nodes(input,u,5);
	while(queue1[h]!=-1)
	{
		if(color[queue1[h++]]==10)
		{
			predecessor[queue1[h]]=u;
			dfs(queue1[h]);
		}
	}
	color[u]=30;
	return;
}
void main()
{
	int n,i,j; 
	printf("narendra\n");
	/*for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("enter element at index [%d][%d]::",i,j);
			scanf("%d",&input[i][j]);
			printf("\n");
		}
	}*/
	/*printf("enter starting node number value");
	scanf("%d",&s);
	color[s]=20;
	predecessor[s]=-1;*/
	//enqueue(s);
	for(i=0;i<5;i++)
	{
		printf("in for");
		if(color[vertices[i]]==10)
			dfs(vertices[i]);
	}
	printf("\npredecessor\n");
	for(i=0;i<5;i++)
		printf("%d\n",predecessor[i]);
	printf("\ncolour\n");
	for(i=0;i<5;i++)
		printf("%d\n",color[i]);
}
