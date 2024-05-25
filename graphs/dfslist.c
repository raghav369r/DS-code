#include<stdio.h>
#include<stdlib.h>
#define white 2
#define gray 1
#define black 0
struct node{
	int ver;
	struct node *link;
};
typedef struct node node1;
node1 **adjl;
int n,time;
int *color,*pre,*dis,*fin;
void add(int,int);
void DFS();
void DFS_VISIT(int);
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	color=(int*)calloc(n,sizeof(int));
	dis=(int*)calloc(n,sizeof(int));
	pre=(int*)calloc(n,sizeof(int));
	fin=(int*)calloc(n,sizeof(int));
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
	DFS();
	printf("discovered\tfinal\tparent\n");
	for(i=0;i<n;i++) printf("%d\t%d\t%d\n",dis[i],fin[i],pre[i]);
}
void DFS_VISIT(int U){
	color[U]=gray;
	dis[U]=++time;
	node1 *tmp=adjl[U];
	for(;tmp!=NULL;tmp=tmp->link){ 
		int i=tmp->ver;
		if(color[i]==white){
			pre[i]=U;
			DFS_VISIT(i);
		}
	}
	color[U]=black;
	fin[U]=++time;
}
void DFS(){
	int i;
	for(i=0;i<n;i++){
		color[i]=white;
		pre[i]=-1;
	}
	time=0;
	for(i=0;i<n;i++){
		if(color[i]==white)
			DFS_VISIT(i);
	}
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
