#include<stdio.h>
#define white 2
#define gray 1
#define black 0
int color[25];
int pre[25];
int dis[25];
int front=-1,rear=-1;
int Q[25];
int n;
void BFS(int G[n][n],int S){
	int i,j,U;
	for(i=0;i<n;i++){
		color[i]=white;
		dis[i]=-1;
		pre[i]=-1;
	}
	color[S]=gray;
	dis[S]=0;
	pre[S]=-1;
	Q[++rear]=S; //enqueue S
	while(rear!=-1 && front!=rear){
		U=Q[++front];	//dequque 
		for(i=0;i<n;i++){ 
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
	printf("Enter vertex to print path: ");
	scanf("%d",&i);
	printf("\nPath from 0 to %d: ",i);
	for(int tmp=i;tmp!=-1;tmp=pre[tmp])
		printf("%d-",tmp);
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
		printf("Enter edges(enter -1 -1 to stop): ");
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

