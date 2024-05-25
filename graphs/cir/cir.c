#include<stdio.h>
#include<stdlib.h>
int n=4;
int adja(int i,int **adj){
	//printf("i= %d\n",i);
	int k=-1;
	for(int j=0;j<n;j++)
		if(adj[i][j]==1) return j;
	return -1;
}
int path(int i,int **adj,int *p,int l){
	p[l]=i;
	int k=adja(i,adj);
	if(k==-1){
		return -1;
	}
	else{
		for(int m=0;m<l;m++){
			printf("|%d|\n",p[m]);
			if(p[m]==k){
				p[l+1]=k;
				return 1;
			}
		}
		path(k,adj,p,l);
	}
}
int cir(int **adj){
	int i,j;
	int arr[4]={0};
	int p[4+1]={-1,-1,-1,-1,-1};
	for(i=0;i<n;i++){
		if(arr[i]==0){
			arr[i]=1;
			//int p[4+1]={-1,-1,-1,-1,-1};
			int l=path(i,adj,p,0);
			if(l==1) return 1;
			
		}
	}
	for(int i=0;i<n;i++) printf("-> %d",p[i]);
	return 0;
}
int main(){
	int **adj,i,j;
	//n=4;
	adj=calloc(n,sizeof(int*));
	for(i=0;i<n;i++){
		adj[i]=calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d",&adj[i][j]);
	}
	printf("circuit: %d",cir(adj));
}
//0 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0
	//4 0 1 1 2 2 3 3 0
	/*for(i=0;i<n;i++){
		if(arr[i]==0){
			int path[n+1];
			int p=0;
			path[p++]=i;
			arr[i]=1;
			for(j=0;j<n;j++){
				if(adj[i][j]==1)
			}
		}
	}*/
