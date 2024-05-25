#include<stdio.h>
#include<stdlib.h>
int n;
int **adj;
int *vi;
int adja(int i){
	int k=0;
	for(int j=0;j<n;j++)
		if(adj[i][j]==1) k++;
	return k;
}
int aele(int i,int j){
	int k=0;
	for(int l=0;l<n;l++){
		if(adj[i][l]==1) k++;
		if(k==j) return l;
	}
}
int paths(int s,int d){
	if(vi[s]==1) return 0;
	vi[s]=1;
	int k=adja(s);
	if(k==0) return 0;
	else{
		for(int o=1;o<=k;o++){
			int kl=aele(s,o);
			if(kl==d){
				printf("%d -",kl);
				return 1;
			}
			if(paths(kl,d)){
				printf("%d - ",s);
				return 1;
			}
		}
		return 0;
	}
}
int path(int s,int d){
	vi=calloc(n,sizeof(int));
	return paths(s,d);
}
int main(){
	int i,j,s,d;
	printf("Enter no of vetices: ");
	scanf("%d",&n);
	adj=calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
		adj[i]=calloc(n,sizeof(int));
	while(1){
		printf("\nEnter edges(enter -1 -1 to stop): ");
		scanf("%d%d",&i,&j);
		if(i==-1) break;
		adj[i][j]=1;	
	}
	while(1){
		printf("\nEnter sorce vertex and destination vertex to print path: ");
		scanf("%d%d",&s,&d);
		if(s==-1) break;
		if(path(s,d))
			printf("\nyes there is a path");
		else printf("\nNo there is no path");
	
	}
	
}
