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
	/*for(int i=0;i<n;i++)
		printf("%d - ",pre[i]);*/
	for(int i=d;i!=s;i=pre[i]) path++;
	return path;
}
int main(){
	int ed[][2]={{1,2},{1,3},{1,4},{3,5},{3,6},{3,7}};
	int len=ed[0][0];
	for(int i=0;i<6*2;i++)
		if(*(*ed+i)>len) len=*(*ed+i);
	int **adj=calloc(len,sizeof(int*));
	for(int i=0;i<len;i++) adj[i]=calloc(len,sizeof(int));
	int q[]={4,5,7};
	char up[20];
	int n=0;
	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			int c=0;
			for(int k=0;k<6;k++){
				adj[ed[k][0]-1][ed[k][1]-1]=1;
				adj[ed[k][1]-1][ed[k][0]-1]=1;
				if(ed[k][0]==q[i]&&ed[k][1]==q[j]){
					
					c=1;
					break;
				}
			}
			if(!c){	
				up[n++]=q[i];
				up[n++]=q[j];
			}
		}
	}
	up[n]='\0';
	/*for(int i=0;i<len;i++){
		for(int j=0;j<len;j++) printf("%d ",adj[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<n;i=i+2)
		printf("(%d , %d)\n",up[i],up[i+1]);
	//for(int i=0;i<n;i++) printf("%d ",up[i]);
	color=(int*)calloc(n,sizeof(int));
	dis=(int*)calloc(n,sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	Q=(int*)calloc(n,sizeof(int));
	int ans=0;
	for(int i=0;i<n;i=i+2){
		ans=ans+((up[i]*up[i+1]*dist(up[i]-1,up[i+1]-1,adj,len))%(int)(pow(10,9)+7));
	}
	printf("\nAns= %d",ans);
	//printf("\ndistance(4 and 7)= %d",dist(4-1,7-1,adj,len));	
	//printf("\ndistance(4 and 5)= %d",dist(4-1,5-1,adj,len));
	//printf("\ndistance(5 and 7)= %d",dist(5-1,7-1,adj,len));
}
