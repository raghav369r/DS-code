#include<stdio.h>
#include<stdlib.h>
#define size 20
#define white 2
#define gray 1
#define black 0
int queue[size];
int rear=-1,front=-1;
void enqueue(int ele){
	queue[++rear]=ele;
}
int dequeue(){
	return(queue[front++]);
}
int isqempty(){
	if(rear==-1 || rear==front)
		return 0;
	return 1;
}
int g[4][4]={0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0};
int color[4];
int pre[4];
int len[4];
void bfs(int st){
	int i;
	for(i=0;i<4;i++){ 
		color[i]=white;
		len[i]=9999;
		pre[i]=-1;
	}
	color[st]=gray;
	len[st]=0;
	pre[st]=-1;
	enqueue(st);
	int u,j;
	//printf("%d,%d,%d\n",front,rear,isqempty());
	while(isqempty()){
		u=dequeue();
		//printf("u==%d\n",u);
		for(i=0;i<4;i++){
			//printf("g[%d][%d]= %d\n",u,i,g[u][i]);
			if(g[u][i]==1 && color[i]==white){
				//printf("iam in it \n");
				color[i]=gray;
				len[i]=len[u]+1;
				pre[i]=u;
				enqueue(i);
			}
		}
		color[u]=black;
	}
	for(i=0;i<4;i++){
		printf("%d ",pre[i]);
	}
}
int main(){
	bfs(0);
	int i;
	
}


/*
#include<stdio.h>
#define white 2
#define gray 1
#define black 0
int color[6];
int pre[6];
int dis[6];
int front=-1,rear=-1;
int Q[20];
void BFS(int G[6][6],int S){
	int i,j,U,n=6;
	for(i=0;i<n;i++){
		color[i]=white;
		dis[i]=-1;
		pre[i]=-1;
	}
	color[S]=gray;
	dis[S]=0;
	pre[S]=-1;
	Q[++rear]=S;
	while(rear!=-1 && front!=rear){
		U=Q[front++];
		for(i=0;i<n;i++){ 
			//printf("G[%d]= %d\n",U,G[U][i]);
			if(G[U][i]==1 && color[i]==white){
				color[i]=gray;
				dis[i]=dis[U]+1;
				pre[i]=U;
				Q[++rear]=i;
			}
		}
		color[U]=black;
	}
	printf("\nditance from 1st: ");
	for(i=0;i<n;i++) printf("%d  ",dis[i]);
	printf("\npreceding: ");
	for(i=0;i<n;i++) printf("%d  ",pre[i]);
}
int main(){
	int n=6,i,j;
	printf("Enter no of elements: \n");
	//printf("hey\n");
	scanf("%d",&n);
	int a[n][n];
	//int a[n][n];
	//int a[4][4]={0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0};
	//int a[4][4]={0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
	int a[6][6]={0,1,0,0,0,0
	,0,0,1,1,0,0,
	0,1,0,0,1,0,
	0,1,0,0,0,1,
	0,0,1,0,0,1,
	0,0,0,1,1,0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	printf("Enter edges(enter -1 -1 to stop): ");
	while(1){
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		a[i][j]=1;	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	BFS(a,0);
}


*/
