#include<stdio.h>
#include<stdlib.h>
#define white 2
#define gray 1
#define black 0
int *color,*pre,*dis,*Q;
int front=-1,rear=-1,n;
void display(){
	printf("\nElements in Q: ");
	for(int i=front+1;i<=rear;i++)
		printf("%d  ",Q[i]);
}
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
	/*printf("\nColour of each vertex: ");
	for(i=0;i<n;i++) printf("%d  ",color[i]);
	printf("\nditance from 1st: ");
	for(i=0;i<n;i++) printf("%d  ",dis[i]);
	printf("\npreceding: ");
	for(i=0;i<n;i++) printf("%d  ",pre[i]);
	printf("\nEnter vertex to print path: ");
	scanf("%d",&i);
	printf("\nPath from 0 to %d: ",i);
	for(int tmp=i;tmp!=-1;tmp=pre[tmp])
		printf("%d-",tmp);
*/}
void paths(int s,int d){
	int stack[100],top=-1,i,j;
	for(i=d;;i=pre[i]){
		stack[++top]=i;
		if(stack[top]==s || stack[top]==-1) break;
	}
	if(stack[top]==s){
		printf("\nPath from %d to %d: ",s,d);
		for(j=top;j>-1;j--) printf("%d - ",stack[j]);
	}
	else printf("\nNo path between %d to %d !!",s,d);
}
int path(int g[n][n],int s,int d){
	if(s==d) printf("%d ",d);
	else if(pre[d]==-1)
		printf("no path\n");
	else{
		path(g,s,pre[d]);
		printf("%d- ",d);
	}
}
//0 1 1 0 1 4 4 1 0 4 4 0 3 2 2 3 2 4 4 2 -1 -1
// 0 1 3 0 1 3 1 4 2 3 2 4 4 2 1 5 5 1 6 5 -1 -1              
//0 1 3 0 1 3 1 4 2 3 2 4 4 2 1 5 5 1 6 5 -1 -1
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	color=(int*)calloc(n,sizeof(int));
	dis=(int*)calloc(n,sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	Q=(int*)calloc(n,sizeof(int));
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
	BFS(a,0);
	/*while(1){
		printf("\nEnter 2 vertexes to print path: ");
		scanf("%d%d",&i,&j);
		if(i==-1 ||j==-1) return 0;
		paths(i,j);
		//path(a,i,j);
	}*/
	for(i=1;i<n;i++){
		paths(0,i);
	}
	for(i=0;i<n;i++)
		printf("-> %d",pre[i]);
}

