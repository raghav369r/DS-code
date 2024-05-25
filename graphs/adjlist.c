#include<stdio.h>
#include<stdlib.h>
struct node{
	int ver;
	struct node *link;
};
typedef struct node node1;
node1 **adjl;
int n;
void add(int i,int j){
	node1 *new=(node1*)malloc(sizeof(node1));
	new->ver=j;
	new->link=adjl[i];
	adjl[i]=new;
	/*if(adjl[i]==NULL)
		adjl[i]=new;
	else{
		node1 *tmp1;
		for(tmp1=adjl[i];tmp1->link!=NULL;tmp1=tmp1->link){
			if(tmp1->ver==j) return;
		}
		if(tmp1->ver==j) return;
		tmp1->link=new;
	}*/
}
int main(){
	int i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	adjl=(node1 **)calloc(n,sizeof(node1));
	for(i=0;i<n;i++) adjl[i]=NULL;
	while(1){
		printf("Enter edge(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1 || j==-1) break;
		if(i<n && j<n) add(i,j);
	}
	for(i=0;i<n;i++){
		printf("%d: ",i);
		node1 *tmp1=adjl[i];
		for(;tmp1!=NULL;tmp1=tmp1->link)
			printf("%d-",tmp1->ver);
		printf("\n");
	}
}
