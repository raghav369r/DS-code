#include<stdio.h>
#include<stdlib.h>
#define white 2
#define gray 1
#define black 0
int *color,*pre,*dis,*Q;
int front=-1,rear=-1,n;
struct node{
	int ver;
	struct node *link;
};
typedef struct node node1;
node1 **adjl;
int n;
void add(int,int);
void BFS(int);
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	color=(int*)calloc(n,sizeof(int));
	dis=(int*)calloc(n,sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	Q=(int*)calloc(n,sizeof(int));
	adjl=(node1 **)calloc(n,sizeof(node1));
	for(i=0;i<n;i++) adjl[i]=NULL;
	while(1){
		printf("Enter edge(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		if(i<n && j<n) add(i,j);
	}
	printf("Adjacent list of the Tree: \n");
	for(i=0;i<n;i++){
		printf("%d: ",i);
		node1 *tmp1=adjl[i];
		for(;tmp1!=NULL;tmp1=tmp1->link)
			printf("%d-",tmp1->ver);
		printf("\n");
	}
	BFS(0);
}
void add(int i,int j){
	node1 *new=(node1*)malloc(sizeof(node1));
	new->ver=j;
	new->link=NULL;
	if(adjl[i]==NULL)
		adjl[i]=new;
	else{
		node1 *tmp1;
		for(tmp1=adjl[i];tmp1->link!=NULL;tmp1=tmp1->link){
			if(tmp1->ver==j) return;
		}
		if(tmp1->ver==j) return;
		tmp1->link=new;
	}
}
void BFS(int S){
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
		node1 *tmp=adjl[U];
		for(;tmp!=NULL;tmp=tmp->link){ 
			i=tmp->ver;
			if(color[i]==white){
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
	printf("\nEnter vertex to print path: ");
	scanf("%d",&i);
	printf("\nPath from %d to Root: ",i);
	for(int tmp=i;tmp!=-1;tmp=pre[tmp])
		printf("%d-",tmp);
}
