#include<stdio.h>
#include<stdlib.h>
#define white 2
#define gray 1
#define black 0
int n,time;
int *color,*pre,*dis,*fin;
void DFS_VISIT(int U,int G[n][n]){
	color[U]=gray;
	dis[U]=++time;
	for(int i=0;i<n;i++){
		if(G[U][i]==1 && color[i]==white){
			pre[i]=U;
			DFS_VISIT(i,G);
		}
	}
	color[U]=black;
	fin[U]=++time;
}
void DFS(int G[n][n]){
	int i;
	for(i=0;i<n;i++){
		color[i]=white;
		pre[i]=-1;
	}
	time=0;
	for(i=0;i<n;i++){
		if(color[i]==white)
			DFS_VISIT(i,G);
	}
}
void paths(int s,int d){
	int stack[100],top=-1,i,j;
	for(i=d;;i=pre[i]){
		stack[++top]=i;
		if(stack[top]==s || stack[top]==-1) break;
	}
	if(stack[top]==s)
		for(j=top;j>-1;j--) printf("%d - ",stack[j]);
	else printf(" no path!!\n");
}
//0 1 1 0 2 3 3 2 0 5 5 0 5 4 4 5 1 6 6 1 -1 -1
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	color=(int*)calloc(n,sizeof(int));
	dis=(int*)calloc(n,sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	fin=(int*)calloc(n,sizeof(int));
	int a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	while(1){
		printf("Enter edge(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		a[i][j]=1;	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	DFS(a);
	printf("discovered\tfinal\tparent\n");
	for(i=0;i<n;i++) printf("%d == %d\t%d\t%d\n",i,dis[i],fin[i],pre[i]);
	for(i=1;i<n;i++){
	printf("\npath from %d to %d ",0,i);
	paths(0,i);
	}
}
