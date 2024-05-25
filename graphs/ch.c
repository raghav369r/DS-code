#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define white 2
#define gray 1
#define black 0
int *color,*pre,*dis,*Q;
int front,rear,n;
void BFS(int **G,int S){
	int i,j,U;
	for(i=0;i<n;i++){
		color[i]=white;
		dis[i]=-1;
		pre[i]=-1;
	}
	color[S]=gray;
	dis[S]=0;
	pre[S]=-1;
	Q[++rear]=S; //ENQUEUE S
	while(rear!=-1 && front!=rear){
	//	display();
		U=Q[++front];	//DEQUEUE
		for(i=0;i<n;i++){ 
			if(G[U][i]==1 && color[i]==white){  //CHECK IF Q IS MT
				color[i]=gray;
				dis[i]=dis[U]+1;
				pre[i]=U;
				Q[++rear]=i;			//ENQUEUE ADJACENT VERTEX
			}
		}
		color[U]=black;
	}
}
int dist(int s,int d,int **adj,int len){
	n=len;
	front=rear=-1;
	BFS(adj,s);
	int path=0;
	for(int i=d;i!=s;i=pre[i]) path++;
	//printf("\n%d %d =%d",s,d,path);
	return path;
}
int main(){
	int len,qu;
	scanf("%d %d",&len,&qu);
	color=(int*)calloc(len,sizeof(int));
	dis=(int*)calloc(len,sizeof(int));
	pre=(int*)calloc(len,sizeof(int));
	Q=(int*)calloc(len,sizeof(int));
	int **adj=calloc(len,sizeof(int*));
	for(int i=0;i<len;i++) adj[i]=calloc(len,sizeof(int));
	int a,b;
	
	for(int i=1;i<len;i++){
		scanf("%d %d",&a,&b);
		adj[a-1][b-1]=1;
		adj[b-1][a-1]=1;
	}
	
	//int que[qu],ll=0;
	for(a=0;a<qu;a++){
		scanf("%d",&b);
		int q[b];
		for(int k=0;k<b;k++)
			scanf("%d",&q[k]);
		char up[20000];
	//int n=0;
	int ans=0;
	for(int i=0;i<sizeof(q)/sizeof(int);i++){
		for(int j=i+1;j<sizeof(q)/sizeof(int);j++){
			if(!adj[q[i]-1][q[j]-1]){	
			ans=ans+((q[i]*q[j]*dist(q[i]-1,q[j]-1,adj,len))%(int)(pow(10,9)+7));
			//	up[n++]=q[i]-1;
			//	up[n++]=q[j]-1;
			}
		}
	}
	//que[ll++]=ans;
	printf("\n%d",ans);
	}
}
