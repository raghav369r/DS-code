#include<stdio.h>
#define white 2
#define gray 1
#define black 0
int n,time;
int color[25];
int pre[25];
int dis[25];
int fin[25];
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
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
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
	for(i=0;i<n;i++) printf("%d\t%d\t%d\n",dis[i],fin[i],pre[i]);
}
